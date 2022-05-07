PKGNAME = small-tools
DESCRIPTION = Small tools for terminal.
VERSION = 0.1
LICENSE = GPLv3+
URL = https://github.com/mdomlop/$(PKGNAME)

PREFIX = '/usr'
DESTDIR = ''

#CC=musl-gcc
#CFLAGS=-static -Os -ansi -Wall -pedantic
CFLAGS=-static -std=c11 -Wall -pedantic -Os
LDFLAGS+=-lm

NAMES = $(shell grep -m1 EXECUTABLE src/*.c | cut -d\" -f2)
PKGEXT=.pkg.tar.zst
ARCHPKG = $(PKGNAME)-$(VERSION)-1-$(shell uname -m)$(PKGEXT)
INSTALLED_BINARIES =  $(addprefix $(DESTDIR)$(PREFIX)/bin/,$(NAMES))

ELFS = $(addsuffix .elf,$(addprefix src/,$(NAMES)))
EXES = $(addsuffix .exe,$(addprefix src/,$(NAMES)))
SRC  =  $(addsuffix .c,$(addprefix src/,$(NAMES)))

all: elf exe

%.elf: %.c
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
elf: $(ELFS)

exe: CC = x86_64-w64-mingw32-gcc
%.exe: %.c
	$(CC) $(CFLAGS) -Wno-format-zero-length $^ -o $@ $(LDFLAGS)
exe: $(EXES)

elf_opti: CFLAGS = -std=c11 -march=native -mtune=native -Wall -pedantic -static -O2
elf_opti: $(ELFS)
install_elf_opti: elf_opti install

elf_debug: CFLAGS = -Wall -ggdb3
elf_debug: $(ELFS)

install_elf: $(INSTALLED_BINARIES)
$(DESTDIR)$(PREFIX)/bin/%: src/%.elf
	install -dm 755 $(DESTDIR)$(PREFIX)/bin/
	install -Dm 755 $^ $@

install: install_elf LICENSE README.md
	install -Dm 644 LICENSE $(DESTDIR)$(PREFIX)/share/licenses/$(PKGNAME)/COPYING
	install -Dm 644 README.md $(DESTDIR)$(PREFIX)/share/doc/$(PKGNAME)/README

uninstall:
	rm -f $(INSTALLED_BINARIES)
	rm -f $(PREFIX)/share/licenses/$(PKGNAME)/LICENSE
	rm -f $(PREFIX)/share/doc/$(PKGNAME)/README

arch_clean:
	rm -rf pkg
	rm -f $(ARCHPKG)

clean: arch_clean
	rm -f $(ELFS) $(EXES)


togit: clean
	git add .
	git commit -m "Updated from makefile"
	git push origin

arch_pkg: $(ARCHPKG)
$(ARCHPKG): PKGBUILD makefile $(SRC) LICENSE README.md
	echo $(ARCHPKG)
	sed -i "s|pkgname=.*|pkgname=$(PKGNAME)|" PKGBUILD
	sed -i "s|pkgver=.*|pkgver=$(VERSION)|" PKGBUILD
	sed -i "s|pkgdesc=.*|pkgdesc='$(DESCRIPTION)'|" PKGBUILD
	sed -i "s|url=.*|url='$(URL)'|" PKGBUILD
	sed -i "s|license=.*|license=('$(LICENSE)')|" PKGBUILD
	makepkg -df PKGDEST=./ BUILDDIR=./ PKGEXT='$(PKGEXT)'
	pwd
	@echo
	@echo Package done!
	@echo You can install it as root with:
	@echo pacman -U $@

.PHONY: all elf exe elf_opti install_elf install_elf_opti elf_degug install uninstall arch_clean clean togit arch_pkg


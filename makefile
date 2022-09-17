####################
#### Tiny tools ####
####################

include vars.mk

#CC=musl-gcc
#CFLAGS=-static -Os -ansi -Wall -pedantic
CFLAGS=-static -std=c11 -Wall -pedantic -Os
LDFLAGS+=-lm

NAMES = $(shell grep -m1 EXECUTABLE src/*.c | cut -d\" -f2)



INSTALLED_BINARIES =  $(addprefix $(DESTDIR)$(PREFIX)/bin/,$(NAMES))
INSTALLED_DOCS = $(DESTDIR)/$(PREFIX)/share/doc/$(PKGNAME)/README $(DESTDIR)/$(PREFIX)/share/doc/$(PKGNAME)/AUTHORS $(DESTDIR)/$(PREFIX)/share/licenses/$(PKGNAME)/COPYING

ELFS = $(addsuffix .elf,$(addprefix src/,$(NAMES)))
EXES = $(addsuffix .exe,$(addprefix src/,$(NAMES)))
SRC  =  $(addsuffix .c,$(addprefix src/,$(NAMES)))

default: pkg_arch pkg_debian pkg_ocs

bin: elf exe

%.elf: %.c
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)
elf: $(ELFS)

exe: CC = x86_64-w64-mingw32-gcc
%.exe: %.c
	$(CC) $^ -o $@ $(CFLAGS) -Wno-format-zero-length $(LDFLAGS)
exe: $(EXES)

elf_opti: CFLAGS = -std=c11 -march=native -mtune=native -Wall -pedantic -static -O2
elf_opti: $(ELFS)
install_elf_opti: elf_opti install

elf_debug: CFLAGS = -Wall -ggdb3
elf_debug: $(ELFS)

$(DESTDIR)/$(PREFIX)/share/doc/$(PKGNAME)/README: README.md
	install -dm 755 "$(DESTDIR)/$(PREFIX)/share/doc/$(PKGNAME)"
	install -Dm 644 $^ $@
$(DESTDIR)/$(PREFIX)/share/doc/$(PKGNAME)/AUTHORS: AUTHORS
	install -dm 755 "$(DESTDIR)/$(PREFIX)/share/doc/$(PKGNAME)"
	install -Dm 644 $^ $@
$(DESTDIR)/$(PREFIX)/share/licenses/$(PKGNAME)/COPYING: LICENSE
	install -dm 755 "$(DESTDIR)/$(PREFIX)/share/licenses/$(PKGNAME)"
	install -Dm 644 $^ $@

install: $(INSTALLED_BINARIES) $(INSTALLED_DOCS)
$(DESTDIR)$(PREFIX)/bin/%: src/%.elf
	install -dm 755 $(DESTDIR)$(PREFIX)/bin/
	install -Dm 755 $^ $@

uninstall:
	rm -f $(INSTALLED_BINARIES)
	rm -f $(INSTALLED_DOCS)
	rmdir $(PREFIX)/share/licenses/$(PKGNAME)
	rmdir $(PREFIX)/share/doc/$(PKGNAME)


clean: clean_arch clean_debian clean_ocs
	rm -f $(ELFS) $(EXES)

purge: clean
	rm -f $(ARCHPKG) $(DEBIANPKG) $(OCSPKG)

include arch.mk
include debian.mk
include ocs.mk

.PHONY: all elf exe elf_opti install_elf install_elf_opti elf_degug install uninstall arch_clean clean togit arch_pkg


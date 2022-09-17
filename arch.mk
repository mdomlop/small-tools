
ARCHI = $(shell uname -m)
PKGEXT=pkg.tar.zst
ARCHPKG = $(PKGNAME)-$(VERSION)-1-$(ARCHI).$(PKGEXT)

PKGBUILD:
	echo '# Maintainer: $(AUTHOR) <$(MAIL)>' > $@
	echo '_pkgver_year=2018' >> $@
	echo '_pkgver_month=07' >> $@
	echo '_pkgver_day=26' >> $@
	echo 'pkgname=$(PKGNAME)' >> $@
	echo 'pkgver=$(VERSION)' >> $@
	echo 'pkgrel=1' >> $@
	echo 'pkgdesc="$(DESCRIPTION)"' >> $@
	#echo 'arch=("any")' >> $@
	echo 'arch=("$(ARCHI)")' >> $@
	echo 'url="$(URL)"' >> $@
	echo 'source=()' >> $@
	echo 'license=("$(LICENSE)")' >> $@

	echo 'group=("tools")' >> $@
	#echo 'changelog=ChangeLog' >> $@
	echo 'build() {' >> $@
	echo 'cd $$startdir' >> $@
	echo 'make elf' >> $@
	echo '}' >> $@
	echo 'package() {' >> $@
	echo 'cd $$startdir' >> $@
	echo 'make install DESTDIR=$$pkgdir' >> $@
	echo '}' >> $@

pkg_arch: $(ARCHPKG)
$(ARCHPKG): PKGBUILD makefile README.md
	sed -i "s|pkgname=.*|pkgname=$(PKGNAME)|" PKGBUILD
	sed -i "s|pkgver=.*|pkgver=$(VERSION)|" PKGBUILD
	sed -i "s|pkgdesc=.*|pkgdesc='$(DESCRIPTION)'|" PKGBUILD
	sed -i "s|url=.*|url='$(URL)'|" PKGBUILD
	makepkg -df PKGDEST=./ BUILDDIR=./ PKGEXT='.$(PKGEXT)'
	@echo
	@echo Package done!
	@echo You can install it as root with:
	@echo pacman -U $@

clean_arch:
	rm -rf pkg PKGBUILD

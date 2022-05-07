# Maintainer: Manuel Domínguez López <mdomlop at gmail dot com>

_pkgver_year=2022
_pkgver_month=05
_pkgver_day=07

pkgname=small-tools
pkgver=0.1
pkgrel=1
pkgdesc='Small tools for terminal.'
arch=('i686' 'x86_64')
url='https://github.com/mdomlop/small-tools'
source=()
license=('GPLv3+')

build() {
    cd $startdir
    make elf
    }

package() {
    cd $startdir
    make install DESTDIR=$pkgdir
}

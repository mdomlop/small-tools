
PREFIX=/usr
DESTDIR=''

HNAME := $(shell grep ^HNAME INFO | cut -d= -f2)
PKGNAME := $(shell grep ^PKGNAME INFO | cut -d= -f2)
AUTHOR := $(shell grep ^AUTHOR INFO | cut -d= -f2)
VERSION := $(shell grep ^VERSION INFO | cut -d= -f2)
LICENSE := $(shell grep ^LICENSE INFO | cut -d= -f2)
DESCRIPTION := $(shell grep ^DESCRIPTION INFO | cut -d= -f2)
URL := $(shell grep ^URL INFO | cut -d= -f2)
MAIL := $(shell grep ^MAIL INFO | cut -d= -f2 | tr '[A-Za-z]' '[N-ZA-Mn-za-m]')
YEAR := $(shell grep ^YEAR INFO | cut -d= -f2)

TIMESTAMP = $(shell LC_ALL=C date '+%a, %d %b %Y %T %z')

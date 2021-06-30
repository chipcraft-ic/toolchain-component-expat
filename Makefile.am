#
#                          __  __            _
#                       ___\ \/ /_ __   __ _| |_
#                      / _ \\  /| '_ \ / _` | __|
#                     |  __//  \| |_) | (_| | |_
#                      \___/_/\_\ .__/ \__,_|\__|
#                               |_| XML parser
#
# Copyright (c) 2017-2021 Sebastian Pipping <sebastian@pipping.org>
# Copyright (c) 2018      KangLin <kl222@126.com>
# Licensed under the MIT license:
#
# Permission is  hereby granted,  free of charge,  to any  person obtaining
# a  copy  of  this  software   and  associated  documentation  files  (the
# "Software"),  to  deal in  the  Software  without restriction,  including
# without  limitation the  rights  to use,  copy,  modify, merge,  publish,
# distribute, sublicense, and/or sell copies of the Software, and to permit
# persons  to whom  the Software  is  furnished to  do so,  subject to  the
# following conditions:
#
# The above copyright  notice and this permission notice  shall be included
# in all copies or substantial portions of the Software.
#
# THE  SOFTWARE  IS  PROVIDED  "AS  IS",  WITHOUT  WARRANTY  OF  ANY  KIND,
# EXPRESS  OR IMPLIED,  INCLUDING  BUT  NOT LIMITED  TO  THE WARRANTIES  OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
# NO EVENT SHALL THE AUTHORS OR  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR  OTHER LIABILITY, WHETHER  IN AN  ACTION OF CONTRACT,  TORT OR
# OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
# USE OR OTHER DEALINGS IN THE SOFTWARE.

AUTOMAKE_OPTIONS = \
    dist-bzip2 \
    dist-lzip \
    dist-xz \
    foreign \
    subdir-objects

ACLOCAL_AMFLAGS = -I m4
LIBTOOLFLAGS = --verbose

SUBDIRS = lib # lib goes first to build first
if WITH_XMLWF
SUBDIRS += xmlwf
endif

pkgconfig_DATA = expat.pc
pkgconfigdir = $(libdir)/pkgconfig


dist_cmake_DATA = \
    cmake/autotools/expat.cmake

nodist_cmake_DATA = \
    cmake/autotools/expat-config-version.cmake \
    cmake/autotools/expat-noconfig.cmake \
    cmake/expat-config.cmake

cmakedir = $(libdir)/cmake/expat-@PACKAGE_VERSION@


_EXTRA_DIST_CMAKE = \
    cmake/autotools/expat-noconfig__linux.cmake.in \
    cmake/autotools/expat-noconfig__macos.cmake.in \
    cmake/autotools/expat-noconfig__windows.cmake.in \
    cmake/autotools/expat-package-init.cmake \
    cmake/mingw-toolchain.cmake \
    \
    CMakeLists.txt \
    CMake.README \
    ConfigureChecks.cmake \
    expat.pc.cmake \
    expat_config.h.cmake

_EXTRA_DIST_WINDOWS = \
    win32/build_expat_iss.bat \
    win32/expat.iss \
    win32/MANIFEST.txt \
    win32/README.txt

EXTRA_DIST = \
    $(_EXTRA_DIST_CMAKE) \
    $(_EXTRA_DIST_WINDOWS) \
    \
    conftools/expat.m4 \
    conftools/get-version.sh \
    \
    fuzz/xml_parsebuffer_fuzzer.c \
    fuzz/xml_parse_fuzzer.c \
    \
    xmlwf/xmlwf_helpgen.py \
    xmlwf/xmlwf_helpgen.sh \
    \
    buildconf.sh \
    Changes \
    README.md \
    \
    fix-xmltest-log.sh \
    test-driver-wrapper.sh


.PHONY: buildlib
buildlib:
	@echo 'ERROR: Running "make buildlib LIBRARY=libexpatw.la"' >&2
	@echo 'ERROR: is no longer supported.  INSTEAD please:' >&2
	@echo 'ERROR:' >&2
	@echo 'ERROR:  * Mass-patch Makefile.am, e.g.' >&2
	@echo 'ERROR:    # find -name Makefile.am -exec sed \' >&2
	@echo 'ERROR:          -e "s,libexpat\.la,libexpatw.la," \' >&2
	@echo 'ERROR:          -e "s,libexpat_la,libexpatw_la," \' >&2
	@echo 'ERROR:          -i {} +' >&2
	@echo 'ERROR:' >&2
	@echo 'ERROR:  * Run automake to re-generate Makefile.in files' >&2
	@echo 'ERROR:' >&2
	@echo 'ERROR:  * Use "./configure --without-xmlwf" and/or' >&2
	@echo 'ERROR:    "make -C lib all install" to bypass compilation' >&2
	@echo 'ERROR:    of xmlwf (e.g. with -DXML_UNICODE)' >&2
	@echo 'ERROR:' >&2
	@false

.PHONY: qa
qa:
	QA_COMPILER=clang QA_SANITIZER=address   ./qa.sh
	QA_COMPILER=clang QA_SANITIZER=memory    ./qa.sh
	QA_COMPILER=clang QA_SANITIZER=undefined ./qa.sh
	QA_COMPILER=gcc   QA_PROCESSOR=gcov      ./qa.sh

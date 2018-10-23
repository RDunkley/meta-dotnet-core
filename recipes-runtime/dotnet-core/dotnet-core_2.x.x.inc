###################################################################################################
# Owner: Richard Dunkley
# Description: Contains additional parameters for the recipe to download the release binaries
# from Microsoft pertaining to all 2.x.x versions.
# Copyright: Richard Dunkley 2018
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://github.com/dotnet/core/issues"
SECTION = "runtime"

S = "${WORKDIR}/dotnet-${PV}"

require recipes-runtime/dotnet-core/dotnet-core_mit.inc

DEPENDS = "zlib"
RDEPENDS_${PN} = "lttng-ust zlib curl libgssglue"

INSANE_SKIP_${PN} += "already-stripped libdir textrel"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

PACKAGES = "${PN}-dbg ${PN}"

FILES_${PN} += "${datadir}"
FILES_${PN} += ""


do_install_prepend () {
	install -d ${D}${bindir}
	install -d ${D}${datadir}/dotnet/
	install -m 0755 ${S}/dotnet ${D}${datadir}/dotnet/
	install -m 0644 ${S}/LICENSE.txt ${D}${datadir}/dotnet/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${datadir}/dotnet/

	install -d ${D}${datadir}/dotnet/host/fxr/${PV}/
	install -m 0755 ${S}/host/fxr/${PV}/libhostfxr.so ${D}${datadir}/dotnet/host/fxr/${PV}/

	install -d ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	
	install -m 0644 ${S}/shared/Microsoft.NETCore.App/${PV}/.version ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/.version
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}/*.so; do
		install -m 0755 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}/{*.dll,*.json,*.txt}; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	done
}

do_install_append() {
    cd ${D}${bindir}
    ln -s ../share/dotnet/dotnet ${D}${bindir}/dotnet
}


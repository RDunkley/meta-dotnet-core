###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft
# pertaining to all 3.x.x versions.
# Copyright Richard Dunkley 2019
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://github.com/aspnet/AspNetCore/issues"
SECTION = "runtime"

S = "${WORKDIR}/aspnet-${PV}"

require recipes-runtime/aspnet-core/aspnet-core_mit_3.x.x.inc

DEPENDS = "zlib"
RDEPENDS:${PN} = "icu lttng-tools lttng-ust zlib curl libgssglue"

INSANE_SKIP:${PN} += "already-stripped libdir textrel"
INSANE_SKIP:${PN}-dbg += "libdir"
INSANE_SKIP:${PN} += "staticdev"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

#PACKAGES =+ "${PN}-dbg ${PN}-staticdev ${PN}"

#FILES:${PN} += "${datadir}"
#FILES:${PN} += ""

FILES:${PN} += " \
	${datadir}/dotnet \
	/usr/local/share/dotnet \
	"

do_install:prepend () {
	install -d ${D}${bindir}
	install -d ${D}${datadir}/dotnet/
	install -m 0755 ${S}/dotnet ${D}${datadir}/dotnet/
	install -m 0644 ${S}/LICENSE.txt ${D}${datadir}/dotnet/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${datadir}/dotnet/

	install -d ${D}${datadir}/dotnet/host/fxr/${PV}/
	install -m 0755 ${S}/host/fxr/${PV}/libhostfxr.so ${D}${datadir}/dotnet/host/fxr/${PV}/

	install -d ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}/
	
	install -m 0644 ${S}/shared/Microsoft.AspNetCore.App/${PV}/.version ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}/.version
	for file in ${S}/shared/Microsoft.AspNetCore.App/${PV}/*.dll; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}/
	done
	for file in ${S}/shared/Microsoft.AspNetCore.App/${PV}/*.json; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}/
	done
	for file in ${S}/shared/Microsoft.AspNetCore.App/${PV}/*.txt; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}/
	done

	install -d ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	
	install -m 0644 ${S}/shared/Microsoft.NETCore.App/${PV}/.version ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/.version
	install -m 0644 ${S}/shared/Microsoft.NETCore.App/${PV}/createdump ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/createdump
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}/*.so; do
		install -m 0755 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}/*.dll; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}/*.json; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}/*.md; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}/*.a; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/
	done

	install -d ${D}/usr/local/share

}

do_install:append() {
	cd ${D}/usr/local/share
	ln -s ../../share/dotnet ${D}/usr/local/share

	cd ${D}${bindir}
	ln -s ../share/dotnet/dotnet ${D}${bindir}/dotnet
}


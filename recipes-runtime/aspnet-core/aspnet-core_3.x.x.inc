###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft
# pertaining to all 3.x.x versions.
# Copyright Richard Dunkley 2019
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://github.com/aspnet/AspNetCore/issues"
SECTION = "runtime"

S = "${WORKDIR}/aspnet-${PV}"

require recipes-runtime/aspnet-core/aspnet-core_mit.inc

DEPENDS = "zlib"
RDEPENDS_${PN} = "aspnet-core-staticdev icu lttng-tools lttng-ust zlib curl libgssglue"

INSANE_SKIP_${PN} += "already-stripped libdir textrel"
INSANE_SKIP_${PN}-dbg += "libdir"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

#PACKAGES =+ "${PN}-dbg ${PN}-staticdev ${PN}"

#FILES_${PN} += "${datadir}"
#FILES_${PN} += ""

FILES_${PN} += " \
	${datadir}/dotnet \
	/usr/local/share/dotnet \
	"

FILES_${PN}-staticdev += " \
	${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/*.a \
	"

do_install_prepend () {
	install -d ${D}${bindir}
	install -d ${D}${datadir}/dotnet/
	install -m 0755 ${S}/dotnet ${D}${datadir}/dotnet/
	install -m 0644 ${S}/LICENSE.txt ${D}${datadir}/dotnet/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${datadir}/dotnet/

	install -d ${D}${datadir}/dotnet/host/fxr/${PV}-preview8-28405-07/
	install -m 0755 ${S}/host/fxr/${PV}-preview8-28405-07/libhostfxr.so ${D}${datadir}/dotnet/host/fxr/${PV}-preview8-28405-07/

	install -d ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}-preview8.19405.7/
	
	install -m 0644 ${S}/shared/Microsoft.AspNetCore.App/${PV}-preview8.19405.7/.version ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}-preview8.19405.7/.version
	for file in ${S}/shared/Microsoft.AspNetCore.App/${PV}-preview8.19405.7/*.dll; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}-preview8.19405.7/
	done
	for file in ${S}/shared/Microsoft.AspNetCore.App/${PV}-preview8.19405.7/*.json; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.AspNetCore.App/${PV}-preview8.19405.7/
	done

	install -d ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/
	
	install -m 0644 ${S}/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/.version ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/.version
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/*.so; do
		install -m 0755 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/*.dll; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/*.json; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/*.md; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/*.a; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-preview8-28405-07/
	done

	install -d ${D}/usr/local/share

}

do_install_append() {
	cd ${D}/usr/local/share
	ln -s ../../share/dotnet ${D}/usr/local/share

	cd ${D}${bindir}
	ln -s ../share/dotnet/dotnet ${D}${bindir}/dotnet
}


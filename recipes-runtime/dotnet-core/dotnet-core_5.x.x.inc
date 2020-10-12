###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft
# pertaining to all 5.x.x versions.
# Copyright Richard Dunkley 2019
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://github.com/dotnet/core/issues"
SECTION = "runtime"

S = "${WORKDIR}/dotnet-${PV}"

require recipes-runtime/dotnet-core/dotnet-core_mit_5.x.x.inc

DEPENDS = "zlib"
RDEPENDS_${PN} = "icu lttng-tools lttng-ust zlib libgssglue krb5"

INSANE_SKIP_${PN} += "already-stripped libdir textrel"
INSANE_SKIP_${PN}-dbg += "libdir"
INSANE_SKIP_${PN} += "staticdev"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

#PACKAGES =+ "${PN}-dbg ${PN}-staticdev ${PN}"

#FILES_${PN} += "${datadir}"
#FILES_${PN} += ""

FILES_${PN} += " \
	${datadir}/dotnet \
	/usr/local/share/dotnet \
	"

do_install_prepend () {
	install -d ${D}${bindir}
	install -d ${D}${datadir}/dotnet/
	install -m 0755 ${S}/dotnet ${D}${datadir}/dotnet/
	install -m 0644 ${S}/LICENSE.txt ${D}${datadir}/dotnet/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${datadir}/dotnet/

	install -d ${D}${datadir}/dotnet/host/fxr/${PV}-rc.1.20451.14/
	install -m 0755 ${S}/host/fxr/${PV}-rc.1.20451.14/libhostfxr.so ${D}${datadir}/dotnet/host/fxr/${PV}-rc.1.20451.14/

	install -d ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/
	
	install -m 0644 ${S}/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/.version ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/.version
	install -m 0644 ${S}/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/createdump ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/createdump
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/*.so; do
		install -m 0755 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/*.dll; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/*.json; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/
	done
	for file in ${S}/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/*.a; do
		install -m 0644 "$file" ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}-rc.1.20451.14/
	done

	install -d ${D}/usr/local/share

}

do_install_append() {
	cd ${D}/usr/local/share
	ln -s ../../share/dotnet ${D}/usr/local/share

	cd ${D}${bindir}
	ln -s ../share/dotnet/dotnet ${D}${bindir}/dotnet
}


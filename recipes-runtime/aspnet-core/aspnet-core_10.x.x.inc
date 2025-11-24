###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft
# pertaining to all 10.x.x versions.
# Copyright Sequent Logic 2025
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://github.com/aspnet/AspNetCore/issues"
SECTION = "runtime"

S = "${WORKDIR}/aspnet-${PV}"

require recipes-runtime/aspnet-core/aspnet-core_mit_10.x.x.inc

# FIXME: patchelf-native must be removed if hack in do_install:append not required
DEPENDS = "zlib patchelf-native"
RDEPENDS:${PN} = "zlib icu libssl krb5"

INSANE_SKIP:${PN} += "already-stripped libdir textrel"
INSANE_SKIP:${PN}-dbg += "libdir"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

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
    	[ -e "$file" ] || continue
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

	install -d ${D}/usr/local/share

}

do_install:append() {
	cd ${D}/usr/local/share
	ln -s ../../share/dotnet ${D}/usr/local/share

	cd ${D}${bindir}
	ln -s ../share/dotnet/dotnet ${D}${bindir}/dotnet

	# FIXME: must be removed if the liblttng-ust library issue was fixed
	# Hack to fix liblttng-ust dependency issues
	patchelf --remove-needed liblttng-ust.so.0 ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/${PV}/libcoreclrtraceptprovider.so
}


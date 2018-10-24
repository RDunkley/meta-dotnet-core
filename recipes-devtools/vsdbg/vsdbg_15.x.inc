###################################################################################################
# Contains additional parameters for the recipe to download the Visual Studio Remote debugger for
# all 15.x versions.
# Copyright Richard Dunkley 2018
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://visualstudio.microsoft.com/"
SECTION = "runtime"

S = "${WORKDIR}/vsdbg-${PV}"

require recipes-devtools/vsdbg/vsdbg_license.inc

DEPENDS = "zlib"
RDEPENDS_${PN} = "openssh openssh-sftp-server lttng-ust zlib curl libgssglue"

INSANE_SKIP_${PN} += "already-stripped libdir textrel"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

PACKAGES = "${PN}-dbg ${PN}"

FILES_${PN} += "${ROOT_HOME}"
FILES_${PN} += ""


do_install_prepend () {
	install -d ${D}${ROOT_HOME}/vsdbg/
	install -m 0755 ${S}/vsdbg ${D}${ROOT_HOME}/vsdbg/
	install -m 0644 ${S}/license.txt ${D}${ROOT_HOME}/vsdbg/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${ROOT_HOME}/vsdbg/
	install -m 0644 ${S}/version.txt ${D}${ROOT_HOME}/vsdbg/

	install -d ${D}${ROOT_HOME}/vsdbg/1033/
	for file in ${S}/1033/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/vsdbg/1033/
	done

	for file in ${S}/*.so; do
		install -m 0755 "$file" ${D}${ROOT_HOME}/vsdbg/
	done
	for file in ${S}/{*.dll,*.vsdconfig}; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/vsdbg/
	done
}


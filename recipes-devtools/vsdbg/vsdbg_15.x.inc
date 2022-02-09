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
RDEPENDS:${PN} = "openssh openssh-sftp-server icu lttng-tools lttng-ust zlib curl libgssglue"

INSANE_SKIP:${PN} += "already-stripped libdir textrel"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

PACKAGES = "${PN}-dbg ${PN}"

FILES:${PN} += "${ROOT_HOME}"
FILES:${PN} += ""


do_install:prepend () {
	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/
	install -m 0755 ${S}/vsdbg ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/
	install -m 0644 ${S}/license.txt ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/
	install -m 0644 ${S}/version.txt ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/1033/
	for file in ${S}/1033/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/1033/
	done

	for file in ${S}/*.so; do
		install -m 0755 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/
	done
	for file in ${S}/{*.dll,*.vsdconfig}; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/
	done
	echo "15.7.20425.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2017u5/success.txt
}


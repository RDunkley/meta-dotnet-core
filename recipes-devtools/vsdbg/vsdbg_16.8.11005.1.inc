###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-16-8-11005-1/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "5b0338ca7e6660f42ad9ab542f90265a"
SRC_URI[script.sha256sum] = "1b44a5c098bc4be77e29296ca4131c63e622edfce5704e5e8f50796732eae94c"

RDEPENDS:${PN} += " procps"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_16.8.11005.1_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "16.8.11005.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success.txt
	echo "16.8.11005.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_version.txt
	echo "linux-${DOTNET_RUNTIME_ARCH}" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_rid.txt
	cd ${D}${ROOT_HOME}/.vs-debugger
	ln -sf vs2019 vs2017u5
}

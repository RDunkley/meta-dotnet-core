###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-16-8-11013-1/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "c3dc91b68b46eff71f96415e64a85796"
SRC_URI[script.sha256sum] = "696a77c895dc888f4e0a8515c5121cf36dee8ee6726ba460b9745f55a787103f"

RDEPENDS:${PN} += " procps"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_16.8.11013.1_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "16.8.11013.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success.txt
	echo "16.8.11013.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_version.txt
	echo "linux-${DOTNET_RUNTIME_ARCH}" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_rid.txt
	cd ${D}${ROOT_HOME}/.vs-debugger
	ln -sf vs2019 vs2017u5
}

###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-16-3-10904-1/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "461264c0870d7a460dd28afef07cb622"
SRC_URI[script.sha256sum] = "7374a28ff55b85f7e70066655dcf00575be3e3d778299e1353d9f8714a5543e7"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_16.3.10904.1_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "16.3.10904.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success.txt
	echo "16.3.10904.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_version.txt
	echo "linux-${DOTNET_RUNTIME_ARCH}" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_rid.txt
	cd ${D}${ROOT_HOME}/.vs-debugger
	ln -sf vs2019 vs2017u5
}

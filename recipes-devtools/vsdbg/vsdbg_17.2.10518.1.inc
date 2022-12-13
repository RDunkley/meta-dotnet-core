###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-2-10518-1/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "76ffe243ffb06b6b1a8a7f8c7bf31776"
SRC_URI[script.sha256sum] = "2608424ae05550a24ac9b767a997635de1e87fe551156536d03356da421f4c64"

RDEPENDS:${PN} += " procps"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.2.10518.1_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "17.2.10518.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

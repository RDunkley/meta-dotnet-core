###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2024
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-10-20209-7/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "fe78292eb1ae3ca93306b77ea07138b8"
SRC_URI[script.sha256sum] = "827b0f965072c06afcc2bb7cf50af35952951b0475a0cd1ee83f927de39b2fc7"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.10.20209.7_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.10.20209.7" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

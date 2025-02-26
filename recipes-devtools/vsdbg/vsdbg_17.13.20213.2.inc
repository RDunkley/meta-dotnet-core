###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2025
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-13-20213-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "1888ecca52b3a02e85b4bd5c641df460"
SRC_URI[script.sha256sum] = "f24331fefe2fed6c75279a78baad535fc3c4ca56e3eeb0f1c6b5ebb95649815c"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.13.20213.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.13.20213.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

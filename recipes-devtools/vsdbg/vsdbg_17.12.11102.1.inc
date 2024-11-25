###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2024
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-12-11102-1/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "295288ad1118c0430e36e94e495237b5"
SRC_URI[script.sha256sum] = "5a80185e81c40aa3e4ef4925eacd131acff5c0e94fe86b422dc656ae76adb05b"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.12.11102.1_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.12.11102.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

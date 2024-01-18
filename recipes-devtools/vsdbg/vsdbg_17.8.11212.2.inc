###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2024
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-8-11212-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "0b4f980fd20b68e83c34b0bf7d2f5815"
SRC_URI[script.sha256sum] = "20e3f9d1847726f8456f1462849f093922ddd20adf9f0d9afd2ccb80aa3126f6"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.8.11212.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.8.11212.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

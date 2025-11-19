###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Sequent Logic 2025
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-18-0-10821-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "83b5b39f5400d5e7b9b2ef47a8ae10a1"
SRC_URI[script.sha256sum] = "176e9ac5add16834198e2287d11d475b4f4382470c0eeb01a1cc1093b04f9520"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_18.0.10821.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "18.0.10821.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

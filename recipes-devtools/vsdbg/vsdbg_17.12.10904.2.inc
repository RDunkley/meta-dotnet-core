###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright cjzzz 2024
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-12-10904-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "68684d4df7479d43d63d98c75f17edd0"
SRC_URI[script.sha256sum] = "8ec3cb1ec8f8a3429047af2dad99ac113db8c53f938015a65ed867565b89063c"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.12.10904.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.12.10904.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

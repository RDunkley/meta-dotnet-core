###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2023
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-7-10808-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "5215ca7a5616b53a68c93296cc3cca49"
SRC_URI[script.sha256sum] = "3d879720773935b23d9e081d14a93a0ca2f3e4d663270d27be91dc2c15d15f37"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.7.10808.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.7.10808.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

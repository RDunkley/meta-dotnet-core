###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2024
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-11-10506-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "1e249dbd01daef9bea8704b1110c6ccd"
SRC_URI[script.sha256sum] = "99c1bcf942f5f601553a37b7242dd66e307f950101bf86ef6e3de670d24e5158"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.11.10506.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.11.10506.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

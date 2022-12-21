###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-4-11209-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "d3623325200f454b9fd480924f0d0a25"
SRC_URI[script.sha256sum] = "20bf3c84fb1bc8ab4ff17b8f9781682f8bdc1c78b3390843c75bab8f47540fd1"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.4.11209.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "17.4.11209.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

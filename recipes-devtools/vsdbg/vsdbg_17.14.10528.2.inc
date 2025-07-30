###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright cjzzz 2025
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-14-10528-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "38b9b436fc5e9d69e62c0b80fddc6594"
SRC_URI[script.sha256sum] = "97200a58afb1209fbd2ff6baefdbdb4661dc1fd83acdb669bbfd44bb70395f59"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.14.10528.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.14.10528.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-16-2-10709-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "338a3dfa8e454bc16f032a848d0d157e"
SRC_URI[script.sha256sum] = "45c10c66cbeea057246641e74879eff0b4d70e97478cafc5be11e9cfdea7a657"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_16.2.10709.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "16.2.10709.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success.txt
	echo "16.2.10709.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_version.txt
	echo "linux-${DOTNET_RUNTIME_ARCH}" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_rid.txt
	cd ${D}${ROOT_HOME}/.vs-debugger
	ln -sf vs2019 vs2017u5
}

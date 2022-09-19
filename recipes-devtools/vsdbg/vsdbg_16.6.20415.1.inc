###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-16-6-20415-1/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "4fc5ffaa936e80938f47ffb95a5182a1"
SRC_URI[script.sha256sum] = "97aba6bdf0b2afffb69626d75b4d88db4eb8d181dce929d802fc2849c9d9f3ed"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_16.6.20415.1_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "16.6.20415.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success.txt
	echo "16.6.20415.1" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_version.txt
	echo "linux-${DOTNET_RUNTIME_ARCH}" > ${D}${ROOT_HOME}/.vs-debugger/vs2019/success_rid.txt
	cd ${D}${ROOT_HOME}/.vs-debugger
	ln -sf vs2019 vs2017u5
}

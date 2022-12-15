###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

SRC_URI += "https://vsdebugger.blob.core.windows.net/vsdbg-17-0-10712-2/GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "bbaa16a2d2cc1073d996346b5b9c8062"
SRC_URI[script.sha256sum] = "7feecbfc02b7b19dc25be03bcfd079048747e69c52a993c6cb8b70cc1ef756e4"

RDEPENDS:${PN} += " procps"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.0.10712.2_${DOTNET_RUNTIME_ARCH}.inc

do_install:append () {
	echo "17.0.10712.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
	echo "17.0.10712.2" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success_version.txt
	echo "linux-${DOTNET_RUNTIME_ARCH}" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success_rid.txt
	cd ${D}${ROOT_HOME}/.vs-debugger
}

###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2026
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

# Unversioned URL: the checksums change when Microsoft updates the script. Re-run meta_dotnet_core_gen to update them.
SRC_URI += "https://aka.ms/getvsdbgsh;downloadfilename=GetVsDbg.sh;name=script"
SRC_URI[script.md5sum] = "ee6947cd78dc7eadd7d5668a963a4839"
SRC_URI[script.sha256sum] = "a20d6294a53695bddad3a3fd578e1ce8d8b15e76eda09959a2e723ac9959caef"

RDEPENDS:${PN} += "procps openssh-sftp-server"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_17.12.11216.3_${DOTNET_RUNTIME_ARCH}.inc

do_install:append() {
	echo "17.12.11216.3" > ${D}${ROOT_HOME}/.vs-debugger/vs2022/success.txt
}

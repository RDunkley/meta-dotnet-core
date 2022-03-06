###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2018
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's Visual Studio Remote Debugger for Linux"
HOMEPAGE = "https://visualstudio.microsoft.com/"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-devtools/vsdbg/vsdbg_15.7.20426.1_${DOTNET_RUNTIME_ARCH}.inc

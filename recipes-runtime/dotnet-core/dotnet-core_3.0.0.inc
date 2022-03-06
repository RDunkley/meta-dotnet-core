###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's .NET Core 3.0.0"
HOMEPAGE = "https://dotnet.microsoft.com/download/dotnet-core/3.0"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-runtime/dotnet-core/dotnet-core_3.0.0_${DOTNET_RUNTIME_ARCH}.inc

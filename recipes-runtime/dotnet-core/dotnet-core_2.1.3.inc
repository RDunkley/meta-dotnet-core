###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2018
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's .NET Core 2.1.3"
HOMEPAGE = "https://www.microsoft.com/net/download/dotnet-core/2.1"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like Yocto likes ${PV} used in require statements.
require recipes-runtime/dotnet-core/dotnet-core_2.1.3_${DOTNET_RUNTIME_ARCH}.inc

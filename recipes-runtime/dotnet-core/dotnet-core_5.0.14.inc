###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Richard Dunkley 2022
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's .NET Core 5.0.14"
HOMEPAGE = "https://dotnet.microsoft.com/download/dotnet-core/5.0"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH_arm = "arm"
DOTNET_RUNTIME_ARCH_x86-64 = "x64"
DOTNET_RUNTIME_ARCH_x86_64 = "x64"
DOTNET_RUNTIME_ARCH_aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-runtime/dotnet-core/dotnet-core_5.0.14_${DOTNET_RUNTIME_ARCH}.inc

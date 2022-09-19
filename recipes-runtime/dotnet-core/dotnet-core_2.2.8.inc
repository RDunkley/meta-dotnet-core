###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Matthijs de Ridder 2019
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's .NET Core 2.2.8"
HOMEPAGE = "https://dotnet.microsoft.com/download/dotnet-core/2.2"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-runtime/dotnet-core/dotnet-core_2.2.8_${DOTNET_RUNTIME_ARCH}.inc

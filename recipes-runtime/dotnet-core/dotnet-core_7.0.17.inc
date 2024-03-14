###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright cjzzz 2024
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's .NET 7.0.17"
HOMEPAGE = "https://dotnet.microsoft.com/download/dotnet/7.0"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86-64 = "x64"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-runtime/dotnet-core/dotnet-core_7.0.17_${DOTNET_RUNTIME_ARCH}.inc


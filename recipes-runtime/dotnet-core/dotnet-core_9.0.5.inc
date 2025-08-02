###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright cjzzz 2025
# Auto-generated using meta_dotnet_core_gen
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's .NET 9.0.5"
HOMEPAGE = "https://dotnet.microsoft.com/download/dotnet/9.0"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86-64 = "x64"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-runtime/dotnet-core/dotnet-core_9.0.5_${DOTNET_RUNTIME_ARCH}.inc


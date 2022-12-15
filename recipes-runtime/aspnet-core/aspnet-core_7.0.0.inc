###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's ASP .NET 7.0.0"
HOMEPAGE = "https://dotnet.microsoft.com/download/dotnet/7.0"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH_arm = "arm"
DOTNET_RUNTIME_ARCH_x86-64 = "x64"
DOTNET_RUNTIME_ARCH_x86_64 = "x64"
DOTNET_RUNTIME_ARCH_aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-runtime/aspnet-core/aspnet-core_7.0.0_${DOTNET_RUNTIME_ARCH}.inc

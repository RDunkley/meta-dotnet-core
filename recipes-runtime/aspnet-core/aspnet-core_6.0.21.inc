###################################################################################################
# Contains additional parameters for the recipe to download the release binaries from Microsoft.
# Copyright Sequent Logic 2023
###################################################################################################
SUMMARY = "Contains the binaries for Microsoft's ASP .NET 6.0.21"
HOMEPAGE = "https://dotnet.microsoft.com/download/dotnet/6.0"

DOTNET_RUNTIME_ARCH = "none"
DOTNET_RUNTIME_ARCH:arm = "arm"
DOTNET_RUNTIME_ARCH:x86-64 = "x64"
DOTNET_RUNTIME_ARCH:x86_64 = "x64"
DOTNET_RUNTIME_ARCH:aarch64 = "arm64"

# This is here because it doesn't seem like bitbake likes ${PV} used in require statements.
require recipes-runtime/aspnet-core/aspnet-core_6.0.21_${DOTNET_RUNTIME_ARCH}.inc

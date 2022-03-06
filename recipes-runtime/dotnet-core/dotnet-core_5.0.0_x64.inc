###################################################################################################
# Contains the URL and checksums to download version 5.0.0 of the x86 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/c84d49aa-200c-4400-a517-87cce5b7516d/94c89b00380eb212e19538b05f8cb968/dotnet-runtime-5.0.0-linux-x64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "ed770c4649cadd9326ca916e7c40f617"
SRC_URI[sha256sum] = "8d1b27cc293cc706a6852508405b803a50c8898a0f1e901ded16baa88d2d463f"

###################################################################################################
# Contains the URL and checksums to download version 6.0.0 of the x86 64-bit .Net runtime
# from Microsoft.
# Copyright Richard Dunkley 2021
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/0ce1c34f-0d9e-4d9b-964e-da676c8e605a/7a6c353b36477fa84f85b2821f2350c2/dotnet-runtime-6.0.0-linux-x64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "861fe027a38dd37410169ad552731230"
SRC_URI[sha256sum] = "1a4076139944f3b16d9a0fc4841190cf060a9d93ebc13330821a2e97f6d4db91"

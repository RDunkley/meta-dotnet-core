###################################################################################################
# Contains the URL and checksums to download version 6.0.2 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2022
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/1b952787-51c7-4708-b20b-a1f59423f1a2/65151b3e18d451fa1303606e402c17fe/dotnet-runtime-6.0.2-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "03a2ba404e2488455dfbc8befed5c386"
SRC_URI[sha256sum] = "2e56447c002ba8dd1bf3e8bdf91a8a1eb71312c72b3ecc6e8ce8f6de6e9bdb02"


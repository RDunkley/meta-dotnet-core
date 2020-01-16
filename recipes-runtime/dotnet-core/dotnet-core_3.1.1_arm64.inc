###################################################################################################
# Contains the URL and checksums to download version 3.1.1 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Matthijs de Ridder 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/38325910-0157-4f3a-b093-da799dcaa24b/d4892d3a53a6d917fbab4037624181a9/dotnet-runtime-3.1.1-linux-arm64.tar.gz;subdir=aspnet-${PV}"

SRC_URI[md5sum] = "31eb37cb2c612ba021214b3d5d460a94"
SRC_URI[sha256sum] = "77806d5a01bf4e25e5a9fed063f117d80d38d2f4a8c46313e51f451c7a8db3b2"


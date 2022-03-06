###################################################################################################
# Contains the URL and checksums to download version 3.1.8 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/aa592fad-b5ef-428e-89b4-7a38cdabb787/1f97cb89b880e222fad432ffefe4a36c/dotnet-runtime-3.1.8-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "2be981d8b55dcff8ca33767fceca76a8"
SRC_URI[sha256sum] = "977c77b1293f8e75ba7218a8f0c35a6a90c147ab099dcebdaed212b73f9047f4"


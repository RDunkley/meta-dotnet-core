###################################################################################################
# Contains the URL and checksums to download version 2.2.8 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Matthijs de Ridder 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/f5e04830-50fc-435c-8bb5-fcd4629da944/8aa7cce5c3fcb6a7db180b923d3574ef/dotnet-runtime-2.2.8-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "e058bd6a66f3e1be61db7ad5f4c0e8cc"
SRC_URI[sha256sum] = "006cb080f1f96f996e0cd33f07d68f9b88ad3b50fa0eb190e2be0e761aed3a72"

###################################################################################################
# Contains the URL and checksums to download version 3.1.0 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Matthijs de Ridder 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/6f19b1ba-8a5e-42ff-abb5-a49f837aa183/a6e01cdf317b967da67eace7565a5b2e/dotnet-runtime-3.1.0-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "a76adf3c77a84b27f4dbabe62439cc7a"
SRC_URI[sha256sum] = "1173166fd51a4d513d2c054dd916b752091afb4f427707a1f352618492ceb5ac"

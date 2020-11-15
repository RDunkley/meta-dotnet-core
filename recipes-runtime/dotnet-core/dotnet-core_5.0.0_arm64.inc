###################################################################################################
# Contains the URL and checksums to download version 5.0.0 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/4b114207-eaa2-40fe-8524-bd3c56b2fd9a/1d74fdea8701948c0150c39645455b2f/dotnet-runtime-5.0.0-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "8f244ecdca537d7f4b6db3e08f11ed99"
SRC_URI[sha256sum] = "14f79a0f1ad6c310482fe30783e6ba4f3a7db29a4195d10bf7df9f246f9aebdf"


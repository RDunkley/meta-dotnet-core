###################################################################################################
# Contains the URL and checksums to download version 6.0.0 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2021
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/e59e190b-fceb-481e-9d82-f1e0660a0a72/3961d79c2fe1e8a2ee8ff3b1bb5e8472/dotnet-runtime-6.0.0-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "c4c590b8606851e72a44c7d8475eac77"
SRC_URI[sha256sum] = "b04393f981ccb4face34d9e86731df4e1ee97106a5571d0c4cc0932c944718a6"


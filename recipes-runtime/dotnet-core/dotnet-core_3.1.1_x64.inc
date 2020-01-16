###################################################################################################
# Contains the URL and checksums to download version 3.1.1 of the x86 64-bit .Net Core runtime
# from Microsoft.
# Copyright Matthijs de Ridder 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/e060c2eb-1476-4d70-857c-24f5eead2070/ff0e007b7373c04f754b3818ffdb2134/dotnet-runtime-3.1.1-linux-x64.tar.gz;subdir=aspnet-${PV}"

SRC_URI[md5sum] = "20e7148e6d858c03f5dc6e302e7650d9"
SRC_URI[sha256sum] = "e049ceeeb912e873534fb0871b3b147deae59dc315236c69731a168d6639adae"
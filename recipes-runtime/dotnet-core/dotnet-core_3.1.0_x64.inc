###################################################################################################
# Contains the URL and checksums to download version 3.1.0 of the x86 64-bit .Net Core runtime
# from Microsoft.
# Copyright Matthijs de Ridder 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/5d139dff-4ca0-4e0c-a68b-0976281d5b2d/d306f725466e058842faa25bf1b2f379/dotnet-runtime-3.1.0-linux-x64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "f6116923409dcf433dde03cef2868eb0"
SRC_URI[sha256sum] = "3fd138add3787c5edf6446245b821dbe0b4acae032c2b9a4cc2b8eac2d9b9997"

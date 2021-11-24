###################################################################################################
# Contains the URL and checksums to download version 5.0.12 of the x86 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2021
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/781b7ae6-166c-4114-97f8-926d2bf74d34/fe51479e3138d672c512ef0322be23d3/dotnet-runtime-5.0.12-linux-x64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "0a19e2ea80ac531aa85709bc01d567ee"
SRC_URI[sha256sum] = "8f9e311fc15dfef7bc5fb489cd05e566d58a4452d7fa14400c13966dd21fd8b0"

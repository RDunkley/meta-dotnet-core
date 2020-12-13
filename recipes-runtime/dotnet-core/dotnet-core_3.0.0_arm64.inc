###################################################################################################
# Contains the URL and checksums to download version 3.0.0 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/707fd000-c376-40de-9862-cabc46a344ec/82e0a3c816247bad4563c3e74655f7cf/dotnet-runtime-3.0.0-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "5eaea4ac0e30ce40b6daea23a5b1ef7e"
SRC_URI[sha256sum] = "5fc3449ecaa8bfd0cd968ab656b278cc435fb2245b9cb838238ae42eccb96880"


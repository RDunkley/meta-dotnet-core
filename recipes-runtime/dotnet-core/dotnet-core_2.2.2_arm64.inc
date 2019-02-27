###################################################################################################
# Contains the URL and checksums to download version 2.2.2 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/4f960c44-ae38-4510-95e9-0b686fcae16f/be50a7c893543038522f5943d920db01/dotnet-runtime-2.2.2-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "4fd3d938a686c27da596887cad782a39"
SRC_URI[sha256sum] = "caf486689e31ece1d386d13b5b5bcc01db30c2e6dd0eb2148c854ac2555fe0c7"


###################################################################################################
# Contains the URL and checksums to download version 16.3.10904.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-16-3-10904-1/vsdbg-linux-arm64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "2e7c49c345a1524d3a25e944359d255c"
SRC_URI[source.sha256sum] = "2d9e7a621aa8eaa4ed17c0d85b3d8b5c9684d3070e4eecbae02cb3545bdeeb00"


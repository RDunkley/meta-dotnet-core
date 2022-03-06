###################################################################################################
# Contains the URL and checksums to download version 17.0.10712.2 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-17-0-10712-2/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "a6d00b871e5649d8f722c69814225e45"
SRC_URI[source.sha256sum] = "dc31bba242615c2b160c6038e74b740568f23db3d3d0103aaf3a88cb35c48da8"


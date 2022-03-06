###################################################################################################
# Contains the URL and checksums to download version 17.0.10712.2 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-17-0-10712-2/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "b7459ef8c6744cfb72d14a6ddac41f1d"
SRC_URI[source.sha256sum] = "44545a24e2630d96f337d017380a91e3ade1ff3fa5f8a954ffb4b91481756796"


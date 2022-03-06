###################################################################################################
# Contains the URL and checksums to download version 16.6.20415.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-16-6-20415-1/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "e132a8ec5ba9b5d5618653970bc3705f"
SRC_URI[source.sha256sum] = "75e206e29f8dbafb29cf52ee40c83534c436f607a4ee247a1734466b05e6ee91"


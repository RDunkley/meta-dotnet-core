###################################################################################################
# Contains the URL and checksums to download version 16.3.10904.1 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-16-3-10904-1/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "cc2fce5546e1b044cb65a18d6cec7f8c"
SRC_URI[source.sha256sum] = "f3d71b167adad9a5c3f41e62a4f3af8c201977c3fda12180cdaf40af874e8533"


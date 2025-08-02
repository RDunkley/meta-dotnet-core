###################################################################################################
# Contains the URL and checksums to download version 16.8.11013.1 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-16-8-11013-1/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "4631945941002d46cf76f7cd5d8347af"
SRC_URI[source.sha256sum] = "bc13945dd27f17de5bfaf1bc530fae7e3b05479853ee71597a46bda7706a10a4"


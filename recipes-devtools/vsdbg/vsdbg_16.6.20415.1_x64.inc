###################################################################################################
# Contains the URL and checksums to download version 16.6.20415.1 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-16-6-20415-1/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "5a21a41f5d835414699a58891aa483b5"
SRC_URI[source.sha256sum] = "b520978bc4ff77d55cba94694a59a14027866bfceeaf715e99030ad6b02d6b66"


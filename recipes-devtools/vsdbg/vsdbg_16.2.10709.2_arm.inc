###################################################################################################
# Contains the URL and checksums to download version 16.2.10709.2 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-16-2-10709-2/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "8e2497708884ba7efb2baf1423981a81"
SRC_URI[source.sha256sum] = "67c3f3f4fcb1aa66c673f472de3f799269acac30cab48df66618f3dd58542f99"


###################################################################################################
# Contains the URL and checksums to download version 16.2.10709.2 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-16-2-10709-2/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "ec95b4e673253661de89b9da526d49bc"
SRC_URI[source.sha256sum] = "c78a82b235f7a6c24363e3efbf75aff9e5c454d0791e2117e54f40dc8f82a322"


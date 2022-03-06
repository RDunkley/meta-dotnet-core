###################################################################################################
# Contains the URL and checksums to download version 17.0.10712.2 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-17-0-10712-2/vsdbg-linux-arm64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "2e72fa52bf4ac6c35fb9a029fe5f42cc"
SRC_URI[source.sha256sum] = "20a5f809b5e7dbe7c11b4d3fefac5b51c62866b1211b2ee7672b606ebe9cc87e"


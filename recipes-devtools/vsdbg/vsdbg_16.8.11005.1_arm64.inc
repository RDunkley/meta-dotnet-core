###################################################################################################
# Contains the URL and checksums to download version 16.8.11005.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-16-8-11005-1/vsdbg-linux-arm64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "f06a823821e161317151ed018eb38889"
SRC_URI[source.sha256sum] = "06a2667497fa6602942e9ddb076ccceacc05baaeca326f7d0db346fbcec44e9b"


###################################################################################################
# Contains the URL and checksums to download version 16.8.11005.1 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-16-8-11005-1/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "b4dbd2a4174d724d134f386f68e2abfc"
SRC_URI[source.sha256sum] = "3540a9a0cbf2ff8ed74a31f4babbd71d47f44fc72b000aae140efc890d1f7257"


###################################################################################################
# Contains the URL and checksums to download version 17.4.11209.2 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-17-4-11209-2/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "1698184a89feac4358f35f33eceb463d"
SRC_URI[source.sha256sum] = "c895976f230635f55f1fc47dc26473647fff07ec70d67c1ba41910c3b17e040b"


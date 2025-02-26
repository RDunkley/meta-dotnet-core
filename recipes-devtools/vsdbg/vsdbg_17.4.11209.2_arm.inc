###################################################################################################
# Contains the URL and checksums to download version 17.4.11209.2 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-17-4-11209-2/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "ef9f7cdabf3cee822971a3eb5844e521"
SRC_URI[source.sha256sum] = "1175850146dc87f5a7e538c112e7f53bed1756f80f6c3830e80cabca5076de90"


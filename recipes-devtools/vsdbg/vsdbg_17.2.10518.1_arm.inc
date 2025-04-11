###################################################################################################
# Contains the URL and checksums to download version 17.2.10518.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-17-2-10518-1/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "9e3eab533fec87bfb44d0bad4367082d"
SRC_URI[source.sha256sum] = "ea42939a03883b0bec0ba92072a0a72ca6ca6134a445e8afe1f123a55b32b967"


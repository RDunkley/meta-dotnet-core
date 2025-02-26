###################################################################################################
# Contains the URL and checksums to download version 16.6.20415.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-16-6-20415-1/vsdbg-linux-arm64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "171ce77ccd743a45f4b87542db9949c2"
SRC_URI[source.sha256sum] = "fdc3c923a6a8411fb2efe895185602c8f4e947b5188ed22cce62a2e75019776c"


###################################################################################################
# Contains the URL and checksums to download version 16.8.11005.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-16-8-11005-1/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "f1d6aeb39c5f31df4aa745d30c269d3a"
SRC_URI[source.sha256sum] = "38defa138e0b272c964693c572554f93a501471358a234946788fa0ed6719411"


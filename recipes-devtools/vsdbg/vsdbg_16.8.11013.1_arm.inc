###################################################################################################
# Contains the URL and checksums to download version 16.8.11013.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-16-8-11013-1/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "28fc2de77461298762cc057ccab96b64"
SRC_URI[source.sha256sum] = "b0a2daed3ce16867d400047da631acd9370fc182eea002682f2ed37aab089b6d"


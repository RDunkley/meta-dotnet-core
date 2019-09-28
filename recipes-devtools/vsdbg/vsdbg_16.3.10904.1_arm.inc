###################################################################################################
# Contains the URL and checksums to download version 16.3.10904.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2019
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-16-3-10904-1/vsdbg-linux-arm.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "0e1063a309f836783e0fb8185f7a8e3a"
SRC_URI[source.sha256sum] = "2efc3b21b78af294a2ed611434703902a074a90977003ba086a4203fbf44a3d0"


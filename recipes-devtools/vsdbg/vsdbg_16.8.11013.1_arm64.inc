###################################################################################################
# Contains the URL and checksums to download version 16.8.11013.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Richard Dunkley 2020
###################################################################################################
SRC_URI += "https://vsdebugger-cyg0dxb6czfafzaz.b01.azurefd.net/vsdbg-16-8-11013-1/vsdbg-linux-arm64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "9ce366a6a12216f758daea4b4d37d78f"
SRC_URI[source.sha256sum] = "373f72d383f573e8920373e1296312f3e23e0a863f12390dbea209e3da363f62"


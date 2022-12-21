###################################################################################################
# Contains the URL and checksums to download version 17.4.11209.2 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-17-4-11209-2/vsdbg-linux-arm64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "c4898a4b79c70931de443268d03d7f8b"
SRC_URI[source.sha256sum] = "eed6c0d33ade8d385ce2424f12f95dfd114b65c710daae52e94ecf516d65db8a"


###################################################################################################
# Contains the URL and checksums to download version 17.2.10518.1 of the ARM Visual Studio
# debugger from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-17-2-10518-1/vsdbg-linux-arm64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "3ac8735338b18d6f4f66c4b3f5846d26"
SRC_URI[source.sha256sum] = "84dbdf48e5c906cdfc89284870b5c20d45bd56b1071baebb6e36eb13ee34356b"


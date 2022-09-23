###################################################################################################
# Contains the URL and checksums to download version 17.2.10518.1 of the 64-bit Visual Studio
# debugger from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SRC_URI += "https://vsdebugger.azureedge.net/vsdbg-17-2-10518-1/vsdbg-linux-x64.zip;subdir=vsdbg-${PV};name=source"

SRC_URI[source.md5sum] = "538c54e6effac1a9f7bb92824c26cbd0"
SRC_URI[source.sha256sum] = "eda05514bb72b30abf0478343bba787e912770fc6f7fc397ba619c9a50cc4b74"


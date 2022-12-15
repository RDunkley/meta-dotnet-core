###################################################################################################
# Contains the URL and checksums to download version 7.0 of the ARM 64-bit .Net Core runtime
# from Microsoft.
# Copyright Sequent Logic 2022
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/edc62d2f-5c2e-4085-a6d8-11ba9abb18f4/6ca82f155ed65e4c1335214d2d948c78/dotnet-runtime-7.0.0-linux-arm64.tar.gz;subdir=dotnet-${PV}"

SRC_URI[md5sum] = "72a16cdd120ff388879ca5e4fdd81804"
SRC_URI[sha256sum] = "f23e32f764f54a08cc721aff4ec4885ee805cd2a8757570cd9a418ecc87ff79b"


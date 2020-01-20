###################################################################################################
# Contains the URL and checksums to download version 3.1.1 of the ARM .Net Core runtime from
# Microsoft.
# Copyright Matthijs de Ridder 2019
###################################################################################################
SRC_URI = "https://download.visualstudio.microsoft.com/download/pr/98931269-612c-47cd-a5a1-f1d8e616c950/1ba015724bba919eccbf159dbda0a483/dotnet-runtime-3.1.1-linux-arm.tar.gz;subdir=aspnet-${PV}"

SRC_URI[md5sum] = "cf8ea5ae94386ca85101ff90358ece65"
SRC_URI[sha256sum] = "eb8286756b2d7813afdd1923e0c4de76cd2d10604c91bd2075d974bf37bf1aee"

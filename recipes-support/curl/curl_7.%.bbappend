###################################################################################################
# This modifies the recipe for curl to make it compatible with the binaries built by Microsoft
# for .Net Core and the Visual Studio remote debugger. The modification enables versioned symbols
# (CURL_OPENSSL_4). It also patches the library so it outputs a version 4 library with 
# CURL_OPENSSL_3 as the versioned symbol. 
#
# From what I can gather, the problem stems from a version of Ubuntu with a messed up curl library
# (version 4 but contains version 3 symbols). That library was used to build the Microsoft
# binaries from and now has a weird dependency. See .Net Core issue 1367
# (https://github.com/dotnet/core/issues/1367). jamespettigrew was the one who came up with the
# solution. 
#
# Note: this leaves the CURL_OPENSSL_4 intact so this shouldn't cause issues with other
# applications looking for version 4.
#
# Copyright Richard Dunkley 2019
###################################################################################################

FILESEXTRAPATHS:prepend := "${THISDIR}/curl:"

SRC_URI += "file://libcurl_vers_in.patch"


PACKAGECONFIG:append = " vers"
PACKAGECONFIG[vers] = "--enable-versioned-symbols, --disable-versioned-symbols,"

#PACKAGECONFIG ??= "${@bb.utils.contains("DISTRO_FEATURES", "ipv6", "
#PACKAGECONFIG:append:pn-curl = " ssl"

#PACKAGECONFIG:append:class-target = " ssl"
#PACKAGECONFIG ??= "${@bb.utils.filter('DISTRO_FEATURES', 'ipv6', d)} gnutls proxy threaded-resolver zlib ssl"

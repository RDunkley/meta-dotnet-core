###################################################################################################
# Contains the recipe to download the release binaries from Microsoft for the version
# 6.0.0 ASP .Net runtime.
# Copyright Richard Dunkley 2021
###################################################################################################

require recipes-runtime/aspnet-core/aspnet-core_6.0.0.inc
require recipes-runtime/aspnet-core/aspnet-core_6.x.x.inc

DEPENDS = "patchelf-native"

do_install:append(){
    # Hack to fix liblttng-ust dependency issues
    patchelf --remove-needed liblttng-ust.so.0 ${D}${datadir}/dotnet/shared/Microsoft.NETCore.App/6.0.0/libcoreclrtraceptprovider.so
}

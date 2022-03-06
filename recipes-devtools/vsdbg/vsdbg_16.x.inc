###################################################################################################
# Contains additional parameters for the recipe to download the Visual Studio Remote debugger for
# all 16.x versions.
# Copyright Richard Dunkley 2019
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://visualstudio.microsoft.com/"
SECTION = "runtime"

S = "${WORKDIR}/vsdbg-${PV}"

require recipes-devtools/vsdbg/vsdbg_license.inc

DEPENDS = "zlib"
RDEPENDS:${PN} = "openssh openssh-sftp-server icu lttng-tools lttng-ust zlib curl libcurl libgssglue libgssapi-krb5"

INSANE_SKIP:${PN} += "already-stripped libdir textrel"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

PACKAGES = "${PN}-dbg ${PN}"

FILES:${PN} += "${ROOT_HOME}"
FILES:${PN} += ""


do_install:prepend () {
	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	install -m 0755 ${S}/vsdbg ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	install -m 0644 ${S}/license.txt ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	install -m 0644 ${S}/version.txt ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	install -m 0755 ${WORKDIR}/GetVsDbg.sh ${D}${ROOT_HOME}/.vs-debugger/

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1028/
	for file in ${S}/1028/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1028/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1029/
	for file in ${S}/1029/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1029/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1031/
	for file in ${S}/1031/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1031/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1033/
	for file in ${S}/1033/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1033/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1036/
	for file in ${S}/1036/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1036/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1040/
	for file in ${S}/1040/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1040/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1041/
	for file in ${S}/1041/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1041/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1042/
	for file in ${S}/1042/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1042/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1045/
	for file in ${S}/1045/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1045/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1046/
	for file in ${S}/1046/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1046/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1049/
	for file in ${S}/1049/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1049/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/1055/
	for file in ${S}/1055/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/1055/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/2052/
	for file in ${S}/2052/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/2052/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/3082/
	for file in ${S}/3082/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/3082/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/cs/
	for file in ${S}/cs/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/cs/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/de/
	for file in ${S}/de/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/de/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/es/
	for file in ${S}/es/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/es/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/fr/
	for file in ${S}/fr/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/fr/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/it/
	for file in ${S}/it/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/it/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/ja/
	for file in ${S}/ja/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/ja/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/ko/
	for file in ${S}/ko/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/ko/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/pl/
	for file in ${S}/pl/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/pl/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/pt-BR/
	for file in ${S}/pt-BR/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/pt-BR/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/ru/
	for file in ${S}/ru/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/ru/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/tr/
	for file in ${S}/tr/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/tr/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/zh-Hans/
	for file in ${S}/zh-Hans/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/zh-Hans/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2019/zh-Hant/
	for file in ${S}/zh-Hant/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/zh-Hant/
	done

	for file in ${S}/*.so; do
		install -m 0755 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	done
	for file in ${S}/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	done
	for file in ${S}/*.vsdconfig; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2019/
	done
}


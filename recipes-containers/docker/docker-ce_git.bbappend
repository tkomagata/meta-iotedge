FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}/:"

SRC_URI_append = " file://daemon.json"

do_install_append () {
     install -Dm 644 ${WORKDIR}/daemon.json ${D}${sysconfdir}/docker/daemon.json
}

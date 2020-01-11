export VERSION = "1.0.8"

IOTEDGE_DEVICE_CONNECTION_STRING ?= "<ADD DEVICE CONNECTION STRING HERE>"

do_install_append () {
    # Config file
    ## Manual provisioning configuration
    sed -i -e "s/<ADD DEVICE CONNECTION STRING HERE>/${IOTEDGE_DEVICE_CONNECTION_STRING}/g" \
        ${D}${sysconfdir}/iotedge/config.yaml
}

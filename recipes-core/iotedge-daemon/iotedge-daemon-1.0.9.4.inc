export VERSION = "1.0.9.4"

IOTEDGE_DEVICE_CONNECTION_STRING ?= "<ADD DEVICE CONNECTION STRING HERE>"

do_compile_append () {
    # Certificates
    export FORCE_NO_PROD_WARNING="true"

    mkdir -p ${S}/certs_work
    cp ${WORKDIR}/iotedge-${PV}/tools/CACertificates/*.cnf ${S}/certs_work/
    cp ${WORKDIR}/iotedge-${PV}/tools/CACertificates/certGen.sh ${S}/certs_work

    cd ${S}/certs_work
    bash ./certGen.sh create_root_and_intermediate
    bash ./certGen.sh create_edge_device_certificate ${MACHINE}
}

do_install_append () {
    # Config file
    ## Manual provisioning configuration
    sed -i -e "s/<ADD DEVICE CONNECTION STRING HERE>/${IOTEDGE_DEVICE_CONNECTION_STRING}/g" \
        ${D}${sysconfdir}/iotedge/config.yaml

    ## Edge device hostname
    sed -i -e "s/<ADD HOSTNAME HERE>/${MACHINE}/g" \
        ${D}${sysconfdir}/iotedge/config.yaml

    # Certificates
    install -d -o iotedge -g iotedge ${D}/${localstatedir}/lib/iotedge/hsm/certs/
    install -d -o iotedge -g iotedge ${D}/${localstatedir}/lib/iotedge/hsm/cert_keys/
    install -m 400 -o iotedge -g iotedge \
        ${S}/certs_work/certs/iot-edge-device-${MACHINE}-full-chain.cert.pem \
        ${D}/${localstatedir}/lib/iotedge/hsm/certs/
    install -m 400 -o iotedge -g iotedge \
        ${S}/certs_work/private/iot-edge-device-${MACHINE}.key.pem \
        ${D}/${localstatedir}/lib/iotedge/hsm/cert_keys/
    install -m 400 -o iotedge -g iotedge \
        ${S}/certs_work/certs/azure-iot-test-only.root.ca.cert.pem \
        ${D}/${localstatedir}/lib/iotedge/hsm/certs/

    sed -i -e "s/\# certificates/certificates/g" \
        ${D}${sysconfdir}/iotedge/config.yaml
    sed -i -e "s/#   device_ca_cert/  device_ca_cert/g" \
        ${D}${sysconfdir}/iotedge/config.yaml
    sed -i -e "s/#   device_ca_pk/  device_ca_pk/g" \
        ${D}${sysconfdir}/iotedge/config.yaml
    sed -i -e "s/#   trusted_ca_certs/  trusted_ca_certs/g" \
        ${D}${sysconfdir}/iotedge/config.yaml

    sed -i -e "s/<ADD URI TO DEVICE CA CERTIFICATE HERE>/file:\/\/\${localstatedir}\/lib\/iotedge\/hsm\/certs\/iot-edge-device-${MACHINE}-full-chain.cert.pem/g" \
        ${D}${sysconfdir}/iotedge/config.yaml
    sed -i -e "s/<ADD URI TO DEVICE CA PRIVATE KEY HERE>/file:\/\/\${localstatedir}\/lib\/iotedge\/hsm\/cert_keys\/iot-edge-device-${MACHINE}.key.pem/g" \
        ${D}${sysconfdir}/iotedge/config.yaml
    sed -i -e "s/<ADD URI TO TRUSTED CA CERTIFICATES HERE>/file:\/\/\${localstatedir}\/lib\/iotedge\/hsm\/certs\/azure-iot-test-only.root.ca.cert.pem/g" \
        ${D}${sysconfdir}/iotedge/config.yaml

    # Systemd
    if ${@bb.utils.contains('DISTRO_FEATURES', 'systemd', 'true', 'false', d)}; then
        sed -i -e "s/User=iotedge/User=root/g" ${D}${systemd_unitdir}/system/iotedge.service
        sed -i -e "s/Group=iotedge/Group=root/g" ${D}${systemd_unitdir}/system/iotedge.service
    fi
}

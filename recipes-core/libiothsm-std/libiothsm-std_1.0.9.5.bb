DESCRIPTION = "Standard mode libiothsm implementation for Azure IoT Edge"
LICENSE = "MIT"

LIC_FILES_CHKSUM=" \
file://LICENSE;md5=b98fddd052bb2f5ddbcdbd417ffb26a8 \
"

SRC_URI += "gitsm://github.com/Azure/iotedge;protocol=https;nobranch=1;branch=release/1.0.9"
SRCREV = "c602ee699e3004dc50fe4c2a4ae30765079b4855"
S = "${WORKDIR}/git/edgelet/hsm-sys/azure-iot-hsm-c"

DEPENDS += "openssl"
PROVIDES += "virtual/libiothsm"
RPROVIDES_${PN} += "virtual/libiothsm"

EXTRA_OECMAKE += "-DBUILD_SHARED=On -Duse_emulator=Off -Duse_http=Off -Duse_default_uuid=On -DCMAKE_SYSTEM_VERSION=10"
inherit cmake


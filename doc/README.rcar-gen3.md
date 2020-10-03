# meta-docker/meta-rcar-gen3

This layer provides the configuration to use Docker Engine on the R-Car.

## Dependencies

This layer depends on:

* URI: git://git.yoctoproject.org/poky
  * branch: thud
  * revision: e7f0177ef3b6e06b8bc1722fca0241fef08a1530

* URI: git://github.com/renesas-rcar/meta-renesas
  * layers; meta-rcar-gen3
  * branch: thud-dev
  * revision: 21d840bc10492ea2f0f45f01df526cbfdb7735cf

* URI: git://git.openembedded.org/meta-openembedded
  * layers: meta-oe, meta-networking, meta-python, meta-filesystems
  * branch: thud
  * revision: 4cd3a39f22a2712bfa8fc657d09fe2c7765a4005

* URI: git://git.linaro.org/openembedded/meta-linaro
  * layers; meta-optee
  * branch: thud
  * revision: 0a94decea3bd2504590d1637eadff9d502c19ee2

* URI: git://git.yoctoproject.org/meta-virtualization
  * branch: thud
  * revision: 7685c7d415e0002c448007960837ae8898cd57a5

* URI: git://github.com/tkomagata/meta-docker
  * branch: thud
  * revision: 72b89595a50133695f011cabfcec27bc9652abb9

* URI: git://github.com/meta-rust/meta-rust.git
  * branch: master
  * revision: d8d77be1292064a02adcb5e72e293604b704f69b

## Patches

Please submit any patches against to the the maintainer:

Maintainer: Tomohiro Komagata <tomohiro.komagata.aj at gmail.com>

## Quick Start

1. TEMPLATECONF=$PWD/meta-iotedge/conf/machine/{h3ulcb or m3ulcb}/bsp/ \
   source poky/oe-init-build-env rcar-build
2. bitbake core-image-minimal
3. Prepare a SD card and set the u-boot environment variables. Please refer the [R-Car page on eLinux Wiki](https://elinux.org/R-Car/Boards/Yocto-Gen3/v3.21.0#Running_Yocto_images).
4. Boot your R-Car Starter Kit.

### Options for IoT Edge

Uncomment and set the environment variable if necessary.

```
# Set Tinezone (Optional)
#DEFAULT_TIMEZONE ="UTC"

# Set the connection String (Optional, NOT USE for production)
#IOTEDGE_DEVICE_CONNECTION_STRING = ""

# Set options to generate certificates (Optional, NOT USE for production)
#  https://aka.ms/iotedge-prod-checklist-certs
#  https://github.com/Azure/iotedge/tree/master/tools/CACertificates
#DEFAULT_VALIDITY_DAYS = "30"
#ROOT_CA_PASSWORD = "1234"
#INTERMEDIATE_CA_PASSWORD = "1234"
#FORCE_NO_PROD_WARNING = "true"
```

## Supported Boards/Machines

- Renesas Electronics Corporation. R-Car Starter Kit premier(H3ULCB) (R8A7795)
- Renesas Electronics Corporation. R-Car Starter Kit pro(M3ULCB) (R8A7796)

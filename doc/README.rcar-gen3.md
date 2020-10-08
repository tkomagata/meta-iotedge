# meta-docker/meta-rcar-gen3

This layer provides the configuration to use Docker Engine on the R-Car.

## Dependencies

This layer depends on:

* URI: git://git.yoctoproject.org/poky
  * branch: dunfell
  * revision: 569b1f5d67c57de957e243997c53ec2f81dc8dfe

* URI: git://github.com/renesas-rcar/meta-renesas
  * layers; meta-rcar-gen3
  * branch: dunfell-dev
  * revision: 072c0f8648a3e19ff145508d8d431308363a699c

* URI: git://git.openembedded.org/meta-openembedded
  * layers: meta-oe, meta-networking, meta-python, meta-filesystems
  * branch: dunfell
  * revision: 654ad8bea49f142d20b2b96c0dd44810a6be233a

* URI: git://git.yoctoproject.org/meta-virtualization
  * branch: dunfell
  * revision: ff997b6b3ba800978546098ab3cdaa113b6695e1

* URI: git://github.com/tkomagata/meta-docker
  * branch: dunfell
  * revision: 8b169e57ec16b1ab8a03304b603be090bc7ea47a

* URI: git://github.com/meta-rust/meta-rust.git
  * branch: master
  * revision: e4d25b98083bcecb94df6ee189a165d63ede7f3d

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

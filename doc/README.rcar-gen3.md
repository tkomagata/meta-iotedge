# meta-docker/meta-rcar-gen3

This layer provides the configuration to use Docker Engine on the R-Car.

## Dependencies

This layer depends on:

* URI: git://git.yoctoproject.org/poky
  * branch: dunfell
  * revision: 5d47cdf448b6cff5bb7cc5b0ba0426b8235ec478

* URI: git://github.com/renesas-rcar/meta-renesas
  * layers; meta-rcar-gen3
  * branch: dunfell-dev
  * revision: 6c12c043f93966ec704d3a19765fbe200d42715d

* URI: git://git.openembedded.org/meta-openembedded
  * layers: meta-oe, meta-networking, meta-python, meta-filesystems
  * branch: dunfell
  * revision: b5f510e48080b6dc710ff4800feb90ef679c5456

* URI: git://git.yoctoproject.org/meta-virtualization
  * branch: dunfell
  * revision: ffd787fb850e5a1657a01febc8402c74832147a1

* URI: git://github.com/tkomagata/meta-docker
  * branch: dunfell
  * revision: 22c0d58b185686f8569d3607b1be3121f2b26eed

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

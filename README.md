# "Das U-Boot" for MediaTek MT65xx
Currently supported SoCs: `MT6572` and `MT6580`
## Supported devices
### MT6572
Lenovo A369i: U-Boot replaces the kernel;\
JTY D101: U-Boot replaces the LK(?).
### MT6580
Prestigio Multipad Wize 3151 (MT8321): U-Boot replaces the LK.

## Status
**Y** = works;\
**P** = partially works;\
**N** = doesn't work.

### MT6572
* Booting - **Y**;
* UART - **Y**;
* Display - **Y** (simple-framebuffer);
* Internal storage / eMMC - **N**;
* External storage / SD card - **N**;
* Buttons - **N**;
* USB - **N**;

### MT6580
* Booting - **Y**;
* UART - **Y**;
* Display - **N**;
* Internal storage / eMMC - **Y**;
* External storage / SD card - **Y**;
* Buttons - **N**;
* USB - **N**;

## Building
### Lenovo A369i (MT6572)
```
./build_mt6572.sh
```

### JTY D101 (MT6572)
```
ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- make O=out d101_defconfig
ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- make O=out -j$(nproc --all)
```

### MT6580
```
ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- make O=out mt6580_defconfig
ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- make O=out -j$(nproc --all)
```

## Flashing
### MT6572
```
mtk w bootimg u-boot-mt6572.img
```

### MT6580
```
mtk w lk out/u-boot-mtk.bin
```
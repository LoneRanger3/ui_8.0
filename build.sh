
#!/bin/bash
mkdir bin

# R818交叉编译工具
# SDK_PATH="/opt/cxsw_sdk/r818"
# TARGET_CC=${SDK_PATH}/gcc/linux-x86/aarch64/toolchain-sunxi-glibc/toolchain/bin/aarch64-openwrt-linux-gnu-gcc-6.4.1
# TARGET_CXX=${SDK_PATH}/gcc/linux-x86/aarch64/toolchain-sunxi-glibc/toolchain/bin/aarch64-openwrt-linux-gnu-g++
# TARGET_STRIP=${SDK_PATH}/gcc/linux-x86/aarch64/toolchain-sunxi-glibc/toolchain/bin/aarch64-openwrt-linux-gnu-strip
# TARGET_CFLAGS="-I${SDK_PATH}/dl/include/"
# TARGET_LDFLAGS="-L${SDK_PATH}/dl/lib/"
# TARGET_SYSTEM="Tina"
# TARGET_SERIAL_PORT="/dev/ttyUSB0"
# TARGET_USER_DATA_PATH="/mnt/UDISK"
# TARGET_U_DISK_PATH="/mnt/exUDISK"
# R818交叉编译工具

# F1C200S交叉编译工具
# SDK_PATH="/opt/cxsw_sdk/f1c200s"
# TARGET_CC=${SDK_PATH}/gcc/linux-x86/arm/toolchain-sunxi-arm9-musl/toolchain/bin/arm-openwrt-linux-muslgnueabi-gcc
# TARGET_CXX=${SDK_PATH}/gcc/linux-x86/arm/toolchain-sunxi-arm9-musl/toolchain/bin/arm-openwrt-linux-muslgnueabi-g++
# TARGET_STRIP=${SDK_PATH}/gcc/linux-x86/arm/toolchain-sunxi-arm9-musl/toolchain/bin/arm-openwrt-linux-muslgnueabi-strip
# TARGET_CFLAGS="-I${SDK_PATH}/dl/include/"
# TARGET_LDFLAGS="-L${SDK_PATH}/dl/lib/"
# TARGET_SYSTEM="Tina"
# TARGET_SERIAL_PORT="/dev/ttyS1"
# TARGET_USER_DATA_PATH="/mnt/UDISK"
# TARGET_U_DISK_PATH="/mnt/exUDISK"
# F1C200S交叉编译工具

# X2000交叉编译工具
CROSS_COMPILE_TOOL="/opt/cxsw_sdk/x2000/gcc/mips-gcc720-glibc229/bin/mips-linux-gnu-"
FS_STAGING_DIR="/opt/cxsw_sdk/x2000/sysroot"
TARGET_CC=${CROSS_COMPILE_TOOL}gcc
TARGET_CXX=${CROSS_COMPILE_TOOL}g++
TARGET_AR=${CROSS_COMPILE_TOOL}ar
TARGET_STRIP=${CROSS_COMPILE_TOOL}strip
TARGET_CFLAGS="--sysroot=${FS_STAGING_DIR} -I${FS_STAGING_DIR}/usr/include/ -I${FS_STAGING_DIR}/include/"
TARGET_CXXFLAGS="--sysroot=${FS_STAGING_DIR} -I${FS_STAGING_DIR}/usr/include/ -I${FS_STAGING_DIR}/include/"
TARGET_LDFLAGS="--sysroot=${FS_STAGING_DIR} -L${FS_STAGING_DIR}/usr/lib/ -L${FS_STAGING_DIR}/lib/"
TARGET_SYSTEM="Ingenic"
TARGET_SERIAL_PORT="/dev/conn_ttyS0"
TARGET_USER_DATA_PATH="/usr/data/"
TARGET_U_DISK_PATH="/tmp/udisk/"
TARGET_SD_CARD_PATH="/tmp/sdcard/mmcblk0p1/"
# X2000交叉编译工具

make -j8    \
CC="$TARGET_CC" \
CXX="$TARGET_CXX" \
AR="$TARGET_AR" \
STAGING_DIR="$FS_STAGING_DIR" \
CFLAGS="$TARGET_CFLAGS" \
CXXFLAGS="$TARGET_CXXFLAGS" \
LDFLAGS="$TARGET_LDFLAGS" \
SYSTEM_PLATFORM="$TARGET_SYSTEM" \
SERIAL_PORT="$TARGET_SERIAL_PORT" \
USER_DATA_PATH="$TARGET_USER_DATA_PATH" \
U_DISK_PATH="$TARGET_U_DISK_PATH" \
SD_CARD_PATH="$TARGET_SD_CARD_PATH" \
CROSS_COMPILE="yes"
DISPLAY_APP="lvgl8.0_knob" #lvgl8.0

${TARGET_STRIP} audio-server/audio-server
if [ $DISPLAY_APP == "lvgl8.0" ]; then
${TARGET_STRIP} display-server/lvgl8.0/display-server
else
${TARGET_STRIP} display-server/lvgl8.0_knob/display-server
fi
${TARGET_STRIP} master-server/master-server
${TARGET_STRIP} monitor/Monitor
${TARGET_STRIP} wifi-server/wifi-server
${TARGET_STRIP} app-server/app-server
${TARGET_STRIP} burn-server/burn-server
${TARGET_STRIP} upgrade-server/upgrade-server
${TARGET_STRIP} web-server/web-server


cp audio-server/audio-server bin/
if [ $DISPLAY_APP == "lvgl8.0" ]; then
cp display-server/lvgl8.0/display-server bin/
else
cp display-server/lvgl8.0_knob/display-server bin/
fi
cp master-server/master-server bin/
cp monitor/Monitor bin/
cp wifi-server/wifi-server bin/
cp app-server/app-server bin/
cp burn-server/burn-server bin/
cp upgrade-server/upgrade-server bin/
cp web-server/web-server bin/

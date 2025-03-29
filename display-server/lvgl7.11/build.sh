
#!/bin/bash

# R818交叉编译工具
# SDK_PATH="/opt/cxsw_sdk/r818"
# TARGET_CC=${SDK_PATH}/gcc/linux-x86/aarch64/toolchain-sunxi-glibc/toolchain/bin/aarch64-openwrt-linux-gnu-gcc-6.4.1
# TARGET_CXX=${SDK_PATH}/gcc/linux-x86/aarch64/toolchain-sunxi-glibc/toolchain/bin/aarch64-openwrt-linux-gnu-g++
# TARGET_STRIP=${SDK_PATH}/gcc/linux-x86/aarch64/toolchain-sunxi-glibc/toolchain/bin/aarch64-openwrt-linux-gnu-strip
# TARGET_CFLAGS="-I${SDK_PATH}/dl/include/"
# TARGET_LDFLAGS="-L${SDK_PATH}/dl/lib/"
# R818交叉编译工具

# F1C200S交叉编译工具
# SDK_PATH="/opt/cxsw_sdk/f1c200s"
# TARGET_CC=${SDK_PATH}/gcc/linux-x86/arm/toolchain-sunxi-arm9-musl/toolchain/bin/arm-openwrt-linux-muslgnueabi-gcc
# TARGET_CXX=${SDK_PATH}/gcc/linux-x86/arm/toolchain-sunxi-arm9-musl/toolchain/bin/arm-openwrt-linux-muslgnueabi-g++
# TARGET_STRIP=${SDK_PATH}/gcc/linux-x86/arm/toolchain-sunxi-arm9-musl/toolchain/bin/arm-openwrt-linux-muslgnueabi-strip
# TARGET_CFLAGS="-I${SDK_PATH}/dl/include/"
# TARGET_LDFLAGS="-L${SDK_PATH}/dl/lib/"
# F1C200S交叉编译工具

# X2000交叉编译工具
CROSS_COMPILE_TOOL="/opt/cxsw_sdk/x2000/gcc/mips-gcc720-glibc229/bin/mips-linux-gnu-"
FS_STAGING_DIR="/opt/cxsw_sdk/x2000/sysroot"
TARGET_CC=${CROSS_COMPILE_TOOL}gcc
TARGET_CXX=${CROSS_COMPILE_TOOL}g++
TARGET_STRIP=${CROSS_COMPILE_TOOL}strip
TARGET_CFLAGS="--sysroot=${FS_STAGING_DIR} -I${FS_STAGING_DIR}/usr/include/ -I${FS_STAGING_DIR}/include/"
TARGET_CXXFLAGS="--sysroot=${FS_STAGING_DIR} -I${FS_STAGING_DIR}/usr/include/ -I${FS_STAGING_DIR}/include/"
TARGET_LDFLAGS="--sysroot=${FS_STAGING_DIR} -L${FS_STAGING_DIR}/usr/lib/ -L${FS_STAGING_DIR}/lib/"
# X2000交叉编译工具

make -j8    \
CC="$TARGET_CC" \
CXX="$TARGET_CXX" \
CFLAGS="$TARGET_CFLAGS" \
CXXFLAGS="$TARGET_CXXFLAGS" \
LDFLAGS="$TARGET_LDFLAGS" \
CROSS_COMPILE="yes"

${TARGET_STRIP} display-server
cp display-server ../../bin/

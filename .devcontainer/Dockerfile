FROM debian:12.6-slim AS tool-builder
LABEL authors="Raymond Wilfong"

RUN apt-get update \
    && apt-get install -y \
    build-essential git autoconf libtool make pkg-config libusb-1.0-0 libusb-1.0-0-dev texinfo wget unzip

WORKDIR /tmp/STM8TOOLCHAIN
RUN wget https://sourceforge.net/projects/stm8-binutils-gdb/files/stm8-binutils-gdb-sources-2021-07-18.tar.gz/download -O - \
    | tar -xzf - \
    && cd stm8-binutils-gdb-sources \
    && ./patch_binutils.sh \
    && ./configure_binutils.sh \
    && cd binutils-2.30 \
    && make -j`grep processor /proc/cpuinfo | wc -l` \
    && make install \
    && cd ../../.. \
    && rm -rf ./STM8TOOLCHAIN

WORKDIR /tmp/OPENOCD
RUN git clone https://git.code.sf.net/p/openocd/code \
    && cd code \
    && ./bootstrap \
    && ./configure \
    && make -j`grep processor /proc/cpuinfo | wc -l` \
    && make install \
    && cd ../.. \
    && rm -rf ./OPENOCD

WORKDIR /tmp/STM8FLASH
RUN git clone https://github.com/vdudouyt/stm8flash.git \
    && cd stm8flash \
    && make -j`grep processor /proc/cpuinfo | wc -l` \
    && make install \
    && cd ../.. \
    && rm -rf ./STM8FLASH

WORKDIR /tmp/STM8SPL
COPY MISC_INSTALL_FILES/STM/en.stsw-stm8069.zip .
RUN git clone https://github.com/gicking/STM8-SPL_SDCC_patch.git \
    && cd STM8-SPL_SDCC_patch \
    && unzip ../en.stsw-stm8069.zip \
    && chmod -R u+w STM8* \
    && patch -p0 < ./STM8S_StdPeriph_Lib_V2.3.1_sdcc.patch \
    && mv STM8S_StdPeriph_Lib /usr/local/share/. \
    && cd ../.. \
    && rm -rf ./STM8SPL



FROM debian:12.6-slim AS stm8-environment
LABEL authors="Raymond Wilfong"

COPY --from=tool-builder /usr/local/ /usr/local/

RUN apt-get update \
    && apt-get install -y \
    build-essential git make gcc clang gdb sdcc bash-completion libusb-1.0-0 usbutils
#    build-essential git autoconf libtool make pkg-config libusb-1.0-0 libusb-1.0-0-dev texinfo \
#    cmake gcc clang gdb usbutils wget bash-completion unzip sdcc

# MISC_INSTALL_FILES moving into place:
WORKDIR  /usr/local/share/openocd/scripts/board
COPY MISC_INSTALL_FILES/openocd/scripts/board/* .
WORKDIR  /usr/local/share/openocd/scripts/target
COPY MISC_INSTALL_FILES/openocd/scripts/target/* .
WORKDIR /root
COPY MISC_INSTALL_FILES/root/.bash_history .

WORKDIR /

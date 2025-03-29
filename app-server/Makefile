TARGET := app-server

ThirdPartyLibs := -lCrLog -lrt -ljson-c -lprotobuf-c -ljpeg -lpng
ThirdPartyLibs += -lpaho-mqtt3a -lpaho-mqtt3c -lcurl -lssl -lcrypto -lqrencode -lpng16
ThirdPartyLibs += -std=c++11 -fno-rtti -lalibabacloud-oss-cpp-sdk
ThirdPartyLibs += -lvod_sdk_static -loss_c_sdk_static -ljsoncpp -lmxml -luuid
ifeq ($(CROSS_COMPILE),yes)
ThirdPartyLibs += $(shell $(STAGING_DIR)/usr/bin/apr-1-config --link-ld --libs)
ThirdPartyLibs += $(shell $(STAGING_DIR)/usr/bin/apu-1-config --link-ld --libs)
else
ThirdPartyLibs += $(shell apr-1-config --link-ld --libs)
ThirdPartyLibs += $(shell apu-1-config --link-ld --libs)
endif
LIBS += $(ThirdPartyLibs) -lpthread

CFLAGS += -Wall
CXXFLAGS += -Wall
ifeq ($(CROSS_COMPILE),yes)
AprInclude = $(shell $(STAGING_DIR)/usr/bin/apr-1-config --includedir)
else
AprInclude = $(shell apr-1-config --includedir)
endif
INCLUDES += -I./../ -I./ -I$(AprInclude)

ifeq ($(CROSS_COMPILE),yes)
DEFINES := -DCROSS_COMPILE
endif

OUT       := out
DIRS      := $(shell find . -type d)
DIRS      := $(basename $(patsubst ./%, %, $(DIRS)))
C_SRCS    := $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
CXX_SRCS  := $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))

OUT_DIRS  := $(foreach src, $(C_SRCS), $(dir $(src)))
OUT_DIRS  += $(foreach src, $(CXX_SRCS), $(dir $(src)))
OUT_DIRS  := $(patsubst %, $(OUT)/%, $(OUT_DIRS))
OUT_DIRS  := $(sort $(OUT_DIRS))

OBJS      := $(patsubst %.c, $(OUT)/%.o, $(C_SRCS))
OBJS      += $(patsubst %.cpp, $(OUT)/%.o, $(CXX_SRCS))
-include $(OBJS:.o=.d)

OBJS += ../global/libglobal.a

$(OUT)/%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) $(DEFINES) -g -c -MMD -o $@ $<

$(OUT)/%.o: %.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) $(DEFINES) -g -c -MMD -o $@ $<

$(TARGET): $(OUT_DIRS) $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

$(OUT_DIRS):
	@mkdir -p $(OUT_DIRS)

all:$(TARGET)

clean:
	rm -rf $(TARGET) $(OUT)

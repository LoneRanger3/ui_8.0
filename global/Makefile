TARGET    := libglobal.a

CFLAGS += -Wall

INCLUDES += -I./

ifeq ($(CROSS_COMPILE),yes)
DEFINES := -DUSER_DATA_PATH=\"$(USER_DATA_PATH)\"
DEFINES += -DU_DISK_PATH=\"$(U_DISK_PATH)\"
DEFINES += -DSD_CARD_PATH=\"$(SD_CARD_PATH)\"
DEFINES += -DSYS_CONFIG=\"/etc/sysConfig\"
DEFINES += -DCROSS_COMPILE
else
DEFINES := -DUSER_DATA_PATH=\"$(shell echo ${HOME})\"
DEFINES += -DU_DISK_PATH=\"$(shell echo ${HOME})/Udisk\"
DEFINES += -DSD_CARD_PATH=\"$(shell echo ${HOME})/gcode_files\"
DEFINES += -DSYS_CONFIG=\"$(shell pwd)/sysConfig\"
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
$(OUT)/%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) $(DEFINES) -g -c -MMD $< -o $@

$(OUT)/%.o: %.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) $(DEFINES) -g -c -MMD $< -o $@

$(TARGET): $(OUT_DIRS) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(OUT_DIRS):
	@mkdir -p $(OUT_DIRS)

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(OUT)

#
# Makefile
# WARNING: relies on invocation setting current working directory to Makefile location
# This is done in .vscode/task.json
#
MAKEFLAGS 			:= -j $(shell nproc)
SRC_EXT      		:= c
OBJ_EXT				:= o
CC 					:= gcc

SRC_DIR				:= ./
WORKING_DIR			:= ./build
BUILD_DIR			:= $(WORKING_DIR)/obj
BIN_DIR				:= $(WORKING_DIR)/bin
UI_DIR 				:= ui

WARNINGS 			:= -Wall -Wextra \
						-Wshadow -Wundef -Wmaybe-uninitialized -Wmissing-prototypes -Wno-discarded-qualifiers \
						-Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith -fno-strict-aliasing -Wno-error=cpp -Wuninitialized \
						-Wno-unused-parameter -Wno-missing-field-initializers -Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default  \
					  	-Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic -Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated  \
						-Wempty-body \
            			-Wtype-limits -Wsizeof-pointer-memaccess -Wpointer-arith

CFLAGS 				:= -O0 -g $(WARNINGS)

# Add simulator define to allow modification of source
DEFINES				:= -D SIMULATOR=1 -D LV_BUILD_TEST=0

# Include simulator inc folder first so lv_conf.h from custom UI can be used instead
INC 				:= -I./ui/simulator/inc/ -I./ -I./lvgl/	\
					   -I./custom -I./generated -I./generated/guider_fonts	\
					   -I./../../ -I./
LIBS 			    += -lm 	\
					   -lprotobuf-c \
					   -ljson-c	\
					   -lCrLog	\
					   -lrt \
					   -lpthread -lssl -lcrypto -ljpeg -lpng
ifneq ($(CROSS_COMPILE),yes)
LIBS 			    += -lSDL2
endif

BIN 				:= $(BIN_DIR)/display-server

COMPILE				= $(CC) $(INC) $(CFLAGS) $(DEFINES)

# Automatically include all source files
SRCS 				:= $(shell find $(SRC_DIR) ! -path "./UserMain/*" ! -path "./lv_examples/*" ! -path "./lvgl/tests/*" ! -path "./lvgl/examples/*" -type f -name '*.c' -not -path '*/\.*')

ifeq ($(CROSS_COMPILE),yes)
SRCS                += ./UserMain/ARM_Main.c
$(info "CROSS_COMPILE = $(CROSS_COMPILE), override lv_drv_conf.h and lv_conf.h for arm")
$(shell cp lv_drv_conf_arm.h lv_drv_conf.h)
$(shell cp lv_conf_arm.h lv_conf.h)

else
SRCS                += ./UserMain/PC_Main.c \
					   ./UserMain/mouse_cursor_icon.c
endif

OBJECTS    			:= $(patsubst $(SRC_DIR)%,$(BUILD_DIR)/%,$(SRCS:.$(SRC_EXT)=.$(OBJ_EXT)))
OBJECTS             += ../../global/libglobal.a

all: default

$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@echo 'Building project file: $<'
	@mkdir -p $(dir $@)
	@$(COMPILE) -g -c -o "$@" "$<"

default: $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(BIN) $(OBJECTS) $(LDFLAGS) $(LIBS)
	@cp $(BIN) $(SRC_DIR)

clean:
	rm -rf $(WORKING_DIR)

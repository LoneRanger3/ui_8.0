TARGET := Monitor

LIBS += -lpthread -lCrLog -lrt -ljson-c -lssl -lcrypto -ljpeg -lpng

CFLAGS += -Wall

INCLUDES += -I./../ -I./

C_SRCS 	 := $(shell find $(./) -type f -name '*.c' -not -path '*/\.*')
CXX_SRCS := $(shell find $(./) -type f -name '*.cpp' -not -path '*/\.*')

OBJS := $(C_SRCS:.c=.o)
OBJS += $(CXX_SRCS:.cpp=.o)
-include $(OBJS:.o=.d)
OBJS += ../global/libglobal.a

%.o: %.c
	$(CC) $(INCLUDES) $(CFLAGS) -g -c -MMD -o $@ $<

$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

all:$(TARGET)

clean:
	$(RM) $(TARGET)
	$(RM) `find . -name '*.[od]' \! -name '.*' \! -type d -print`

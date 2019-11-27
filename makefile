BUILD_DIR=.
SRC_DIR=$(BUILD_DIR)/src
CC=g++
RM=rm
SRCS=cxxlin_test.cxx
OBJS=cxxlin_test.o
OUTPUT=cxxlin_test
DEFINE_FLAGS_DEBUG=-DDEBUG
DEFINE_FLAGS_RELEASE=-DRELEASE
CC_FLAGS=-c -std=c++14
CC_FLAGS_DEBUG=$(CC_FLAGS) -g $(DEFINE_FLAGS_DEBUG) -Wno-write-strings
CC_FLAGS_RELEASE=$(CC_FLAGS) $(DEFINE_FLAGS_RELEASE) -O3
CC_SRCS=$(addprefix $(SRC_DIR)/,$(SRCS))
LINKER_OPTIONS=`sdl2-config --cflags --libs` -lGL
CC_OBJS=$(addprefix $(BUILD_DIR)/,$(OBJS))
CC_OUT=-o $(OUTPUT)
CLEAN_OBJS=$(CC_OBJS)
CLEAN_OUT=$(addprefix $(BUILD_DIR)/,$(OUTPUT))

all: objs
	$(CC) $(CC_OBJS) $(CC_OUT) $(LINKER_OPTIONS) 

debug: debugobjs
	$(CC) $(CC_OBJS) $(CC_OUT) $(LINKER_OPTIONS)

debugobjs:
	$(CC) $(CC_FLAGS_DEBUG) $(CC_SRCS) $(LINKER_OPTIONS)

objs:
	$(CC) $(CC_FLAGS_RELEASE) $(CC_SRCS) $(LINKER_OPTIONS)

clean:
	-$(RM) $(CLEAN_OBJS)

cleanall: clean
	-$(RM) $(CLEAN_OUT)

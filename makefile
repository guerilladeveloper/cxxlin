BUILD_DIR=.
SRC_DIR=$(BUILD_DIR)/src
CC=g++
RM=rm
TEST_SRCS=cxxlin_test.cxx
LIB_SRCS=cxxlin_vec2f.cxx cxxlin_vec2fptr.cxx cxxlin_vec3f.cxx cxxlin_vec4f.cxx
TEST_OBJS=cxxlin_test.o
LIB_OBJS=cxxlin_vec2f.o cxxlin_vec2fptr.o cxxlin_vec3f.o cxxlin_vec4f.o
TEST_OUTPUT=cxxlin_test
LIB_OUTPUT=libcxxlin.so
DEFINE_FLAGS_DEBUG=-DDEBUG
DEFINE_FLAGS_RELEASE=-DRELEASE
CC_TEST_FLAGS=-c -std=c++14
CC_LIB_FLAGS=-c -std=c++14 -fpic
CC_TEST_FLAGS_DEBUG=$(CC_TEST_FLAGS) -g $(DEFINE_FLAGS_DEBUG) -Wno-write-strings
CC_TEST_FLAGS_RELEASE=$(CC_TEST_FLAGS) $(DEFINE_FLAGS_RELEASE) -O3
CC_TEST_SRCS=$(addprefix $(SRC_DIR)/,$(TEST_SRCS))
CC_LIB_SRCS=$(addprefix $(SRC_DIR)/,$(LIB_SRCS))
TEST_LINKER_OPTIONS=-L$(BUILD_DIR) -Wl,-rpath=$(BUILD_DIR) `sdl2-config --cflags --libs` -lGL -lcxxlin
CC_TEST_OBJS=$(addprefix $(BUILD_DIR)/,$(TEST_OBJS))
CC_LIB_OBJS=$(addprefix $(BUILD_DIR)/,$(LIB_OBJS))
CC_TEST_OUT=-o $(TEST_OUTPUT)
CC_LIB_OUT=-shared -o $(LIB_OUTPUT)
CLEAN_TEST_OBJS=$(CC_TEST_OBJS)
CLEAN_LIB_OBJS=$(CC_LIB_OBJS)
CLEAN_TEST_OUT=$(addprefix $(BUILD_DIR)/,$(TEST_OUTPUT))
CLEAN_LIB_OUT=$(addprefix $(BUILD_DIR)/,$(LIB_OUTPUT))

all: objs
	$(CC) $(CC_TEST_OBJS) $(CC_TEST_OUT) $(TEST_LINKER_OPTIONS) 

debug: debugobjs
	$(CC) $(CC_TEST_OBJS) $(CC_TEST_OUT) $(TEST_LINKER_OPTIONS)

debugobjs: lib
	$(CC) $(CC_TEST_FLAGS_DEBUG) $(CC_TEST_SRCS) $(TEST_LINKER_OPTIONS)

objs: lib
	$(CC) $(CC_TEST_FLAGS_RELEASE) $(CC_TEST_SRCS) $(TEST_LINKER_OPTIONS)

lib: libobjs
	$(CC) $(CC_LIB_OBJS) $(CC_LIB_OUT)

libobjs:
	$(CC) $(CC_LIB_FLAGS) $(CC_LIB_SRCS)

clean:
	-$(RM) $(CLEAN_TEST_OBJS) $(CLEAN_LIB_OBJS)

cleanall: clean
	-$(RM) $(CLEAN_TEST_OUT) $(CLEAN_LIB_OUT)

##########makefile#######

MAKEDATE = $(shell date +%Y%m%d%H%M%S)
MACRO = -DMAKEDATE=\"$(MAKEDATE)\"

# DEBUG can be set to YES to include debugging info, or NO otherwise
DEBUG          := YES


#define g++ arguments
CO   := g++ -g -c
CC   := gcc -g -c -fPIC
CXX  := g++ -g

AR     := ar -cru
LDFLAGS:= -shared -fPIC

DEBUG_CFLAGS     := -Wall -Wno-format -g -DDEBUG -fPIC -std=c++11
RELEASE_CFLAGS   := -Wall -Wno-unknown-pragmas -Wno-format -fPIC -O2 -std=c++11

DEBUG_CXXFLAGS   := ${DEBUG_CFLAGS}
RELEASE_CXXFLAGS := ${RELEASE_CFLAGS}

ifeq (YES, ${DEBUG})
   CFLAGS       := ${DEBUG_CFLAGS}
   CXXFLAGS     := ${DEBUG_CXXFLAGS}
   #LDFLAGS      := ${DEBUG_LDFLAGS}
else
   CFLAGS       := ${RELEASE_CFLAGS}
   CXXFLAGS     := ${RELEASE_CXXFLAGS}
   #LDFLAGS      := ${RELEASE_LDFLAGS}
endif

#define src obj bin path
vpath %.c $(shell find src/) 
vpath %.cpp $(shell find src/)
BIN_DIR = ./sbin
OBJ_DIR = ./objs
#install_dir = /usr/local/flv_access

TARGET := essential_client


INCS := -I./src/inc/
LIBS := -levent -lthrift

cppobjects := $(OBJ_DIR)/common_event.o \
$(OBJ_DIR)/app_context.o \
$(OBJ_DIR)/stage_handler.o \
$(OBJ_DIR)/service_types.o \
$(OBJ_DIR)/service_constants.o \
$(OBJ_DIR)/provider_types.o \
$(OBJ_DIR)/provider_constants.o \
$(OBJ_DIR)/login_types.o \
$(OBJ_DIR)/login_constants.o \
$(OBJ_DIR)/comsumer_types.o \
$(OBJ_DIR)/comsumer_constants.o \
$(OBJ_DIR)/common_types.o \
$(OBJ_DIR)/common_constants.o \
$(OBJ_DIR)/essential.o


#####objtest		
test_objs := $(OBJ_DIR)/test.o


objs := $(cppobjects) $(cobjects)

#all: $(TARGET) test
all : test
$(TARGET) : $(objs)
	$(CXX) ${CXXFLAGS} $(objs) -o $(BIN_DIR)/$(TARGET) $(LIBS)

test : $(objs) $(test_objs) dynamiclib staticlib
	$(CXX) ${CXXFLAGS} $(test_objs) -o $(BIN_DIR)/test ./lib/libessential.so $(LIBS)

staticlib: $(testobjs)
	${AR} ./lib/libessential.a $(objs)

dynamiclib: $(testobjs)
	$(CXX) ${LDFLAGS} -o ./lib/libessential.so $(objs)
	
# define a function which creates a target for c proj
define CREATE_TARGET_C
#echo "in C"
$1:$(addsuffix .c,$(basename $(notdir $1)))
	$(CC) ${CFLAGS} $$< -o $1
endef

# define a function which creates a target for cpp proj
define CREATE_TARGET_CPP
#echo "in CPP"
#srcfcpp:=$(srcdir)/$(addsuffix .cpp,$(basename $(notdir $1)))
$1:$(addsuffix .cpp,$(basename $(notdir $1)))
	$(CO) ${CXXFLAGS} ${INCS} $$< -o $1
endef


# create projects C targets
$(foreach obj, $(cobjects), $(eval $(call CREATE_TARGET_C,$(obj))))

# create projects CPP targets
$(foreach obj, $(cppobjects) $(test_objs), $(eval $(call CREATE_TARGET_CPP,$(obj))))

clean:
	rm -rf ${OBJ_DIR}/* ${BIN_DIR}/*

install:

.PHONY: install clean


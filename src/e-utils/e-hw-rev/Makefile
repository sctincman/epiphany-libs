#BUILD_ROOT  	= $(EPIPHANY_HOME)/../
BUILD_ROOT  	= ../../..

EXENAME			= e-hw-rev
EXTRACXXFLAGS  	= 
EXTRALINKFLAGS  = -fmessage-length=0

INCLUDES    = 
LIB_PATHS   = 
DBG_LIB_PATHS = 

LIBS        = 


C_SRCS      = \
	e-hw-rev.c

all: symlink_exe

.PHONY: symlink_exe
symlink_exe: 
	ln -sf Debug/$(EXENAME)



# REQUIRED - Include the X3C rules for building executable binaries
include $(BUILD_ROOT)/build_tools/make_exe.rules

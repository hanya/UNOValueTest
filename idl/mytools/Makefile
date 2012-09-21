
EXTENSION_VERSION=0.1.1
EXTENSION_STATE=
EXTENSION_ID=mytools.ValueTest
EXTENSION_NAME=ValueTest
EXTENSION_DISPLAY_NAME=Testing UNO values

PRJ=$(OO_SDK_HOME)
SETTINGS=$(PRJ)/settings

include $(SETTINGS)/settings.mk
include $(SETTINGS)/std.mk
include $(SETTINGS)/dk.mk

COMP_NAME=valuetest
COMP_IMPL_NAME=$(COMP_NAME).uno.$(SHAREDLIB_EXT)
RDB_NAME=ValueTest
RDB_FILE_NAME=$(RDB_NAME).rdb

ifeq "$(OS)" "WIN"
ORIGIN_NAME=%%origin%%
CC_FLAGS+= /O2 
else
ORIGIN_NAME=%origin%
CC_FLAGS=-c -O -fpic
COMP_LINK_FLAGS=$(LIBRARY_LINK_FLAGS) 
ifeq "$(SDKVERSION)" "3.4"
CC_FLAGS+= -fvisibility=hidden
else
COMP_LINK_FLAGS+= -Wl,--version-script,$(SETTINGS)/component.uno.map 
endif
endif

SRC=./src
OUT=.
IDL_LOC_DIR=./idl
EXT_DIR=./ext
BUILD_DIR=./build

OUT_COMP_INC=$(OUT_INC)/$(COMP_NAME)
OUT_COMP_GEN=$(OUT_MISC)/$(COMP_NAME)
OUT_COMP_SLO=$(OUT_SLO)/$(COMP_NAME)


CXXFILES = test.cpp test_service.cpp 

OBJFILES = $(patsubst %.cpp,$(OUT_SLO)/%.$(OBJ_EXT),$(CXXFILES))

MATH_PATH=mytools
IDL_FILES = ValueTest.idl XValueTest.idl Values.idl

IDL_FILES2 = $(patsubst %.idl,$(IDL_LOC_DIR)/$(MATH_PATH)/%.idl,$(IDL_FILES))
URD_FILES = $(patsubst %.idl,$(OUT_MISC)/%.urd,$(IDL_FILES))
TYPE_NAMES = $(patsubst %.idl,-Tmytools.%,$(IDL_FILES))

IDL_INC=../inc
IDL_LOC_INC=./inc
CC_INCLUDES=-I. -I$(IDL_INC) -I$(IDL_LOC_INC) -I$(PRJ)/include



MANIFEST=$(BUILD_DIR)/META-INF/manifest.xml
DESCRIPTION=$(BUILD_DIR)/description.xml
COMP_DIR=$(BUILD_DIR)/libs
COMP_REGISTRATION=$(COMP_DIR)/registration.components

ifneq "$(PLATFORM)" "windows"
TAEGET_PLATFORM=$(PLATFORM)_x86
else
ifneq "$(PLATFORM)" "linux"
ifneq "$(PROCTYPE)" "i386"
TAEGET_PLATFORM=$(PLATFORM)_x86
else
ifneq "$(PROCTYPE)" "x86_64"
TAEGET_PLATFORM=$(PLATFORM)_x86_64
endif
endif
endif
endif


UNO_PKG_NAME=$(EXTENSION_NAME)-$(EXTENSION_VERSION)$(EXTENSION_STATE)-$(subst _,-,$(TAEGET_PLATFORM)).$(UNOOXT_EXT)


.PHONY: ALL
ALL : \
	ValueTest

include $(SETTINGS)/stdtarget.mk

ValueTest : $(UNO_PKG_NAME)


$(UNO_PKG_NAME) : $(COMP_DIR)/$(COMP_IMPL_NAME) $(MANIFEST) $(DESCRIPTION) $(COMP_REGISTRATION) 
	$(COPY) README $(subst /,$(PS),$(BUILD_DIR)/README)
	$(COPY) LICENSE $(subst /,$(PS),$(BUILD_DIR)/LICENSE)
	#$(COPY) -r $(EXT_DIR)/* $(BUILD_DIR)
	cd $(BUILD_DIR) && $(SDK_ZIP) -9 -r -o ../$(UNO_PKG_NAME) META-INF/manifest.xml README LICENSE description.xml libs/*.$(SHAREDLIB_EXT) libs/*.components descriptions/* $(RDB_FILE_NAME) $(ADDINRDB_FILE_NAME)


$(OUT_SLO)/%.$(OBJ_EXT) : $(SRC)/%.cpp $(SDKTYPEFLAG)
	-$(MKDIR) $(subst /,$(PS),$(@D))
	$(CC) $(CC_OUTPUT_SWITCH)$(subst /,$(PS),$@) $(CC_FLAGS) $< $(CC_INCLUDES) $(CC_DEFINES) 

ifeq "$(OS)" "WIN"
$(COMP_DIR)/$(COMP_IMPL_NAME) : mtridl $(OBJFILES)
	-$(MKDIR) $(subst /,$(PS),$(COMP_DIR))
	$(LINK) $(COMP_LINK_FLAGS) /OUT:$(COMP_DIR)/$(COMP_IMPL_NAME) $(OBJFILES) $(LINK_LIBS) -lm $(CPPUHELPERLIB) $(CPPULIB) $(SALLIB) $(STC++LIB) $(CPPUHELPERDYLIB) $(CPPUDYLIB) $(SALDYLIB) $(STLPORTLIB) msvcrt.lib kernel32.lib
# $(LINK_MANIFEST)
else
#mtr : mtridl $(OBJFILES)
$(COMP_DIR)/$(COMP_IMPL_NAME) : mtridl $(OBJFILES)
	-$(MKDIR) $(subst /,$(PS),$(COMP_DIR))
	$(LINK) -o $(COMP_DIR)/$(COMP_IMPL_NAME) $(COMP_LINK_FLAGS) $(OBJFILES) $(LINK_LIBS) -lm $(CPPUHELPERLIB) $(CPPULIB) $(SALLIB) $(STC++LIB) $(CPPUHELPERDYLIB) $(CPPUDYLIB) $(SALDYLIB)
endif

mtridl : 
	$(IDLC) -I"$(OO_SDK_HOME)/idl" -I$(IDL_LOC_DIR) -O$(OUT_MISC) $(IDL_FILES2)
	-$(MKDIR) $(subst /,$(PS),$(BUILD_DIR))
	$(REGMERGE) $(BUILD_DIR)/$(RDB_FILE_NAME) /UCR $(URD_FILES)
	$(CPPUMAKER) -Gc -BUCR -O$(IDL_LOC_INC) $(TYPE_NAMES) $(OFFICE_TYPES) $(URE_TYPES) $(BUILD_DIR)/$(RDB_FILE_NAME)



$(MANIFEST) : 
	@-$(MKDIR) $(subst /,$(PS),$(@D))
	@echo $(OSEP)?xml version="$(QM)1.0$(QM)" encoding="$(QM)UTF-8$(QM)"?$(CSEP) > $@
	@echo $(OSEP)manifest:manifest$(CSEP) >> $@
	@echo $(OSEP)manifest:file-entry manifest:full-path="$(QM)$(RDB_FILE_NAME)$(QM)" >> $@
	@echo manifest:media-type="$(QM)application/vnd.sun.star.uno-typelibrary;type=RDB$(QM)"/$(CSEP) >> $@
ifeq "$(SDKVERSION)" "3.3"
	@echo $(OSEP)manifest:file-entry manifest:full-path="$(QM)libs/$(COMP_IMPL_NAME)$(QM)"  >> $@
	@echo manifest:media-type="$(QM)application/vnd.sun.star.uno-component;type=native;platform=$(UNOPKG_PLATFORM)$(QM)"/$(CSEP)  >> $@
else
	@echo $(OSEP)manifest:file-entry manifest:full-path="$(QM)libs/registration.components$(QM)"  >> $@
	@echo manifest:media-type="$(QM)application/vnd.sun.star.uno-components;platform=$(UNOPKG_PLATFORM)$(QM)"/$(CSEP)  >> $@
endif
	@echo $(OSEP)/manifest:manifest$(CSEP) >> $@

$(DESCRIPTION) : 
	@echo $(OSEP)?xml version="$(QM)1.0$(QM)" encoding="$(QM)UTF-8$(QM)"?$(CSEP) > $@
	@echo $(OSEP)description xmlns="$(QM)http://openoffice.org/extensions/description/2006$(QM)" >> $@
	@echo xmlns:xlink="$(QM)http://www.w3.org/1999/xlink$(QM)" >> $@
	@echo xmlns:d="$(QM)http://openoffice.org/extensions/description/2006$(QM)"$(CSEP) >> $@
	@echo $(OSEP)identifier value="$(QM)$(EXTENSION_ID)_$(UNOPKG_PLATFORM)$(QM)" /$(CSEP) >> $@
ifeq "$(SDKVERSION)" "3.3"
else
	@echo $(OSEP)dependencies$(CSEP) >> $@
	@echo $(OSEP)OpenOffice.org-minimal-version value="$(QM)3.4$(QM)" d:name="$(QM)OpenOffice.org 3.4$(QM)" /$(CSEP) >> $@
	@echo $(OSEP)/dependencies$(CSEP) >> $@
endif
	@echo $(OSEP)version value="$(QM)$(EXTENSION_VERSION)$(QM)" /$(CSEP) >> $@
#	@echo $(OSEP)registration$(CSEP) >> $@
#	@echo $(OSEP)simple-license accept-by="$(QM)admin$(QM)" default-license-id="$(QM)this$(QM)" suppress-on-update="$(QM)true$(QM)"$(CSEP) >> $@
#	@echo $(OSEP)license-text xlink:href="$(QM)LICENSE$(QM)" license-id="$(QM)this$(QM)" /$(CSEP) >> $@
#	@echo $(OSEP)/simple-license$(CSEP) >> $@
#	@echo $(OSEP)/registration$(CSEP) >> $@
	@echo $(OSEP)platform value="$(QM)$(TAEGET_PLATFORM)$(QM)" /$(CSEP) >> $@
	@echo $(OSEP)display-name$(CSEP) >> $@
	@echo $(OSEP)name lang="$(QM)en$(QM)"$(CSEP)$(EXTENSION_DISPLAY_NAME)$(OSEP)/name$(CSEP) >> $@
	@echo $(OSEP)/display-name$(CSEP) >> $@
	@echo $(OSEP)extension-description$(CSEP) >> $@
	@echo $(OSEP)src lang="$(QM)en$(QM)" xlink:href="$(QM)descriptions/desc.en$(QM)"/$(CSEP) >> $@
	@echo $(OSEP)/extension-description$(CSEP) >> $@
	@echo $(OSEP)/description$(CSEP) >> $@


$(COMP_REGISTRATION) : 
	@echo $(OSEP)?xml version="$(QM)1.0$(QM)" encoding="$(QM)UTF-8$(QM)"?$(CSEP) >> $@
	@echo $(OSEP)components xmlns="$(QM)http://openoffice.org/2010/uno-components$(QM)"$(CSEP) >> $@
	@echo $(OSEP)component loader="$(QM)com.sun.star.loader.SharedLibrary$(QM)" uri="$(QM)valuetest.uno.so$(QM)"$(CSEP) >> $@
	@echo $(OSEP)implementation name="$(QM)mytools.ValueTest$(QM)"$(CSEP) >> $@
	@echo $(OSEP)service name="$(QM)mytools.ValueTest$(QM)"/$(CSEP) >> $@
	@echo $(OSEP)/implementation$(CSEP) >> $@
	@echo $(OSEP)/component$(CSEP) >> $@
	@echo $(OSEP)/components$(CSEP) >> $@


clean : 
	@- $(RM)  $(subst \\,\,$(subst /,$(PS),$(MANIFEST)))
	@- $(RM)  $(subst \\,\,$(subst /,$(PS),$(DESCRIPTION)))
	@- $(DELRECURSIVE) $(subst \,$(PS),$(OUT_SLO))
	@- $(RM)  $(subst \\,\,$(subst /,$(PS),$(COMP_DIR)/$(COMP_IMPL_NAME)))
	@- $(RM) $(subst \\,\,$(subst /,$(PS),$(BUILD_DIR)/$(RDB_FILE_NAME)))
	@- $(RM) $(subst /,$(PS),$(BUILD_DIR)/LICENSE)
	@- $(RM) $(subst /,$(PS),$(BUILD_DIR)/README)
	@- $(RM) $(UNO_PKG_NAME)
	@- $(DELRECURSIVE) $(BUILD_DIR)


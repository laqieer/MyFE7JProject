# by laqieer in 2017/1/9
#---------------------------------------------------------------------------------
# Clear the implicit built in rules
#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------
ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM)
endif

#---------------------------------------------------------------------------------
# make sure we have bash on OSX
#---------------------------------------------------------------------------------
UNAME_S	:=	$(shell uname -s)
UNAME_R	:=	$(shell uname -r)

ifneq (,$(findstring Darwin,$(UNAME_S)))
	export SHELL=/bin/bash
endif
#---------------------------------------------------------------------------------
# path to tools
#---------------------------------------------------------------------------------
PATH	:=	$(DEVKITARM)/bin:$(PATH)

#---------------------------------------------------------------------------------
# the prefix on the compiler executables
#---------------------------------------------------------------------------------
PREFIX		:=	arm-none-eabi-

CC	:=	$(PREFIX)gcc
CXX	:=	$(PREFIX)g++
AS	:=	$(PREFIX)as
AR	:=	$(PREFIX)gcc-ar
OBJCOPY	:=	$(PREFIX)objcopy
STRIP	:=	$(PREFIX)strip
NM	:=	$(PREFIX)gcc-nm
RANLIB	:=	$(PREFIX)gcc-ranlib

ISVC=$(or $(VCBUILDHELPER_COMMAND),$(MSBUILDEXTENSIONSPATH32),$(MSBUILDEXTENSIONSPATH))

ifneq (,$(ISVC))
	ERROR_FILTER	:=	2>&1 | sed -e 's/\(.[a-zA-Z]\+\):\([0-9]\+\):/\1(\2):/g'
endif

#---------------------------------------------------------------------------------
# TARGET is the name of the output, if this ends with _mb a multiboot image is generated
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# DATA is a list of directories containing data files
# INCLUDES is a list of directories containing header files
#---------------------------------------------------------------------------------
TARGET		:=	$(shell basename $(CURDIR))
BUILD		:=	build
SOURCES		:=	src
DATA		:=	data
GRAPHICS	:=	gfx	
INCLUDES	:=  include
LDS			:=	../FE7J.ld
GRIT 		:=  grit

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
ARCH	:=	-mthumb -mthumb-interwork

CFLAGS	:=	-g -Wall -O2\
		-mcpu=arm7tdmi -mtune=arm7tdmi\
 		-fomit-frame-pointer\
		-ffast-math \
		$(ARCH)\
		-fno-toplevel-reorder\
		-Wno-return-type

CFLAGS	+=	$(INCLUDE)

CXXFLAGS	:=	$(CFLAGS) -fno-rtti -fno-exceptions

ASFLAGS	:=	
LDFLAGS	:=	-g -T$(LDS) -Wl,-Map,$(notdir $@).map
OBJCOPYFLAGS	:=	--set-section-flags .rom="r,c,a"

#---------------------------------------------------------------------------------
%.arm.o: %.arm.cpp
	@echo $(notdir $<)
	$(CXX) $(CXXFLAGS) -marm -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.arm.o: %.arm.c
	@echo $(notdir $<)
	$(CC) $(CFLAGS) -marm -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.thumb.o: %.thumb.cpp
	@echo $(notdir $<)
	$(CXX) $(CXXFLAGS) -mthumb -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.thumb.o: %.thumb.c
	@echo $(notdir $<)
	$(CC) $(CFLAGS) -mthumb -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.iwram.o: %.iwram.cpp
	@echo $(notdir $<)
	$(CXX) $(CXXFLAGS) -marm -mlong-calls -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.iwram.o: %.iwram.c
	@echo $(notdir $<)
	$(CC) $(CFLAGS) -marm -mlong-calls -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.itcm.o: %.itcm.cpp
	@echo $(notdir $<)
	$(CXX) $(CXXFLAGS) -marm -mlong-calls -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.itcm.o: %.itcm.c
	@echo $(notdir $<)
	$(CC) $(CFLAGS) -marm -mlong-calls -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.o: %.cpp
	@echo $(notdir $<)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.o: %.c
	@echo $(notdir $<)
	$(CC) $(CFLAGS) -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.o: %.s
	@echo $(notdir $<)
	$(CC) -x assembler-with-cpp $(ASFLAGS) -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
%.o: %.S
	@echo $(notdir $<)
	$(CC) -x assembler-with-cpp $(ASFLAGS) -c $< -o $@ $(ERROR_FILTER)

#---------------------------------------------------------------------------------
# canned command sequence for binary data
#---------------------------------------------------------------------------------
define bin2o
	bin2s $< | $(AS) -o $(@)
	echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > `(echo $(<F) | tr . _)`.h
	echo "extern const u8" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> `(echo $(<F) | tr . _)`.h
	echo "extern const u32" `(echo $(<F) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> `(echo $(<F) | tr . _)`.h
endef

#---------------------------------------------------------------------------------
%.gba: %.elf
	@$(OBJCOPY) $(OBJCOPYFLAGS) $<
	@$(OBJCOPY) -O binary $< $@
	@echo built ... $(notdir $@)
	@gbafix $@

#---------------------------------------------------------------------------------
%_mb.elf: $(LDS)
	@echo linking multiboot
	@$(LD) -specs=gba_mb.specs $(LDFLAGS) $(OFILES) $(LIBPATHS) -o $@

#---------------------------------------------------------------------------------
%.elf: $(LDS)
	@echo linking cartridge
#	@$(LD)  $(LDFLAGS) -specs=gba.specs $(OFILES) $(LIBPATHS) -o $@
	@$(LD)  $(LDFLAGS) $(OFILES) $(LIBPATHS) -o $@
	
#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export OUTPUT	:=	$(CURDIR)/$(TARGET)
export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
			$(foreach dir,$(DATA),$(CURDIR)/$(dir)) \
			$(foreach dir, $(GRAPHICS), $(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)

#---------------------------------------------------------------------------------
# automatically build a list of object files for our project
#---------------------------------------------------------------------------------
CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))
PNGFILES	:=	$(foreach dir,$(GRAPHICS),$(notdir $(wildcard $(dir)/*.png)))

#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
	export LD	:=	$(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
	export LD	:=	$(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

export OFILES	:=	$(addsuffix .o,$(BINFILES)) \
					$(PNGFILES:.png=.o) \
					$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)

#---------------------------------------------------------------------------------
# build a list of include paths
#---------------------------------------------------------------------------------
export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
			-I$(CURDIR)/$(BUILD)

#---------------------------------------------------------------------------------
# build a list of library paths
#---------------------------------------------------------------------------------
export LIBPATHS	:=	-nostdlib

.PHONY: $(BUILD) clean

#---------------------------------------------------------------------------------
$(BUILD):
	@[ -d $@ ] || mkdir -p $@
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

all	: $(BUILD)
#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET).elf $(TARGET).gba $(TARGET).sav

#---------------------------------------------------------------------------------
else

DEPENDS	:=	$(OFILES:.o=.d)

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
$(OUTPUT).gba	:	$(OUTPUT).elf

$(OUTPUT).elf	:	$(OFILES)


#---------------------------------------------------------------------------------
# The bin2o rule should be copied and modified
# for each extension used in the data directories
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
# This rule links in binary data with the .bin extension
#---------------------------------------------------------------------------------
%.bin.o	:	%.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
# This rule links in binary data with the .raw extension
#---------------------------------------------------------------------------------
%.raw.o	:	%.raw
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
# This rule creates assembly source files using grit
# grit takes an image file and a .grit describing how the file is to be processed
# add additional rules like this for each image extension
# you use in the graphics folders 
#---------------------------------------------------------------------------------
# With matching grit-file
%.s %.h	: %.png %.grit
	$(GRIT) $< -fts

# No grit-file: try using dir.grit
%.s %.h	: %.png
	$(GRIT) $< -fts -ff $(<D)/$(notdir $(<D)).grit

-include $(DEPENDS)

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

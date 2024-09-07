################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../Drivers


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../Drivers/adc.c \
../Drivers/clkctrl.c \
../main.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
Drivers/adc.o \
Drivers/clkctrl.o \
main.o

OBJS_AS_ARGS +=  \
Drivers/adc.o \
Drivers/clkctrl.o \
main.o

C_DEPS +=  \
Drivers/adc.d \
Drivers/clkctrl.d \
main.d

C_DEPS_AS_ARGS +=  \
Drivers/adc.d \
Drivers/clkctrl.d \
main.d

OUTPUT_FILE_PATH +=Hist_Band.elf

OUTPUT_FILE_PATH_AS_ARGS +=Hist_Band.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
Drivers/adc.o: ../Drivers/adc.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Prog\MicrochipStudio\7.0\Packs\Atmel\ATtiny_DFP\2.0.368\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=attiny424 -B "D:\Prog\MicrochipStudio\7.0\Packs\Atmel\ATtiny_DFP\2.0.368\gcc\dev\attiny424" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

Drivers/clkctrl.o: ../Drivers/clkctrl.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Prog\MicrochipStudio\7.0\Packs\Atmel\ATtiny_DFP\2.0.368\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=attiny424 -B "D:\Prog\MicrochipStudio\7.0\Packs\Atmel\ATtiny_DFP\2.0.368\gcc\dev\attiny424" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Prog\MicrochipStudio\7.0\Packs\Atmel\ATtiny_DFP\2.0.368\include"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=attiny424 -B "D:\Prog\MicrochipStudio\7.0\Packs\Atmel\ATtiny_DFP\2.0.368\gcc\dev\attiny424" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Hist_Band.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=attiny424 -B "D:\Prog\MicrochipStudio\7.0\Packs\Atmel\ATtiny_DFP\2.0.368\gcc\dev\attiny424"  
	@echo Finished building target: $@
	"D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Hist_Band.elf" "Hist_Band.hex"
	"D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Hist_Band.elf" "Hist_Band.eep" || exit 0
	"D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Hist_Band.elf" > "Hist_Band.lss"
	"D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Hist_Band.elf" "Hist_Band.srec"
	"D:\Prog\MicrochipStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Hist_Band.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Hist_Band.elf" "Hist_Band.a" "Hist_Band.hex" "Hist_Band.lss" "Hist_Band.eep" "Hist_Band.map" "Hist_Band.srec" "Hist_Band.usersignatures"
	
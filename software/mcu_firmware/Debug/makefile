################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.0.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./driver/clock.obj" \
"./driver/gpio.obj" \
"./driver/spi.obj" \
"./driver/timer.obj" \
"./driver/uart.obj" \
"./lib/dpuser.obj" \
"./lib/flash.obj" \
"./lib/max2828.obj" \
"./lib/ringbuffer.obj" \
"./lib/scheduler.obj" \
"./lib/sw_uart.obj" \
"./plat/hscom.obj" \
"./src/main.obj" \
"../link/lnk_msp430fr5969.cmd" \
$(GEN_CMDS__FLAG) \
-llibmpu_init.a \
-llibmath.a \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include driver/subdir_vars.mk
-include lib/subdir_vars.mk
-include link/subdir_vars.mk
-include plat/subdir_vars.mk
-include src/subdir_vars.mk
-include driver/subdir_rules.mk
-include lib/subdir_rules.mk
-include link/subdir_rules.mk
-include plat/subdir_rules.mk
-include src/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
HSCOM_FW.out \

EXE_OUTPUTS__QUOTED += \
"HSCOM_FW.out" \

BIN_OUTPUTS += \
HSCOM_FW.hex \

BIN_OUTPUTS__QUOTED += \
"HSCOM_FW.hex" \


# All Target
all: HSCOM_FW.out

# Tool invocations
HSCOM_FW.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.0.LTS/bin/cl430" -vmspx --data_model=restricted --opt_for_speed=0 --use_hw_mpy=F5 --advice:power=all --advice:hw_config="all" --define=__MSP430FR5969__ --define=_MPU_ENABLE -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU40 -z -m"HSCOM_FW.map" --heap_size=160 --stack_size=160 --cinit_hold_wdt=on -i"C:/ti/ccsv7/ccs_base/msp430/include" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.0.LTS/lib" -i"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.0.LTS/include" -i"C:/ti/ccsv7/ccs_base/msp430/lib/5xx_6xx_FRxx" -i"C:/ti/ccsv7/ccs_base/msp430/lib/FR59xx" --priority --reread_libs --define=_MPU_ENABLE --diag_wrap=off --display_error_number --warn_sections --xml_link_info="HSCOM_FW_linkInfo.xml" --use_hw_mpy=F5 --rom_model -o "HSCOM_FW.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

HSCOM_FW.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/ti/ccsv7/tools/compiler/ti-cgt-msp430_16.9.0.LTS/bin/hex430" --memwidth=8 --romwidth=8 -o "HSCOM_FW.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "driver\clock.obj" "driver\gpio.obj" "driver\spi.obj" "driver\timer.obj" "driver\uart.obj" "lib\dpuser.obj" "lib\flash.obj" "lib\max2828.obj" "lib\ringbuffer.obj" "lib\scheduler.obj" "lib\sw_uart.obj" "plat\hscom.obj" "src\main.obj" 
	-$(RM) "driver\clock.d" "driver\gpio.d" "driver\spi.d" "driver\timer.d" "driver\uart.d" "lib\dpuser.d" "lib\flash.d" "lib\max2828.d" "lib\ringbuffer.d" "lib\scheduler.d" "lib\sw_uart.d" "plat\hscom.d" "src\main.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets


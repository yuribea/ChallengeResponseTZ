################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32U5xx_HAL_Driver/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := TrustZone_challengeResponse_NonSecure
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
TrustZone_challengeResponse_NonSecure.elf \

MAP_FILES += \
TrustZone_challengeResponse_NonSecure.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
TrustZone_challengeResponse_NonSecure.list \


# All Target
all: main-build

# Main-build Target
main-build: TrustZone_challengeResponse_NonSecure.elf secondary-outputs

dependents:
	-cd /home/bea/STM32CubeIDE/workspace_TrustZone/TrustZone_challengeResponse/Secure/Debug && $(MAKE) all

# Tool invocations
TrustZone_challengeResponse_NonSecure.elf TrustZone_challengeResponse_NonSecure.map: $(OBJS) $(USER_OBJS) /home/bea/STM32CubeIDE/workspace_TrustZone/TrustZone_challengeResponse/Secure/Debug/TrustZone_challengeResponse_Secure.elf /home/bea/STM32CubeIDE/workspace_TrustZone/TrustZone_challengeResponse/NonSecure/STM32U585AIIXQ_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "TrustZone_challengeResponse_NonSecure.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"/home/bea/STM32CubeIDE/workspace_TrustZone/TrustZone_challengeResponse/NonSecure/STM32U585AIIXQ_FLASH.ld" --specs=nosys.specs -Wl,-Map="TrustZone_challengeResponse_NonSecure.map" -Wl,--gc-sections -static -L/home/bea/st/x-cube-cryptolib-v4-5-0/STM32CubeExpansion_Crypto_V4.5.0/Middlewares/ST/STM32_Cryptographic/lib --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

TrustZone_challengeResponse_NonSecure.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "TrustZone_challengeResponse_NonSecure.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) TrustZone_challengeResponse_NonSecure.elf TrustZone_challengeResponse_NonSecure.list TrustZone_challengeResponse_NonSecure.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified
/home/bea/STM32CubeIDE/workspace_TrustZone/TrustZone_challengeResponse/Secure/Debug/TrustZone_challengeResponse_Secure.elf:

-include ../makefile.targets

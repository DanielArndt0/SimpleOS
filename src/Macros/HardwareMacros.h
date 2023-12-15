#pragma once

// Clock
#define HW_CLOCK 16E6

// EEPROM
#define HW_EEPROM_SIZE 0x400

// SRAM
#define HW_START_ADDR_SRAM 0x0100
#define HW_END_ADDR_SRAM 0x08FF

// Addressing
#define HW_OFFSET (0x20)
#define HW_MEMIO_ADDR(addr) (*(volatile unsigned char *)(addr))
#define HW_IO_ADDR(addr) (*((volatile unsigned char *)(addr) + SYSM_OFFSET))

// ADC
#define ADC_RESOLUTION 1024
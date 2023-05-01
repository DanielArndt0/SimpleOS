#pragma once

// VERSION
#define SYSM_VERSION "V1.0.00"

// Sintaxe
#define implements virtual public
#define extends virtual public
#define conceptualize virtual public
#define SameOf decltype

// Heap
#define SYSM_HEAP_SIZE 128

// Force go to
#define FORCE_EXIT goto sysm_exit_lbl
#define EXIT sysm_exit_lbl:""

// String
#define BUFFER_SIZE_STR(type) ((8 * sizeof(type)) + 1)
#define HEX 16
#define DEC 10
#define OCT 8
#define BIN 2
#define NULL_STR ""

// Array
#define SYSM_ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

// Hardware
#define SYSM_SYSTEM_CLOCK 16E6
// TODO Adicionar modo INPUT_PULLUP
#define OUTPUT 0x01
#define INPUT 0x00

// EEPROM
#define SYSM_EEPROSYSM_SIZE 0x400

// SRAM
#define SYSM_START_ADDR_SRAM 0x0100
#define SYSM_END_ADDR_SRAM 0x08FF

// Addressing
#define SYSM_OFFSET (0x20)
#define SYSM_MEMIO_ADDR(addr) (*(volatile unsigned char *)(addr))
#define SYSM_IO_ADDR(addr) (*((volatile unsigned char *)(addr) + SYSM_OFFSET))

// Registers
#define SYSM_SET(byte, bit) ((byte) |= (0x01 << (bit)))
#define SYSM_CLEAR(byte, bit) ((byte) &= ~(0x01 << (bit)))
#define SYSM_CHECK(byte, bit) ((byte) & (0x01 << (bit)))
#define SYSM_FLIP(byte, bit) ((byte) ^= (0x01 << (bit)))
#define SYSM_WRITE_REG(byte, bit, value) ((value) == SYSM_TRUE ? SYSM_SET((byte), (bit)) : SYSM_CLEAR((byte), (bit)))
#define SYSM_SHIFTR(byte, shift) ((byte) >> shift)
#define SYSM_SHIFTL(byte, shift) ((byte) << shift)
#define SYSM_HIGH(byte) ((byte) >> (0x08))
#define SYSM_LOW(byte) ((byte) & (0xFF))
#define SYSM_MASK(byte, mask) ((byte) & (mask))

// Analog-Digital
#define SYSM_ADC_VOLTAGE(x) (x * (5.0 / 1024.0))

// Math
#define SYSM_ABSOLUTE(x) (x >= 0x00 ? x : (x * (-0x01)))

// Boolean
#define SYSM_FALSE 0x00
#define SYSM_TRUE 0x01

// Serial macros
#define cmd(comma) (char)(comma)
#define endl cmd(0x0A) << cmd(0x0D)
#pragma once

// ISR
#define INT(vector, ...)                                                          \
  extern "C" void vector(void) __attribute__((signal, used, externally_visible)); \
  void vector(void)

// Bit
#define BIT_SET(byte, bit) ((byte) |= (0x01 << (bit)))
#define BIT_CLEAR(byte, bit) ((byte) &= ~(0x01 << (bit)))
#define BIT_CHECK(byte, bit) ((byte) & (0x01 << (bit)))
#define BIT_FLIP(byte, bit) ((byte) ^= (0x01 << (bit)))
#define BIT_WRITE_REG(byte, bit, value) ((value) == true ? BIT_SET((byte), (bit)) : BIT_CLEAR((byte), (bit)))
#define SHIFT_RIGHT(byte, shift) ((byte) >> shift)
#define SHIFT_LEFT(byte, shift) ((byte) << shift)
#define BYTE_MASK(byte, mask) ((byte) & (mask))
#define BYTE_LOW(byte) (BYTE_MASK(byte, 0xFF))
#define SHIFT_BYTE(byte) (SHIFT_RIGHT(byte, 0x08))

// Analog-Digital
#define SYS_ADC_VOLTAGE(x) (x * (5.0 / 1024.0))

// Serial macros
#define cmd(comma) (char)(comma)
#define endl cmd(0x0A) << cmd(0x0D)

// Numbers Base
#define HEX 16
#define DEC 10
#define OCT 8
#define BIN 2

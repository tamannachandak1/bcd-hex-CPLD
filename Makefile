# Raw avr-gcc build for the nibble counter — no Arduino IDE, no arduino-cli.
#
# Usage:
#   make            # build main.elf, main.hex
#   make flash      # build + upload via avrdude
#   make clean
#
# Adjust MCU/F_CPU/PORT/PROGRAMMER for your actual board.

MCU        = atmega328p
F_CPU      = 16000000UL
PORT       = /dev/ttyUSB0
BAUD       = 115200
PROGRAMMER = arduino

CC      = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -std=gnu11 -Wall -Wextra

TARGET  = main
SRCS    = main.c

all: $(TARGET).hex

$(TARGET).elf: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

flash: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -P $(PORT) -b $(BAUD) -U flash:w:$(TARGET).hex:i

clean:
	rm -f $(TARGET).elf $(TARGET).hex

.PHONY: all flash clean

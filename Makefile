CONTIKI_PROJECT = leds_on_off
all: $(CONTIKI_PROJECT)

CONTIKI = ../..
include $(CONTIKI)/Makefile.include

APP=leds_on_off
PLATFORM=native


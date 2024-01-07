#@copyright : Eman Elsayed 

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AS = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
project_name = ToggleLed
all: $(project_name).bin
	@echo "=========Build is done======="


%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $< -o $@

$(project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe  -T $(LIBS)linkerscript.ld $(ASOBJ) $(OBJ)  -o $@ -Map=mapfile.map

$(project_name).bin: $(project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.bin *.elf *.map

clean: 
	rm *.bin *.elf *.map
	

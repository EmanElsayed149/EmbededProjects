
### LAB3
#### Baremetal sw on TM4C123 ARM CortexM4 to toggle green led connected on PF3 
- it's required to make stack size = 1k 
- it's required to write startup file in c 
### required information 
- CortexM4 memory map 
	- flash (code and data section) : from 0x00000000  to 0x20000000
	- SRAM (heap , stack , bss, data): from 0x20000000 to 0x40000000
	- Boot sequence 
	- registers to toggle led
### Boot sequence 
- When the power is applied to the MCU , pc register value will be 0 which will be mapped to 
0x00000000 and therefore sp value expected exist at this address 
- the program counter then will be 0x00000004 , and expects to find the address of the reset handler 
### explanation of my code: 
#### startup.c
1. reserve space in SRAM for stack 
	- One of the ways to reserve 1024 byte for stack is to define static global array of array of 256 ints number and initialize them with 0 and use adrdress of last element of this array (base address +  sizeof array)to be stack top
```
/*reserve space for stack = 1024 byte ===> 256 int element */
static uint32 stack_top[256];
```	
2. from specs of TIVA C ..put sp value  in 0x00000000 , then addresses of vector handlers 
	- you can use (.word in assemp ) .. to do this step in c write global array of pointers , each pointer points to function 
	- but array stored in data section .... to make it stored in 0x00000000 (as defined in boot sequence), use attribute to give it section name like (.vectors)
	- in linkerscript ... you can determine map address for this array 
- as shown :
```
//define this global array of cont pointers (each pointer points to func) to be put in vector section not in data section
void (* const ptr_to_handlervectors[])() __attribute__((section(".vectors"))) = {
	(void (*)()) ((uint32)stack_top + sizeof(stack_top)),                                   //put value of sp in first 4 byte in vector section
	&ResetHandler,
	&NMIHandler,
	&HFaultHandler
	//and so on ... put addresses of vectors handler 
};
```

#### linkerscript
1. define physical address for each FLASH , SRAM 
```
MEMORY
{
   flash(RX) : ORIGIN = 0x00000000, LENGTH = 512M 
   sram(RWX) : ORIGIN = 0x20000000, LENGTH = 512M
}
```
2. determine vma AT> lma  for each section : 
- vma : relocatable section address in run-time located 
- lma : relocatable section address in load-time located 

```
SECTIONS
{   
   .text :
   {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
   }> flash
   .data :
   {
		_S_data = .;
		*(.data)
		_E_data = .;
   }> sram AT> flash
   .bss :
   {
		_S_bss = .;
		*(.bss*)
		. = ALIGN(4) ;
		_E_bss = .;
   }> sram
}
```
#### **Note** :  (.vectors)  section address at  load and run time is  0x0000000 (as required in boot sequence).
#### **Note** : (.data )section  load-time address in flash but its run-time address in sram
#### **(_E_text ) sympol**:  refer to end address of text section in flash and at the same time refer to start address of data section in flash
#### **(_S_data) sympol**:  refer to start address of data address in sram

## Mapfile 
- as shown : 
![mapfile](https://github.com/EmanElsayed149/Learn-In-Depth/blob/main/unit3EmbeddedC/lesson4/1.png)
	- .vectors section : there is ptr_to_handlervectors (to initialize sp , vectorhandlers) at 0x00000000
	- all vectorshandlers except reset  at the same address ....although each has its own function ?! ..... because I used weak and alias definition to save memory 
	```
	void NMIHandler(void)        __attribute__((weak,alias("DefaultHandler")));;
	```
	```
	void HFaultHandler(void)     __attribute__((weak,alias("DefaultHandler")));;
	```
- ![mapfile](https://github.com/EmanElsayed149/Learn-In-Depth/blob/main/unit3EmbeddedC/lesson4/2.png)
	- load address of _E_text = load address of _S_data 
	- sizeof bss = 0x400 = 1024 byte = 1 k = space of stack 
	
	
#### output 

#### files to be downloaded :
1. Keil_uvision_unit3_lab4_project
2. startup.c 
3. linkerscript.ld
4. main.c
5. gpio.c
6. gpio.h
7. PlatformTypes.h  
8. Makefile

#### Run this code 
```
> make 
```
```
1. open Keil_uvision_unit3_lab4_project/Keil_uvision_unit3_lab4_project.uvprojx
2. select options for target 
3. from outpu select path of ToggleLed.elf
```

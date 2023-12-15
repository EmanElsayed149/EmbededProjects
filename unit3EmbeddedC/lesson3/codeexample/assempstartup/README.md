### Boot sequence 
- When the power is applied to the MCU , pc register value will be 0 which will be mapped to 
0x80000000 and therefore sp value expected exist at this address 
- the program counter then will be 0x80000004 , and expects the address of the reset handler 
- you can do this by startup code as shown :
 
```
.section .vectors

.word 0x20001000
.word _reset           /*1 Rsest      */
```
- .word :  is often used to reserve space in memory and initialize it with a specific value.
- and so on ... reserve spaces and initiates it with handler vectors 
### linker script 
- To map adress 0x0 (at which sp is stored virtually )to the physical address 0x80000000 , you should put vectors section at the begining of flash 
```
MEMORY
{
   flash(RX) : ORIGIN = 0x08000000, LENGTH = 128k 
   sram(RWX) : ORIGIN = 0x20000000, LENGTH = 20k
}

SECTIONS
{   
   .text :
   {
      *(.vectors*)
      *(.text*)
	  *(.rodata)
   }> flash
```
### files
- startup.s 
- linkerscript.ld
- app.c : code for toggleled
- toggleled.pdsprj: simulation on proteus  
- mapfile.map : sections addresses after mapping 


## Baremetal software 
In this lab , my implementation for very simple baremetal sw for ARM cortex-m3 to Toggle led on port c13

### tools needed 
1- ARM toolchain (cross toolchain): (complier - assempler - linker - disassempler )


### My SW 
1- c code files
2- startup file to :
   - Define interrupt vectors section
   - Copy data section from flah to Ram 
   - initialize bss section in Ram 
   - create reset section and call main
   - initialize stack
3- linker script code:
   - define memory layout of target system, including start address
4- makefile

### files
- codeexample/assempstartup : startup file is written in assemply
- codeexample/sourcestartup : startup file is written in C language


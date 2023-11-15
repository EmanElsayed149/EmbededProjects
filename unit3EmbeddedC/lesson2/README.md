## Baremetal software 
In this lab , my implementation for very simple baremetal sw for ARM versatilePB to send "Learn In Depth : Eman Elsayed" using UART

### tools needed 
1- ARM toolchain : (complier - assempler - linker - desassempler)
2- Qemu : ARM versatilePB firmware

### My SW 
1- c code files
2- startup file to :
   - create reset section and call main
   - initialize stack
3- linker script code:
   - initiate location counter
   - define memory layout of target system, including start address
4- makefile



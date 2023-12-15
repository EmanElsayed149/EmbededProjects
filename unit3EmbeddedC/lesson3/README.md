## Baremetal software 
In this lab , my implementation for very simple baremetal sw for ARM cortex-m3 to Toggle led on port c13
<video src="20231215_213920.mp4" controls title="Title"></video>
### tools needed 
1- ARM toolchain (cross toolchain): (complier - assempler - linker - disassempler )


### My SW 
1. c code files
2. startup file to :
   - Define interrupt vectors section
   - Copy data section from flah to Ram 
   - initialize bss section in Ram 
   - create reset section and call main
   - initialize stack
3. linker script code:
   - define memory layout of target system, including start address
4. makefile

### files
- codeexample/assempstartup : startup file is written in assemply
- codeexample/sourcestartup : startup file is written in C language

### How to use 
1. For testing using startup.s
   - run 
   ```
   > git clone https://github.com/EmanElsayed149/Learn-In-Depth/tree/main/unit3EmbeddedC/lesson3/codeexample/assempstartup
   ```
   - run 
   ```
   > make
   ```
2. For testing using startup.c
   - run 
   ```
   > git clone https://github.com/EmanElsayed149/Learn-In-Depth/tree/main/unit3EmbeddedC/lesson3/codeexample/sourcestartup
   ```
   - run 
   ```
   > make 
   ```
## Baremetal software 
In this lab , my implementation for very simple baremetal sw for ARM cortex-m3 to Toggle led on port c13
and write  malloc function that compatable with cortex-m3


### How to use 
   -  
   ```
   $ git clone https://github.com/EmanElsayed149/Learn-In-Depth/tree/main/unit3EmbeddedC/lesson5
   ```
   - Don't use make file (because of we need liberaries so linker tool used in makefile need pathes of these liberaries ), this make your make file dependent on pathes, so use ths following command   
   ```
   $ arm-none-eabi-gcc.exe -mcpu=cortex-m3  -mthumb -nostartfiles -T linkerscript.ld startup.c app.c -o unit3_lesson5.elf
   ```
   -  To make sure that malloc is aleardy added to your code (check size of .data section), .data before malloc was 4 byte only
   ```
   $  arm-none-eabi-objdump.exe -h unit3_lesson5.elf
   ```
### output
![Screenshot (258)](https://github.com/EmanElsayed149/Learn-In-Depth/assets/91433516/df6a7649-faff-40c6-9fd8-d64dccb26193)

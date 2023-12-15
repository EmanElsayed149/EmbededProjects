/*startup cortex-m3
Eman Elsayed 
*/
 

.global _reset

/*SRAM starts at 0x20000000*/
.section .vectors

.word 0x20001000
.word _reset           /*1 Rsest      */
.word vector_handler   /*2 NMI        */
.word vector_handler   /*3 Hard fault */
.word vector_handler   /*4 MM Fault   */
.word vector_handler   /*5 Bus Fault  */
.word vector_handler   /*6 Usage Fault*/
.word vector_handler   /*7 Reserved   */
.word vector_handler   /*8 Reserved   */
.word vector_handler   /*9 Reserved   */
.word vector_handler   /*10 Reserved  */
.word vector_handler   /*11 SV Call   */
.word vector_handler   /*12 Debug reserved */
.word vector_handler   /*13 Reserved  */
.word vector_handler   /*14 PendSV    */
.word vector_handler   /*15 SysTick   */
.word vector_handler   /*16 RIQ0      */
.word vector_handler   /*17 RIQ1      */
.word vector_handler   /*18 RIQ2      */
.word vector_handler   /*19 RIQ3      */
.word vector_handler   /*20 RIQ4      */
.word vector_handler   /*21 RIQ5      */
.word vector_handler   /*22 RIQ6      */
.word vector_handler   /*23 RIQ7      */

.section .text
_reset:
	bl main
stop:
	b stop
.thumb_func
vector_handler:
	b _reset

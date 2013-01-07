.global _start
_start:
	/* Peri port setup*/
	ldr r0, =0x70000000
	orr r0, r0, # 0x13
	mcr p15, 0, r0, c15, c2,4

	/* disable watchdog*/
	ldr r0, =0x7e004000
	mov r1, #0
	str r1, [r0]

	/* setup stack */
	ldr sp,=8*1024
	bl main
halt:
	b halt

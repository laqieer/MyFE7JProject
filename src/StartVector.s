@    .section  .StartVector,"ax"
	
@--------------------------------------------------------------------
@-                          Reset                                   -
@--------------------------------------------------------------------

    .GLOBAL     StartVector
    .CODE 32
StartVector:
        mov     r0, #0x12       @ switch to IRQ mode
        msr     cpsr, r0
        ldr     sp, =#0x3007FA0              @ set SP_irq
        mov     r0, #0x1F       @ switch to system mode
        msr     cpsr, r0
        ldr     sp, =#0x3007E00              @ set SP_usr
        ldr     r1, =#0x3007FFC    @ set interrupt address
        ldr     r0, =#0x80000FC
        str     r0, [r1]
        ldr     r1, =#0x8000A21           @ start & switch to 16bit code
        mov     lr, pc
        bx      r1
        b       StartVector            @ reset

    .ALIGN
	
@--------------------------------------------------------------------
@-          Interrupt Branch Processing (table lookup) 32Bit 25-60c -
@--------------------------------------------------------------------
/*     .section	.IntrMain,"ax"
	.GLOBAL     IntrMain
    .ALIGN
    .CODE 32
IntrMain:
        ldr     r3, =#0x4000200
        ldr     r2, [r3]
		mov		r1,r2,lsl #16
		mov 	r1,r1,lsr #16
		mrs		r0,spsr
		stmfd	sp!,{r0,r1,r3,lr}
		and 	r1,r2,r2,lsr #16
        ands    r0, r1, #0x2000  @ Game Pak interrupt
loop:   bne     loop
        mov     r2, #0
        ands    r0, r1, #1   @ V-blank interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #2   @ H-blank interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #4   @ V-counter interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #8    @ timer 0 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x10    @ timer 1 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x20    @ timer 2 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x40    @ timer 3 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x80        @ serial communication interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x100      @ DMA0 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x200      @ DMA1 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x400      @ DMA2 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x800      @ DMA3 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x1000       @ key interrupt
		bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x2000		@ Game Pak interrupt (多余?)
loop2:	bne	 loop2
jump_intr:
        strh    r0, [r3, #2]            @ IF clear           11c
		mrs  	r3,cpsr
		bic		r3,r3,#0xDF
		orr		r3,r3,#0x1F
		msr		cpsr_cf,r3
        ldr     r1, =#0x3002800          @ jump to user IRQ processing
        add     r1, r1, r2
        ldr     r0, [r1]
		stmfd	sp!,{lr}
		adr		lr,jump2
        bx      r0
jump2:ldmfd	sp!,{lr}
		mrs		r3,cpsr
		bic		r3,r3,#0xDF
		orr		r3,r3,#0x92
		msr		cpsr_cf,r3
		ldmfd	sp!,{r0,r1,r3,lr}
		strh	r1,[r3]
		msr		cpsr_cf,r0
		bx		lr

    .END */
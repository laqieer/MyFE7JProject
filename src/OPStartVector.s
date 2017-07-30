@	.section  .OPStartVector,"ax"
	
@--------------------------------------------------------------------
@-                          Reset                                   -
@--------------------------------------------------------------------
    .EXTERN     OPMain
	.EXTERN		OPIntrMain
	.EXTERN		StartVector
    .GLOBAL     OPStartVector
    .CODE 32
OPStartVector:
        mov     r0, #0x12        @ switch to IRQ mode
        msr     cpsr, r0
        ldr     sp, sp_irq              @ set SP_irq
        mov     r0, #0x1F       @ switch to system mode
        msr     cpsr, r0
        ldr     sp, sp_usr              @ set SP_usr
        ldr     r1, =#0x3007FFC    @ set interrupt address
        ldr     r0, =#OPIntrMain
        str     r0, [r1]
        ldr     r1, =OPMain            @ start & switch to 16bit code
        mov     lr, pc
        bx      r1
        b       StartVector            @ reset

    .ALIGN
sp_usr: .word   0x3008000 - 0x100
sp_irq: .word   0x3008000 - 0x60

@--------------------------------------------------------------------
@-          Interrupt Branch Processing (table lookup) 32Bit 25-60c -
@--------------------------------------------------------------------
@	.section	.OPIntrMain,"ax"
    .EXTERN     OPIntrTable
    .GLOBAL     OPIntrMain
    .ALIGN
    .CODE 32
OPIntrMain:
        mov     r3, #0x4000000           @ check IE/IF
        add     r3, r3, #0x200  @ r3: REG_IE
        ldr     r2, [r3]
        and     r1, r2, r2, lsr #16     @ r1: IE & IF
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
        ands    r0, r1, #0x80       @ serial communication interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x100      @ DMA0 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x200      @ DMA1 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x400     @ DMA2 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x800      @ DMA3 interrupt
        bne     jump_intr
        add     r2, r2, #4
        ands    r0, r1, #0x1000       @ key interrupt
jump_intr:
        strh    r0, [r3, #2]            @ IF clear           11c
        ldr     r1, =OPIntrTable          @ jump to user IRQ processing
        add     r1, r1, r2
        ldr     r0, [r1]
        bx      r0

    .END

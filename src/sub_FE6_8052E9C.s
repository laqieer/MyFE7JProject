.GLOBAL sub_FE6_8052E9C
.ALIGN
.CODE 16
sub_FE6_8052E9C:
	push {r4-r7,lr}
	add sp, #-0x4
	add r5, r0, #0x0
	ldr r4, [r5, #0x60]
	mov r0, #0x2c
	ldsh r3, [r5, r0]
	mov r7, #0x3c
	str r7, [sp, #0x0]
	mov r0, #0x0
	mov r1, #0xb4
	mov r2, #0x32
	ldr r6,=#0x8013508+1
	bl call6
	ldrh r2, [r5, #0x30]
	mov r3, #0xc0
	lsl r3, r3, #0x2
	add r1, r2, r3
	mov r6, #0x0
	strh r1, [r5, #0x30]
	lsr r2, r1, #0x8
	ldr r3, =#0x80C0E98
	lsl r1, r2, #0x1
	add r1, r1, r3
	add r2, #0x40
	lsl r2, r2, #0x1
	add r2, r2, r3
	mov r3, #0x0
	ldsh r1, [r1, r3]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	mul r1, r0
	lsl r1, r1, #0x4
	mov r3, #0x0
	ldsh r2, [r2, r3]
	mul r0, r2
	lsl r0, r0, #0x4
	asr r1, r1, #0x10
	ldrh r2, [r5, #0x32]
	add r1, r2, r1
	asr r0, r0, #0x10
	ldrh r3, [r5, #0x3a]
	add r0, r3, r0
	strh r1, [r4, #0x2]
	strh r0, [r4, #0x4]
	ldrh r0, [r5, #0x2c]
	add r0, #0x1
	strh r0, [r5, #0x2c]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	cmp r0, #0x3c
	ble loc_52f04
	strh r7, [r5, #0x2c]
loc_52f04:
	ldrh r0, [r5, #0x2e]
	add r0, #0x1
	strh r0, [r5, #0x2e]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	cmp r0, #0x78
	ble loc_52f1c
	strh r6, [r5, #0x2c]
	strh r6, [r5, #0x2e]
	add r0, r5, #0x0
	ldr r6,=0x800457C+1
	bl call6
loc_52f1c:
	add sp, #0x4
	pop {r4-r7}
	pop {r0}
	bx r0
call6:
	bx r6
.end

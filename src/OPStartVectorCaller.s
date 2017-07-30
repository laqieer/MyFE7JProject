	.section  .OPStartVectorCaller,"ax"
	.GLOBAL     OPStartVectorCaller
    .CODE 32
OPStartVectorCaller:
	ldr r0,=OPStartVector
	mov lr,pc
	bx r0
	
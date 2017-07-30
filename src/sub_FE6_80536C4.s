.GLOBAL sub_FE6_80536C4
.ALIGN
.CODE 16
sub_FE6_80536C4:
push {r4-r7,lr}
add sp, #-0x4
add r6, r0, #0x0
ldr r5, [r6, #0x60]
mov r0, #0x2c
ldsh r3, [r6, r0]
mov r1, #0x2e
ldsh r0, [r6, r1]
str r0, [sp, #0x0]
mov r0, #0x1
mov r1, #0x6e
mov r2, #0x0
ldr r7,=#0x8013508+1
bl call7
add r4, r0, #0x0
lsl r4, r4, #0x10
lsr r4, r4, #0x10
ldr r1, [r6, #0x44]
ldr r2, [r6, #0x48]
mov r7, #0x2c
ldsh r3, [r6, r7]
mov r7, #0x2e
ldsh r0, [r6, r7]
str r0, [sp, #0x0]
mov r0, #0x1
ldr r7,=#0x8013508+1
bl call7
lsl r0, r0, #0x10
lsr r0, r0, #0x18
ldr r2, =#0x80C0E98
lsl r1, r0, #0x1
add r1, r1, r2
add r0, #0x40
lsl r0, r0, #0x1
add r0, r0, r2
mov r2, #0x0
ldsh r1, [r1, r2]
lsl r4, r4, #0x10
asr r4, r4, #0x10
mul r1, r4
lsl r1, r1, #0x4
mov r7, #0x0
ldsh r0, [r0, r7]
mul r0, r4
lsl r0, r0, #0x4
asr r1, r1, #0x10
ldrh r2, [r6, #0x32]
add r1, r2, r1
asr r0, r0, #0x10
ldrh r7, [r6, #0x3a]
add r0, r7, r0
strh r1, [r5, #0x2]
strh r0, [r5, #0x4]
ldrh r0, [r6, #0x2c]
add r0, #0x1
strh r0, [r6, #0x2c]
lsl r0, r0, #0x10
ldrh r2, [r6, #0x2e]
lsl r1, r2, #0x10
cmp r0, r1
ble loc_53752
ldr r0, [r6, #0x60]
ldr r7,=#0x80064E0+1
bl call7
ldr r1, =#0x201774C
ldr r0, [r1, #0x0]
sub r0, #0x1
str r0, [r1, #0x0]
add r0, r6, #0x0
ldr r7,=#0x800457C+1
bl call7
loc_53752:
add sp, #0x4
pop {r4-r7}
pop {r0}
bx r0
call7:
bx r7
.end

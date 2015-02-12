	.file	"rot.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
	.type	rota, @function
rota:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	in r24,0x9
	mov r25,r24
	andi r25,lo8(8)
	sbrs r24,3
	rjmp .L3
	cpi r25,lo8(8)
	brne .L6
	lds r24,rin
	lds r25,rin+1
	sbiw r24,1
	sts rin+1,r25
	sts rin,r24
	cpi r24,-23
	sbci r25,3
	brlo .L1
	ldi r24,lo8(-25)
	ldi r25,lo8(3)
	sts rin+1,r25
	sts rin,r24
.L1:
	ret
.L6:
	ret
.L3:
	lds r24,rin
	lds r25,rin+1
	adiw r24,1
	sts rin+1,r25
	sts rin,r24
	lds r20,rin
	lds r21,rin+1
	movw r18,r20
	lsr r19
	ror r18
	lsr r19
	ror r18
	lsr r19
	ror r18
	ldi r26,lo8(-59)
	ldi r27,lo8(32)
	call __umulhisi3
	swap r25
	swap r24
	andi r24,0x0f
	eor r24,r25
	andi r25,0x0f
	eor r24,r25
	ldi r22,lo8(-24)
	ldi r23,lo8(3)
	mul r24,r22
	movw r18,r0
	mul r24,r23
	add r19,r0
	mul r25,r22
	add r19,r0
	clr r1
	movw r24,r20
	sub r24,r18
	sbc r25,r19
	sts rin+1,r25
	sts rin,r24
	ret
	.size	rota, .-rota
.global	rot_setup
	.type	rot_setup, @function
rot_setup:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	in r24,0xa
	andi r24,lo8(12)
	out 0xa,r24
	ldi r20,lo8(2)
	ldi r21,0
	ldi r22,lo8(gs(rota))
	ldi r23,hi8(gs(rota))
	ldi r24,0
	jmp attachInterrupt
	.size	rot_setup, .-rot_setup
.global	rot_loop
	.type	rot_loop, @function
rot_loop:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	ret
	.size	rot_loop, .-rot_loop
.global	get_number
	.type	get_number, @function
get_number:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	lds r24,rin
	lds r25,rin+1
	ret
	.size	get_number, .-get_number
.global	reset_number
	.type	reset_number, @function
reset_number:
/* prologue: function */
/* frame size = 0 */
/* stack size = 0 */
.L__stack_usage = 0
	sts rin+1,__zero_reg__
	sts rin,__zero_reg__
	ret
	.size	reset_number, .-reset_number
	.local	rin
	.comm	rin,2,1
	.ident	"GCC: (GNU) 4.9.2 20141224 (prerelease)"
.global __do_clear_bss

	section	.text
	global	_start
_start:
;;;  multiply example. change out mul for imul - what happens? why?
	mov	eax, -1
	mov	ebx, 2
	mov	edx, 0x11223344
	mul	ebx

;;; divide example
	mov	eax, 127
	mov	ebx, 10

;;;  set up edx before doing div
	mov	edx, 0
	div	ebx

;;; signed divide example
	mov	eax, -127
	mov	ebx, 10

;;;  set up edx before doing div
	cdq
	idiv	ebx
	
	;; exit to linux
	mov	rax, 1
	mov	rbx, 0
	int 	0x80

	

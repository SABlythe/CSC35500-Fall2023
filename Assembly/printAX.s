	section .data
negSignString:		db	'-'
	section	.text
	global	printAX
	extern 	printDigit
printAX:
	push 	rax
	push 	rbx
	push 	rcx
	push 	rdx

	;;  check if number is negative ...
	cmp	ax, 0
	jge	printPos

	push	rax
	;; we have a negative number. print a '-' and negate number 
	mov	eax, 4
	mov	ebx, 1
	mov	ecx, negSignString
	mov	edx, 1
	int	0x80
	pop 	rax

	neg	ax
	
printPos:	
	mov	rcx, 0
doDigit:
	mov	bx, 0xa
	mov	dx, 0  		;set up div to work and do only ax/bx
	div	bx		; quotient now in ax, remainder in dx

	push	rdx		; push next digit onto stack
	inc	rcx

	cmp	ax, 0
	jne	doDigit

nextDigit:
	pop	rax
	call	printDigit

	dec	rcx
	cmp	rcx, 0
	jne	nextDigit

	
	pop 	rdx
	pop 	rcx
	pop 	rbx
	pop 	rax
	
	ret

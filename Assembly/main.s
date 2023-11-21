	section	.text
	extern 	printAX
	extern	printNL
	global	_start
_start:
	mov	rax, -100
myLabel:
	call	printAX
	call	printNL

	inc	rax
	cmp	rax, 0x100  	; 16
	jl	myLabel

	;; clean up and go back to Linux
	mov	eax, 1
	mov	ebx, 0
	int 	0x80

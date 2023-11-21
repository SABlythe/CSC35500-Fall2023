		section	.data
nlstring:	db	0xa

	section	.text
	global	printNL

printNL:
	push 	rax
	push 	rbx
	push 	rcx
	push 	rdx
	
	mov	rax, 4
	mov	rbx, 1
	mov	rcx, nlstring
	mov	rdx, 1
	int	0x80

	pop 	rdx
	pop 	rcx
	pop 	rbx
	pop 	rax
	
	ret

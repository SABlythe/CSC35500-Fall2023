	section	.data
prompt:	db	'Enter a string: '
buffer:	resb	100

	section	.text
	global	_start
_start:	
	;;  print prompt
	mov 	rax, 4
	mov	rbx, 1
	mov	rcx, prompt
	mov	rdx, buffer-prompt
	int 	0x80

	;; read string into buffer
	mov	rax, 3
	mov	rbx, 0
	mov	rcx, buffer
	mov	rdx, 100
	int	0x80

;;;  when linux "returns" to our code, it stores count of characters read into rax
	
	;;  print contents of buffer
	mov	rdx, rax
	mov 	rax, 4
	mov	rbx, 1
	mov	rcx, buffer
	int 	0x80

	
	;; exit to linux
	mov	rax, 1
	mov	rbx, 0
	int 	0x80

	

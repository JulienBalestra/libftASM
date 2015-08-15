section .text
	global ft_isspace

ft_isspace:
	cmp		rdi, 32
	je		true
	cmp		rdi, 9
	je		true
	cmp		rdi, 10
	je		true
	cmp		rdi, 11
	je		true
	cmp		rdi, 12
	je		true
	cmp		rdi, 13
	je		true
	jmp		false

true:
	mov		rax, 1
	ret

false:
	mov		rax, 0
	ret
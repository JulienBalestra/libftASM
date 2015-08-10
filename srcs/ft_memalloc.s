extern malloc
extern ft_bzero

section	.text
	global ft_memalloc

section .text

ft_memalloc:
	push rbp
	mov rbp, rsp
	sub rsp, 0x10

	test rdi, rdi
	jz ret_null

	mov [rbp - 0x8], rdi
	call malloc
	test rax, rax
	jz ret_null

	mov rdi, rax
	mov rsi, [rbp - 0x8]
	mov [rbp - 0x10], rax
	call ft_bzero
	mov rax, [rbp - 0x10]
	jmp done

ret_null:
	xor rax, rax

done:
	mov rsp, rbp
	pop rbp
	ret
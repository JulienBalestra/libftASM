global ft_puts

%ifdef OSX
	%define WRITE 0x2000004
%elif LINUX
	%define WRITE 1
%endif

extern ft_strlen
default rel ; support 32-bit absolute addresses

section .data
endline: db 0x0a
nullMsg: db "(null)", 10, 0

segment .text
ft_puts:
	cmp rdi, 0
	je null
	call ft_strlen
	mov rdx, rax
	mov rcx, rdi
	mov rax, WRITE
	mov rdi, 1
	mov rsi, rcx
	syscall
	jc abort
	jmp good_ndl

good_ndl:
	mov rax, WRITE
	mov rdi, 1
	lea rsi, [endline]
	mov rdx, 1
	syscall
	mov rax, 42
	ret

null:
	mov rax, WRITE
	mov rdi, 1
	lea rsi, [nullMsg]
	mov rdx, 7
	syscall
	lea rsi, [endline]
    mov rdx, 1
    syscall
    mov rax, -1
    ret

abort:
	ret
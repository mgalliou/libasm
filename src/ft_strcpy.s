bits 64

section .text
	global _ft_strcpy

_ft_strcpy:
	push rbp
	mov  rbp, rsp

	mov rax, rdi
	cld
.loop:
	movsb
	cmp byte [rdi - 1], 0
	loopne .loop

	leave
	ret

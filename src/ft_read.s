SYS_read equ 0x02000003

section .text
	global _ft_read

_ft_read:
	push rbp
	mov  rbp, rsp

	push rax
	mov  rax, SYS_read
	syscall

	pop rax
	leave
	ret

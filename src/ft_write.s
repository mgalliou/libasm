SYS_write  equ 0x02000004

section .text
	global _ft_write

_ft_write:
	push rbp
	mov  rbp, rsp

	mov  rax, SYS_write
	syscall

	leave
	ret

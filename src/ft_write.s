SYS_write  equ 0x02000004

section .text
	global _ft__write

_ft__write:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	push rax
	mov  rax, SYS_write
	syscall

	pop rax
	leave
	ret

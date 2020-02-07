bits 64

SYS_read equ 0x02000003

section .text
	global _ft__write

_ft__write:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	push rax
	mov rax, SYS_read ;print first board
	syscall

	pop rax
	leave
	ret
	

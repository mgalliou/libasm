bits 64

section .text
	global _ft__strcpy

_ft__strcpy:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	xor rcx, rcx ; zero rcx
.loop:
	movzx rax, byte [rsi + rcx] ; put in rcx byte to be copied
	mov   byte [rdi + rcx], al  ; cpy byte to dst
	inc   rcx                   
	test  al, al ; if copied byte is not zero continue
	jne   .loop

	mov rax, rdi
	leave
	ret

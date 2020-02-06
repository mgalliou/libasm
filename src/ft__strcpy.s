bits 64

section .text
	global _ft__strcpy

_ft__strcpy:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	mov  rax, rsi ;save dst str ptr
.loop:
	cmp byte [rsi], ''
	jz  .done ; if byte of zeroed jump out of the loop
	mov rbx, [rsi] ; copy src str to tmp register
	mov [rdi], rbx ; copy tmp register to dst str
	inc rdi        ; increment dst ptr
	inc rsi        ; increment src ptr
	jmp .loop

.done:
	leave
	ret

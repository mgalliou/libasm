bits 64

section .text
	global _ft__strlen


_ft__strlen:
	push rbp      ;init scope
	mov rbp, rsp

	mov rax, 0    ;init len
.inc:
	cmp byte [rdi], ''
	jz .done
	inc rdi
	inc rax
	jmp .inc
	
.done:
	pop rbp
	ret


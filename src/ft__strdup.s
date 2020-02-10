bits 64

section .text
	global _ft__strdup
	extern _malloc
	extern _ft__strlen
	extern _ft__strcpy

_ft__strdup:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	mov  rbx, rdi ; save ptr on str to be dup
	call _ft__strlen
	inc  rax ; inc len for terminating null
	mov  rdi, rax
	call _malloc
	test rax, rax
	jz   .done ; leave if malloc returned null
	mov  rdi, rax
	mov  rsi, rbx
	leave
	jmp _ft__strcpy

.done:
	leave
	ret

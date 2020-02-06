bits 64

section .text
	global _ft__strcmp

_ft__strcmp:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	xor rax, rax
	xor rbx, rbx
.loop:
	mov rax, rdi
	mov rbx, rsi
	cmp byte di, ''
	je .done
	cmp al, bl
	jne  .done ; if byte of zeroed jump out of the loop
	inc rdi        ; increment dst ptr
	inc rsi        ; increment src ptr
	jmp .loop

.done:
	sub al, bl
	leave
	ret

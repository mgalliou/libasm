bits 64

section .text
	global _ft__strcmp

_ft__strcmp:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	xor rax, rax ; make sure rax and r11 are zeroed
	xor r11, r11
.loop:
	movzx rax, byte [rdi] ; move param to registers
	movzx r11, byte [rsi] ; //
	cmp al, '' ; check end of str
	je .done   ; jump if byte is null
	cmp al, r11b   ; compare byte
	jne .done      ; if different jump out of the loop
	inc rdi        ; increment dst ptr
	inc rsi        ; increment src ptr
	jmp .loop

.done:
	sub rax, r11
	leave
	ret

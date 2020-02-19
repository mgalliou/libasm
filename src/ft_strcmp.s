bits 64

section .text
	global _ft_strcmp

_ft_strcmp:
	push rbp
	mov  rbp, rsp

	cld ; clear direction flag
.loop:
	movzx rdx, byte [rdi]
	test  rdx, rdx
	jz    .compute_return ; jmp if byte is null
	cmpsb  
	loope .loop           ; loop until bytes are equals
	dec   rdi
	dec   rsi

.compute_return:
	xor rax, rax       ; default return to 0
	cmp dl, byte [rsi]
	je  .done          ; jmp if bytes are equals
	mov rax, 1         ; set return to 1
	cmp dl, byte [rsi]
	jae .done          ; jmp if rdi > rsi
	neg rax            ; else neg return

.done:
	leave
	ret

bits 64

section .text
	global _ft_strcmp

_ft_strcmp:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

.loop:
	movzx rdx, byte [rdi] ; move param to registers
	cmp   rdx, ''
	je    .compute_return ; jump if byte is null
	cmp   dl, byte [rsi]
	jne   .compute_return ; if different jump out of the loop
	inc   rdi             ; increment dst ptr
	inc   rsi             ; increment src ptr
	jmp   .loop

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

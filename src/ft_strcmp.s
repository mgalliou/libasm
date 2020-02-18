bits 64

section .text
	global _ft_strcmp

_ft_strcmp:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

.loop:
	movzx rdx, byte [rdi] ; move param to registers
	movzx rcx, byte [rsi] ; //
	cmp   rdx, ''   ; check end of str
	je    .compute  ; jump if byte is null
	cmp   dl, cl    ; compare byte
	jne   .compute  ; if different jump out of the loop
	inc   rdi       ; increment dst ptr
	inc   rsi       ; increment src ptr
	jmp   .loop

.compute:
	xor   rax, rax  ; default return to 0
	cmp   rdx, rcx
	je    .done     ; jmp if str equal
	mov   rax, 1    ; set return to 1
	cmp   rdx, rcx  
	jae   .done     ; jmp if rdi > rsi
	neg   rax       ; else neg return


.done:
	leave
	ret

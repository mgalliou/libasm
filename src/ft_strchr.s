bits 64

section .text
	global _ft_strchr

_ft_strchr:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	xor rax, rax
	xor rbx, rbx
	dec rdi
.loop:
	inc   rdi
	movzx rbx, byte [rdi]
	test  bl, bl
	jz    .notfound
	cmp   rbx, rsi
	jne   .loop
	
;.end_loop:
;	cmp [rdi], rsi
;	je  .found
;	xor rax, rax
;	mov rax, rax

.notfound:
	mov rax, rax
	leave
	ret

.exit:
	leave
	ret

bits 64

section .text
	global _ft_strchr

_ft_strchr:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

	movzx rcx, sil  ; save char to find

.loop:
	movzx rax, byte [rdi]
	cmp   al, 0 
	jz    .endofstr
	cmp   al, cl
	je    .found
	inc   rdi
	jmp   .loop

.endofstr:
	cmp al, cl
	je  .found
	jmp .notfound

.found:
	mov rax, rdi
	jmp .exit

.notfound:
	xor rax, rax
	jmp .exit

.exit:
	leave
	ret

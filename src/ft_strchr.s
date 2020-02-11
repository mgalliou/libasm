bits 64

section .text
	global _ft_strchr

_ft_strchr:
	push rbp
	mov  rbp, rsp
	sub  rsp, 16

.loop:
	movzx rax, byte [rdi] ; save cur byte
	cmp   al, 0      
	jz    .endofstr       ; jmp if cur byte is terminating null
	cmp   al, sil
	je    .found          ; jmp if cur byte is char to find
	inc   rdi             ; increment cur byte addr
	jmp   .loop

.endofstr:
	cmp al, sil ; check if char to find is null
	je  .found
	jmp .notfound

.found:
	mov rax, rdi ; set cur byte  to return reg
	jmp .exit

.notfound:
	xor rax, rax ; zero return register
	jmp .exit

.exit:
	leave
	ret

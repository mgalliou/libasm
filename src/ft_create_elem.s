bits 64

%include "libasm.s"

section .text
	global _ft_create_elem
	extern _malloc

_ft_create_elem:
	push rbp
	mov  rbp, rsp
	sub  rsp, 8
	push rbx

	mov  rbx, rdi
	mov  rdi, t_list_size
	call _malloc
	cmp  rax, 0
	je   .failed            ;jmp if malloc failed
	mov  rdi, rbx
	mov  qword [rax], rdi
	mov  qword [rax + 8], 0
	jmp  .done
	
.failed:
	xor  rax, rax
.done:
	pop  rbx
	leave
	ret

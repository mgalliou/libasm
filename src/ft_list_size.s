bits 64

%include "libasm.s"

section .text
	global _ft_list_size

_ft_list_size:
	push rbp
	mov  rbp, rsp
	
	mov  rax, 0
.loop:
	cmp  rdi, 0
	je   .done
	inc  rax
	mov  rdi, [rdi + t_list.next]
	jmp  .loop
	
.done:
	leave
	ret 

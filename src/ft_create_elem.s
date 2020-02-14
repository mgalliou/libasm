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

	mov  rbx, rdi         ; save ptr on data 
	mov  rdi, t_list_size ; prepare malloc call
	call _malloc
	cmp  rax, 0
	je   .failed          ; jmp if malloc failed

	mov  qword [rax + t_list.data], rbx ; make new_elem->data point on data
	mov  qword [rax + t_list.next], 0   ; make new_elem->next point on NULL
	jmp  .done
	
.failed:
	xor  rax, rax

.done:
	pop  rbx
	leave
	ret

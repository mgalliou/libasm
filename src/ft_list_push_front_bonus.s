%include "t_list_bonus.s"

section .text
	global _ft_list_push_front
	extern _ft_create_elem

_ft_list_push_front:
	push rbp
	mov  rbp, rsp
	sub  rsp, 8
	push rbx

	mov  rbx, rdi        ; save ptr on list beg addr
	mov  rdi, rsi        ; prepare ft_create_elem call with data ptr
	call _ft_create_elem
	test rax, rax
	jz   .done           ; jmp if ft_create_elem failed

	mov  rdi, [rbx]
	mov  [rax + t_list.next], rdi ; make new_elem->next point on list beg
	mov  [rbx], rax               ; make list beg ptr point on new elem

.done:
	pop rbx
	leave
	ret

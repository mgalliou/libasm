bits 64

section .text
	global _ft_list_sort

%include "libasm.s"

_ft_list_sort:
	push rbp
	mov  rbp, rsp
	sub  rsp, 8
	push rbx
	;push r12
	;push r13
	;push r14

	cmp rsi, 0
	je  .done       ; jmp if cmp is null
	cmp rdi, 0
	je  .done       ; jmp if addr of beg list ptr is null
	mov rbx, [rdi]  ; save list beg ptr in tmp reg
	cmp rbx, 0
	je  .done       ; jmp if beg list ptr is null
	;mov r14, rbx    ; save list beg ptr
	;mov r12, rsi    ; save ptr on cmp

;.loop:
	cmp qword [rbx + t_list.next], 0
	je  .done ; jmp if cur->next is null

	;mov  rdi, [rbx + t_list.data]
	;mov  rsi, [rcx + t_list.data]
	;push rsi
	;call r12
	;pop  rsi
	;cmp  rax, 0
	;jne  .swap_data
	;mov  rbx, [rbx + t_list.next] ; mov next ptr to cur ptr
	;jmp  .loop

.swap_data:
	mov rax, [rbx + t_list.next] ; save ptr on next elem
	mov rcx, [rbx + t_list.data] ; save ptr on cur elem data
	mov rdi, [rax + t_list.data] ; save ptr on next elem data
	mov [rbx + t_list.data], rdi ; move next elem data to cur data
	mov [rax + t_list.data], rcx ; move cur data to next elem data 
	;mov rbx, r14 ; mov cur ptr to beg list ptr
	;jmp .loop


.done:
	;pop r14
	;pop r13
	;pop r12
	pop rbx
	leave
	ret

bits 64

%include "libasm.s"

section .text
	global _ft_list_remove_if
	extern _free

_ft_list_remove_if:
	push rbp
	mov  rbp, rsp
	sub  rsp, 8
	push rbx
	push r12
	push r13
	push r14
	push r15
	xor  rax, rax
	push rax

	cmp rdi, 0
	je  .done      ; jmp if begin list addr is null
	cmp rdx, 0
	je  .done      ; jmp if cmp is null
	cmp rcx, 0
	je  .done      ; jmp if free_fct is null
	mov rbx, [rdi] ; get ptr to first elem
	mov r12, rdi   ; save list beg ptr addr
	mov r13, rsi   ; save data_ref
	mov r14, rdx   ; save cmp
	mov r15, rcx   ; save free_fct

.loop:
	cmp  rbx, 0
	je   .done                    ; jmp if cur elem is null
	mov  rdi, [rbx + t_list.data]
	mov  rsi, r13
	call r14                      ; call cmp
	cmp  rax, 0
	jne  .next                    ; jmp if cmp returned 0
	mov  rdi, [rbx + t_list.data]
	call r15                      ; call free_fct

	cmp  rbx, [r12]
	jne  .skip_beg_swap ; if cur elem equal beg list, point beg list to cur->next
	mov  rax, [rbx + t_list.next]
	mov  [r12], rax 

.skip_beg_swap:
	mov  rax, [rbx + t_list.next]
	push rax
	mov  rdi, rbx
	call _free
	pop  rax
	mov  rbx, rax
	pop  rax
	cmp  rax, 0
	je   .skip_prev_link
	mov  [rax + t_list.next], rbx
.skip_prev_link:
	push rax
	jmp  .loop

.next:
	mov rbx, [rbx + t_list.next]
	jmp .loop
	
.done:
    pop rax
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbx
	leave
	ret
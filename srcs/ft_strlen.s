section .text
		global ft_strlen

ft_strlen:
		mov		rax, 0				; rax = 0

.loop:
		cmp		byte[rdi + rax], 0	; check end of str (str[rax] == 0)
		je		.end				; jump to end if end of str
		inc		rax					; rax++
		jmp		.loop

.end:
		ret
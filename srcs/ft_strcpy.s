section .text
		global ft_strcpy

ft_strcpy:
		mov		rax, 0					; rax = 0

.loop:
		cmp		byte[rsi + rax], 0		; compare s1[rax] and 0
		je		.end					; end if = 0
		mov		cl, byte[rsi + rax]		; cl[rax] = s1[rax]
		mov		byte[rdi + rax], cl		; s2[rax] = cl[rax]
		inc		rax						; rax++
		jmp		.loop

.end:
		mov		byte[rdi + rax], 0		; s2[rax] = \0
		mov		rax, rdi				; s2 = dst
		ret
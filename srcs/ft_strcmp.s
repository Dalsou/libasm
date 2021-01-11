section .text
		global ft_strcmp

ft_strcmp:
		mov		rax, 0					; rax = 0
		mov		rcx, 0					; rcx = 0
		mov		rdx, 0					; rdx = 0

.loop:
		mov		al, byte[rdi + rdx]		; al = s1[rdx]
		mov		cl, byte[rsi + rdx]		; cl = s2[rdx]
		cmp		al, 0					; compare al and 0
		je		.end					; end if = 0
		cmp		cl, al					; compare cl and al 
		jne		.end					; end if != 0
		inc		rdx						; rdx++
		jmp		.loop
		
.end:
		sub		rax, rcx				; compare value
		ret
.code

asm_03_04_01 PROC
	cmp rcx, 0
	jz _case0
	cmp rcx, 1
	jz _case1
	jmp _default
_case0:
	mov rax, 10
	jmp _end
_case1:
	mov rax, 20
	jmp _end
_default:
	mov rax, 30
_end:
	ret


asm_03_04_01 ENDP

END
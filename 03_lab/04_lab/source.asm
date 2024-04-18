.code

asm02_01 PROC
	xor rax,rax
	add cl, dl
	mov al, cl
	mov bl, 7
	mul bl
	mov bl,5
	CBW
	idiv bl
	ret
asm02_01 ENDP

asm04_01 PROC
	xor eax, eax
	movsxd rdx, edx
_loop:
	add eax, dword ptr [rcx+4*rdx-4]
	dec rdx
	jnz _loop
	ret
asm04_01 ENDP

asm04_02 PROC
	mov eax, 1
	movsxd rdx, edx
_loop:
	mov r8d, dword ptr [rcx+4*rdx-4]
	imul eax, r8d
	dec rdx
	jnz _loop
	ret
asm04_02 ENDP

asm04_08 PROC
	xor eax, eax
	movsxd rdx, edx
_loop:
	mov r8d, dword ptr [rcx+4*rdx-4]
	sal r8d, 4
	add eax, r8d
	add eax, 6
	dec rdx
	jnz _loop
	ret
asm04_08 ENDP

asm05_03 PROC
	xor rax, rax
	movsxd r9, r9d
_loop:
	mov rax, qword ptr [rcx + 8 * r9 - 8]
	mov ebx, dword ptr [rdx + 4 * r9 - 4]
	movsxd rbx, ebx
	add rax, rbx
	mov ebx, dword ptr [r8 + 4 * r9 - 4]
	movsxd rbx, ebx
	add rax, rbx
	mov qword ptr [rcx + 8 * r9 - 8], rax
	dec r9
	jnz _loop
	ret

asm05_03 ENDP

END
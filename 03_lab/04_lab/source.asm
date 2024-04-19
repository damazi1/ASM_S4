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

asm02_02 PROC
	xor rax,rax
	add cx, dx
	imul cx, 7
	movsx rax, cx
	cqo
	mov r8, 5
	idiv r8
	ret
asm02_02 ENDP


asm04_01 PROC
	xor eax, eax
	movsxd rdx, edx
_loop:
	add eax, dword ptr [rcx+4*rdx-4]
	dec rdx
	jne _loop
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

asm04_10 PROC
	xor rax, rax
	movsxd rdx, edx
_loop:
	mov r8w, word ptr [rcx+2*rdx-2]
	shr r8w, 1
	jc _skip
	inc rax
_skip:
	dec rdx
	jne _loop
	ret
asm04_10 ENDP

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
;rcx <= wynik
;rdx <= vector<a>
;r8 <= vecotr<b>
;r9 <= index

asm05_06 PROC	USES rbx
	movsxd r9, r9d
	mov r10, rdx
_loop:
	mov ax, word ptr[r10+2*r9-2]
	mov bx, word ptr[r8+2*r9-2]
	movsx eax, ax
	movsx ebx, bx
	cdq
	idiv ebx
	mov dword ptr [rcx+4*r9-4], edx
	dec r9
	jne _loop
	ret
asm05_06 ENDP

asm05_08 PROC
	movsxd rdx, edx
_loop:
	mov r8, rdx
	shr r8, 1
	jc _skip
	mov dword ptr [rcx+4*rdx-4], 0
_skip:
	dec rdx
	jne _loop
	ret
asm05_08 ENDP

END
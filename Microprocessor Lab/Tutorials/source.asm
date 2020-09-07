section .data

section .text

; Function Call: stats(arr,len,&sum);
;  Arguments Passed: 
; - rdi - address of array 
; - rsi - length of passed array 
; - rdx - address of variable for sum 

;  Returns: The value of arr[0]+arr[1]+arr[2]-arr[3] in integer "sum" (via reference) 

	
	global stats
	stats:
        	push r12
		mov r12d,0
		mov eax, dword[rdi]
        	add r12d,eax
		mov eax, dword[rdi+4]
		add r12d, eax
		mov eax, dword[rdi+8]
		add r12d, eax
		mov eax, dword[rdi+12]
		sub r12d, eax
		mov dword[rdx],r12d
		pop r12
		syscall
		ret
	last:
		mov rax,60
		mov rdi,0
		syscall

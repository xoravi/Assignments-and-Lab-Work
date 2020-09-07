;Name: Ravi Sahni
;Faculty No.: 17 COB 085
;Enrol. No.: GJ 7718
;Serial No.: 24
;Objective: Compute a+b+c-d where a,b,c and d are integers. Take the integer inputs in a C/C++ program
;and perform the required operation in a subroutine in assembly language.

;Compilation Instructions (Ubuntu):
; $ nasm -felf64 func.asm
; $ g++ -c main.cpp
; $ g++ -o outfile func.o main.o
; $ ./outfile

section .text

;	Function to perform (a + b + c - d) 
;	Call: 
;		sum_sub(a, b, c, d); 
;  	Arguments Passed: 
; 		1) edi - integer a 
; 		2) esi - integer b 
; 		3) edx - integer c
; 		4) ecx - integer d
;  Returns: 
; 		- Value of (a + b + c - d) through eax register.

global sum_sub
sum_sub:
	mov eax, edi
	add eax, esi
	add eax, edx
	sub eax, ecx
	ret

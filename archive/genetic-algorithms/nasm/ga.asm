;name: ga.asm
;desciption: genetic algorithm to sole the equation
;            a + 2b = 75
;build: nasm -felf64 ga.asm -o ga.o && ld -melf_x86_64 -o ga ga.o
;
;08/09/2021 : start of program no avx

bits 64
[list -]
    %include "unistd.inc"
    %define CHROMOSOMES 10              ;10 chromosomes in a population
    %define GENES       2               ;2 genes a en b
[list +]

section .bss
    parent:     resq    1               ;start of heapmemory parent population
    offspring:  resq    1               ;start of heapmemory for offspring population
    
section .rodata

section .data

section .text
global _start

_start:
    ;create heap space for our parent population
    syscall brk,0              ;get heap address
    mov qword[parent],rax       ;store start of heap memory
    mov rdi,rax                 ;start of heap in rdi
    add rdi,CHROMOSOMES*GENES   ;memory needed
    
    syscall brk,rdi            ;reserve memory
    and rax,rdi
    js  .error                  ;if sign bit is set then error
    xor rax,rdi                 ;if zero all is fine
    jnz .error                  ;if not zero then error
    
    ;create heap space for our offspring population
    syscall brk,0
    mov qword[offspring],rax    ;save begin of 
    
    mov rdi,rax                 ;start of heap in rdi
    add rdi,CHROMOSOMES*GENES   ;memory needed
    
    syscall brk,rdi            ;reserve memory
    and rax,rdi
    js  .error                  ;if sign bit is set then error
    xor rax,rdi                 ;if zero all is fine
    jnz .error                  ;if not zero then error
    
    mov rax,qword[parent]
    mov byte[rax],0xFF
    add rax,CHROMOSOMES*GENES
    dec rax
    mov byte[rax],0xAA
    
    mov rax,qword[offspring]
    mov byte[rax],0xEE
    add rax,CHROMOSOMES*GENES
    dec rax
    mov byte[rax],0xBB
    ;the next can be done in one move, here I do it in two moves
    ;to have a bit more control
    ;release offspring memory, beware of the possibility that the memory contents are still available
    
    syscall brk,qword[offspring]
    
    ;release parent memory
    syscall brk,qword[parent]
    
    
.error:                         ;just exit for now
    syscall exit,0              ;terminate program

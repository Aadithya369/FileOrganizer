section .data
    numbers db 10, 20, 30, 40, 50 ; Array of numbers
    size db 5                      ; Size of the array
    sum db 0                       ; To store the sum
    average db 0                   ; To store the average

section .bss
    result resb 20                 ; Buffer for result display

section .text
    global _start

_start:
    ; Initialize registers
    xor eax, eax                   ; Clear EAX (sum)
    xor ecx, ecx                   ; Clear ECX (index)

calculate_sum:
    cmp ecx, [size]                ; Compare index (ECX) with size
    jge calculate_average           ; Jump if ECX >= size

    ; Load number into AL and add to sum
    movzx ebx, byte [numbers + ecx] ; Load number into EBX (zero-extend)
    add eax, ebx                    ; Add number to sum
    inc ecx                         ; Increment index
    jmp calculate_sum               ; Repeat loop

calculate_average:
    mov [sum], al                  ; Store the sum in memory

    ; Calculate the average
    cmp ecx, 0                     ; Check if size is not zero
    je end_program                 ; If size is zero, skip average calculation

    ; Divide sum by size
    movzx ebx, byte [size]         ; Load size into EBX
    xor edx, edx                   ; Clear EDX for division
    mov al, [sum]                  ; Move sum into AL
    div bl                         ; Divide AL by BL (size), quotient in AL

    ; Store average
    mov [average], al              ; Store the average in memory

end_program:
    ; Exit the program
    mov eax, 1                     ; syscall: exit
    xor ebx, ebx                   ; exit code 0
    int 0x80                       ; call kernel



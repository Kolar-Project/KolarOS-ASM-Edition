BITS 16
;------------------------------------------
jmp boot

;GreenSoupDev, mail: greensoupdev@gmail.com

;KolarOS Coralriff - Codename ASM Edition
;
;Copyright 2022 - 2023 C The Kolar Project Organization.
;
;All rights reserved.

boot:
    mov [BOOT_DISK], dl
	mov ax, 07C0h		; set up 4k stack space after this bootloader
	add ax, 288		; (4096 + 512) / 16 bytes per paragraph
	mov ss, ax
	mov sp, 4096

	mov ax, 07C0h		; set data segment to where were loaded
	mov ds, ax


	mov si, welcome_msg	; put string position into SI

	call print_string	; pall the string-printing routine

    mov [BOOT_DISK], dl

  
 
    welcome_msg  db "+------------------------------------------------------------------------------+", 0Dh,0Ah ; main massage
	db "|  Welcome to KolarOS Coralriff                                                |", 0Dh,0Ah
	db "|                                                                              |", 0Dh,0Ah
    db "|  Version Alpha 0.0.30 - Build 05062023                                       |", 0Dh,0Ah
    db "|  Codename 'Caribe'                                                           |", 0Dh,0Ah
	db "|  (C)2023 The Kolar Project Organization. All rights reserved.                |", 0Dh,0Ah
	db "|  This is a alpha version, you should be aware of the errors.                 |", 0Dh,0Ah
	db "|  CHANGELOG: (GreenSoupDev)                                                   |", 0Dh,0Ah
	db "|  i'm just trying to make the compiling more easyer than before.              |", 0Dh,0Ah
	db "|  and hello there fella.                                                      |", 0Dh,0Ah
    db "+------------------------------------------------------------------------------+", 0Dh,0Ah
	db "", 0Dh,0Ah
	db "[CALL] Calling 'ReadDisk' sector...", 0Dh,0Ah
	
    call ReadDisk

	 
	 

ReadDisk: ;the readdisk sh#t, idk if it works cuz idk asm, i prefeer C, and C++
 
    mov ah, 0x02
	mov bx, 0x8000
	mov al, 4
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 2

	int 13h
	jnc DiskReadOkString

	jc DiskReadFailed

	


	ret

	

DiskReadErrorString: ;error
db "[ERROR] Disk Read Failed", 0

DiskReadOkString: ;ok
db "[OK] Disk Read Successfull", 0

DiskReadFailed: ;fail
	mov si, DiskReadErrorString

BOOT_DISK: ;mi
	db 0
	
   
    



print_string:			; routine: output string in si to screen
	mov ah, 0Eh		; int 10h 'print char' function

.repeat:
	lodsb			; get character from string
	cmp al, 0
	je .done		; if char is zero, end of string
	int 10h			; otherwise, print it
	jmp .repeat

.done:
	ret

int 10h
times 9999-($-$$) db 0
dw 0xAA55


	
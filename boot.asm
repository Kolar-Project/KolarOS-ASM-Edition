bits 16
org 0x7c00
;------------------------------------------
jmp boot

BootPrint:
 lodsb
 
 or al, al
 jz .done
 mov ah, 0eh
 int 10h
 jmp BootPrint

 .done:
  ret

boot:
mov [BOOT_DISK], dl

mov bp, 0x7c00
mov sp, bp

call ReadDisk

jmp 0x8000

ReadDisk:
	
	mov ah, 0x02
	mov bx, 0x8000
	mov al, 4
	mov dl, [BOOT_DISK]
	mov ch, 0x00
	mov dh, 0x00
	mov cl, 2

	int 13h

	jc DiskReadFailed

	ret

BOOT_DISK:
	db 0

DiskReadErrorString:
	db 'Disk Read Failed',0

DiskReadFailed:
	mov si, DiskReadErrorString
	call BootPrint

mov ah, 0eh
int 10h


;------------------------------------------
times 510-($-$$) db 0
dw 0xAA55
%include "stage2.asm"
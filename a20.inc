;credit to theMike97 for this a20 controller
testA20:

pusha

mov ax, [0x7dfe]  ; 7dfe = 7c00+510 (memory location of magic number)
                  ; create a reference to check for wrapping
; set es to zero
push bx
mov bx, 0xffff
mov es, bx
pop bx

mov bx, 0x7e0e    ; set offset to 0x7e0e

mov dx, [es:bx]   ; print the contents located in the segment

cmp ax, dx        ; compare the segment to the reference
je .cont          ; if (ax == dx) {jmp to .cont}

popa              ; else { popa
mov ax, 1         ; set ax to 1 as a return value
ret               ; return }


; for this section, do the same as what was done above
; except shift the reference (and thus the offset) location
; one byte for confirmation

.cont:
mov ax, [0x7dff]

push bx
mov bx, 0xffff
mov es, bx
pop bx

mov bx, 0x7e0f
mov dx, [es:bx]

cmp ax, dx      ; if (ax == dx) {exit}
je .exit

popa
mov ax, 1       ; else {...}
ret

.exit:
popa
xor ax, ax      ; set ax to 0 as return value
ret

enableA20:
pusha


;BIOS
  mov ax, 0x2401 
  int 0x15

  call testA20     ;test to see if BIOS method worked
  cmp ax, 1
  je .done         ;if it did, jump to .done

;Keyboard
  sti

  call waitC        ; wait for controller to accept command
  mov al, 0xad      ; 0xad is the disable keyboard command
  out 0x64, al      ; send the command to port 0x64 (command port)

  call waitC
  mov al, 0xd0      ; 0xd0 is the command that allows us to read from the controller
  out 0x64, al

  call waitD        ; wait for controller data to be ready
  in al, 0x60       ; store data from port 0x60 (data port) in al
  push ax           ; push to the stack for later

  call waitC
  mov al, 0xd1      ; 0xd1 command tells the controller we want to write data to it
  out 0x64, al

  call waitC
  pop ax            ; pop data from stack
  or al, 2          ; mask bit #2
  out 0x60, al      ; send to controller through data port

  call waitC
  mov al, 0xae      ; 0xae enabled the keyboard
  out 0x64, al

  call waitC

  sti

  call testA20
  cmp ax, 1
  je .done

;FastA20
  in al, 0x92       ; read data through port 0x92 (chipset)
  or al, 2          ; mask bit 2
  out 0x92, al      ; send data back to chipset

  call testA20
  cmp al, 1
  je .done

  jmp $

.done:
  popa
  ret

waitC:              ; wait for controller to accept commands
  in al, 0x64       ; get status from command port
  test al, 2        ; is bit2 of al = 1?
                    ; 1 = busy, 0 = ready
  jnz waitC         ; if it is (jump if not equal to zero), try again
  ret

waitD:              ; wait for controller to have data to read
  in al, 0x64       ; get status from command port
  test al, 1        ; is bit1 of al = 1?
                    ; 0 = empty, 1 = full
  jz waitD          ; if data is empty try again (jump if zero)
  ret
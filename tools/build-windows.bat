cd C:\Users\GreenSoup Dev\AppData\Local\bin\NASM

nasm -f bin -o C:/asmkolar/bin/kolar.bin C:/asmkolar/src/boot.asm

nasm -f elf -o C:/asmkolar/bin/kolar.elf C:/asmkolar/src/boot.asm

copy /b C:\asmkolar\bin\kolar.bin c:\asmkolar\bin\kolar.flp

C:\asmkolar\tools\mkisofs.exe -no-emul-boot -boot-load-size 4 -o C:\asmkolar\bin\kolar.iso -b kolar.flp C:/asmkolar/bin/

echo Done!
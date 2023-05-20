nasm -f bin -o C:\asmkolar\kolar.bin C:\asmkolar\boot.asm

copy /b C:\asmkolar\kolar.bin c:\asmkolar\cdiso\kolar.flp


C:\asmkolar\mkisofs.exe -no-emul-boot -boot-load-size 4 -o C:\asmkolar\kolar.iso -b kolar.flp C:/asmkolar/cdiso/
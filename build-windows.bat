cd C:/Users/GreenSoup Dev/AppData/Local/bin/NASM

nasm -f bin -o C:/KolarOS-Coralriff/bin/kolar.bin C:/KolarOS-Coralriff/src/boot.asm

nasm -f elf -o C:/KolarOS-Coralriff/bin/kolar.elf C:/KolarOS-Coralriff/src/boot.asm

copy /b C:\KolarOS-Coralriff\bin\kolar.bin C:\KolarOS-Coralriff\bin\kolar.flp

C:/KolarOS-Coralriff/tools/mkisofs.exe -no-emul-boot -boot-load-size 4 -o C:/KolarOS-Coralriff/bin/kolar.iso -b kolar.flp C:/KolarOS-Coralriff/bin/

echo Done!
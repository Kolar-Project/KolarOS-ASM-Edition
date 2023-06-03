#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("This is a file that will make that changing the paths of the compiling files be easier\n\n");
    char pathreal[100], pathnasmreal[100], path[100], pathtools[100];
    printf("Enter the path where you have the Source Code saved(ex: C:/asmkolar): ");
    scanf("%s", pathreal);
    printf("Enter the path where you have NASM installed(ex: C:/Users/GreenSoup Dev/AppData/Local/bin/NASM): ");
    scanf("%s", pathnasmreal);
    strcat(pathreal, "/bin/");
    strcat(pathtools, pathreal);
    strcat(pathtools, "/tools/");
    FILE *windowsbuild = fopen(strcat(pathtools, "build-windows.bat"), "w");
    fprintf(windowsbuild, "cd %s\n\nnasm -f bin -o %skolar.bin %sboot.asm\n\nnasm -f elf -o %skolar.elf %sboot.asm\n\ncopy /b %skolar.bin %skolar.flp\n\n%s/mkisofs.exe -no-emul-boot -boot-load-size 4 -o %skolar.iso -b kolar.flp %s\n\necho Done!", pathnasmreal, path, path, path, path, path, path, pathtools, path, path);
    fclose(windowsbuild);
    printf("Path's Edited Successfully!");
    return 0;
}

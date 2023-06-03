#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    cout << "This is a file that will make that changing the paths of the compiling files be easier\n" << endl;

    string pathreal;
    cout << "Enter the path where you have the Source Code saved(ex: C:/asmkolar): ";
    cin >> pathreal;

    string pathnasmreal;
    cout << "Enter the path where you have NASM installed(ex: C:/Users/GreenSoup Dev/AppData/Local/bin/NASM): ";
    cin >> pathnasmreal;

    string path = pathreal + "/bin/";
    string pathtools = pathreal + "/tools/";

    ofstream windowsbuild;
    windowsbuild.open(pathtools + "build-windows.bat");

    windowsbuild << "cd " << pathnasmreal << "\n\nnasm -f bin -o " << path << "kolar.bin " << path << "boot.asm\n\nnasm -f elf -o " << path << "kolar.elf " << path << "boot.asm\n\ncopy /b " << path << "kolar.bin " << path << "kolar.flp\n\n" << pathtools << "mkisofs.exe -no-emul-boot -boot-load-size 4 -o " << path << "kolar.iso -b kolar.flp " << path << "\n\necho Done!";
    windowsbuild.close();

    cout << "Path's Edited Successfully!" << endl;

    return 0;
}
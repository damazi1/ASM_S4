#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <iostream>
#include <ctime>
#include "utils.h"
#include "lab04.h"
using namespace std;
extern "C" char asm02_01(char, char);
extern "C" int64 asm02_02(short, short);


extern "C" int asm04_01(int*, uint);
extern "C" int asm04_02(int*, uint);
extern "C" int asm04_08(int*, uint);
extern "C" int asm04_10(short*, uint);
extern "C" void asm05_03(int64*, int*, int*, uint);
extern "C" void asm05_06(int*, short*, short*, uint);
extern "C" void asm05_08(int*, uint);

int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));
    //Zadania ASM_02_xx
    {
        char a = 6, b = 5;
        cout << a << b << endl;
        char yAsm = asm02_01(a, b);
        char yCpp=cpp02_xx<char,char>(a, b);
        resultComparator(yCpp, yAsm);
    }
    {
        short a = 5, b = 10;
        int64 yAsm = asm02_02(a, b);
        int64 yCpp = cpp02_xx<int64, short>(a, b);
        resultComparator(yCpp, yAsm);
    }
    {
        char a = 6, b = 5;
        cout << a << b << endl;
        short yAsm = asm02_01(a, b);
        short yCpp = cpp02_xx<short, char>(a, b);
        resultComparator(yCpp, yAsm);
    }
    const uint n = 10;
    int* a = newFillPtr<int>(n);
    printPtr(a, n);
    freePtr(a);
    {
        int yAsm = asm04_01(a, n);
        int yCpp = cpp04_01<int, int>(a, n);
        resultComparator(yCpp, yAsm);
    }
    {
        const uint nn = 4;
        int* aa = newFillPtr<int>(n);
        printPtr(aa, nn);
        int yAsm = asm04_02(aa, nn);
        int yCpp = cpp04_02<int, int>(aa, nn);
        resultComparator(yCpp, yAsm);

        freePtr(aa);
    }
    //zad04_08
    {
        int yAsm = asm04_08(a, n);
        int yCpp = cpp04_08<int, int>(a, n);
        resultComparator(yCpp, yAsm);
    }
    //zad04_10
    {
        const uint n = 10;
        short* a = newFillPtr<short>(n);
        int yCpp = cpp04_10<int, short>(a, n);
        int yAsm = asm04_10(a, n);
        printPtr(a, n);

        resultComparator(yCpp, yAsm);

        freePtr(a);
    }
    //zad05_03
    {
        const uint n = 10;
        int* a = newFillPtr<int>(n);
        int* b = newFillPtr<int>(n);
        int64* yCpp = newFillPtr<int64>(n, false);
        int64* yAsm = newFillPtr<int64>(n, false);

        printPtr(a, n);
        printPtr(b, n);

        asm05_03(yAsm, a, b, n);
        cpp05_03<int64, int>(yCpp, a, b, n);
        
        printPtr(yAsm, n);
        printPtr(yCpp, n);

        resultComparator(yCpp, yAsm,n);
        freePtr(a);
        freePtr(b);
        freePtr(yCpp);
        freePtr(yAsm);
    }
    //zad05_06
    {
        const uint n = 10;
        short* a = newFillPtr<short>(n);
        short* b = newFillPtr<short>(n);
        int* yCpp = newFillPtr<int>(n, false);
        int* yAsm = newFillPtr<int>(n, false);

        printPtr(a, n);
        printPtr(b, n);

        asm05_06(yAsm, a, b, n);
        cpp05_06<int, short>(yCpp, a, b, n);

        printPtr(yAsm, n);
        printPtr(yCpp, n);

        resultComparator(yCpp, yAsm, n);
        freePtr(a);
        freePtr(b);
        freePtr(yCpp);
        freePtr(yAsm);
    }
    //zad05_08
    {
        const uint n = 10;
        int* a = newFillPtr<int>(n);
        int* b = newCopyPtr<int,int>(a,n);
        printPtr(a, n);
        printPtr(b, n);
        asm05_08(a,n);
        cpp05_08<int>(b, n);
        printPtr(a, n);
        printPtr(b, n);
        resultComparator(b,a,n);

        freePtr(a);
    }
    system("pause");
    return 0;
}
#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <iostream>
#include <ctime>
#include "utils.h"
#include "lab05.h"
using namespace std;

extern "C" int64 asm01_01(int**, uint, uint);
extern "C" int asm01_06(int**,int**, uint, uint);
extern "C" void asm02_08(short**, uint, uint);
extern "C" void asm02_11(int64**, uint, uint);


int main() {
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand((uint)time(0));
    int n = 0;
    cout << "Podaj numer zadania w formacie x= temat y=numer zadania xy: ";
    cin >> n;
    switch (n)
    {
    case 11:
    {
        uint rows = 4, cols = 3;
        int** A = newFillPtr<int>(rows, cols);
        printPtr(A, rows, cols);
        int64 yAsm = asm01_01(A, rows, cols);
        int64 yCpp = cpp01_01<int64, int>(A, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        break;
    }
    case 16:
    {
        uint rows = 4, cols = 3;
        int** A = newFillPtr<int>(rows, cols), **B =newFillPtr<int>(rows,cols);
        printPtr(A,rows,cols);
        printPtr(B, rows, cols);
        int yAsm = asm01_06(A, B, rows, cols);
        int yCpp = cpp01_06<int,int>(A, B, rows, cols);
        resultComparator(yCpp, yAsm);
        freePtr(A, rows);
        freePtr(B, rows);
    }   

    case 28:
    {
        uint rows = 8, cols = 6;
        short** A = newFillPtr<short>(rows, cols);
        short** B = newCopyPtr<short,short>(A,rows, cols);
        printPtr(A, rows, cols);
        printPtr(B, rows, cols);
        asm02_08(A, rows, cols);
        cpp02_08(B, rows, cols);
        
        printPtr(A, rows, cols);
        printPtr(B, rows, cols);
        
        resultComparator(B, A, rows, cols);
        freePtr(A, rows);
        freePtr(B, rows);
    }

    case 211: 
    {
        uint rows = 10, cols = 8;
        int64** a = newFillPtr<int64>(rows, cols);
        int64** b = newCopyPtr<int64>(a, rows, cols);
        printPtr(a, rows, cols);
        asm02_11(a, rows, cols);
        cpp02_11<int64>(b, rows, cols);

        printPtr(a, rows, cols);
        printPtr(b, rows, cols);

        resultComparator(b, a, rows, cols);

        freePtr(b, rows);
        freePtr(a, rows);
    }
    default:
        break;
    }


    system("pause");
    return 0;
}
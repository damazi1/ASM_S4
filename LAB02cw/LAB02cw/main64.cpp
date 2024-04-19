#include <iostream>
#include <iomanip>
#include <chrono>
#include <Windows.h>

using namespace std;

typedef long long int64;
typedef unsigned int uint;

extern "C" int64 asmADD(int, int);
extern "C" int64 asmSUB(int, int);
extern "C" int64 asmSHL(int);
extern "C" int64 asmSHR(int);
extern "C" int64 asmSAR(int);
extern "C" int64 asmMUL(int,int);
extern "C" int64 asmDIV(int, int);
extern "C" int64 asmIMUL(int, int);
extern "C" int64 asmIDIV(int, int);


int main() {
	int a = -5431, b = 1232;
	//Dodawanie
	{
		cout << "[CPP] dodawanie: " << a + b << endl;
		int64 w = asmADD(a, b);
		cout << "[ASM] dodawanie: " << w << endl;
	}
	//Odejmowanie
	{
		cout << "[CPP] Odejmowanie: " << a - b << endl;
		int64 w = asmSUB(a, b);
		cout << "[ASM] Odejmowanie: " << w << endl;
	}
	//Logiczne Przesunięcie Bitu w lewo (SHL) WPŁYWA NA CF (CARRY FLAG)
	{
		cout << "[CPP] Przesunięcie logiczne w lewo: " << a * 32 << endl;
		cout << "[ASM] Przesunięcie logiczne w lewo: " << asmSHL(a) << endl;
	}
	//Logiczne Przesunięcie Bitu w Prawo (SHR) WPŁYWA NA CF (CARRY FLAG)
	{
		cout << "[CPP] Przesunięcie logiczne w prawo: " << a / 4 << endl;
		cout << "[ASM] Przesunięcie logiczne w prawo: " << asmSHR(a) << endl;
	}
	//Arytmetyczne Przesunięcie Bitu w Prawo (SAR) WPŁYWA NA CF (CARRY FLAG)
	{
		cout << "[CPP] Arytmetyczne przesunięcie w prawo: " << a / 10 << endl;
		cout << "[ASM] Arytmetyczne przesunięcie w prawo: " << asmSAR(a) << endl;
	}
	//Operacja mnozenia bez znaku (mul)
	{
		cout << "[CPP] Mnozenie bez znaku: " << a * b << endl;
		cout << "[ASM] Mnozenie bez znaku: " << asmMUL(a,b) << endl;
	}
	//Operacja dzielenia bez znaku (div)
	{
		cout << "[CPP] Dzielenie bez znaku: " << a / b << endl;
		cout << "[ASM] Dzielenie bez znaku: " << asmDIV(a,b) << endl;
	}
	//Operacja mnozenia ze znakiem (IMUL)
	{
		cout << "[CPP] mnozenie ze znakiem: " << a * b << endl;
		cout << "[ASN] mnozenie ze znakiem: " << asmIMUL(a,b) << endl;
	}
	//Operacja Dzielenia ze znakiem (IDIV)
	{
		cout << "[CPP] Dzielenie ze znakiem: " << a / b << endl;
		cout << "[ASM] Dzielenie ze znakiem: " << asmIDIV(a,b) << endl;
	}
	system("pause");
	return 0;
}
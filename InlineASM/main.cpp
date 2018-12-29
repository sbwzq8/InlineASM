#include <iostream>;
//#include "stdio.h"
#include <stdlib.h>
#include <wchar.h>
using namespace std;

__declspec(dllexport) wchar_t* ASMResult();

int main() {
	wchar_t* p;
	p = (wchar_t*)malloc(sizeof(wchar_t) * 1000);
	wchar_t* ptr = ASMResult();

	printf("%s", ptr);
	return 0;
}

__declspec(dllexport) wchar_t* ASMResult(){

	int cypher[] = { 2366981,13,2455638,7833,1969907,17,833,859,0,278775,188055,254,6297303,19,13,51138,1045748,46158,146,3747,349977,13937091,46807,376388,4632,278775,479,3260788,108792,13,57554,191611,407292,13,1774,4632,17028678,51357,833,5086887,167240,185423,1410635,254,4632,10302704,6297303,19,1031361,2470182,14258,13557614,157,4091537,110,4632,1471289,697881,60609,20500575,32,26161,4632,182710,615190,35,76798,8070075,9496840,32,7227253,157,348445,424,7650687,760,5985040,833,859,4526177,60609,3285425,4632,43518,15994367,76798,7306177,7,46250,833,159855,146,749939,19,344753,254,156537,99158,33763146,12472,668518,19,76798,8070075,9496840,32 };
	char clen[] = { 5,1,5,3,5,1,2,2,1,5,4,2,5,1,1,4,4,3,2,3,4,5,4,4,3,5,2,5,3,1,4,4,4,1,3,3,5,4,2,5,5,4,4,2,3,5,5,1,4,5,3,5,2,5,3,3,5,4,4,5,1,3,3,4,5,1,4,5,5,1,5,2,5,2,5,2,5,2,2,5,4,5,3,4,5,4,4,2,3,2,5,2,5,1,4,2,4,4,5,3,5,1,4,5,5,1 };
	int ccount = 106;
	static wchar_t output[1000];

	char *cle = clen;
	int *cyp = cypher;
	wchar_t *outp = output;

	_asm {
	start:
			mov		edi, outp
			mov		esi, cyp
			mov		ecx, cle

			xor		eax, eax
		loop1 :
			cmp		eax, ccount
			jge		endloop1

			xor		ebx, ebx
		loop2 :
			cmp		bl, byte ptr[ecx + eax]
			jge		endloop2

			mov		edx, dword ptr[esi + 4 * eax]
			imul	edx, 41C64E6Dh
			add		edx, 3039h
			mov		dword ptr[esi + 4 * eax], edx

			push	eax
			push	ebx

			shr		edx, 10h
			mov		eax, edx
			xor		edx, edx
			mov		ebx, 8000h
			idiv	ebx
			mov		eax, edx
			xor		edx, edx
			mov		ebx, 1Ah
			idiv	ebx
			add		edx, 41h
			mov		byte ptr[edi], dl

			pop		ebx
			pop		eax
			add		edi, 1
			inc		ebx
			jmp		loop2
		endloop2 :

			mov		byte ptr[edi], 32
			add		edi, 1

			inc		eax
			jmp		loop1
		endloop1 :
			mov		byte ptr[edi], 00
		endstart :
	}
	return outp;
}
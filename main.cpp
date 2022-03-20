#include <iostream>
#include <d3d9.h>



LPDIRECT3D9       g_pDirect3D = NULL;
LPDIRECT3DDEVICE9 g_pDirect3D_Device = NULL;

/* this should be a global variable 
   refers to the D3DADAPTER_IDENTIFIER9  struct
   see 
   https://docs.microsoft.com/en-us/windows/win32/direct3d9/d3dadapter-identifier9
   */
D3DADAPTER_IDENTIFIER9 pIdentifier ; 

char * what_GPU()
{

	UINT x = 0; // Ordinal number that denotes the display adapter.
	DWORD xWord = 0 ; 
	
	// create Direct3d object to use functions 
	// see 
	// https://docs.microsoft.com/en-us/windows/win32/api/d3d9/nf-d3d9-idirect3d9-getadapteridentifier
	g_pDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	HRESULT hResult = g_pDirect3D->GetAdapterIdentifier(x, xWord, &pIdentifier);
	
	if (hResult != D3D_OK)
		std::cout << "Failed to create DirectX handle" << std::endl;

	std::cout << pIdentifier.Description << std::endl;
	return pIdentifier.Description;

}


int main(void)
{
	what_GPU();
	return 0;
}


/*
Detecting a GPU using DirextX 
https://stackoverflow.com/questions/40444046/c-how-to-detect-graphics-card-model


Makefile

CC = g++
FILES = main.cpp
OUT_EXE = what_GPU
INCLUDES = -ld3d9 -ld3dcompiler -lgdi32 -static -static-libstdc++

build:$(FILES)
	$(CC) $(FILES) $(INCLUDES) -o $(OUT_EXE)
clean:
	rm -f *.o *.exe
*/
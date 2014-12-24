#include <Windows.h>

#ifdef _DEBUG
#include "MemDbg.h"
#endif

int main(int argc, char ** argv)
{
	HANDLE hProcHeap = GetProcessHeap();
	void * lpMem;
#ifdef _DEBUG
	InitMemDbg();
#endif

	/* Allocate memory */
	lpMem = HeapAlloc(hProcHeap, 0, 32);
	/* Free the memory */
	HeapFree(hProcHeap, 0, lpMem);

	/* Allocate and forget to free */
	lpMem = HeapAlloc(hProcHeap, 0, 32);

#ifdef _DEBUG
	WriteMemDbgMessage();
#endif
	return 0;
}
#include <Windows.h>
#include <iostream>

int main()
{
#if _DEBUG
	const char* CaminDll = "C:\\projcpp\\AssaultCube Hack\\bin\\Debug\\HackDll.dll";	// Caminho da .dll, deve mudar caso você use uma pasta diferente
#else
	const char* CaminDll = "C:\\projcpp\\AssaultCube Hack\\bin\\Release\\HackDll.dll";	// Caminho da .dll, deve mudar caso você use uma pasta diferente
#endif

	HWND Processo = FindWindowA(NULL, "AssaultCube");

	if (Processo == NULL)
	{
		std::cout << "Jogo nao encontrado!\n\n";
		std::cin.get();
		return EXIT_FAILURE;
	}
	else
		std::cout << "Hack iniciado!\n\n";

	DWORD pID = NULL;
	GetWindowThreadProcessId(Processo, &pID);

	HANDLE hProcesso = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);

	if (hProcesso != INVALID_HANDLE_VALUE)
	{
		LPVOID VirtMemAloc = VirtualAllocEx(hProcesso, NULL, strlen(CaminDll) + 1, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

		if (VirtMemAloc)
		{
			WORD DllInjetada = WriteProcessMemory(hProcesso, VirtMemAloc, CaminDll, strlen(CaminDll) + 1, NULL);
			if (DllInjetada != 0)
				std::cout << "Hack Dll.dll injetada!\n";
			else
			{
				std::cout << "Dll não injetada!\n";
				std::cin.get();
				return EXIT_FAILURE;
			}
		}

		HANDLE hDllThread = CreateRemoteThread(hProcesso, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryA, VirtMemAloc, NULL, NULL);

		if (hDllThread)
			CloseHandle(hDllThread);
	}

	if (hProcesso)
		CloseHandle(hProcesso);

	return EXIT_SUCCESS;
}

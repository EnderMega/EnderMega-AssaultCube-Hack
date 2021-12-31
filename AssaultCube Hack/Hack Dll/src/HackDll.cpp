// A ordem é importante
#include "pch.h"
#include "Cabeçalhos/MeuMat.hpp"
#include "Cabeçalhos/Dados.h"
#include "Classes/Jogadores.h"
#include "Cabeçalhos/funcHacks.h"

#define DESREF(x) *(uintptr)(x)


DWORD WINAPI ThreadPrincipal(HMODULE hModulo)
{
	// Alocar console

	AllocConsole();

	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesEscritos = 0;

	WriteConsoleA(hConsole, "Um hack bem meh de EnderMega :D\n", strlen("Um hack bem meh de EnderMega :D\n"), &dwBytesEscritos, nullptr);

	uint EndrMod_ac_client = (uint)GetModuleHandleA("ac_client.exe");

	/*-------------------------------------------------------------------*/
	
	// Se eu criar no heap, eu posso usar uma variável em vez de uma constante e assim posso criar durante "runtime"
	Jogadores Entidades[32];

	{
		uint ptrLista_Entidades = EndrMod_ac_client + OffSets::Lista_EndrBase;
		uint ptrBase_Jogador = EndrMod_ac_client + OffSets::Jogador_EndrBase;

		Geral::Num_Jogadores = DESREF(EndrMod_ac_client + OffSets::Num_JogadoresOffSet);

		/*-------------------------------------------------------------------*/

		// Inicializar jogadores inimigos

		ushort Cont = 1;

		while (Cont < Geral::Num_Jogadores)
		{
			Entidades[Cont].Ponteiros(ptrLista_Entidades, Cont);
			Cont++;
		}

		/*-------------------------------------------------------------------*/

		// Jogador (eu)

		for (auto i : OffSets::Jogador_OffSetMatriz)
		{
			ptrBase_Jogador = DESREF(ptrBase_Jogador);
			ptrBase_Jogador += i;
		}

		/*-------------------------------------------------------------------*/

		Entidades[0].JogadorPonteiros(ptrBase_Jogador);
	}

	Jogadores* MeuJogador = &Entidades[0];

	// while (!(GetAsyncKeyState(TECLA_END) & 1))
	while (true)
	{
		/*ESTÁTUS*/

		// Vida
		if (GetAsyncKeyState(VK_F7) & 1)
		{
			Hax::GodMode = !Hax::GodMode;
			switch (Hax::GodMode)
			{
			case true:
				WriteConsoleA(hConsole, "GodMode ativado\n", strlen("GodMode ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "GodMode desativado\n", strlen("GodMode desativado\n"), &dwBytesEscritos, NULL);
			}
		}
		
		// Armadura
		if (GetAsyncKeyState(VK_F8) & 1)
		{
			Hax::Armadura = !Hax::Armadura;
			switch (Hax::Armadura)
			{
			case true:
				WriteConsoleA(hConsole, "Armadura ativado\n", strlen("Armadura ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "Armadura desativado\n", strlen("Armadura desativado\n"), &dwBytesEscritos, NULL);
			}
		}

		/*EXTRA*/

		// Granadas
		if (GetAsyncKeyState(VK_F6) & 1)
		{
			Hax::Granada = !Hax::Granada;
			switch (Hax::Granada)
			{
			case true:
				WriteConsoleA(hConsole, "Granada ativado\n", strlen("Granada ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "Granada desativado\n", strlen("Granada desativado\n"), &dwBytesEscritos, NULL);
			}
		}

		/*MUNIÇÕES*/

		// Munição primária
		if (GetAsyncKeyState(VK_F1) & 1)
		{
			Hax::MunicaoPrimaria = !Hax::MunicaoPrimaria;
			switch (Hax::MunicaoPrimaria)
			{
			case true:
				WriteConsoleA(hConsole, "Municao Primaria ativado\n", strlen("Municao Primaria ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "Municao Primaria desativado\n", strlen("Municao Primaria desativado\n"), &dwBytesEscritos, NULL);
			}
		}

		// Munição primária Pente		
		if (GetAsyncKeyState(VK_F2) & 1)
		{
			Hax::MunicaoPrimariaPente = !Hax::MunicaoPrimariaPente;
			switch (Hax::MunicaoPrimariaPente)
			{
			case true:
				WriteConsoleA(hConsole, "Municao Primaria Pente ativado\n", strlen("Municao Primaria Pente ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "Municao Primaria Pente desativado\n", strlen("Municao Primaria Pente desativado\n"), &dwBytesEscritos, NULL);
			}
		}

		// Munição secundária
		if (GetAsyncKeyState(VK_F3) & 1)
		{
			Hax::MunicaoSecundaria = !Hax::MunicaoSecundaria;
			switch (Hax::MunicaoSecundaria)
			{
			case true:
				WriteConsoleA(hConsole, "Municao Secundaria ativado\n", strlen("Municao Secundaria ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "Municao Secundaria desativado\n", strlen("Municao Secundaria desativado\n"), &dwBytesEscritos, NULL);
			}
		}

		// Munição secundária Pente
		if (GetAsyncKeyState(VK_F4) & 1)
		{
			Hax::MunicaoSecundariaPente = !Hax::MunicaoSecundariaPente;
			switch (Hax::MunicaoSecundariaPente)
			{
			case true:
				WriteConsoleA(hConsole, "Municao Secundaria Pente ativado\n", strlen("Municao Secundaria Pente ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "Municao Secundaria Pente desativado\n", strlen("Municao Secundaria Pente desativado\n"), &dwBytesEscritos, NULL);
			}
		}


		// Frenzie
		if (GetAsyncKeyState(VK_F5) & 1)
		{
			Hax::AtivarFrenzie = !Hax::AtivarFrenzie;
			switch (Hax::AtivarFrenzie)
			{
			case true:
				WriteConsoleA(hConsole, "Frenzie ativado ativado\n", strlen("Frenzie ativado ativado\n"), &dwBytesEscritos, NULL);
				break;

			case false:
				WriteConsoleA(hConsole, "Frenzie desativado ativado\n", strlen("Frenzie desativado ativado\n"), &dwBytesEscritos, NULL);
			}
		}

		/*HAX*/
		
		// Aimbot
		if (GetAsyncKeyState(VK_F9) & 1)
		{
			Hax::Aimbot = !Hax::Aimbot;
			switch (Hax::Aimbot)
			{
			case true:
				WriteConsoleA(hConsole, "Aimbot ativado\n", strlen("Aimbot ativado\n"), &dwBytesEscritos, NULL);
				break;
			case false:
				WriteConsoleA(hConsole, "Aimbot desativado\n", strlen("Aimbot desativado\n"), &dwBytesEscritos, NULL);
			}
		}

		/*-------------------------------------------------------------------*/

		/*ESTÁTUS*/

		if (Hax::GodMode)						// Eu não sei se eu estou copiando ou se eu estou passando o ponteiro da matriz
			InfinitoQualquerCoisa(Entidades[0].PegptrVida(), 1337);	// mas acho que eu estou mandando um valor e não uma variável
																
		if (Hax::Armadura)
			InfinitoQualquerCoisa(Entidades[0].PegptrArm(), 1337);

		/*EXTRA*/

		if (Hax::Granada)
			InfinitoQualquerCoisa(Entidades[0].PegptrGranada(), 3);

		/*MUNIÇÕES*/
		
		// Tem um problema com sniper e rifle, mas fora isso, de boa; Esse hack nem é grande coisa
		// pois, pela maior parte, não dá pra usar em multiplayer
		if (Hax::MunicaoPrimaria)
			InfinitoQualquerCoisa(Entidades[0].PegptrMunicaoPrimaria(), 1337);

		if (Hax::MunicaoPrimariaPente)
			InfinitoQualquerCoisa(Entidades[0].PegptrMunicaoPrimariaPente(), 30);

		// Testar sobre Frenzie
		if (Hax::MunicaoSecundaria)
		{
			switch (Hax::AtivarFrenzie)
			{
			case false:
				InfinitoQualquerCoisa(Entidades[0].PegptrMunicaoSecundaria(), 100);
				break;

			case true:
				InfinitoQualquerCoisa(Entidades[0].PegptrMunicaoSecundariaFrenzie(), 100);
			}
		}

		// Testar sobre Frenzie
		if (Hax::MunicaoSecundariaPente)
		{
			switch (Hax::AtivarFrenzie)
			{
			case false:
				InfinitoQualquerCoisa(Entidades[0].PegptrMunicaoSecundariaPente(), 10);
				break;

			case true:
				InfinitoQualquerCoisa(Entidades[0].PegptrMunicaoSecundariaPenteFrenzie(), 20);
			}
		}

		/*HAX*/

		if (Hax::Aimbot)						// Ações do Aimbot
			funcAimBot(Entidades, MeuJogador);

		if (GetAsyncKeyState(VK_END) & 1)	// Para sair do hack
			break;
	}

	// Finalização

	CloseHandle(hConsole);
	FreeConsole();
	FreeLibraryAndExitThread(hModulo, NULL);

	return 0;
}

DWORD APIENTRY DllMain( HMODULE hModulo,
	DWORD RasaoChamada,
	LPVOID lpReservado )
{
	switch (RasaoChamada)
	{
	case DLL_PROCESS_ATTACH:
#pragma warning( push )
#pragma warning( disable : 6387 )
		CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)ThreadPrincipal, hModulo, 0, nullptr));
#pragma warning( pop )
	}

	return TRUE;
}

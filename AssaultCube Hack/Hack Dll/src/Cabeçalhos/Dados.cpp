// Se eu não incluir, as definições precisam ser "extern"
#include "MeuMat.hpp"
#include "Dados.h"

/*
typedef unsigned int uint;
typedef unsigned short ushort;

typedef unsigned int* uintptr;
*/

// Pelo que parece todos os offsets mudaram

namespace Hax {

	bool Aimbot = false;
	bool GodMode = false;
	bool Armadura = false;
	bool Granada = false;
	bool MunicaoPrimaria = false;
	bool MunicaoPrimariaPente = false;
	bool MunicaoSecundaria = false;
	bool MunicaoSecundariaPente = false;
	ushort AtivarFrenzie = 0;
	bool Fly = false;
}

// Agora que eu sei sobre o foreach eu não preciso dos "X_TamanhoOffSetMatriz",
// só vou deixar como história kk

namespace OffSets {

	// Base jogador/Lista
	const uint Lista_EndrBase = 0x10F4F8;
	const uint Jogador_EndrBase = 0x110A28;
	const uint Jogador_OffSetMatriz[2] = { 0x0, 0xA0 };
	const uint Lista_OffSet = 0x4;		// Distância de cada jogador, primeiro ponteiro é nulo
	const uint Num_JogadoresOffSet = 0x10F500;
	//const uint Jogador_TamanhoOffSetMatriz = MeuMat::TamMatriz(Jogador_OffSetMatriz);

	uintptr ptrBase_Jogador = nullptr;
	uintptr ptrLista_Entidades = nullptr;

	//ptrBase_Jogador;
	
	const uint Nome_OffSet = 0x225;

	// Estátus offsets
	const uint Vida_OffSet = 0xF8;
	const uint Arm_OffSet = 0xFC;

	// Extra
	const uint Granada_OffSet = 0x158;

	// Munições
	const uint MunicaoPrimaria = 0x128;
	const uint PentePrimaria = 0x150;
	const uint MunicaoSecundaria = 0x114;
	const uint PenteSecundaria = 0x13C;

	const uint FrenzieAtivado = 0x10c;
	const uint MunicaoSecundariaFrenzie = 0x134;
	const uint MunicaoSecundariaPenteFrenzie = 0x15c;

	// Posições offsets
	const uint Pos_OffSetMatriz[3] = { 0x34, 0x38, 0x3C };	// X, Z, Y (Y é a altura)
	//const uint Pos_TamanhoOffSetMatriz = MeuMat::TamMatriz(Pos_OffSetMatriz);		// Por mais que vai sempre ser 3, só se usa 3 posições

	// Ângulos offsets
	const uint Ang_OffSetMatriz[3] = { 0x40, 0x44, 0x48 };	// Yaw, Pitch, Roll
	//const uint Ang_TamanhoOffSetMatriz = MeuMat::TamMatriz(Ang_OffSetMatriz);		// Por mais que vai sempre ser 3, só se usa 3 ângulos
}

namespace Geral {

	ushort Num_Jogadores = 0;
	float MenorHip[2] = { 0.0f, 0.0f };
	float DifVec3[3] = { 0.0f, 0.0f };
}
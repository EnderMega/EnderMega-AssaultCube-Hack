#pragma once

namespace Hax {
	
	extern bool Aimbot;
	extern bool GodMode;
	extern bool Armadura;
	extern bool Granada;
	extern bool MunicaoPrimaria;
	extern bool MunicaoPrimariaPente;
	extern bool MunicaoSecundaria;
	extern bool MunicaoSecundariaPente;
	extern ushort AtivarFrenzie;
	extern bool Fly;
}

namespace OffSets {

	// Base jogador/Lista
	extern const uint Lista_EndrBase;
	extern const uint Jogador_EndrBase;
	extern const uint Jogador_OffSetMatriz[2];
	extern const uint Lista_OffSet;		// Distância de cada jogador, primeiro ponteiro é nulo
	extern const uint Num_JogadoresOffSet;

	extern uintptr ptrBase_Jogador;
	extern uintptr ptrLista_Entidades;
	
	//ptrBase_Jogador;

	extern const uint Nome_OffSet;
	extern const uint Num_Jogadores;
	
	// Estátus offsets
	extern const uint Vida_OffSet;	// Vida
	extern const uint Arm_OffSet;	// Armadura
	
	// Munições
	extern const uint Granada_OffSet;

	extern const uint MunicaoPrimaria;
	extern const uint PentePrimaria;
	extern const uint MunicaoSecundaria;
	extern const uint PenteSecundaria;

	extern const uint FrenzieAtivado;
	extern const uint MunicaoSecundariaFrenzie;
	extern const uint MunicaoSecundariaPenteFrenzie;

	// Posições offsets
	extern const uint Pos_OffSetMatriz[3];	// X, Z, Y (Y é a altura)
	
	// Ângulos offsets
	extern const uint Ang_OffSetMatriz[3];	// Yaw, Pitch, Roll
}

namespace Geral {

	extern ushort Num_Jogadores;
	extern float MenorHip[2];	// horizontal, vertical
	extern float DifVec3[3];
}

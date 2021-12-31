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

// Agora que eu sei sobre o foreach eu não preciso dos "X_TamanhoOffSetMatriz",
// só vou deixar como história kk

namespace OffSets {

	// Base jogador/Lista
	extern const uint Lista_EndrBase;
	extern const uint Jogador_EndrBase;
	extern const uint Jogador_OffSetMatriz[2];
	extern const uint Lista_OffSet;		// Distância de cada jogador, primeiro ponteiro é nulo
	extern const uint Num_JogadoresOffSet;
	//const uint Jogador_TamanhoOffSetMatriz = MeuMat::TamMatriz(Jogador_OffSetMatriz);

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
	//const uint Pos_TamanhoOffSetMatriz = MeuMat::TamMatriz(Pos_OffSetMatriz);		// Por mais que vai sempre ser 3, só se usa 3 posições
	
	// Ângulos offsets
	extern const uint Ang_OffSetMatriz[3];	// Yaw, Pitch, Roll
	//const uint Ang_TamanhoOffSetMatriz = MeuMat::TamMatriz(Ang_OffSetMatriz);		// Por mais que vai sempre ser 3, só se usa 3 ângulos
}

//namespace JPonteiros {
//
//	// Ponteiros
//	extern uintptr ptrVidaJogador;	// Vida
//	extern uintptr ptrArmJogador;	// Armadura
//	
//	// Pos
//	extern uintptr ptrPosX;			// Posição X
//	extern uintptr ptrPosZ;			// Posição Z
//	extern uintptr ptrPosY;			// Posição Y
//	extern uintptr Matriz_ptrPos[3];	// Matriz de ponteiros Pos
//	
//	// Ang
//	extern uintptr ptrAngYaw;		// Ângulo Yaw
//	extern uintptr ptrAngPitch;		// Ângulo Pitch
//	extern uintptr ptrAngRoll;		// Ângulo Roll
//	extern uintptr Matriz_ptrAng[3];	// Matriz de ponteiros Ang
//}

/*namespace Jogador {

	float Vec3[3];
}*/

namespace Geral {

	extern ushort Num_Jogadores;
	extern float MenorHip[2];	// horizontal, vertical
	extern float DifVec3[3];
}
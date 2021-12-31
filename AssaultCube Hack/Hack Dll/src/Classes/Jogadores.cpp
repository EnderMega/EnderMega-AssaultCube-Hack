#include "../Cabeçalhos/MeuMat.hpp"
#include "../Cabeçalhos/Dados.h"
#include "Jogadores.h"

#define DESREF(x) *(uintptr)(x)

// ====== Aleatório ======

void Jogadores::Ponteiros(uint ListaBase, ushort Index)
{
	Index *= OffSets::Lista_OffSet;

	ptrNome = (char*)(DESREF(DESREF(ListaBase) + Index) + OffSets::Nome_OffSet);
	ptrVida = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::Vida_OffSet);
	ptrArmadura = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::Arm_OffSet);

	ptrArmadura = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::Granada_OffSet);

	ptrMunicaoPrimaria = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::MunicaoPrimaria);
	ptrMunicaoPrimariaPente = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::PentePrimaria);
	ptrMunicaoSecundaria = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::MunicaoSecundaria);
	ptrMunicaoSecundariaPente = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::PenteSecundaria);

	ptrFrenzieAtivado = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::FrenzieAtivado);
	ptrMunicaoSecundariaFrenzie = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::MunicaoSecundariaFrenzie);
	ptrMunicaoSecundariaPenteFrenzie = (uintptr)(DESREF(DESREF(ListaBase) + Index) + OffSets::MunicaoSecundariaPenteFrenzie);

	for (ushort i = 0; i < 3; i++)
		ptrPosVec3[i] = (float*)(DESREF(DESREF(ListaBase) + Index) + OffSets::Pos_OffSetMatriz[i]);
	for (ushort i = 0; i < 3; i++)
		ptrAngVec3[i] = (float*)(DESREF(DESREF(ListaBase) + Index) + OffSets::Ang_OffSetMatriz[i]);
}

void Jogadores::JogadorPonteiros(uint ListaBase)
{
	ptrNome = (char*)(DESREF(ListaBase) + OffSets::Nome_OffSet);
	ptrVida = (uintptr)(DESREF(ListaBase)+ OffSets::Vida_OffSet);
	ptrArmadura = (uintptr)(DESREF(ListaBase) + OffSets::Arm_OffSet);

	ptrGranadas = (uintptr)(DESREF(ListaBase) + OffSets::Granada_OffSet);

	ptrMunicaoPrimaria = (uintptr)(DESREF(ListaBase) + OffSets::MunicaoPrimaria);
	ptrMunicaoPrimariaPente = (uintptr)(DESREF(ListaBase) + OffSets::PentePrimaria);
	ptrMunicaoSecundaria = (uintptr)(DESREF(ListaBase) + OffSets::MunicaoSecundaria);
	ptrMunicaoSecundariaPente = (uintptr)(DESREF(ListaBase) + OffSets::PenteSecundaria);

	for (ushort i = 0; i < 3; i++)
		ptrPosVec3[i] = (float*)(DESREF(ListaBase) + OffSets::Pos_OffSetMatriz[i]);
	for (ushort i = 0; i < 3; i++)
		ptrAngVec3[i] = (float*)(DESREF(ListaBase) + OffSets::Ang_OffSetMatriz[i]);
}

// ====== Peg funcs ======

		/*ESTÁTUS*/

uintptr Jogadores::PegptrVida() const
{
	return ptrVida;
}

uintptr Jogadores::PegptrArm() const
{
	return ptrArmadura;
}

		/*EXTRA*/

uintptr Jogadores::PegptrGranada() const
{
	return ptrGranadas;
}

		/*MUNIÇÕES*/

uintptr Jogadores::PegptrMunicaoPrimaria() const
{
	return ptrMunicaoPrimariaPente;
}

uintptr Jogadores::PegptrMunicaoPrimariaPente() const
{
	return ptrMunicaoSecundaria;
}

uintptr Jogadores::PegptrMunicaoSecundaria() const
{
	return ptrMunicaoSecundariaPente;
}

uintptr Jogadores::PegptrMunicaoSecundariaPente() const
{
	return ptrMunicaoPrimaria;
}

/*-------------------------------------------------------------------*/

uintptr Jogadores::PegptrFrenzieAtivado() const
{
	return ptrFrenzieAtivado;
}

uintptr Jogadores::PegptrMunicaoSecundariaFrenzie() const
{
	return ptrMunicaoSecundariaFrenzie;
}

uintptr Jogadores::PegptrMunicaoSecundariaPenteFrenzie() const
{
	return ptrMunicaoSecundariaPenteFrenzie;
}

// ====== Def funcs ======

float Jogadores::PegPos(ushort index) const
{
	return *(ptrPosVec3[index]);
}

void Jogadores::DefAng(float ang, ushort index)
{
	*ptrAngVec3[index] = ang;
}

void Jogadores::DefPos(float pos, ushort index)
{
	*ptrPosVec3[index] = pos;
}
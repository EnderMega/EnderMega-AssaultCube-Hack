#pragma once

class Jogadores {
public:
	static const ushort x = 0;
	static const ushort z = 1;
	static const ushort y = 2;

private:
	char* ptrNome = nullptr;
	uintptr ptrVida = nullptr;
	uintptr ptrArmadura = nullptr;

	uintptr ptrGranadas = nullptr;

	uintptr ptrMunicaoPrimaria = nullptr;
	uintptr ptrMunicaoPrimariaPente = nullptr;
	uintptr ptrMunicaoSecundaria = nullptr;
	uintptr ptrMunicaoSecundariaPente = nullptr;

	uintptr ptrFrenzieAtivado = nullptr;
	uintptr ptrMunicaoSecundariaFrenzie = nullptr;
	uintptr ptrMunicaoSecundariaPenteFrenzie = nullptr;

	float* ptrPosVec3[3] = { nullptr, nullptr, nullptr };	// x, z, y
	float* ptrAngVec3[3] = { nullptr, nullptr, nullptr };	// Guinada, Ataque, rolagem

public:
	Jogadores() { }

	/*Jogadores() {

	}*/

	// ====== Aleatório ======

	// Para o jogador o "index" deve ser 0
	void Ponteiros(uint ListaBase, ushort Index);

	void JogadorPonteiros(uint ListaBase);

	// ====== Peg funcs ======

	uintptr PegptrVida() const;
	uintptr PegptrArm() const;
	uintptr PegptrGranada() const;
	uintptr PegptrMunicaoPrimaria() const;
	uintptr PegptrMunicaoPrimariaPente() const;
	uintptr PegptrMunicaoSecundaria() const;
	uintptr PegptrMunicaoSecundariaPente() const;
	uintptr PegptrFrenzieAtivado() const;
	uintptr PegptrMunicaoSecundariaFrenzie() const;
	uintptr PegptrMunicaoSecundariaPenteFrenzie() const;

	float PegPos(ushort index) const;

	// ====== Def funcs ======

	void DefAng(float ang, ushort index);
	void DefPos(float ang, ushort index);
};
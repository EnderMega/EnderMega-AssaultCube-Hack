#pragma once
#include "MeuMat.hpp"

// Todos os template tem que estar no .hpp

namespace MeuMat {

	// § Extra

	// § Aritimética

	/*
	* Eu quero que no futuro seja possível usar negativos.
	* Eu até pensei em colocar o "exp" como "unsigned int", mas se alguem entrar um valor negativo,
	isso vai ser basicamente um "cast" para "unsigned", o que gera um valor totalmente estranho.
	*/

	/*float Pot(float base, int exp)
	{
		// Para casos negativos
		if (base || exp < 0)	// Testar se posso isso ou se tem que ser if  (base < 0 || exp < 0)
			return -1;	// Sei lá como lidar com erros, então retorna '-1' e boa kkk

		if (exp == 0)
			return 1;
		else if (base == 0)
			return 0;
		else if (base == 1)
			return 1;

		float Resultado = base;

		//exp -= 1;

		for (int i = 1; i < exp; i++)	// i começa em 1 para remover a linha exp -= 1;
			Resultado *= base;

		return Resultado;
	}*/

	/*double Pot(double base, int exp)
	{
		// Para casos negativos
		if (base || exp < 0)	// Testar se posso isso ou se tem que ser if  (base < 0 || exp < 0)
			return -1;	// Sei lá como lidar com erros, então retorna '-1' e boa kkk

		if (exp == 0)
			return 1;
		else if (base == 0)
			return 0;
		else if (base == 1)
			return 1;

		double Resultado = base;

		//exp -= 1;

		for (int i = 1; i < exp; i++)	// i começa em 1 para remover a linha exp -= 1;
			Resultado *= base;

		return Resultado;
	}*/

	/*float RaizQuad(float raiz)
	{
		float precisao = 0.000001f;
		float b = raiz, a = 1;
		while ((b - a) >= precisao) {
			b = (b + a) / 2;
			a = raiz / b;
		}
		return b;
	}*/

	// § Trigonometria

}
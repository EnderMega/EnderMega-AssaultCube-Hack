#pragma once

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulong_long;

#ifdef _WIN64
typedef unsigned long long* uinptr;
#else
typedef unsigned int* uintptr;
#endif

typedef void* voidptr;

#define TAMMATRIZ(matriz) (sizeof matriz / sizeof matriz[0])
#define QUAD(x) (x*x)
#define CUBO(x) (x*x*x)

#define MEUPI 3.14159265358

namespace MeuMat {

	// § Extra

	template <typename T>
	static inline uint TamMatriz(T& matriz)
	{
		return sizeof matriz / sizeof matriz[0];
	}

	// § Aritimética

	template<typename T>
	static inline T Quad(T quad)
	{
		return quad * quad;
	}

	template <typename T>
	static T Pot(T base, int exp)
	{
		// Para casos negativos
		if (base < 0 || exp < 0)
			return -1;

		switch (base)
		{
		case 0:
			return 0;
		case 1:
			return 1;
		}

		switch (exp)
		{
		case 0:
			return 1;
		case 1:
			return base;
		}

		T Resultado = base;

		//exp -= 1;

		for (uint i = 1; i < exp; i++)	// i começa em 1 para remover a linha exp -= 1;
			Resultado *= base;

		return Resultado;
	}

	static float Pot(float base, int exp)
	{
		// Para casos negativos
		if (base < 0 || exp < 0)
			return -1;

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
	}
	
	static double Pot(double base, int exp)
	{
		// Para casos negativos
		if (base < 0 || exp < 0)
			return -1;

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
	}

	static float RaizQuad(float raiz)
	{
		float precisao = 0.000001f;
		float b = raiz, a = 1;
		while ((b - a) >= precisao) {
			b = (b + a) / 2;
			a = raiz / b;
		}
		return b;
	}


	// § Trigonometria

	// Calcula a hipotenusa
	template<typename T>
	static T Hip(T cat1, T cat2)
	{
		T Hip = RaizQuad(QUAD(cat1) + QUAD(cat2));

		return Hip;
	}
}

using System;

public static class GlobalMembers
{
	public static int nrCifre(int x)
	{
		int nr_cifre = 0;
		while (x != 0)
		{
			nr_cifre++;
			x /= 10;
		}
		return nr_cifre;
	}

	public static void AlocareDinamica(int dim, int[] matrice)
	{
		matrice[0] = new int[dim * dim];
		for (int index = 1; index < dim; ++index)
		{
			matrice[index] = matrice[index - 1] + dim;
		}
	}

	public static void TransformareNumarInVector(int x, int[] v, int dim)
	{
		for (int i = dim - 1; i >= 0; i--)
		{
			v[i] = x % 10;
			x /= 10;
		}
	}

	public static void ConstruireMatrice(int dim, int[] matrice, int[] v1, int[] v2)
	{
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				matrice[i][j] = v1[i] * v2[j];
			}
		}
	}

	public static void AfisareMatrice(int dim, int[] matrice)
	{
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				Console.Write(matrice[i][j]);
				Console.Write(" ");
			}
			Console.Write("\n");
		}
	}

	public static void ConstruireNumar(int dim, int[] fr)
	{
		int tr;
		tr = fr[dim - 1] / 10;
		fr[dim - 1] %= 10;
		for (int i = dim - 2; i >= 0; i--)
		{
			fr[i] += tr;
			tr = fr[i] / 10;
			fr[i] = fr[i] % 10;
		}
		for (int i = 0; i < dim ; i++)
		{
			Console.Write(fr[i]);
			Console.Write(" ");
		}
		Console.Write("\n");

		if (tr != 0)
		{
			Console.Write(tr);
		}
		int i = 0;
		while (fr[i] == 0)
		{
			i++;
		}
		for (int j = i; j < dim; j++)
		{
			Console.Write(fr[j]);
		}
	}


	public static void InmultireaChinezeasca(int dim, int[] matrice)
	{
		int[] fr;
		fr = new int[2 * dim - 1];
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				fr[i + j] += matrice[i][j];
			}
		}
		for (int i = 0; i < 2 * dim - 1; i++)
		{
			Console.Write(fr[i]);
			Console.Write(" ");
		}
		Console.Write("\n");
		ConstruireNumar(2 * dim - 1, fr);
	}

	internal static void Main()
	{
		int Numar1;
		int Numar2;
		int nr_cif1;
		int nr_cif2;
//C++ TO C# CONVERTER TODO TASK: C# does not have an equivalent to pointers to value types:
//ORIGINAL LINE: int **matrice;
		int[] matrice;
		int dim;
		int[] v1;
		int[] v2;
		Numar1 = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		Numar2 = int.Parse(ConsoleInput.ReadToWhiteSpace(true));
		nr_cif1 = nrCifre(Numar1);
		nr_cif2 = nrCifre(Numar2);
		dim = Math.Max(nr_cif1, nr_cif2);

		v1 = new int[dim];
		v2 = new int[dim];

		TransformareNumarInVector(Numar1, v1, dim);
		TransformareNumarInVector(Numar2, v2, dim);

		matrice = new int[dim];
		AlocareDinamica(dim, matrice);

		ConstruireMatrice(dim, matrice, v1, v2);

		//AfisareMatrice(dim, matrice);
		InmultireaChinezeasca(dim, matrice);
		matrice[0] = null;
		matrice = null;
	}

}
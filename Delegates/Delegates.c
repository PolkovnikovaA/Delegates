#include <stdio.h>
#include <malloc.h>
#include <math.h>

int intfuc;
int Summ(int a, int b)	//	Сумма
{
	return a + b;
}
int Razn(int a, int b)	// Разность
{
	return a - b;
}
int Degree(int a, int b)	//	Возведение в степень
{
	return pow(a, b);
}

typedef int (*F)(int, int);
typedef F* delegate;

delegate intgelegat()
{
	delegate p = calloc(1, sizeof(F));
	return p;
}

void addFun(delegate p, F f)
{
	p[intfuc] = f;
	intfuc++;
	p = realloc(p, (intfuc + 1) * sizeof(F));
}

void removeFun(delegate p, F f, char type)
{
	for (size_t i = 0; i < intfuc; i++)
	{
		if (p[i] == f)
		{
			intfuc--;
			for (size_t j = i; j < intfuc; j++)
			{
				p[j] = p[j + 1];
			}
			p = realloc(p, (intfuc + 1) * sizeof(F));
			if (type)
			{
				break;
			}
		}
	}
}

void removePovtor(delegate p)
{
	int k = 0;
	int m = 0;
	int l = 0;
	do
	{
		int s = 0;
		int r = 0;
		int y = 0;
		for (size_t i = 0; i < intfuc; i++)
		{

			if (p[i])
			{
				if (p[i] == Summ)
				{
					s++;
					if (s > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							p[j] = p[j + 1];
						}
					}
				}
				else if (p[i] == Razn)
				{
					r++;
					if (r > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							p[j] = p[j + 1];
						}
					}
				}
				else if (p[i] == Degree)
				{
					y++;
					if (y > 1)
					{
						intfuc--;
						for (size_t j = i; j < intfuc; j++)
						{
							p[j] = p[j + 1];
						}
					}
				}
				p = realloc(p, (intfuc + 1) * sizeof(F));

			}

		}
		k = s;
		m = r;
		l = y;
	} while ((k > 1) || (m > 1) || (l > 1));

}

void Show(delegate p, int a, int b)
{
	for (size_t i = 0; i < intfuc; i++)
	{
		if (p[i])
		{
			printf("%d ", p[i](a, b));
		}
	}
	printf("\n");
}

int main()
{
	delegate p = intgelegat();
	addFun(p, Summ);
	addFun(p, Summ);
	addFun(p, Summ);
	addFun(p, Razn);
	addFun(p, Degree);
	addFun(p, Degree);
	addFun(p, Razn);
	addFun(p, Summ);
	addFun(p, Summ);
	addFun(p, Summ);


	Show(p, 5, 2);
	removePovtor(p);
	printf("...............................\n");
	Show(p, 5, 2);

	return 0;
}
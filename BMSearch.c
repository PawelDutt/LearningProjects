#include <stdio.h>
#include <stdbool.h>;
#include <time.h>;
//HARD
int BMSearch(char wzorzec[10],char slowo[100])
{
	int wzorzec_dl = strlen(wzorzec) -2;
	int i = wzorzec_dl;
	int stala = 0;
	int licznik_wzorcow = 0;
	while (i < strlen(slowo))
	{
		if (stala == 0)
		{
			for (int j = 0; j <= wzorzec_dl; j++)
			{
				if (wzorzec[wzorzec_dl - j] == slowo[i])
				{
					i = i + j;
					j = wzorzec_dl + 1;
				}
			}
		}
		if (slowo[i - stala] == wzorzec[wzorzec_dl - stala])
		{
			stala++;
			if (stala == wzorzec_dl)
			{
				licznik_wzorcow++;
				i +=wzorzec_dl+1;
				stala = 0;
			}
		}
		else if (stala > 0)
		{
			i += stala;
			stala = 0;
		}
		else
		{
			stala = 0;
			i += wzorzec_dl+1;
		}
		
	}
	return licznik_wzorcow;
}

int main()
{
	char wzorzec[10];
	fgets(wzorzec, sizeof wzorzec, stdin);
	
	char slowo[100];
	fgets(slowo, sizeof slowo, stdin);
	clock_t start = clock();
	int ilosc_wzorcow = BMSearch(wzorzec, slowo);
	clock_t end = clock();

	float time = (float)(end - start) / CLOCKS_PER_SEC;
	
	

	if (ilosc_wzorcow > 0)
	{
		printf("Ilosc wzorcow w tekscie: %d\n", ilosc_wzorcow);
	}
	else printf("Brak wzorcow w tekscie");
	printf("Czas wyszukiwania to %f \n", time);
	return 0;
}
//EASY
//int main()
//{
//	char wzorzec[10];
//	fgets(wzorzec, sizeof wzorzec, stdin);
//
//	char slowo[100];
//	fgets(slowo, sizeof slowo, stdin);
//
//	int licznik_wzorcow = 0;
//	int wzorzec_dl = strlen(wzorzec)-2;
//	int i = wzorzec_dl;
//	int stala = 0;
//
//	while (i < strlen(slowo))
//	{
//		if (slowo[i - stala] == wzorzec[wzorzec_dl - stala])
//		{
//			stala++;
//			//printf("%d", stala);
//			if (stala == wzorzec_dl)
//			{
//				licznik_wzorcow++;
//				i += wzorzec_dl + 1;
//				stala = 0;
//			}
//		}
//		else
//		{
//			stala = 0;
//			i += wzorzec_dl + 1;
//		}
//	}
//
//	printf("Ilosc wzorcow: %d", licznik_wzorcow);
//	_getch();
//	return 0;
//}
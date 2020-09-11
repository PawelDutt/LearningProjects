#include <stdio.h>
#include <time.h>

void bubbleSort(int tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (tab[i] < tab[j])
			{
				int tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
		}
	}
}

void quickSort(int tab[], int low, int high)
{
	if (low < high)
	{
		int pi = part(tab, low, high); //œrodek

		quickSort(tab, low, pi - 1);
		quickSort(tab, pi + 1, high);
	}
}

int part(int tab[], int low, int high)
{
	//PIVOT
	int pivot = tab[high];
	int i = low - 1;
	for (int j = low; j <= high - 1; j++)
	{
		if (tab[j] < tab[i])
		{
			int tmp = tab[j];
			tab[j] = tab[i];
			tab[i] = tmp;
		}
	}
	if (tab[i + 1] < tab[high])
	{
		int tmp = tab[i];
		tab[i] = tab[high];
		tab[high] = tmp;
	}
	return i + 1;
}

void main()
{
	int tab[10] = { 20,56,15,84,24,17,53,34,8,75 };
	int n = 10;

	clock_t start1 = clock();

	//bubbleSort(tab, n);
	printf("Bubble Sort: \n");
	for (int i = 0; i < n - 1; i++)
	{
		printf(" %d,", tab[i]);
	}
	printf(" %d", tab[n - 1]);

	clock_t end1 = clock();
	float time1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
	printf("\nBubbleSort time is: %f\n\n", time1);

	clock_t start = clock();

	quickSort(tab, 1, n);
	printf("\n\nQuick Sort: \n");
	for (int i = 0; i < n - 1; i++)
	{
		printf(" %d,", tab[i]);
	}
	printf(" %d", tab[n - 1]);

	clock_t end = clock();
	float time = (float)(end - start) / CLOCKS_PER_SEC;
	printf("\nQuickSort time is: %f\n", time);

	_getch();
}
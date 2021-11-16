#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

void BFS(int n, bool* Arr2, int i, int** Arr)
{
	queue<int> que;
	que.push(i);
	Arr2[i] = true;

	while (!que.empty())
	{
		i = que.front();
		que.pop();
		printf("%d ", i + 1);

		for (int j = 1; j < n; j++)
		{
			if (Arr[i][j] == 1 && Arr2[j] == false)
			{
				que.push(j);
				Arr2[j] = true;
			}
		}
	}
}


void main() {

	system("chcp 1251"); system("cls");
	int start, n, t = clock();

	cout << "Задание 1" << endl;

	cout << "Количество вершин > "; cin >> n;

	bool* visited = new bool[n];

	int** matrix;
	matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; ++i) {
		//matrix[i] = new int[n];
		visited[i] = false;
	}

	int s = 1;
	srand(time(NULL));
	for (int i = 0; i < n; i++) // создание матрицы
	{
		matrix[i] = (int*)malloc(n * sizeof(int));
		matrix[i][i] = 0;
		for (int j = s; j < n; j++)
		{
			if (rand() % 100 > 10)
			{
				matrix[i][j] = 0;
			}
			else {
				matrix[i][j] = 1;
			}
		}
		s++;
	}
	s = 1;
	for (int i = 0; i < n; i++) // неориентированный граф
	{
		for (int j = s; j < n; j++)
			matrix[j][i] = matrix[i][j];
		s++;
	}
	cout << "Matrix"; // вывод матрицы на экран
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
	}
	cout << endl;
	cout << "Стартовая вершина > "; cin >> start;
	cout << "Порядок обхода: ";
	BFS(n, visited, start - 1, matrix);

	delete[]visited;

	cout << "\nТакты:" << ((float)t / CLOCKS_PER_SEC) << "\n";
	system("pause");
}

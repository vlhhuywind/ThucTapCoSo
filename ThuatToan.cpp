#include<conio.h>
#include <fstream>
#include <iostream>
using namespace std;
/////
struct Node
{
	int index;  // so thu tu
	int g;      // khoang cach tu dinh ban dau den dinh hien ta
	int f;      // f = h + g;
	int h;      // duong di ngan nhat
	int color;  // danh dau dinh di qua
	int parent;    // dinh cha
};

int a[100][100];
Node p[100];
Node Open[100];
Node Close[100];

void ReadInputFile1(int *b, int &n)
{
	fstream fs1("Input1.txt");

	if (!fs1.is_open())
	{
		cout << "Khong the mo duoc file!";
	}
	else
	{
		fs1 >> n;

		for (int i = 0; i < n; i++)
		{
			fs1 >> b[i];
		}
	}
    fs1.close();
}

void ReadInputFile2(int a[100][100], int &n, int &start, int &finsh)
{
	fstream fs2("Input2.txt");

	if (!fs2.is_open())
	{
		cout << "Khong the mo duoc file!";
	}
	else
	{
		fs2 >> n >> start >> finsh;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				fs2 >> a[i][j];
		}
	}
	fs2.close();
}
void RhowMatrix(int a[100][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << "\n";
	}
}

int Count(int n, Node *Open)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (Open[i].color == 1)
			count++;
	}
	return count;
}

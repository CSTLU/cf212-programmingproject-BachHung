#include "Linked_List.h"
#include <stdlib.h>
#include <stdio.h>
void main()
{
	List ds;
	int N;
	/*ds.AddFirst(1);
	ds.AddLast(8);
	ds.AddLast(7);
	ds.InsertPos(6,3);
	ds.AddLast(5);
	ds.AddLast(2);
	ds.AddLast(3);
	ds.AddLast(5);*/
	cout << "Nhap n: ";
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		ds.AddLast((rand() %(N + 1)));
	}
	//ds.Inra();
	//cout << "\n";
	ds.ShellSort();
	ds.Inra();
}
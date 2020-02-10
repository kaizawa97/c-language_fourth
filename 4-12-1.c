#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main () 
{
	int v[] = {1,5,15,7,2,11};
	int left = 0; 
	int right = 5;
	qsort(v, left, right);
	for (int i = 0; i < 6; i++)
	{
		printf("%d\n",v[i]);
	}
}

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)
	{
		return;
	}
	
	swap(v,left, (left + right) / 2);
	last = left;

	for (i = left + 1; i <= right; i++)
	{
		if (v[i] < v[left])
		{
			swap(v, ++last, i);
		}
	}
		swap(v, left, last);
		qsort(v, left, last-1);
		qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

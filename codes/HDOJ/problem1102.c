/*
 *	HDOJ problem 1102.
 */

#include <stdio.h>
#include <stdlib.h>

#define LENGTH 100
static char set[101];
static char size[101];
static int distance[5000];

static int N;
static int Q;
static int length;

int compare(const void*, const void*);
int kruskal();

int main(int argc, char *argv[])
{
	int i,j,index;
	int data;
	int m,n;
	while(scanf("%d", &N) != EOF)
	{
		if(N <3 || N > 100)
			break;

		// initilize set and size array
		for(i = 1; i < LENGTH + 1; i++)
		{
			set[i] = i;
			size[i] = 1;
		}

		index = 0;
		for(i = 1; i <= N; i++)
		{
			for(j = 1; j <= N; j++)
			{
				scanf("%d", &data);
				if(i > j)
				{
					distance[index] = (distance[index] & 0x00FFFFFF)|((i & 0x000000FF)<<24);
					distance[index] = (distance[index] & 0xFF00FFFF)|((j & 0x000000FF)<<16);
					distance[index] = (distance[index] & 0xFFFF0000)|(data & 0x0000FFFF);
					index++;
				}
			}
		}
		length = index;

		scanf("%d", &Q);
		index = 0;
		while(index++ < Q)
		{
			scanf("%d %d", &i, &j);
			if(i > j) return 1;

			for(m = i; m != set[m]; m = set[m]);
			for(n = j; n != set[n]; n = set[n]);
			if(m == n) continue;
			if(size[m] <= size[n])
			{
				set[m] = n;
				size[n] += size[m];
			}
			else
			{
				set[n] = m;
				size[m] += size[n];
			}
		}

		//kruskal algorithm.
		qsort((void*)distance, length, sizeof(int), compare);
		printf("%d\n", kruskal());
	}
	return 0;
}


int compare(const void* a, const void* b)
{
	const int *p = (const int *)a;
	const int *q = (const int *)b;
	return ((*p) & 0x0000FFFF) - ((*q) & 0x0000FFFF);
}

int kruskal()
{
	int sum = 0;
	int index, elem;
	int i,j,p,q;
	for(index = 0; index < length; index++)
	{
		elem = distance[index];
		i = (elem & 0xFF000000) >> 24;
		j = (elem & 0x00FF0000) >> 16;
		for(p = i; p != set[p]; p = set[p]);
		for(q = j; q != set[q]; q = set[q]);
		if(size[p] == N) break;
		if(p == q) continue;
		if(size[p] <= size[q])
		{
			set[p] = q;
			size[q] += size[p];
		}
		else
		{
			set[q] = p;
			size[p] += size[q];
		}
		sum += (elem & 0x0000FFFF);
	}
	return sum;
}
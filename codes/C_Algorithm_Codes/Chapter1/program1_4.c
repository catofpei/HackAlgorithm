/*
 * connectivity problem
 * weighted-quick-union algorithm with path compression by halving.
 * The num of steps from one node to his root affects the efficiency of weighted-quick-union algorithm.
 */

#include <stdio.h>
#define N 1000

int main(int argc, char **argv)
{
	int i,j,p,q;
	int id[N],sz[N];
	for(i = 0; i < N; i++)
	{
		id[i] = i;
		sz[i] = 1;
	}

	while(scanf("%d %d", &p, &q) == 2)
	{
		//halving-path-compression means that link the node to his grandfather node, skip his parent.
		for(i = p; i != id[i]; i = id[i])
		{
			id[i] = id[id[i]];
		}
		for(j = q; j != id[j]; j = id[j])
		{
			id[j] = id[id[j]];
		}
		if(i == j) continue;

		//weighted means that link the root of smaller tree to bigger one.
		if(sz[i] < sz[j])
		{
			id[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			id[j] = i;
			sz[i] += sz[j];
		}
		//print the unlinked pair.
		printf("%d %d\n", p, q);

	}
	return 0;
}
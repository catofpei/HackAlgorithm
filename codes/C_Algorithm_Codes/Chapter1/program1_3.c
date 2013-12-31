/*
 * To solve the issue of program1_2.c
 * connectivity problem: weighted-quick-union algorithm solution
 * link the root of smaller tree to bigger one, to avoid linear path.
 */
 
 #include <stdio.h>
 #define N 1000
 
 int main(int argc, char **argv)
 {
	int i,j,p,q;
	int id[N], sz[N];
	for(i = 0; i < N; i++)
	{
		id[i] = i;
		sz[i] = i;
	}
	while(scanf("%d %d", &p, &q) == 2)
	{
		for(i = p; i != id[i]; i = id[i]);
		for(j = q; j != id[j]; j = id[j]);
		if(i == j) continue;
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
		printf("%d %d\n", p, q);
	}
	
	
	
	return 0;
}
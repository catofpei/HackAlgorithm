/*
 * Connectivity-Problem. quick-union solution.
 * N objects and M pairs.
 */
 
 /*  TEST EXAMPLE
  * p  q   0  1  2  3  4  5  6  7  8  9
  * 
  * 3  4   0  1  2 _4  4  5  6  7  8  9
  * 4  9   0  1  2  4 _9  5  6  7  8  9
  * 8  0   0  1  2  4  9  5  6  7 _0  9
  * 2  3   0  1 _9  4  9  5  6  7  0  9
  * 5  6   0  1  9  4  9 _6  6  7  0  9
  * 2  9   0  1  9  4  9  6  6  7  0  9
  * 5  9   0  1  9  4  9  6 _9  7  0  9
  * 7  3   0  1  9  4  9  6  9 _9  0  9
  * 4  8   0  1  9  4  9  6  9  9  0 _0
  * 5  6   0  1  9  4  9  6  9  9  0  0
  * 0  2   0  1  9  4  9  6  9  9  0  0
  * 6  1  _1  1  9  4  9  6  9  9  0  0
  * 5  8   1  1  9  4  9  6  9  9  0  0
  */
  
  #include <stdio.h>
  #define N 1000
  
  int main(int argc, char **argv)
  {
	int i,j,p,q;
	int id[N];
	for(i = 0; i < N; i++) id[i] = i;
	while(scanf("%d %d", &p, &q) == 2)
	{
		for(i = p; i != id[i]; i = id[i]);
		for(j = q; j != id[j]; j = id[j]);
		if( i == j) continue;
		id[i] = id[j]; // or id[i] = j;
		printf("%d %d\n", p, q);
	}
		
	return 0;
  }
  
  /*
   * NOTE: worst case:
   * 0-1 1-2 2-3 3-4 4-5 5-6 6-7 7-8 8-9 , 1-9 2-9 3-9 4-8 ...
   * need weighted-quick-union algorithm.
   */
  
  
  
  
  
  
  
  
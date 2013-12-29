/*
 * Program 1-1. connectivity-problem quick-find solution.
 * C Algorithms.
 */

#include <stdio.h>
#define N 1000

int main(int argc, char **argv)
{
	int id[N];
	int i,t,p,q;
	for( i = 0; i < N; i++)
	{
		id[i] = i;
	}
	while(scanf("%d %d", &p, &q) == 2) // books: scanf("%d %d\n", &p, &q). The newline(`\n') will cause some problem when you test.
	{
		if(id[p] == id[q]) continue;
		for( t = id[p], i = 0; i < N; i++)
		{
			if(id[i] == t) id[i] = id[q];
		}
		printf("%d-%d\n", p, q);
	}

	return 0;
}

/*
 * NOTE:
 * scanf("%d%d%d\n",&a,&b,&c);当scanf的格式说明字符串中包含格式符之外的字符
 * 必须输入与之匹配的字符，你这里就是'\n'
 * 但scanf是格式化输入，它把'\n'当成了分格符
 * 从来不读入的，当前输入其它字符时,因为与'\n'不匹配，读取就结束了
 */
 
 
 /*
  *  p   q
  *  3   4
  *  4   9
  *  8   0
  *  2   3
  *  5   6
  *  2   9
  *  5   9
  *  7   3
  *  4   8
  *  5   6
  *  0   2
  *  6   1
  */
/*
 * HDOJ problem 1100
 */

#include <stdio.h>
#define N 100
static int F[N];

void calc_permutations();
void calc_index_nodes(int, int*, int*);
void printTree(int index, int nodes);

int main(int argc, char *argv[])
{
	int n;
	int index, nodes;

	calc_permutations();
	while(scanf("%ld", &n) != EOF)
	{
		if(n <= 0)	break;
		calc_index_nodes(n, &index, &nodes);
		printTree(index, nodes);
		printf("\n");
	}

	return 0;
}

// F[m]代表具有m个节点的二叉树组合个数
void calc_permutations()
{
	int i,j,sum;
	F[0] = 1;
	F[1] = 1;
	F[2] = 2;
	for(i = 3; i < N; i++)
	{
		F[i] = 0;
		for(j = 0; j < i; j++)
			F[i] += F[j] * F[i - 1 - j];
		if(F[i] >= 500000000) break;
	}
}

//计算编号为n的二叉树 的节点个数nodes，以及在相同节点数的二叉树中内部编号index
void calc_index_nodes(int n, int* pindex, int* pnodes)
{
	int i,sum;
	i = 1;
	sum = 0;
	while(sum < n)
	{
		sum += F[i++];
	}
	i--;
	sum -= F[i];
	*pnodes = i;
	*pindex = n - sum;
}

//计算左右子树节点数以及各自内部编号  采用递归的方法打印树
void printTree(int index, int nodes)
{
	int i, sum, L, R, left, right;
	for(i = 0; i < nodes; i++)
	{
		sum = F[i]*F[nodes - 1 - i];
		if(index > sum)
		{
			index -= sum;
		}
		else
		{
			break;
		}

	}
	left = i;
	right = nodes - 1 - i;
	L = index/F[right];
	R = index % F[right];
	if(R != 0)
		L++;
	if(R == 0)
		R = F[right];
	if(left > 0)
	{
		printf("(");
		printTree(L, left);
		printf(")");
	}
	printf("X");
	if(right > 0)
	{
		printf("(");
		printTree(R, right);
		printf(")");
	}
}



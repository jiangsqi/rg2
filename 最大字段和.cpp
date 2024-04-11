#include<iostream>
#include<cstdlib>
#include<cstdio>
#define MAX 10010
using namespace std;
int MaxSubSum(int* a, int left, int right)
{
	int sum = 0;
	if (left == right)
		sum = a[left] > 0 ? a[left] : 0;
	else
	{
		int mid;
		mid = (right + left) / 2;
		int leftsum = MaxSubSum(a, left, mid);
		int rightsum = MaxSubSum(a, mid + 1, right);
		int s1 = 0;
		int lefts = 0;
		for (int i = mid; i >= left; i--)
		{
			lefts += a[i];
			if (lefts > s1)
				s1 = lefts;
		}
		int s2 = 0;
		int rights = 0;
		for (int i = mid + 1; i <= right; i++)
		{
			rights += a[i];
			if (rights > s2)
				s2 = rights;
		}
		sum = s1 + s2;
		if (sum < leftsum)
			sum = leftsum;
		if (sum < rightsum)
			sum = rightsum;
	}
	return sum;
}
int main()
{
	int num;
	int sequence[MAX];
	int ANS;
	
	scanf("%d", &num);
	
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &sequence[i]);
	}
	int o = MaxSubSum(sequence, 0, num - 1);
	printf("%d", o);
	return 0;
}
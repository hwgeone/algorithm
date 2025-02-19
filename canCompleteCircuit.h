#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>

//Input: gas = [2, 3, 4], cost = [3, 4, 3]
//Output : -1

//int gas[] = { 1,2,3,4,5 };
//int cost[] = { 3,4,5,1,2 };
//在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
//你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i + 1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
//给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 - 1 。如果存在解，则 保证 它是 唯一 的。
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
	int n = gasSize;
	if (n == 0)
		return -1;

	int i = 0;
	//第一步，第二步。。。第n步

	while (i < n)
	{
		int step = 0;	
		int rest = 0;
		for (int j = 1; j <= n; j++)
		{
			int next = i + j >= n ? (i + j - n) : i + j;
			int cur = next >= 1 ? next - 1 : next - 1 + n;

			rest += (gas[cur] - cost[cur]);

			if (rest < 0)
			{
				step = i+j;
				break;
			}
		}

		if (step > 0)
		{
			//从0到0+step-1的加油站都不行
			i = step;
		}
		else
		{
			return i;
		}
	}

	return -1;
}

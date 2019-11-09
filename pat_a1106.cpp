// pat_practice.cpp : 定义控制台应用程序的入口点。


#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>
#include <algorithm>
#define and &&
#define or ||

/*
dfs还是得学习一个
A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.

Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.

Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.

Input Specification:
Each input file contains one test case. For each case, The first line contains three positive numbers: N (≤10
​5
​​ ), the total number of the members in the supply chain (and hence their ID's are numbered from 0 to N−1, and the root supplier's ID is 0); P, the price given by the root supplier; and r, the percentage rate of price increment for each distributor or retailer. Then N lines follow, each describes a distributor or retailer in the following format:

K
​i
​​  ID[1] ID[2] ... ID[K
​i
​​ ]

where in the i-th line, K
​i
​​  is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. K
​j
​​  being 0 means that the j-th member is a retailer. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price. There must be one space between the two numbers. It is guaranteed that the all the prices will not exceed 10
​10
​​ .


*/

using namespace std;
int num = 0;
void dfs(vector<vector<int> > &v, double price, int index, double &min_price, double rate)
{
	if(v[index].size() == 0)
	{
		if(price < min_price)
		{
			min_price = price;
			num = 1;
		}
		else if(price = min_price)
			num++;
	}
	else
	{

		for(int i = 0;i < v[index].size();++i)
		{
			dfs(v, price * (1+rate / 100), v[index][i], min_price, rate);
		}
		
	}
	return;
}


int main()
{
	int n;
	double price, rate;
	double min_price = INT_MAX;
	cin >> n >> price >> rate;
	vector<vector<int> > v;
	v.resize(n);
	for(int i = 0;i < n;++i)
	{
		int k;
		cin >> k;
		for(int j = 0;j < k;++j)
		{
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	dfs(v,price,0,min_price,rate);
	printf("%.4f %d\n", min_price, rate);
	return 0;
}

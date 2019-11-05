// pat_practice.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
你可以假设网格的四个边均被水包围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


dfs bfs 并查集

*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <set>

#define and &&
#define or ||

using namespace std;

class Solution {
private:
	int dfs(vector<vector<char> >& grid, int r, int c){
		int nr = grid.size();
		int nc = grid[0].size();
		grid[r][c] == '0';
		if(r - 1 >= 0 and grid[r-1][c] == '1')	dfs(grid, r - 1, c);
		if(r + 1 < nr and grid[r+1][c] == '1')	dfs(grid, r + 1, c);
		if(c - 1 >= 0 and grid[r][c-1] == '1')	dfs(grid, r, c - 1);
		if(c + 1 < nc and grid[r][c+1] == '1')	dfs(grid, r, c+1);
	}

public:
    int numIslands(vector<vector<char>>& grid) {
		int nr = grid.size();
		if(!nr)	return 0;
		int nc = grid[0].size();
		int islands = 0;
		for(int i = 0;i < nr;++i)
		{	
			for(int j = 0;j < nc;++j){
				if(grid[i][j] == '1')
				{
					islands++;
					dfs(grid, i, j);
				}
			}
		}
		return islands;
    }
};


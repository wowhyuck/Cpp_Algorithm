﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 그래프/트리 응용
// 오늘의 주제 : 최소 스패닝 트리 (Minimum Spanning Tree)

class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	// 니 대장이 누구니?
	//    [3]         [3]
	// [4][5]  ->  [4][5][0]   최적화
	//    [0]
	int Find(int u)
	{
		if (u == _parent[u])
			return u;

		_parent[u] = Find(_parent[u]);
		return _parent[u];
	}

	// u와 v를 합친다
	void Merge(int u, int v)
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

		// rank[u] <= rank[v] 보장됨
		_parent[u] = v;

		// [1]	       [3]
		// [2]	->  [4][5][1]
		// [6]	       [0][2]
		//                [6]
		if (_rank[u] == _rank[v])
			_rank[v]++;

	}

private:
	vector<int> _parent;
	vector<int> _rank;
};

struct Vertex
{
	// int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;	// 인접 행렬

void CreateGraph()
{
	vertices.resize(6);
	adjacent = vector<vector<int>>(6, vector<int>(6, -1));

	adjacent[0][1] = adjacent[1][0] = 15;
	adjacent[0][3] = adjacent[3][0] = 35;
	adjacent[1][2] = adjacent[2][1] = 5;
	adjacent[1][3] = adjacent[1][3] = 10;
	adjacent[3][4] = adjacent[4][3] = 5;
	adjacent[3][5] = adjacent[5][3] = 10;
	adjacent[5][4] = adjacent[4][5] = 5;
}

struct CostEdge
{
	int cost;
	int u;
	int v;

	bool operator<(CostEdge& other)
	{
		return cost < other.cost;
	}
};

int Kruskal(vector<CostEdge>& selected)
{
	int ret = 0;

	selected.clear();
	vector<CostEdge> edges;

	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent[u].size(); v++)
		{
			if (u > v)
				continue;

			int cost = adjacent[u][v];
			if (cost == -1)
				continue;

			edges.push_back(CostEdge{ cost, u, v });
		}
	}

	std::sort(edges.begin(), edges.end());

	DisjointSet sets(vertices.size());

	for (CostEdge& edge : edges)
	{
		// 같은 그룹이면 스킵 (안 그러면 사이클 발생)
		if (sets.Find(edge.u) == sets.Find(edge.v))
			continue;

		// 두 그룹을 합친다
		sets.Merge(edge.u, edge.v);
		selected.push_back(edge);
		ret += edge.cost;
	}

	return ret;
}


int main()
{
	CreateGraph();

	vector<CostEdge> selected;
	int cost = Kruskal(selected);



	return 0;
}
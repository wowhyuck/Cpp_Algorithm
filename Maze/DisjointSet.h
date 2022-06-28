﻿#pragma once
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


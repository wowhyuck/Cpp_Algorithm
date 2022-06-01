#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 힙 정렬
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// O(NlogN)
	for (int num : v)
		pq.push(num);

	v.clear();

	// O(NlogN)
	while (pq.empty() == false)
	{
		v.push_back(pq.top());
		pq.pop();
	}
}


int main()
{
	vector<int> v{ 5, 1, 3, 4, 2 };

	HeapSort(v);

	return 0;
}
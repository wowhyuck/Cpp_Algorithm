#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [5][J][3][K][9]
// 예를들어 왼쪽부터 시작해서 가장 작은 수를 찾아서 배치한다.
// [3][5][9][J][K]
// 2) 선택 정렬 (Selection Sort)
void SelectionSort(vector<int>& v)
{
	const int n = (int)v.size();

	// O(N^2)
	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}

		// 교환
		int temp = v[i];
		v[i] = v[bestIdx];
		v[bestIdx] = temp;
	}
}

int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	//std::sort(v.begin(), v.end());
	SelectionSort(v);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [3][J][5][K][9]
// [3][5][J][9][K]
// [3][5][9][J][K]
// 1) 버블 정렬 (Bubble Sort)
void BubbleSort(vector<int>& v)
{
	const int n = (int)v.size();

	// (N - 1) + (N - 2) + ... + 2 + 1
	// 등차수열의 합 = N * (N - 1) / 2
	// O(N^2)
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
		{
			if (v[j] > v[j + 1])
			{
				int temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
			}
		}
	}
}

int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	//std::sort(v.begin(), v.end());
	BubbleSort(v);

	return 0;
}
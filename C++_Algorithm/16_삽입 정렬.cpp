#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [5] [J][3][K][9]
// 왼쪽은 정렬, 오른쪽은 후보군
// 
// [J]
// [5] [J][3][K][9]
// 
// [3]
// [5][J] [3][K][9]
// 
// ...
// 
// [3][5][9][J][K]
// 3) 삽입 정렬 (Insertion Sort)
void InsertionSort(vector<int>& v)
{
	const int n = (int)v.size();

	// O(N^2)
	for (int i = 1; i < n - 1; i++)
	{
		int insertData = v[i];

		int j;

		for (int j = i - 1; j >= 0; j--)
		{
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else
				break;
		}

		v[j + 1] = insertData;
	}
}

int main()
{
	vector<int> v{ 1, 5, 3, 4, 2 };

	//std::sort(v.begin(), v.end());
	InsertionSort(v);

	return 0;
}
﻿#include <iostream>
#include <vector>

using namespace std;

// 정렬된 배열을 이용해서 이진 탐색 가능 (numbers[mid])
// - 잠깐! 그런데 배열의 단점은 뭐더라?
// -- 중간 삽입/삭제가 느리다!
// 정렬된 연결 리스트로는 불가 (임의 접근X)
vector<int> numbers;

// O(logN)
void BinarySearch(int N)
{
	int left = 0;
	int right = (int)numbers.size() - 1;

	while (left <= right)
	{
		cout << "탐색 범위:" << left << " ~ " << right << endl;
		int mid = (left + right) / 2;

		if (N < numbers[mid])
		{
			cout << N << " < " << numbers[mid] << endl;
			right = mid - 1;
		}
		else if (N > numbers[mid])
		{
			cout << N << " > " << numbers[mid] << endl;
			left = mid + 1;
		}
		else
		{
			cout << "찾음!" << endl;
			break;
		}
	}
}


int main()
{
	numbers = vector<int>{ 1, 8, 15, 23, 32, 44, 56, 63, 81, 91 };
	BinarySearch(82);

	return 0;
}
#include <iostream>
#include <vector>

#include "BinarySearchTree.h"

using namespace std;

// 오늘의 주제 : 이진 탐색 트리

int main()
{
	BinarySearchTree bst;

	bst.Insert(20);
	bst.Insert(10);
	bst.Insert(30);
	bst.Insert(25);
	bst.Insert(26);
	bst.Insert(40);
	bst.Insert(50);

	bst.Delete(20);
	bst.Delete(26);

	bst.Print();

	return 0;
}
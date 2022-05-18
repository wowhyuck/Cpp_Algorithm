#include <iostream>
#include <vector>
#include <thread>

#include "BinarySearchTree.h"

using namespace std;

// 오늘의 주제 : 레드 블랙 트리

int main()
{
	BinarySearchTree bst;

	bst.Insert(30);
	bst.Print();
	this_thread::sleep_for(1s);
	
	bst.Insert(10);
	bst.Print();
	this_thread::sleep_for(1s);
	
	bst.Insert(20);
	bst.Print();
	this_thread::sleep_for(1s);
	
	bst.Insert(25);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(20);
	bst.Print();
	this_thread::sleep_for(1s);

	bst.Delete(10);
	bst.Print();

	return 0;
}
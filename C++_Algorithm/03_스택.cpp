#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

// Stack (LIFO Last-In-First-Out 후입선출)

template<typename T>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	T& top()
	{
		return _container.back();
	}

	bool empty() { return _container.empty(); }
	int size() { return _container.size(); }

private:
	//vector<T> _container;
	list<T> _container;
};


int main()
{
	//stack<int> s;
	Stack<int> s;

	// 삽입
	s.push(1);
	s.push(2);
	s.push(3);
	
	// 비었나?
	while (s.empty() == false)
	{
		// 최상위 원소
		int data = s.top();

		// 최상위 원소 삭제
		s.pop();

		cout << data << endl;
	}

	int size = s.size();

	return 0;
}
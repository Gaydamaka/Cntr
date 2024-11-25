#include <iostream>
#include <list>
using namespace std;

template <typename T>
class Stack {
	list<T> data; 
	unsigned int index = 0;


public:
	void Clear() {
		data.clear();
		index = 0;
	}

	bool IsEmpty() const {
		return index == 0;
	}

	bool IsFull() const {
		return false;
	}

	unsigned int GetCount() const {
		return index;
	}

	void Push(T value) {
		data.push_back(value);
		index++;
	}

	void Pop() {
		if (!IsEmpty()) {
			data.pop_back();
			index--;
		}
	}

	int Peek() {
		if (!IsEmpty())
			return data.back();
		else throw "Stack is empty!";
	}

	bool Contains(T value) {
		for (auto it = data.begin(); it != data.end(); it++)
		{
			if (*it == value) return true;
			next(it);
		}
		return false;
	}

	int PushLessValue(T value) {
		if (value < data.back()) {
			data.push_back(value);
			index++;
		}
		else return -1;
	}

	int PushUnique(T value) {
		if (!Contains(value)) {
			data.push_back(value);
			index++;
		}
		else return -1;
	}

	void Print() {

		unsigned int i;
		for (auto it = data.begin(); it != data.end(); it++)
		{
			i = *it;
			cout << i << ", ";
			next(it);
		}

	}
};

int main() {
	Stack<int> st; 

	for (int i = 0; i < 100; i++)
		st.Push(rand() % 90 + 10); 

	while (!st.IsEmpty()) {
		cout << st.Peek() << "  ";
		st.Pop();
	}

	Stack<int> st2;
	st2.Push(10);
	st2.Push(20);
	st2.Push(30);
	st2.Push(40);
	st2.Push(50);

	bool result = st2.Contains(40);
	cout << "\n" << result << "\n";

	st2.Print();
}
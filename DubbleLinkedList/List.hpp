#ifndef LIST_HPP
#define LIST_HPP
#include <vector>
#include <iostream>
#include <string>
class List
{
private:
	struct Node {
		int value;
		Node* previous;
		Node* next;
	};

	Node* first;
	Node* last;

	void insert(int value, Node* currentNode);
		
public:
	List(std::vector<int> elements = {});
	List(List& other, bool killother = 0);

	~List();


	void insert(int value);
	void insert(std::vector<int> elements);
	void remove(int index);
	void showAll() const;

	List& move(List& other);
	List& operator=(List& other);
	int& operator[](int index) const;
	int getNumberOf() const;
};

#endif // !LIST_HPP

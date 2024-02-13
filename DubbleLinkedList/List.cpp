#include "List.hpp"


void List::insert(int value, Node* currentNode)
{
	if (currentNode == nullptr) {
		Node* newNode = new Node{ value, last, nullptr };
		last->next = newNode;
		last = newNode;
		return;
	}
	if (value < currentNode->value) {
		Node* newNode = new Node{ value, currentNode->previous, currentNode };

		currentNode->previous = newNode;
		if (currentNode != first) newNode->previous->next = newNode;
		else first = newNode;
		return;
	}
	return insert(value, currentNode->next);
}

List::List(std::vector<int> elements)
{
	for (int i : elements) {
		insert(i);
	}
}

List::~List()
{
	Node* next = first;
	while (first != nullptr) {
		next = first->next;
		delete first;
		first = next;
	}
}

void List::insert(int value)
{
	if (first == nullptr) {
		first = new Node{ value, nullptr, nullptr };
		last = first;
	}
	else insert(value, first);
}

void List::insert(std::vector<int> elements)
{
	for (int i : elements) {
		insert(i);
	}
}

void List::remove(int index)
{
	if (first == nullptr) return;
	Node* currentNode = first;
	for (int i = 0; i < index; i++)
	{
		if (currentNode == nullptr) return;
		currentNode = currentNode->next;
	}
	if(currentNode->next != nullptr) currentNode->next->previous = currentNode->previous;
	if (currentNode->previous != nullptr) currentNode->previous->next = currentNode->next;
	delete currentNode;
}

void List::showAll() const 
{
	Node* currentNode = first;
	std::string list = "{";
	while (currentNode != nullptr) {
		list += std::to_string(currentNode->value);
		if (currentNode->next != nullptr) list += ", ";
		currentNode = currentNode->next;
	}
	list += "}";
	std::cout << list + "\n";
}

int List::operator[](int index) const
{
	Node* currentNode = first;
	for (int i = 0; i < index; i++)
	{
		if (currentNode->next == nullptr) return currentNode->value;
		currentNode = currentNode->next;
	}
	return currentNode->value;
}

int List::getNumberOf() const
{
	int nrOf = 0;
	Node* currentNode = first;
	while (currentNode != nullptr) {
		nrOf++;
		currentNode = currentNode->next;
	}
	return nrOf;
}

#include "List.hpp"

/*Insert func for recursivly going through the nodes until the value added is less than the next value, should not be used directly for inserting values*/
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

/*Whipes the list*/
void List::freeMemory()
{
	Node* next = first;
	while (first != nullptr) {
		next = first->next;
		delete first;
		first = next;
	}
}

/*Creates a list with the elements in the vector*/
List::List(std::vector<int> elements)
{
	for (int i : elements) {
		insert(i);
	}
}

/*Copies other List object and creates a new List*/
List::List(List& other)
{
	Node* otherCurrentNode = other.first;
	{
		while (otherCurrentNode != nullptr) {
			insert(otherCurrentNode->value);
			otherCurrentNode = otherCurrentNode->next;
		}
	}
}

/*creates a new list and moves others items into this list, leaves other list empty*/
List::List(List&& other)
{
	this->first = other.first;
	this->last = other.last;

	this->first = nullptr;
	this->last = nullptr;
}

/*Destructor*/
List::~List()
{
	freeMemory();
}

/*Inserts value in order of size*/
void List::insert(int value)
{
	if (first == nullptr) {
		first = new Node{ value, nullptr, nullptr };
		last = first;
	}
	else insert(value, first);
}

/*Inserts multiple values in order of size*/
void List::insert(std::vector<int> elements)
{
	for (int i : elements) {
		insert(i);
	}
}

/*Removes value at index*/
void List::remove(int index)
{
	if (first == nullptr) return;
	Node* currentNode = first;
	for (int i = 0; i < index; i++)
	{
		if (currentNode->next == nullptr) break;
		currentNode = currentNode->next;
	}

	if (currentNode != first && currentNode != last) {
		currentNode->next->previous = currentNode->previous;
		currentNode->previous->next = currentNode->next;
	}
	if (currentNode == first) {
		if (currentNode->next != nullptr) currentNode->next->previous = nullptr;
		first = currentNode->next;
	}
	if (currentNode == last) {
		if(currentNode->previous != nullptr) currentNode->previous->next = nullptr;
		last = currentNode->previous;
	}
	delete currentNode;
}

/*Prints out all values*/
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

/*Moves list from other list to this list, other list becomes empty*/
List& List::move(List& other)
{
	Node* next = first;
	while (first != nullptr) {
		next = first->next;
		delete first;
		first = next;
	}

	this->first = other.first;
	this->last = other.last;
	other.last = nullptr;
	other.first = nullptr;

	return *this;
}

/*Overwrites this list to match other list*/
List& List::operator=(List& other)
{
	if (this != &other) {
		freeMemory();

		Node* otherCurrentNode = other.first;
		while (otherCurrentNode != nullptr) {
			insert(otherCurrentNode->value);
			otherCurrentNode = otherCurrentNode->next;
		}
	}
	return *this;
}

/*moves other list to this list, leaves other list empty*/
List& List::operator=(List&& other)
{
	freeMemory();

	this->first = other.first;
	this->last = other.last;
	other.last = nullptr;
	other.first = nullptr;
}

/*Returns reference value at place index*/
int& List::operator[](int index) const
{
	Node* currentNode = first;
	for (int i = 0; i < index; i++)
	{
		if (currentNode->next == nullptr) return currentNode->value;
		currentNode = currentNode->next;
	}
	return currentNode->value;
}

/*Returns number of elements in the list*/
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
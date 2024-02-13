#include "List.hpp"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	List a({ 1,2,3,4,5,6 });
	a.showAll();
	std::cout << a[0] << "\n";
	std::cout << a[5] << "\n\n";

	List b({ 0,2,4,6,8,10 });
	b.insert(1);
	b.insert(-1);
	b.insert(11);
	b.remove(0);
	b.remove(0);
	b.remove(6);
	b.remove(5);
	b.remove(2);
	b.showAll();
	std::cout << b[0] << "\n";
	std::cout << b[5] << "\n\n";

}
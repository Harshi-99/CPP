#include <iostream> 
class A { 
private: 
	int a = 5; 
    void showA(int a) 
	{ 
		// Since B is friend of A, it can access 
		// private members of A 
		std::cout << "A::a=" <<a; 
	} 
public: 
	A() { a = 0; } 

	friend class B; // Friend Class 
}; 

class B { 
private: 
	int b; 

public: 
	void showA(int a) 
	{ 
		// Since B is friend of A, it can access 
		// private members of A 
		std::cout << "A::a=" <<a; 
	} 
}; 

int main() 
{ 
	
	b.showA(a); 
	return 0; 
} 

#include "factory.h"
#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 
#include <list>
using namespace std;

class ICustomer {
public:
	virtual double Discount()=0;
	static ICustomer* Create(int type);
	//static ICustomer* virtual ~ICustomer() {}
};

class PrivilegedCustomer : public ICustomer {
public:
	double Discount() {
		return 0.4 * 100;
	}
};

class OrdinaryCustomer : public ICustomer {
public:
	double Discount() {
		return 0.1 * 100;
	}
};

//Factory
ICustomer* ICustomer::Create(int type) {
	if (type == 1) return new PrivilegedCustomer();
	if (type == 2) return new OrdinaryCustomer();
	return NULL;
}



//Client
int main()
{
	ICustomer* obj1 = ICustomer::Create(1);
	ICustomer* obj2 = ICustomer::Create(2);

	cout << "   $$ PrivilegedCustomer: " << obj1->Discount() << '\n';
	cout << "   $$ OrdinaryCustomer: " << obj2->Discount() << '\n';

}
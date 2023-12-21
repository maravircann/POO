#include<iostream>
#include<string>
using namespace std;
class A {
	string attrA;
public: 
	A() {
		attrA = "";
	}
	A(string attrA) {
		this->attrA = attrA;
	}
	virtual string showDetails() { 
		return "Eu sunt attrA";
	}
};

class B:public A {
	string attrB;
public:
	B() {
		attrB = "";
	}
	B(string attrA, string attrB):A(attrA) {
		this->attrB = attrB;
	}
	string showDetails() override{
		return "Eu sunt attrB";
	}
};

int main() {
	A** vector = new A*[4];
	vector[0] = new A("dcf");
	vector[1] = new B("dsf", "egyds");
	vector[2] = new B("deuek", "dveys");
	vector[3] = new A("rft");
	cout<<vector[0]->showDetails()<<endl;
	cout<<vector[1]->showDetails()<<endl;
	cout<<vector[2]->showDetails()<<endl;
	cout<<vector[3]->showDetails()<<endl;
	//ar aparea numai eu sunt attra deci punem virtual
}
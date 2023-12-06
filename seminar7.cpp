#include <iostream>
#include <string>
using namespace std;

class Product
{
	int id;
	char* name;
	char* description;
	double price;
	double* priceHistory;
	int historySize;

public:
	Product(int id, const char* name, const char* description, double price, const double* priceHistory, int historySize)
	{

		
	}
	Product(int _id, char* _name, char* _description, double _price, double* _priceHistory, int _historySize) : id(_id), name(_name), description(_description), price(_price), priceHistory(_priceHistory), historySize(_historySize)
	{

		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);

		this->description = new char[strlen(_description) + 1];
		strcpy_s(this->description, strlen(_description) + 1, _description);

		this->priceHistory = new double[_historySize];
		for (int index = 0; index < _historySize; index++)
		{
			this->priceHistory[index] = _priceHistory[index];
		}
	}

	Product(const Product& product) {

		this->id = product.id;
		this->name = new char[strlen(product.name) + 1];
		strcpy_s(this->name, strlen(product.name) + 1, product.name);

		this->description = new char[strlen(product.description) + 1];
		strcpy_s(this->description, strlen(product.description) + 1, product.description);

		this->price = product.price;

		this->priceHistory = new double[product.price];
		for (int index = 0; index < product.price; index++)
		{
			this->priceHistory[index] = product.priceHistory[index];
		}
		this->historySize = product.historySize;

	}

	//all setters

	void set_name(char* _name) {
		this->name = _name;
	}

	void set_description(char* _description) {
		this->description = _description;
	}

	/*void set_priceHistory(double* _priceHistory, double _price)
	{
		this->price = _price;

		this->priceHistory = new double[_price];
		for (int i = 0; i < _price; i++)
		{
			this->priceHistory[i] = _priceHistory[i];
		}
	}*/
	//all getters

	int get_id() { return this->id; }
	char* get_name() { return this->name; }
	char* get_description() { return this->description; }
	double get_price() { return this->price; }
	double* get_priceHistory() { return this->priceHistory; }
	int get_history() { return this->historySize; }

	double getPriceAverage()
	{
		if (priceHistory) {
			double sum = 0;
			for (int index = 0; index < historySize; index++) {
				sum += priceHistory[index];
			}
			return sum / historySize;
		}
		return 0;
	}

	~Product()
	{
		delete[] this->name;
		delete[] this->description;
		delete[] this->priceHistory;
	}



};

int main() {


	int historySize = 6;
	double priceHistory[6] = { 156, 170, 184, 235, 127, 323 };
	Product myProd(1, "Produs", "Descriere", 20.50, priceHistory, 6);
	return 0;



}
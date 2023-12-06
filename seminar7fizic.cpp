#include<iostream>
using namespace std;

class Masina
{
private:
	string marca;
	char* model;
	string nr_inmatriculare;
	static int total_masini_fabricate;

public:

	Masina(string mparam_arca, char* param_model, string nr_inmatriculare, static int total_masini_fabricate) {

	}
	Masina(string _marca, char* _model, string _nr_inmatriculare, static int _tottal_masini_fabricate) : marca(_marca), model(_model), nr_inmatriculare(_nr_inmatriculare), total_masini_fabricate(_total_masini_fabricate)
	{
		this->marca = _marca;
		this->model = new char[strlen(_model) + 1];
		strcpy_s(this->model, strlen(_model) + 1, _model);

	}

	Masina(const Masina& masina) {
		this->marca = masina.marca;
		this->model = new char[strlen(masina.model) + 1];
		strcpy(this->model, strlen(masina.model) + 1, masina.model);
		this->nr_inmatriculare = masina.nr_inmatriculare;
		this->total_masini_fabricate = masina.total_masini_fabricate;
	}

	
	string get_marca() { return this->marca; }
	char* get_model() { return this->model; }
	string get_nr_inmatriculare() { return this->nr_inmatriculare; }
	static int get_total_masini_fabricate() { return this->total_masini_fabricate; }


string getMarca() {
	return this->marca;
}
char* getModel() {
	//return this->model; /asa nu

	char* tmp = new char[strlen(this->model) + 1];
	strcpy_s(this->model, strlen(_model) + 1,_model);
	return tmp;
	
}

string getNrInmatriculare() {
	return this->nr_inmatriculare;
}

void setMarca(string marca) {
	this->marca = marca;
}
void setNrINmatriculare(string nr_inmatriculare) {
	this->nr_inmatriculare = nr_inmatriculare;
}
void setModel(char* model) {

	this->model = new char[strlen(_model) + 1];
	strcpy_s(this->model, strlen(_model) + 1, _model);
	

}

};

static void incrementMasina()
{
	Masina::total_masini++;
}



int main(){

	Masina a("dacia", (char*)"spring", "B123TGR");
	Masina::incrementMasina();
	Masina a("audi", (char*)"a1", "B566NBV");
	Masina::incrementMasina();
}







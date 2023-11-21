
/*sa se implementeze o clasa spital conf urm cerinte :  alegem noi ce tip de data este
clasa are cel putin urmm atrib:
	*cif (cod de identif fiscala -valoare de tip sir de caractere se atriib valoare la crearea obiectului si apoi nu se mai puate modifica
	* nume (sie de caractere)
	* adresa (sir de caractere)
	* medici (vector de valori string alocat dinamic)
	* nrMedici
	* nrSpitale (va retine nr de spiatle - obiecte de tip spital - instantiate vreodata -sttaic)
	
	se vor implementa: 
	-constructor fara parametri
	-constructor cu param
	-constructor de copiere
	-destructor
	

	-supraincarcare operator =
	-supraincarecare operatori de citire si scrieer din/in consola (>> si <<)
	-supraincarcare op [] -returneaza medicul de pe o pozitie data --atat in mod scriere cat si in mod
	-supr op !
	-cast explici int - returneaza numarul de spitale instantiate

	-toate atrib treb sa fie private
	-metode de get si set
	-cel putin unul dintre atrib de tip sir de caractere treb sa fie de char*
	*/
#include<iostream>
#include<string>
using namespace std;

class Spital {
private:
	const string cif; //atributul este const dar parametrul din constructor e o variabila care ia valoarea in consola
	char* nume; //aici punem const si in constructor
	string adresa;
	string* medici;
	int nrMedici;
	static int nrSpitale; //treb sa i da valoare initiala
public:
	Spital():cif("") {
		this->nume = nullptr;
		this->adresa = "";
		this->medici = nullptr;
		this->nrMedici = 0;

	}

	Spital(string _cif, const char* _nume, string _adresa, const string* _medici, int _nrMedici) : cif(_cif), adresa(_adresa), nrMedici(_nrMedici)
	{
		if (_nume != nullptr) {
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		else
		{
			this->nume = nullptr;
		}

		this->medici = new string[_nrMedici];
		for (int i = 0; i < _nrMedici; i++) {
			this->medici[i] = _medici[i];
		}
		Spital::nrSpitale++; //pt a arata ca a mai fost construit un spital
	}

	Spital( Spital& s) : Spital(s.cif,s.nume, s.adresa, s.medici, s.nrMedici) {

	}

	Spital& operator =(Spital& s)
	{
		//this -> cif = s.cif; //nu pot sa fac asignarea pt ca am const string
		if (this == &s)
			return *this;

		delete[] this->nume;
		this->nume = new char[strlen(s.nume) + 1];
		strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);

		delete[] this->medici;
		this->nrMedici = s.nrMedici;
		this->medici = new string[s.nrMedici];
		
		//this->nume = s.nume;
		//this->medici = s.medici;

		for (int i = 0; i < s.nrMedici; i++) {
			this->medici[i] = s.medici[i];
			this->adresa = s.adresa;
		}

		return *this;
	}

	void setNume(const char* _nume)
	{
		if (_nume != nullptr) {
			delete[] this->nume;
			this->nume = new char[strlen(_nume) + 1];
			strcpy_s(this->nume, strlen(_nume) + 1, _nume);
		}
		else
			this->nume = nullptr;
	}

	void setAdresa(string _adresa) { this->adresa = _adresa; }
	void setMedici(const string* _medici, int _nrMedici) {
		if (_medici != nullptr && _nrMedici > 0)
		{
			delete[] this->medici;
			this->nrMedici = _nrMedici;
			this->medici = new string[_nrMedici];
			for (int i = 0; i < _nrMedici; i++) {
				this->medici[i] = _medici[i];
			}
				
		}
		else {
			this->medici = nullptr;
			this->nrMedici = 0;
		}
	}

	char* getNume() {
		char* copy = new char[strlen(this->nume) + 1];
		strcpy_s(copy, strlen(this->nume) + 1, this->nume);
		return copy;
	}

	friend ostream& operator << (ostream& os, Spital s);
	friend istream& operator >>(istream& is, Spital& s)
	{
		char* tmp = new char[256];
		cout <<endl<<endl<< "Nume: ";
		is.getline(tmp, 256);
		s.setNume(tmp);

		cout << "Adresa: ";
		is.getline(tmp, 256);
		s.setAdresa(tmp);

		cout << "Nr medici";

		int tmpNr;
		is >> tmpNr;

		cout << "Numele pt " << tmp << " medici";
		string* medici = new string[tmpNr];
		for (int i = 0; i < tmpNr; i++ ){
			is.getline(tmp, 256);
			medici[i] = (string)tmp;
		}
		s.setMedici(medici, tmpNr);

		return is;

		return is;
	}
	~Spital() {
		delete[] this->nume;
		delete[] this->medici;
		Spital::nrSpitale--; //pt a ev ca afost desfintat un spital   daca cerinta ar fi ca nr spitale sa retina spitalele active, obiecte instantiate care nu au fost sterse
	}
};

ostream& operator << (ostream& os, Spital s) {
	os << "CIF:" << s.cif << endl;
	os << "Nume:" << s.nume << endl;
	os << "Adresa:" << s.adresa << endl;
	os << "Nr medici:" << s.nrMedici << endl;
	for (int i = 0; i < s.nrMedici; i++)
		os << s.medici[i] << " ";
	return os;
}

int Spital::nrSpitale = 0;

int main() {

	string* medici = new string[3];
	medici[0] = "medic 1";
	medici[1] = "medic 2";
	medici[2] = "medic 3";
	Spital s1, s2("RO1234","floreasca","Bucuresti", medici, 3);
	s2 = s2;
	s1 = s2;
	s1.setNume("alt nume");
	cout << s2;
	Spital s3;

	cin >> s3;
	return 0;
}
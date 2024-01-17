#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
    Person() : name(nullptr), age(0), adresa(nullptr){}
    Person(const string& n, int a, const string& adr) : age(a) {
        name = new char[n.size() + 1];
        strcpy_s(name, n.size() + 1, n.c_str());

        adresa = new char[adr.size() + 1];
        strcpy_s(adresa, adr.size() + 1, adr.c_str());
    }

    // Destructor pentru a elibera memoria alocata dinamic
    ~Person() {
        delete[] name;
        delete[] adresa;
    }

    // Funcție de serializare
    void Serialize(ofstream& ofs) const {
        size_t nameLength = strlen(name) + 1;
        ofs.write( reinterpret_cast<const char*>(&nameLength), sizeof(nameLength)); // Scriem lungimea numelui
        ofs.write(name, nameLength);//scriem numele propriu-zis, nameLenght lungimea stabilita mai devreme
        ofs.write(reinterpret_cast<const char*>(&age), sizeof(age));

        size_t adresaLength = strlen(adresa) + 1;
        ofs.write(reinterpret_cast<const char*>(&adresaLength), sizeof(adresaLength));
        ofs.write(adresa, adresaLength);
    }

    // Funcție de deserializare
    void Deserialize(ifstream& ifs) {
        size_t nameLength;
        ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength)); // Citim lungimea numelui
        delete[] name; //vreau sa suprascriu si trebuie sa eliberez spatiul de mem altfel rezulta memory leak
        name = new char[nameLength];
        ifs.read(name, nameLength);
        ifs.read(reinterpret_cast<char*>(&age), sizeof(age));

        size_t adresaLength;
        ifs.read(reinterpret_cast<char*>(&adresaLength), sizeof(adresaLength)); 
        delete[] adresa; 
        adresa = new char[adresaLength];
        ifs.read(adresa, adresaLength);
    }

    void DisplayInfo() const {
        cout << "Name: " << name << ", Age: " << age << ", Adresa: "<<adresa<<endl;
    }

private:
    char* name;
    int age;
    char* adresa;
};

int mainSD() {
    // Salvare obiect într-un fișier binar
    {
        ofstream outputFile("person.dat", ios::binary); //specific tipul datelor 
        if (!outputFile) {
            cerr << "Error opening file for writing." << endl;
            return 1;
        }

        Person personToSave("John Doe", 25, "Adresa 1");
        personToSave.Serialize(outputFile);

        cout << "Object saved successfully." << endl;
    }

    // Restaurare obiect din fișier binar
    {
        ifstream inputFile("person.dat", ios::binary);
        if (!inputFile) {
            cerr << "Error opening file for reading." << endl;
            return 1;
        }

        Person restoredPerson;
        restoredPerson.Deserialize(inputFile);

        cout << "Object restored successfully." << endl;
        restoredPerson.DisplayInfo();
    }

    return 0;
}

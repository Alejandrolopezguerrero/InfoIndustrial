#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define FILENAME "log.txt"
#define MAX_SIZE 255

using namespace std;

struct alumno {
	string nombre;
	string asignatura;
	int idMat;
	int idGrupo;
};

string toString(const alumno& a);
//marshalling. Aplanar el tipo (convertir los datos en  una cadena de chars legible por el ser humano.
string toString(const alumno& a) {
	string strRET;
	stringstream sstr;
	sstr << "Nombre:" << a.nombre << endl;
	sstr << "Asignatura:" << a.asignatura << endl;
	sstr << "Matricula:" << a.idMat << endl;
	sstr << "Grupo:" << a.idGrupo << endl;

	strRET=sstr.str();//Método interno que devuelve el string del buffer strRET
	return strRET;
}

void clearAlumno(alumno& a) {
	a.nombre.clear(); //Limpia el buffer del string
	a.asignatura.clear();
	a.idMat = NULL;
	a.idGrupo = NULL;
}

int toFile(string filename, const alumno& a) {

	ofstream fout(filename);
	if (!fout) {
		cerr << "Flie don't found" << endl;
		return -1;
	}

	fout << toString(a);

	fout.close();
	return 0;
}

int fromFile(string filename, alumno& a) {
	
	ifstream fin(filename);
	if (!fin) {
		cerr << "Flie don't found" << endl;
		return -1;
	}
	//READ FILE

	string tk1, tk2, tk3, tk4;
	char line[MAX_SIZE];
	//fin >> tk1 >> tk2 >> tk3 >> tk4;

	fin.getline(line, MAX_SIZE);
	tk1 = line;
	if (!fin.good()) {
		cerr << "Error al leer el fichero" << endl;
		return -1;
	}

	a.nombre = tk1.substr(tk1.find_first_of(":")+1);
	fin.getline(line, MAX_SIZE);
	tk2 = line;
	a.asignatura = tk2.substr(tk2.find_first_of(":") + 1);
	fin.getline(line, MAX_SIZE);
	tk3 = line;
	stringstream sstr;
	sstr << tk3.substr(tk3.find_first_of(":") + 1);
	sstr >> a.idMat;
	
	sstr.clear();
	sstr.str("");
	fin.getline(line, MAX_SIZE);
	tk4 = line;
	sstr << tk4.substr(tk4.find_first_of(":") + 1);
	sstr >> a.idGrupo;
	return 0;
}

int main() {
	alumno a;

	a.nombre = "Alejandro Lopez";
	a.idMat = 54044;
	a.asignatura = " INFORMATICA";
	a.idGrupo = 309;

	string str = toString(a);
	cout << str << endl;

	int retval = toFile(FILENAME, a);
	if (retval == -1) {
		cout << "TEST CON FALLO to file" << endl;
	}
	alumno alRead;
	retval=fromFile(FILENAME, alRead);
	if (retval == -1) {
		cout << "TEST CON FALLO from file" << endl;
	}
	cout << "Alumno leido: " << endl;
	cout << toString(alRead);
	return 0;
}
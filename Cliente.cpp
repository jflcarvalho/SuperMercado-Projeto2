#include "Cliente.h"
#include <algorithm>
using namespace std;

Cliente::Cliente(ifstream & in){
	string line;
	getline(cin, line);
	id = stoi(line, nullptr, 10);
	getline(cin, line);
	nome = line;
	getline(cin, line);
	dataAdesao = line;
	getline(cin, line);
	volCompras = stof(line);

}
Cliente::Cliente(unsigned int newId, string newNome, Data newData, float newVolCompras){
	id = newId;
	nome = newNome;
	dataAdesao = newData;
	volCompras = newVolCompras;
}

string Cliente::getNome() const{
  return nome;
}

unsigned int Cliente::getId() const{
  return id;
}


Data Cliente::getDataAdesao() const{
	return dataAdesao;
}

float Cliente::getVolCompras() const{
  return volCompras;
}

void Cliente::save(ofstream & out) const{
	out << id << endl
		<< nome << endl
		<< dataAdesao << endl
		<< volCompras << endl;
	return;

}

ostream& operator<<(ostream& out, const Cliente & cli){
	out << cli.id << " - "
		<< cli.nome << " - "
		<< cli.dataAdesao << " - "
		<< cli.volCompras << endl;
	return out;

}

bool operator<(const Cliente &cli1, const Cliente &cli2){
	return cli1.nome < cli2.nome;
}
void Cliente::setNome(string newName){
	nome = newName;
	cout << "Nome de cliente com id: " << id << ", editado com sucesso para: " << nome << endl;
	return;
}
void Cliente::setDataAdesao(Data newDate){
	dataAdesao = newDate;
	cout << "Data de adesao de cliente com id: " << id << ", editado com sucesso para: " << dataAdesao << endl;
	return;
}
void Cliente::setVolCompras(float newVolCompras){
	volCompras = newVolCompras;
	cout << "Vol. de Compras de cliente com id: " << id << ", editado com sucesso para: " << volCompras << endl;
	return;
}
void Cliente::sortClientsByName(vector<Cliente> &clientsVector){
	sort(clientsVector.begin(), clientsVector.end(), less<Cliente>());
	return;
}
void Cliente::removeClient(vector<Cliente> &clientsVec, unsigned int idCliente){
	for (unsigned int i = 0; i < clientsVec.size(); i++) {
		if (clientsVec.at(i).getId == idCliente) {
			clientsVec.erase(clientsVec.begin() + i);
		}
	}
	return;
}

int getIndexById(unsigned int idOfClient, vector<Cliente> &clientsVector) {
	for (unsigned int i = 0; i < clientsVector.size(); i++) {
		if (clientsVector.at(i).getId() == idOfClient) {
			return i;
		}
	}
	return -1;
}
int getIndexByName(string nameOfClient, vector<Cliente> &clientsVector) {
	for (unsigned int i = 0; i < clientsVector.size(); i++) {
		if (clientsVector.at(i).getNome() == nameOfClient) {
			return i;
		}
	}
	return -1;
}
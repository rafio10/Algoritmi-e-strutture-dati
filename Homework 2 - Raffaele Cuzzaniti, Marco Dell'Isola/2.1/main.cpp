#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>

using namespace std;

void findMax(vector<int>& vector, int& max, int& sum){
    // scorrimento del vettore dall'inizio alla fine
    for(int i=0; i<vector.size(); i++){

        // aggiunta del valore della poizione i-esima del vettore alla somma corrente
        sum += vector[i];

        // controlla se la somma corrente è positiva
        if ( sum > 0 ){

            // controlla se la somma corrente è maggiore del massimo corrente ed in caso positivo pone max = sum
            if(sum > max){
             max = sum;
            }
        } else {

            // se la somma corrente è negativa la pone uguale a 0
            sum = 0;
        } 
    }
}

int main() {
    // apriamo il file in modalità di lettura
    ifstream file;
    file.open("input.txt");

    // istanziamo i parametri necessari: il vettore, max che contiene il sub-array con la somma più grande, sum che tiene traccia della somma corrente
    vector<int> vector;
    int max = 0;
    int sum = 0;
    string line;

    // finchè non legge la parola "END" continua
    while (getline(file, line)) {
        if (line == "END") {
            break;
        } else {
            // l'oggetto iss di tipo istringstream consente di trattare la stringa "line" come uno stream di input
            istringstream iss(line);
            int num;

            // riempe il vettore finchè ci sono interi sulla riga
            while (iss >> num) {
                vector.push_back(num);
            }

            // richiama la funzione che calcola il sub-array con la somma più grande
            findMax(vector, max, sum);
            cout << max << endl;

            // pulizia del vettore e dei parametri per il prossimo caso di test
            vector.clear();
            max = 0;
            sum = 0;
        }
    }

    // chiusura del file
    file.close();
}
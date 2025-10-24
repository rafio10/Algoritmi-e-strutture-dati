// -----------------------------------------------------------------------------------------
/* Algoritmo implementato da:  Marco Dell'Isola, Raffaele Cuzzaniti */
// -----------------------------------------------------------------------------------------
#include  <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> parole;

string commonPrefixUtil(string str1, string str2)
{
	string result;
	int n1 = str1.length(), n2 = str2.length();

    /* Viene eseguito un ciclo for per ogni lettera delle due stringhe, che se uguale viene aggiunto ad un vettore di appoggio.
    Questo fino a quando non viene individuato un carattere differente */
	for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
	{
		if (str1[i] != str2[j])
			break;
		result.push_back(str1[i]);
	}
	return (result);
}

string commonPrefix(vector<string>&  arr, int low, int high)
{
    // Verifica se il vettore è composto da un unico elemento
	if (low == high)
		return (arr[low]);

	if (high > low)
	{
        // Utilizzo di un aproccio ricorsivo che divide il vettore in tanti sottovettori dividendoli a metà
		int mid = low + (high - low) / 2;

		string str1 = commonPrefix(arr, low, mid);
		string str2 = commonPrefix(arr, mid+1, high);

        /* Invocazione delle funzione che individua il prefisso in comunque più lungo tra due parole. Il prefisso viene trovato solo tra due parole in quanto
        la suddivisione del vettore in più sottovettori porterà a dover individuare la parola in comune per un massimo di due stringhe*/
		return commonPrefixUtil(str1, str2);
	}
}

int main(){
    int testcase = 0;
    // Lettura del numero testcase da analizzare
    cin >> testcase;
    int nparole = 0;
    string p;
    bool exit = true;

    for(int k=0; k<testcase; k++){
        while(exit) {
            cin >> p;
            // Si verifica se è stato inserito il carattere terminatore per la fine del set di parole
            if (p == "0"){
                exit = false;
                break;
            }
            parole.push_back(p);
        }
        //Invocazione della funzione che determina il prefisso in comunque più lungo in un set di parole
        cout << commonPrefix(parole, 0, parole.size()-1) << endl;
        parole.clear();
    }

    return 0;
}

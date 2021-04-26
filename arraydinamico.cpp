/*Implementare una classe che simuli il comportamento di un array in maniera dnamica, l' array conterrà solo interi.*/

#include <iostream>
#include <fstream>

using namespace std;

class ArrayDinamico {
	int numeroElementi;
	int dimensioneMassima;
	int * array;
	
	public:
	
	ArrayDinamico(int _dimensioneMassima) : dimensioneMassima (_dimensioneMassima){
		numeroElementi = 0;
		array = new int[dimensioneMassima];
	}
	
	void print(){
		for(int i=0; i < numeroElementi; i++) {
			cout << array[i]<<"\t";
		}
		cout<<endl;
	}
	
	int getDimesioneMassima() {
		return dimensioneMassima;
	}
	
	void setDimensioneMassima(int _dimensioneMassima) {
		dimensioneMassima = _dimensioneMassima;
	}
	
	void inserisci (int n) {
	if(numeroElementi==dimensioneMassima){
		cout<<"sto espandendo la memoria"<<endl;
		
		dimensioneMassima *= 2;
		int * tmp = new int[dimensioneMassima];
		for(int i=0; i<numeroElementi; i++) {
			tmp[i]=array[i];
		}
		int * toDelete =array;
		array =tmp;
		delete [] toDelete;
	}
	
		array[numeroElementi++]=n;
	}
	
	void cancella(int i) {
		for (int j=i; i< numeroElementi-1; j++){
			array[j]=array[j+1];
		}
		numeroElementi--;
		if(numeroElementi < dimensioneMassima/2){
			int * tmp = new int [dimensioneMassima/2];
			for(int j=0; j< numeroElementi; j++){
				tmp[j]=array[j];
			}
			dimensioneMassima/=2;
			
			int * toDelete = array;
			array= tmp;
			delete []toDelete;
		}
	}
};


int main(){
	ArrayDinamico ad(10);
	
	for(int i=0; i<10;i++){
		ad.inserisci(i);
	}
	ad.print();
	ad.inserisci(10);
	ad.inserisci(11);
	ad.print();
}

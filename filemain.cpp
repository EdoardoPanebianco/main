#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "distkey.h"

using namespace std;

int main(){
	ifstream file;
	file.open("input.txt");
	string line;
	if(file.is_open())
	{
		//QUESTO WHILE CARICA TUTTI GLI ELEMENTI DEL FILE TXT NELLA LISTA
		while(getline(file, line) )
		{
			string token, type, operation, data;
			int n, ih, ik;
			char ch, ck;
			typename H;
			BST<int> *bst= new BST<int>;
			BST<char> *cbst=new BST<char>;
			stringstream ss(line);
			//cout << line << "\n";

				getline(ss, token,' ');
				type=token;
				cout << "tipo: " << type << " ";

				
				//BST<T> *Albero = new BST<T>; 


				getline(ss, token,' ');
				n=atoi( token.c_str() );
				cout << "N: " << n << endl;

			for(int i=0; i<n; i++)
			{
				getline(ss, token,' ');
				stringstream sstoken(token);
				//cout << token << "\n";
				getline(sstoken, operation,':');
				getline(sstoken, data,' ');
				//cout << operation << " " << data << ", ";
				if( type=="int" ) {
				int ii=atoi(data.c_str());
				cout <<ii<<endl; 
				bst->insert(ii);
				}
				if( type=="char" ) {
				char ci=data[0];
				cout<<ci<<endl;
				cbst->insert(ci);
				}
			}
			bst->inorder();
			cbst->inorder();
				
				//getline(ss, token,' ');
				if(type=="int") {getline(ss, token,' ');ik=atoi( token.c_str());getline(ss, token,' '); ih=atoi( token.c_str() ); cout << "k: " << ik << " h: " << ih << "\n"; 
				std::cout << "la distanza del valore k: "<<ik <<" dal valore h "<<ih<<" è di: "<<bst->distanzaChiavi(ik,ih)<<" archi"<< std::endl;}
				if(type=="char") {getline(ss, token,' '); ck=token[0]; getline(ss, token,' '); ch=token[0]; cout << "k: " << ck << " h: " << ch << "\n"; 
				std::cout << "la distanza del valore k: "<<ck <<" dal valore h "<<ch<<" è di: "<<cbst->distanzaChiavi(ck,ch)<<" archi"<< std::endl;}
				cout << "\n";
		delete [] bst;
		delete [] cbst;
		}
}
}

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

class Ranking{
	
	public:	
		double calcularIDF(int n,int nt){
			float x,y=n,z=nt;
			if (z==0)
				return (0);
			else 
				x = (y/z);
			return (log(x));
		}
		vector <string> readInput(){ //Le a consulta do teclado e retorna como um vector de strings
			string aux,consulta;
			vector <string> palavras;
			cout << "Digite a consulta desejada: ";
			getline(cin,consulta); //Le a consulta
			for (int i = 0; i < consulta.length(); i++) //separa a consulta em palavras
				if (consulta[i] == ' ') 
				{
					palavras.push_back(aux);
					aux = "";
					this->numPalavras_++;
				}
				else
					aux = aux+consulta[i];	
			palavras.push_back(aux);
			return palavras;
		}
		map<string,double> calculateIDF(map<int,map<string,int>> itf,int tamanho){ //calcula o IDF
			map<string,double> idf; //map que será retornado no final da função
			map<string,int> numArquivos; //quantidade de arquivos que cada palavra aparece
			for (int i=0; i < tamanho; i ++)
				for (auto it=itf[i].begin();it!=itf[i].end() ;it++) //Verificando em quantos documentos cada palavra aparece
					numArquivos[it->first]++;
			for (auto it=numArquivos.begin();it!=numArquivos.end(); it++){//preenchendo map idf
				this->tamanhoIDF_++;
				idf[it->first] = calcularIDF(tamanho,it->second);
			} 
			return idf;
		}
		map<int,map<string,double>> calculateW(map<string,double> idf,map<int,map<string,int>> itf,int tamanho){ //Calcula o valor de W
			map<int,map<string,double>> W;
			for (int i=0; i < tamanho; i ++){ // Preenchendo map "W", que é a multiplicação de ITF e TF
				for (auto it=itf[i].begin();it!=itf[i].end(); it++)
					W[i][it->first] = idf[it->first]*itf[i][it->first];
				this->tamW_++;
			}
			return W;
		}
		map <int,double> calculateCosine(vector<string> frase,map<string,double> idf,map<int,map<string,double>> W,int tamanho){ 
		//Utilizando os parametros de entrada IDF e W, calcula o Cosseno de cada vetor
			int repeteFrase = 1;
			map <int,double> cos;
			double numerador=0,denominador=0,aux1=0,aux2=0,aux3=0,i=0,j=0;
			for (i=0;i<tamanho;i++){
					for (j=0;j<frase.size();j++){
						aux2 += (W[i][frase[j]]*W[i][frase[j]]);
						aux3 += (repeteFrase*idf[frase[j]])*(repeteFrase*idf[frase[j]]);
						numerador += (W[i][frase[j]])*(repeteFrase*idf[frase[j]]); 
					}
				denominador = (sqrt(aux2))*(sqrt(aux3));
				if ((numerador == 0) && (denominador == 0)) //Elimina casos de indeterminação
					cos[i] = 0;
				else if (denominador == 0)
					cos[i] = 0;
				else
					cos[i] = (numerador/denominador); //calcula o valor do cosseno
				numerador = 0;
				denominador = 0;
				aux2 = 0;
				aux3 = 0;
			}
			this->cosseno_ = cos;
			return cos;
		}
		void printRank(map<int,double> cos,int tamanho){ // Mostra para o usuário qual o documento mais proximo da consulta
			vector<double> posDoc;// vetor criado para ajudar na ordenação
			int posicao = 1,total=0,i,j;
			this->t_ = tamanho;
			for (i=0;i<tamanho;i++)
				posDoc.push_back(cos[i]);
			sort(posDoc.begin(),posDoc.end()); //ordena o vetor
			cout << "Posicao\t\tDocumentos\n" ;
			for (i=(tamanho-1);i>=0;i--){ 
				cout << "  " << posicao << "\t\t";
				int vezes = 0;
				for (j=0;j<tamanho;j++)
					if (posDoc[i]==cos[j]){
						vezes++;
						total++;
					}
				for (j=0;j<tamanho;j++)
					if (posDoc[i]==cos[j]){
						if (vezes==1)
							cout << "D" << j+1;
						else if (vezes == 2)
							cout << "D" << j+1 << " e ";
						else
							cout << "D" << j+1 << ", ";
						vezes--;
					}	
				cout << endl;
				posicao++;
				if (total==tamanho) 
					break;
			}
			this->cosseno_ = cos;
		}
	private:
		int t_,tamanhoIDF_,numPalavras_,tamW_;
		map<int,double> cosseno_;
		friend class Teste;
};

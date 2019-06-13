#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

class dataStructuration{
	
	public:
		
		void documentMap(int argc, char* argv[]){
			
			int i;
			
			for (i = 0; i < argc; i++){
				
				fileDocuments[argv[i]] = i;
				
			}
			
		}
		
		/*A função fillMap recebe como parametros o nome do arquivo, o vector<string> contendo todas
		as palavras do arquivo, e um map<string,int> por referencia cuja chave é uma palavra do arquivo e o valor 
		associado a chave é o numero de documentos no qual ela aparece
		*/
		
		void fillMap(string s, vector<string> words, map<string,int> &inFileCount){
			
			int i,j,aux;
			
			invertedDocumentFrequency(words,inFileCount);
			
			termFrequency(words);
			
			dataStructure[wordCount] = s;
			
			sort(words.begin(), words.end());
			words.erase(unique(words.begin(),words.end()),words.end());
		}
		
		/* A função term frequency percorre o vetor de palavras de cada arquivo, o qual a função recebe como parametro,
		e conta quantas repetições de cada palavra existem no vector, após isso a palavra comparada é deletada a fim de 
		evitar contagens repetidas*/
		
		void termFrequency(vector<string> words){
			
			int i,j;
			
			for(i = 0;i < words.size(); i++){
				for(j = 0;j < words.size(); j++){
					
					if(words[i] == words[j]){
						
						wordCount[words[i]]++;
						words[i].erase();
						
					}		
				}
			} 
	}
				
		map<string,int> totalValue(vector<string> words){
		//retorna um map com as palavras que aparecem e a quantidade de vezes que cada uma aparece
			map<string,int> s;
			int i;
			
			sort(words.begin(), words.end());
			words.erase(unique(words.begin(),words.end()),words.end());
		
			for (i = 0;i<words.size();i++){
				s[words[i]]++;
			}
			return s;
		}
	private:
		
		int MaxLengh, Y, X; 
		map<string,int> fileDocuments;
		map<map<string,int>,string> dataStructure;
		map<string,int> wordCount;
		
};



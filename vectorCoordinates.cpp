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
		
		void fillMap(string s, vector<string> words, map<string,int> &inFileCount){
			
			int i,j,aux;
			
			invertedDocumentFrequency(words,inFileCount);
			
			termFrequency(words);
			
			dataStructure[wordCount] = s;
			
			sort(words.begin(), words.end());
			words.erase(unique(words.begin(),words.end()),words.end());
		
			
			for(i = 0; i < words.size(); i++){
				
				cout << "Existem: " << wordCount[words[i]] << " instancias da palavra \"" << words[i] << "\" no arquivo " << dataStructure[wordCount] << "\n";
					
			}
			
			for(i = 0; i < words.size(); i++){
				
				cout << "Existem: " << inFileCount[words[i]] << " instancias da palavra \"" << words[i] << "\" no arquivos \n";
					
			}
		}
			
		map<string,int> getTFfMap(){
			
			return wordCount;
			
		}
		
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
		
		void invertedDocumentFrequency(vector<string> words,map<string,int> &inFileCount){
			
			int i;
						
			sort(words.begin(), words.end());
			words.erase(unique(words.begin(),words.end()),words.end());
			
			for(i = 0; i <  words.size(); i++){
				
				inFileCount[words[i]]++;	
			}				
		}
		map<string,int> totalValue(vector<string> words){//retorna um map com as palavras que aparecem e a quantidade de vezes que cada uma aparece
			map<string,int> s;
			int i;
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




#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

class dataManagement{
	
	public:
		
		void dataFormat(string s){
			
			int count;
			string aux;
			int i = 0,k = 0;
			
			ifile.open(s);
			while(!ifile.eof()){
				
				getline(ifile,aux);
				this->sentences.push_back(aux);
				
			}
			
			aux.clear();
			
			for(i = 0; i < this->sentences.size(); i++){
				
				aux = sentences[i];
				istringstream ss(aux);
				
				for(k = 0; k < this->sentences[i].size(); k++){
					
					if(this->sentences[i][k] == ' ' || k + 1 == this->sentences[i].size()){
						ss >> aux;
						this->words.push_back(aux);
						continue;
					}
				}
			}
		}
		
		void formatWords(string s){
			
			int i,j;
			
			dataFormat(s);
			
			for(i = 0; i < this->words.size(); i++){
				for(j = 0; j < this->words[i].size(); j++){
					
					if(this->words[i][j] >= 65 && this->words[i][j] <= 91){
						
						this->words[i][j] = this->words[i][j] + 32;
						
					}
					
					if(ispunct(this->words[i][j])){
						
						this->words[i].erase(j,1);
					}
				}
			}
		}
		
		void displayData(){
			
			int i;
			
			for(i = 0; i < this->words.size(); i++){
		
				cout << this->words[i] << "\n";
			
			}
		}
		
		vector<string> getData(string s){
			
			formatWords(s);
			return this->words;
		}
		
		void clearWords(){
			this->words.clear();
			this->sentences.clear();
		}
	
	private:
		
		vector<string> sentences;
		vector<string> words;
		ifstream ifile;
};

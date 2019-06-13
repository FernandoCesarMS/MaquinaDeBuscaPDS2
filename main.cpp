#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "vectorCoordinates.cpp"
#include "FileInput.cpp"
#include "Ranking.cpp"

using namespace std;

int main(int argc,const char* argv[]){
	
	int tamanho = argc;
	dataManagement f[tamanho];
	dataStructuration g[tamanho];
	string fileName[tamanho];
	map<string,map<string,int>> tf;
	
	//Variaveis ranqueamento
	map<int,map<string,int>> itf;
	map<string,double> idf;
	map<int,map<string,double>> W;
	map<int,double> cos;
	
	Ranking rank;
	vector<string> frase;
	
	for(int i = 0;i < tamanho;i++)
		fileName[i] = argv[i];
	
	for(int i = 0;i < tamanho;i++)
		itf[i] = g[i].totalValue(f[i].getData(fileName[i]));
		
	idf = rank.calculateIDF(itf,tamanho); //preenche o map com os valores de IDF
	W = rank.calculateW(idf,itf,tamanho); //Preenche o Map W, explicar melhor oq é o map w
	frase = rank.readInput(); //Le a consulta
	cos = rank.calculateCosine(frase,idf,W,tamanho); // calcula os valores do Ranking Cosseno de cada documento
	rank.printRank(cos,tamanho); // Ordena os valores do cosseno do maior pro menor e printa na tela o ranking de documentos mais proximos da consulta
}

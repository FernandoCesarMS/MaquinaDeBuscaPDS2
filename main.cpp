#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "vectorCoordinates.cpp"
#include "FileInput.cpp"
#include "Ranking.cpp"
#define tamanho 4

using namespace std;

int main(int argc,const char* argv[]){
	dataManagement f[tamanho];
	dataStructuration g[tamanho];
	string fileName[tamanho];
	
	//Variaveis ranqueamento
	map<int,map<string,int>> itf;
	map<string,double> idf;
	map<int,map<string,double>> W;
	map<int,double> cos;
	map <string,int > df;
	
	Ranking rank;
	vector<string> frase;
	
	argv[0] = "teste.txt";
	argv[1] = "teste2.txt";
	argv[2] = "teste3.txt";
	argv[3] = "teste4.txt";	
	
	for(int i = 0;i < tamanho;i++){
		fileName[i] = argv[i];
		//g[i].fillMap(fileName[i],f[i].getData(fileName[i]),df);
	}
	
	for(int i = 0;i < tamanho;i++)
		itf[i] = g[i].totalValue(f[i].getData(fileName[i]));
		
	idf = rank.calculateIDF(itf,tamanho); //preenche o map com os valores de IDF
	W = rank.calculateW(idf,itf,tamanho); //Preenche o Map W, explicar melhor oq é o map w
	frase = rank.readInput(); //Le a consulta
	cos = rank.calculateCosine(frase,idf,W,tamanho); // calcula os valores do Ranking Cosseno de cada documento
	rank.printRank(cos,tamanho); // Ordena os valores do cosseno do maior pro menor e printa na tela o ranking de documentos mais proximos da consulta
	//rank.printRank(rank.calculateCosine(frase = rank.readInput(),idf = rank.calculateIDF(itf,tamanho),rank.calculateW(idf,itf)));
}

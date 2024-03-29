#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Ranking.cpp"

using std::string;

class Teste {
public:
	static int tamanho(const Ranking& c) {
    	return  c.t_;
    }
	static int tamanhoIDF(const Ranking& c) {
    	return  c.tamanhoIDF_;
    }
	static int numPalavras(const Ranking& c) {
    	return  c.numPalavras_;
    }
	static int tamW(const Ranking& c) {
    	return  c.numW_;
    }
};

TEST_SUITE("Ranking") {
TEST_CASE("calcularIDF(int ,int )"){
	Ranking rank;
	CHECK(rank.calcularIDF(4,2) == log(2));
	CHECK(rank.calcularIDF(2,2) == 0);
	CHECK(rank.calcularIDF(1,2) == -log(2));
	CHECK(rank.calcularIDF(15,0) == 0);
}
TEST_CASE("readInput()"){ 
	Ranking rank;
	vector <string> Teste;
	Teste = rank.readInput();
	CHECK(Teste.numPalavras == 0);
}
TEST_CASE("calculateIDF(map<int,map<string,int>> ,int )"){
	Ranking rank;
	map<int,map<string,int>> itf;
	int tamanho;
	map<string,double> idf = calculateIDF(itf,tamanho);
	CHECK(rank.tamanhoIDF == 0);
	tamanho = 1
	idf = calculateIDF(itf,tamanho);
	CHECK(rank.tamanhoIDF == 1);
	tamanho = -1;
	idf = calculateIDF(itf,tamanho);
	CHECK(rank.tamanhoIDF == 0);
}
TEST_CASE("calculateW(map<string,double> ,map<int,map<string,int>> ,int )"){
	Ranking rank;
	map<string,double> idf;
	map<int,map<string,int>> itf;
	int tamanho=0;
	map<int,map<string,double>> teste = calculateW(idf,itf,tamanho);
	CHECK(teste.tamW == 0);
	tamanho = 1;
	CHECK(teste.tamW == 1);
	tamanho = -1;
	CHECK(teste.tamW == 0);
}
TEST_CASE("calculateCosine(vector<string> ,map<string,double> ,map<int,map<string,double>> ,int )"){
	Ranking rank;
	vector<string> palavras;
	map<string,double> idf;
	map<int,map<string,double>> W;
	int tamanho = 0;
	map <int,double> cos;
	cos = calculateCosine(palavras,idf,w,tamanho);
	CHECK(cos[0] == 0);
	palavras.push_back("Teste");
	tamanho = 1;
	idf[0] = 0.9;
	map[0] = idf;
	cos = calculateCosine(palavras,idf,w,tamanho);
	CHECK(cos[0] > 0); 	
}
TEST_CASE("printRank(map<int,double> ,int )"){
	Ranking rank;
	map<int,double> valores;
	int tam=0;
	rank.printRank(valores,tam);
	CHECK(tam == 0);
	CHECK(valores[0] == 0.0);
	tam = 1;
	CHECK(tam == 1);
	CHECK(valores[0] == 0.0);
	tam=2;
	CHECK(tam == 2);
	CHECK(valores[0] == 0,0);
	CHECK(valores[1] == 0,0);
}
}

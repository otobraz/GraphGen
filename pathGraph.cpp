#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include <stdlib.h>
#include<ctime>
#include<random>

using namespace std;

int main(){

    int nV;
    int nE;
    int dense = 0;
    int weighted = 0;
	int selfLoop = 0;
	int minWeight = 1;
	int maxWeight = 1000000;
	int weight;

    string separator = " ";
    string path = "D:/Oto/UFMG/PAA/Module 2/TP - Grafos/Exemplos/";
    std::ofstream out;
    std::ostringstream sS;

    cout << "nV: "; cin >> nV;
    cout << "nE: "; cin >> nE;
//    cout << "Max Weight: "; cin >> maxWeight;
//    cout << "n: "; cin >> n;

    /* Random number generator */
    default_random_engine gen((int)time(0));

    /* Distribution on which to apply the generator */
    uniform_int_distribution<long long unsigned> disV(1,nV);

    sS << path << "pg_" << nV << "_" << nE << "_minD.txt";
    out.open(sS.str());
    out << nV << " " << nE << endl;
    for(int i = 1; i <= nE; i++){
        out << i << " " << i+1 << " " << minWeight << endl;
    }
    out.close();

    std::ostringstream sS1;
    sS1 << path << "pg_" << nV << "_" << nE << "_maxD.txt";
    out.open(sS1.str());
    out << nV << " " << nE << endl;
    for(int i = 1; i <= nE; i++){
        out << i << " " << i+1 << " " << maxWeight << endl;
    }
    out.close();

    std::ostringstream sS2;
    uniform_int_distribution<long long unsigned> disW(minWeight,maxWeight);
    sS2 << path << "pg_" << nV << "_" << nE << ".txt";
    out.open(sS2.str());
    out << nV << " " << nE << endl;
    for(int i = 1; i <= nE; i++){
        out << i << " " << i+1 << " " << disW(gen) << endl;
    }
    out.close();

    return 0;
}

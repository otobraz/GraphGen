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
    std::ostringstream sS, sS1, sS2;

    string separator = " ";
    string path = "D:/Oto/UFMG/PAA/Module 2/TP - Grafos/Exemplos/";
    std::ofstream out;


    cout << "nV: "; cin >> nV;
//    cout << "nE: "; cin >> nE;
//    cout << "Max Weight: "; cin >> maxWeight;
//    cout << "n: "; cin >> n;

    /* Random number generator */
    default_random_engine gen((int)time(0));

    /* Distribution on which to apply the generator */
    uniform_int_distribution<long long unsigned> disV(1,nV);

    uniform_int_distribution<long long unsigned> disW(minWeight,maxWeight);

    int n = (nV*nV)/2;
    nE = (nV-1) + n;

    sS << path << "g_" << nV << "_" << nE << "_minD.txt";
    out.open(sS.str());

    out << nV << " " << nE << endl;
    for(int i = 1; i < nV; i++){
        out << i << " " << i+1 << " " << minWeight << endl;
    }

    for(int i = 1; i <= nV; i++){
        for(int j = 1; j <= n/nV; j++){
            int v = disV(gen);
            while(v == i){
                v = disV(gen);
            }
            out << i << " " << v << " " << minWeight << endl;
        }
    }
    out.close();

    sS1 << path << "g_" << nV << "_" << nE << "_maxD.txt";
    out.open(sS1.str());

    out << nV << " " << nE << endl;
    for(int i = 1; i < nV; i++){
        out << i << " " << i+1 << " " << maxWeight << endl;
    }

    for(int i = 1; i <= nV; i++){
        for(int j = 1; j <= n/nV; j++){
            int v = disV(gen);
            while(v == i){
                v = disV(gen);
            }
            out << i << " " << v << " " << maxWeight << endl;
        }
    }
    out.close();

    sS2 << path << "g_" << nV << "_" << nE << ".txt";
    out.open(sS2.str());

    out << nV << " " << nE << endl;
    for(int i = 1; i < nV; i++){
        out << i << " " << i+1 << " " << disW(gen) << endl;
    }

    for(int i = 1; i <= nV; i++){
        for(int j = 1; j <= n/nV; j++){
            int v = disV(gen);
            while(v == i){
                v = disV(gen);
            }
            out << i << " " << v << " " << disW(gen) << endl;
        }
    }
    out.close();

    return 0;
}

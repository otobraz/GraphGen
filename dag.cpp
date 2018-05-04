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
    int v = 1;
    int n, c, k;
    std::ostringstream sS, sS1, sS2;

    string separator = " ";
    string path = "D:/Oto/UFMG/PAA/Module 2/TP - Grafos/Exemplos/";
    std::ofstream out;

    cout << "nV: "; cin >> nV;
//    cout << "Max Weight: "; cin >> maxWeight;
//    cout << "nE: "; cin >> nE;
//    cout << "n: "; cin >> n;

    /* Random number generator */
    default_random_engine gen((int)time(0));

    /* Distribution on which to apply the generator */
    uniform_int_distribution<long long unsigned> disV(1,nV);

    /* Distribution on which to apply the generator */
    uniform_int_distribution<long long unsigned> disW(minWeight,maxWeight);

    int hNV = nV/2;
    nE = hNV*hNV + (hNV*(hNV-1))/2;

    sS << path << "dag_" << nV << "_" << nE << ".txt";
    out.open(sS.str());
    out << nV << " " << nE << endl;
    for(int i = 1; i <= nV/2; i++){
        for(int j = i+1; j <= nV/2+i; j++){
            if(i == j) continue;
            out << i << " " << j << " " << disW(gen) << endl;
        }
    }
    for(int i = nV/2+1; i < nV; i++){
        for(int j = i+1; j <= nV; j++){
            if(i == j) continue;
            out << i << " " << j << " " << disW(gen) << endl;
        }
    }
    out.close();

    sS1 << path << "dag_" << nV << "_" << nE << "_minD.txt";
    out.open(sS1.str());
    out << nV << " " << nE << endl;
    for(int i = 1; i <= nV/2; i++){
        for(int j = i+1; j <= nV/2+i; j++){
            if(i == j) continue;
            out << i << " " << j << " " << minWeight << endl;
        }
    }
    for(int i = nV/2+1; i < nV; i++){
        for(int j = i+1; j <= nV; j++){
            if(i == j) continue;
            out << i << " " << j << " " << minWeight << endl;
        }
    }
    out.close();

    sS2 << path << "dag_" << nV << "_" << nE << "_maxD.txt";
    out.open(sS2.str());
    out << nV << " " << nE << endl;
    for(int i = 1; i <= nV/2; i++){
        for(int j = i+1; j <= nV/2+i; j++){
            if(i == j) continue;
            out << i << " " << j << " " << maxWeight << endl;
        }
    }
    for(int i = nV/2+1; i < nV; i++){
        for(int j = i+1; j <= nV; j++){
            if(i == j) continue;
            out << i << " " << j << " " << maxWeight << endl;
        }
    }
    out.close();

    return 0;
}

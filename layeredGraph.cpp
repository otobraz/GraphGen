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

    cout << "Layers: "; cin >> c;
    k = nV/c;
    nV = nV + 2;
    nE = 2*k + k*k*(c/2);
    sS << path << "lg_" << nV << "_" << nE << ".txt";
    out.open(sS.str());
    out << nV << " " << nE << endl;
    for(int j = 1; j <= k; j++){
            out << 1 << " " << j+1 << " " << disW(gen) << endl;
    }
    for(int counter = 0; counter < c/2; counter++){
        for(int i = 1; i <= k; i++){
           for(int j = 1; j <= k; j++){
                int vId = (counter*k)+1;
                out << vId+i << " " << vId+k+j << " " << disW(gen) << endl;
           }
        }
    }
    for(int j = 1; j <= k; j++){
            out << (c/2)*k+1+j << " " << nV << " " << disW(gen) << endl;
    }
    out.close();


    sS1 << path << "lg_" << nV << "_" << nE << "_minD.txt";
    out.open(sS1.str());
    out << nV << " " << nE << endl;
    for(int j = 1; j <= k; j++){
            out << 1 << " " << j+1 << " " << minWeight << endl;
    }
    for(int counter = 0; counter < c/2; counter++){
        for(int i = 1; i <= k; i++){
           for(int j = 1; j <= k; j++){
                int vId = (counter*k)+1;
                out << vId+i << " " << vId+k+j << " " << minWeight << endl;
           }
        }
    }
    for(int j = 1; j <= k; j++){
            out << (c/2)*k+1+j << " " << nV << " " << minWeight << endl;
    }
    out.close();


    sS2 << path << "lg_" << nV << "_" << nE << "_maxD.txt";
    out.open(sS2.str());
    out << nV << " " << nE << endl;
    for(int j = 1; j <= k; j++){
            out << 1 << " " << j+1 << " " << maxWeight << endl;
    }
    for(int counter = 0; counter < c/2; counter++){
        for(int i = 1; i <= k; i++){
           for(int j = 1; j <= k; j++){
                int vId = (counter*k)+1;
                out << vId+i << " " << vId+k+j << " " << maxWeight << endl;
           }
        }
    }
    for(int j = 1; j <= k; j++){
            out << (c/2)*k+1+j << " " << nV << " " << maxWeight << endl;
    }
    out.close();

    return 0;
}

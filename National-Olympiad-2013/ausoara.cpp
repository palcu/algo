#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <stack>
#include <limits>

using namespace std;

// EIUCLAP

// Constants
const int INF = 0x3f3f3f;
const int N = 128; /// Daca as fi pus 1000, solutia de 100 de puncte

// Structs

// Globals
int sol[2][N], nSol[2];
int newSol[N], nNewSol;
int v[N], lg;

// Functions

int main()
{
    ifstream fin("ausoara.in");
    ofstream fout("ausoara.out");

    int i, j, nSiruri;
    bool b = 0;
    fin >> nSiruri >> nSol[0];

    for(i=0; i<nSol[0]; i++)
        fin >> sol[0][i];

    for(int t=1; t<nSiruri; t++){
        fin >> lg;
        for(i=0; i<lg; i++)
            fin >> v[i];

        i=0; j=0;
        while(i<nSol[b] && j<lg){
            if(sol[b][i] == v[j]){
                sol[!b][ nSol[!b]++ ] = sol[b][i];
                j++; i++;
            }
            else if (sol[b][i] < v[j])
                i++;
            else
                j++;
        }
        if(nSol[!b] == 0){
            b = !b;
            break;
        }
        b = !b;
        nSol[!b] = 0;
    }
    fout << nSol[b] << ' ';
    for(i=0; i<nSol[b]; i++)
        fout << sol[b][i] << ' ';

    fin.close(); fout.close(); return 0;
}

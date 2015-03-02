#include <fstream>
#include <iostream>

using namespace std;

const int N_SOLDATI = 100000;

int soldatInEchipa[N_SOLDATI];

int main() {
    ifstream fin("meciul.in");
    ofstream fout("meciul.out");

    int t; fin >> t;
    for(int tt=0; t<tt; tt++) {
        memset(0, soldatInEchipa, sizeof(soldatInEchipa));
        int nSoldati, nLupte;
        fin >> nSoldati >> nLupte;

        int x, y; fin >> x >> y;
        soldatInEchipa[x] = 1;
        soldatInEchipa[y] = 2;
        fout << "YES\n";

        for (int i=1; i<nLupte; i++) {
            fin >> x >> y;
            if (soldatInEchipa[x] == 0 ||)
        }
    }
    return 0;
}

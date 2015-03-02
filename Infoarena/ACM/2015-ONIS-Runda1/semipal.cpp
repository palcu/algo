#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("semipal.in");
    ofstream fout("semipal.out");

    unsigned long long t; fin >> t;
    for (unsigned long long tt = 0; tt < t; tt++) {
        unsigned long long l, k;
        fin >> l >> k;

        unsigned long long nrSemiPal = (1 << (l - 1));
        unsigned long long jumate = nrSemiPal / 2;

        char inFata;
        if (k <= jumate) {
            inFata = 'a';

        } else {
            inFata = 'b';
            k -= jumate;
        }
        fout << inFata;

        // sa dea bine
        k--;
        jumate/=2;
        // cout << k << endl;

        while(jumate) {
            if(jumate & k)
                fout << 'b';
            else
                fout << 'a';
            jumate/=2;
        }
        fout << inFata << '\n';
    }

    return 0;
}

#include <cstdio>
#include <cmath>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("perechi3.in");
    ofstream fout("perechi3.out");

    int t; fin >> t;

    for (int p=0; p<t; p++) {
        int n; fin >> n;
        unsigned long long sum = 0;
        unsigned long long floor_sqrt_n = floor(sqrt(n));
        for (int i=1; i<=floor_sqrt_n; i++) {
            int term = n/i;
            sum += term;
        }
        fout <<  2*sum - floor_sqrt_n*floor_sqrt_n << "\n";
    }

    return 0;
}

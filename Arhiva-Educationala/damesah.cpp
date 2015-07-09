#include <fstream>
using namespace std;

const int MAX_N = 13;
int n, count_sol, sol[MAX_N];
int row[MAX_N], col[MAX_N], diag1[MAX_N*2], diag2[MAX_N*2];

ifstream fin("damesah.in");
ofstream fout("damesah.out");

void back(int r) {
    if (r == n) {
        count_sol++;
        if (count_sol == 1) {
            for (int i=0; i<n; i++)
                fout << sol[i]+1 << " ";
            fout << "\n";
        }
    }
    for (int c=0; c<n; c++) {
        int pos_diag1 = c - r + n - 1;
        int pos_diag2 = c + r;

        if (!row[r] && !col[c] && !diag1[pos_diag1] && !diag2[pos_diag2]) {
            sol[r] = c;
            row[r] = 1;
            col[c] = 1;
            diag1[pos_diag1] = 1;
            diag2[pos_diag2] = 1;
            
            back(r+1);
            
            row[r] = 0;
            col[c] = 0;
            diag1[pos_diag1] = 0;
            diag2[pos_diag2] = 0;
        }
    }
}

int main() {
    fin >> n;
    back(0);
    fout << count_sol << "\n";
    return 0;
}

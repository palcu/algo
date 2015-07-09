#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = 13;

class Solution {
public:
    int row[MAX_N], col[MAX_N], diag1[MAX_N*2], diag2[MAX_N*2];
    vector<vector<string> > sol;
    vector<string> current;

    void back(int r, int n) {
        if (r == n) {
            sol.push_back(current);
            return;
        }
        for (int c=0; c<n; c++) {
            int pos_diag1 = c - r + n - 1;
            int pos_diag2 = c + r;
            if (!row[r] && !col[c] && !diag1[pos_diag1] && !diag2[pos_diag2]) {
                current[r][c] = 'Q';
                row[r] = 1;
                col[c] = 1;
                diag1[pos_diag1] = 1;
                diag2[pos_diag2] = 1;

                back(r+1, n);

                current[r][c] = '.';
                row[r] = 0;
                col[c] = 0;
                diag1[pos_diag1] = 0;
                diag2[pos_diag2] = 0;
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        string empty_row;
        for (int i=0; i<n; i++)
            empty_row.push_back('.');
        for (int i=0; i<n; i++)
            current.push_back(empty_row);
        fill(row, row+n, 0);
        fill(col, col+n, 0);
        fill(diag1, diag1+2*n, 0);
        fill(diag2, diag2+2*n, 0);

        back(0, n);
        return sol;
    }
};

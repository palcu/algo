#include <iostream>
#include <cstdio>

using namespace std;

const int MODULO = 1000000007;

// int solve(unsigned long long p) {
//     // printf("%d\n", p);
//     unsigned long long sol = 1;
//     int n = 2;
//     for (int i=0; (1<<i) <= p; ++i){
//         if (((1 << i) & p) > 0)
//             sol = (sol * n) % MODULO;
//         n = (n * n) % MODULO;
//         printf("%d %d\n", n, sol);
//     }
//     if (sol == 0) {
//         return MODULO - 1;
//     }
//     return sol - 1;
// }

int solve(unsigned long long n, unsigned long long m) {
    // printf("%d %d\n", n, m);
    if (m == 0) return 1;
    if (m == 1) return n;
    if (m % 2 == 0)
        return solve((n * n) % MODULO, m / 2);
    else
        return (n * solve((n * n) % MODULO, (m - 1) / 2)) % MODULO;
}

int main()
{
    freopen("azerah.in","r",stdin);
    freopen("azerah.out","w",stdout);

    int t;
    scanf("%d", &t);
    for (int i=0; i<t; i++) {
        int nSir;
        scanf("%d", &nSir);
        int nPare = 0, nImpare = 0;
        for (int j=0; j<nSir; j++) {
            int x;
            scanf("%d", &x);
            if (x%2) nImpare++;
            else nPare++;
        }
        if (nImpare == 0) {
            nImpare = 1;
        }

        // printf("%d %d\n", nPare, nImpare);
        int sol = solve(2, nPare + nImpare - 1);
        if (sol == 0)
            sol = MODULO - 1;
        else
            sol--;
        printf("%d\n", sol);
    }
    // printf("%lld\n", solve(2, 100));
    return 0;
}

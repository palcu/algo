/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2011
****************************************************/

#include <cstdio>
#include <cstring>

using namespace std;

//Constants
const int NMAX = 2 << 4;

//Global Vars
char initv[NMAX];
int n, v[NMAX];

//Structs

//Solve Functions
void move_to_first() {
    int first = v[0] - 1;

    int div = first / 3;
    int move_up = 3 - div;
    printf("S %d ", move_up);

    int mod = first % 3;
    if (mod)
        printf("D %d", mod);

    printf("A ");
}

void move(int from, int to) {
    if (from == 0)
        from = 11;
    if (to == 0)
        to = 11;

    --from;
    --to;
    int div_from, div_to, mod_from, mod_to;
    div_from = from / 3;
    div_to = to / 3;
    mod_from = from % 3;
    mod_to = to % 3;

    if (div_from < div_to)
        printf("J %d ",div_to-div_from);
    else if (div_from > div_to)
        printf("S %d ",div_from-div_to);

    if (mod_from < mod_to)
        printf("DR %d ",mod_to-mod_from);
    else if (mod_from > mod_to)
        printf("ST %d ",mod_from-mod_to);
}
void move_to_last() {}

int main() {
#ifndef ONLINE_JUDGE
    freopen("telefon.in","r",stdin);
    freopen("telefon.out","w",stdout);
#endif

    fgets(initv, NMAX, stdin);
    int n = strlen(initv) - 1;
    for(int i=0; i<n; i++)
        v[i] = initv[i] - '0';

    move(10,v[0]);
    printf("A ");
    for(int i=1; i<n; i++) {
        move(v[i-1],v[i]);
        printf("A ");
    }
    move(v[n-1],12);
    return 0;
}

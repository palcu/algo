/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2011
****************************************************/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

//Constants
const int NMAX = 16;
const int EF_MAX = 2 << 16;
const int PUT[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072};

//Global Vars
int n, efecte[EF_MAX + 2], v[NMAX];
bitset<EF_MAX> is_set;
vector<pair<int,int> > values;

//Structs

//Solve Functions
void debug_vector(int v[], int n){
    printf("== VECTOR ==\n");
    for(int i=0; i<n; i++)
        printf("%d ",v[i]);
    printf("\n");
}

inline int efect(int a, int b){
    return a*b - 2 * (a + b) - 6;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("efect.in","r",stdin);
    //freopen("efect.out","w",stdout);
    #endif

    int i, j;

    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &v[i]);
        efecte[PUT[i]] = v[i];
        is_set[PUT[i]] = 1;
        values.push_back(make_pair(PUT[i], v[i]));
    }

    for(i=0; i<values.size(); i++){
        int x, y;
        x = values[i].first;
        for(j=i+1; j<values.size(); j++){
            y = values[j].first;
            int intersection = x & y;
            if (intersection == 0){
                int newefect = efect(values[i].second, values[j].second);
                if (!is_set[x+y]){
                    efecte[x+y] = newefect;
                    values.push_back(make_pair(x+y, newefect));
                }
                else{
                    if (efecte[x+y] > newefect){
                        is_set[x+y] = true;
                        efecte[x+y] = newefect;
                        values.push_back(make_pair(x+y, newefect));
                    }
                }
            }
        }
    }



    /*
    for(i=0; i<values.size(); i++){
        int x,y;
        x = values[i].first;
        for(j=i+1; j<values.size(); j++){
            y = values[j].first;
            if (!(x ^ y)){ // cele 2 multimi sunt disjuncte
                int newefect = efect(values[i].second, values[j].second);
                if (is_set[x+y])
                    efecte[x+y] = min(efecte[i+j], newefect);
                else{
                    is_set[x+y] = true;
                    efecte[x+y] = newefect;
                }
            }
        }
    }
    */

    //debug_vector(efecte, PUT[n+1]);

    return 0;
}

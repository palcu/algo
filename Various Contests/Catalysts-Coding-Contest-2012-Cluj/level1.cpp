/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2012
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
#include <fstream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <cstring>

using namespace std;

//{Defines
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define X first
#define Y second
#define pb push_back

//Constants
const int N = 1<<10;
const int INF = 0x3f3f3f3f;

//Structs

//Global Vars
int nLitere = 26, v[N], nTeste=6;
char m[2000][2000];
vector<vector<char> > comb;

//{Helpers
template <typename T>
inline void db(const T x, const char * name){
	cerr << name << " = " << x << '\n';
}
template <typename T> inline void dbv(const T * v, const char * name, int n){
	fprintf(stderr, "=== %s ===\n", name);
	for(int i=0; i<n; i++)
		cerr << v[i] << " ";
	cerr << '\n';
}
template <typename T> inline void dbs(T x){
	cerr << x << ' ';
}

template<typename T>
void dbw(const std::vector<T>& t, const char * name){
	fprintf(stderr, "=== %s ===\n", name);
	unsigned n = t.size();
	for(typename std::vector<T>::size_type i=0; i<n; ++i)
		std::cerr << t[i] << ' ';
	cerr << '\n';
}
//}

//Solve Functions
void find(char x, char y, char z, char t){
    vector<char> sol;
    int i;
    for(i=0;i<nLitere;i++){
        if(
           m[i][0] == x &&
           m[i][1] == y &&
           m[i][2] == z &&
           m[i][3] == t
        ){
            sol.pb(i);
        }
    }
    printf("%d ", sol.size());
    sort(sol.begin(), sol.end());
    comb.pb(sol);
    /*for(i=0;i<sol.size();i++)
        printf("%c ",sol[i]+'a');*/
    return;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("level1.in","r",stdin);
	freopen("level1.out","w",stdout);
	#endif

	int i,j;
	char lit;
	char x,y,z,t;
	for(i=0;i<nLitere;i++){

	    scanf("%c %c %c %c %c\n", &lit, &x, &y, &z, &t);
	    m[i][0] = x;
	    m[i][1] = y;
	    m[i][2] = z;
	    m[i][3] = t;
	}
    int nLit;

    freopen("test.in","r",stdin);

	for(i=0;i<nTeste;i++){

        scanf("%d ", &nLit);
        comb.clear();
        for(j=0;j<nLit;j++){
            scanf("%c %c %c %c", &x, &y, &z, &t);

            find(x,y,z,t);

            if(j+1 == nLit)
                scanf("\n");
            else
                scanf(" ");

        }
        for(i=0; i<comb.sz;i++){
        }
	}


	//prv(m[2],4);

	return 0;
}


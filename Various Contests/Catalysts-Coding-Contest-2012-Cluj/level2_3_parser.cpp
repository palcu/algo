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
int n, v[N];

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
int main(){
	#ifndef ONLINE_JUDGE
	freopen("parse.in","r",stdin);
	freopen("parse.out","w",stdout);
	#endif

	char sir[20000];
	for(int j=0;j<6;j++){
	    cin.getline(sir,20000);
	    int i;
	    int lg = strlen(sir);
	    int nr = 0;
	    for(i=0; i<lg && nr!=2; i++){
	        if(sir[i] == ' '){
	            nr++;
	        }
	    }
	    for(; i<lg; i++){
	        bool ok=0;
            if(isdigit(sir[i])){
                printf("\n"); ok=1;
                if(isdigit(sir[i+1]))
                    i++;
                i++;
            }
            else if (sir[i] == '\n') break;
            else {
                printf("%c", sir[i]);
            }
	    }
	    printf(" \n\n\n");
	}

	return 0;
}


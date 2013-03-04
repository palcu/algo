/***************************************************
 * Alex Palcuie
 * Romania
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
 * 2013
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
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <fstream>
#include <cstring>

using namespace std;

// Defines
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))
#define X first
#define Y second
#define pb push_back

// Helpers
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

// Constants
const int N = 500008;
const int INF = 0x3f3f3f3f;

// Globals
int n, v[N], k;
ifstream f("secventa.in");
char sir[5500000];

// Structs

// Functions
int main(){
	#ifndef ONLINE_JUDGE
	freopen("secventa.in","r",stdin);
	freopen("secventa.out","w",stdout);
	#endif

	int i;

	scanf("%d %d\n", &n, &k);

	f>>n>>k;
    f.get();
    f.get(sir,3500000);
    int lg=strlen(sir), crt=0;
    for (i=0; i<lg; i++)
    {
        int semn=1; int nr=0;
        if (sir[i]=='-')
        {
            semn=-1;
            i++;
        }
        while (sir[i]>='0' && sir[i]<='9')
        {
            nr=nr*10+(sir[i]-'0');
            i++;
        }
        v[++crt]=semn*nr;
    }

    //prv(v, n+1);
    deque<pair<int,int> > d;
    for(i=1; i<=k; i++){
        while(!d.empty() && d.back().X > v[i])
            d.pop_back();
        d.push_back(make_pair(v[i],i));
    }
    int myMax = d.front().X, posLeft = 1, posRight = k;

    for(; i<=n; i++){
        if(d.front().Y <= i-k)
            d.pop_front();
        while(!d.empty() && d.back().X > v[i])
            d.pop_back();
        d.push_back(make_pair(v[i],i));
        if(d.front().X > myMax){
            myMax=d.front().X;
            posRight = i;
            posLeft = i-k+1;
        }
    }

	printf("%d %d %d\n", posLeft, posRight, myMax);
	return 0;
}

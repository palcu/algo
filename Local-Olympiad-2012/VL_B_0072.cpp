// How many roads must a man walk down
// Before he can be, a man
// How many seas must a white dove sail
// Before it can sleep in the sand.

// Bob Dylan

// Parc

//{Includes
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
//}
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
//}

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
//Constants
const int N = 1<<10;
const int INF = 0x3f3f3f3f;



//Solve Functions
const int NMAX = 30007;
int oriz[NMAX], vert[NMAX];
int main(){
	freopen("parc.in","r",stdin);
	freopen("parc.out","w",stdout);
	
	int m, n, a, b, x, y, i, j;
	scanf("%d%d%d%d%d%d", &m, &n, &a, &b, &x, &y);
	//cin >> m >> n >> a >> b >> x >> y;
	int distO = abs(a-x);
	int distV = abs(b-y);
	
	int noriz;
	scanf("%d", &noriz);
	int e,f;
	int ocupO = 0, ocupV = 0;
	
	for(i=0; i<noriz; i++){
		scanf("%d%d", &e, &f);
		if (f<e){
			int aux = f;
			f=e;
			e=aux;
		}
		for(j=e; j<f; j++)
			if(!oriz[j]){
				oriz[j]=1;
			}
	}
	
	int nvert;
	scanf("%d", &nvert);
	
	for(i=0; i<nvert; i++){
		scanf("%d%d", &e, &f);
		if (f<e){
			int aux = f;
			f=e;
			e=aux;
		}
		for(j=e; j<f; j++)
			if(!vert[j]){
				vert[j]=1;
			}
	}
	
	for(i=a; i<=x; i++)
		if(oriz[i])
			ocupO++;
	for(i=b; i<=y; i++)
		if(vert[i])
			ocupV++;
	
	
	double sol;
	sol = ocupO + ocupV;
	int c1 = distO - ocupO;
	int c2 = distV - ocupV;
	sol += sqrt(double(c1*c1) + double(c2*c2));
	printf("%.6lf\n1\n", sol);
	
	return 0;
}

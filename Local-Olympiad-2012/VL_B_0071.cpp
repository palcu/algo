// How many roads must a man walk down
// Before he can be, a man
// How many seas must a white dove sail
// Before it can sleep in the sand.

// Bob Dylan

// Bliss

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
const int N = 100007;
const int INF = 0x3f3f3f3f;
const int MAXK = 4096;

//Structs

//Global Vars
int k, n;
char v[N];


//Solve Functions
inline int max_dintre(const int * v, const int a, const int b){
	int sol = 0;
	for(int i=a; i<=b; i++)
		sol = max(sol, v[i]);
	return sol;
}

int car[2][MAXK];

int main(){
	freopen("blis.in","r",stdin);
	freopen("blis.out","w",stdout);
	
	int i, j, p;
	const unsigned p2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536,131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432,67108864, 134217728, 268435456, 536870912, 1073741824};
	
	scanf("%d\n", &k);
	fgets(v, N, stdin);
	n = strlen(v) - 1;

	for(i=0; i<n; i++)
		v[i] -= '0';
	
	int sol1 = 0;
	
	int curent = 0;
	for(i=0, j=k-1; i<k; i++, j--)
		curent += v[i] * p2[j];
	sol1 = max(sol1, curent);
	
	for(j=k; j<n; i++, j++){
		curent <<= 1;
		if(v[i-k])
			curent-=p2[k];
		if (v[i])
			curent+=1;
		sol1 = max(sol1, curent);
	}
	
	
	int din, in;
	
	int sol2=0;
	
	int finalSigur = k, big=0;
	for(i=0; finalSigur<n; i++, finalSigur++){
		curent = 0;
		big=0;
		din = i%2; in = !din;
		for(j=i, p=0; j<i+k; j++, p++){
			curent <<= 1;
			curent += v[j];
			if (curent > MAXK){
				big=1;
				break;
			}
			if (!curent)
				car[in][0] = 1;
			else
				car[in][curent] = max(max_dintre(car[din], 0, curent-1) + 1, car[in][curent]);
		}
	}
	
	sol2 = max_dintre(car[in], 0, 33);
	if (big) sol2++;

	printf("%d\n%d\n", sol1, sol2);
	
	return 0;
}

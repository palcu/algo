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
const int N_NODURI = 200007;
const int N_MUCHII = 400007;
const int INF = 0x3f3f3f3f;

//Structs
struct Nod{
	int val;
	struct Nod * next;
};
typedef struct Nod * Lista;

struct Muchie{
	int a,b,val;
};

bool operator < (Muchie a, Muchie b){
	return a.val < b.val;
}

//Global Vars
int nNoduri, nMuchii, inaltime[N_NODURI];
Lista  l[N_NODURI];
Muchie v[N_MUCHII];


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
int find_set(int a){
	while(l[a] -> next)
		l[a] = l[a]->next;
	return l[a]->val;
}

bool uneste(int a, int b){
	int capA, capB;

	capA = find_set(a);
	capB = find_set(b);

	if(capA == capB)
		return false;
	else{
		if(inaltime[capA] < inaltime[capB])
			l[capA]->next = l[capB];
		else if (inaltime[capA] > inaltime[capB])
			l[capB]->next = l[capA];
		else{
			l[capA]->next = l[capB];
			inaltime[capB] ++;
		}
	}
	return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("apm.in","r",stdin);
	freopen("apm.out","w",stdout);
	#endif

	scanf("%d%d", &nNoduri, &nMuchii);

	int i;

	int a,b,val;
	for(i=0; i<nMuchii; i++){
		scanf("%d%d%d", &a, &b, &val);
		v[i].a = a;
		v[i].b = b;
		v[i].val = val;
	}
	sort(v, v+nMuchii);

	for(i=1; i<=nNoduri; i++){
		l[i] = new Nod;
		l[i]->val = i;
		l[i]->next = NULL;
		inaltime[i] = 1;
	}

	int noduriInApm = 0;
	i=0;
	vector<pair<int,int> > vSol; int sol=0;
	while(noduriInApm < nNoduri && i<nMuchii){
		Muchie muchieCurenta = v[i++];
		if (uneste(muchieCurenta.a, muchieCurenta.b)){
			sol += muchieCurenta.val;
			vSol.push_back(make_pair(muchieCurenta.a, muchieCurenta.b));
		}
	}

	printf("%d\n%d\n", sol, vSol.size());
	for(i=0; i<vSol.size(); i++)
		printf("%d %d\n", vSol[i].first, vSol[i].second);

	return 0;
}

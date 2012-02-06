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

//Define
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))

//Constants
const int N = 100005;

//Structs

//Global Vars
int nSets;
int heights[N];

struct Nod{
	int val;
	struct Nod * next;
};
typedef struct Nod * Lista;

Lista v[N];

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
	while(v[a]->next != NULL){
		v[a] = v[a]->next;
	}
	return v[a]->val;
}

void union_set(int a, int b){
	int x, y;

	x = find_set(a);
	y = find_set(b);

	if (heights[x] < heights[y]){
		v[x]->next = v[y];
		if (heights[x] == heights[y])
			heights[x] ++;
	}
	else{
		v[y]->next = v[x];
		if (heights[x] == heights[y])
			heights[y] ++;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("disjoint.in","r",stdin);
	freopen("disjoint.out","w",stdout);
	#endif

	int nOps; cin >> nSets >> nOps;
	int i;
	for(i=1; i<=nSets; i++){
		v[i] = new Nod;
		v[i]->val = i;
		v[i]->next = NULL;
		heights[i] = 1;
	}

	int tip, a, b;
	while(nOps--){
		scanf("%d%d%d",&tip,&a,&b);
		if(tip == 1)
			union_set(a,b);
		else{
			if(find_set(a) == find_set(b))
				printf("DA\n");
			else
				printf("NU\n");
		}
	}

	return 0;
}

/***************************************************
 * Alex Palcuie
 * Romania - 2013
 * alex [dot] palcuie [at] gmail [dot] com
 * http://palcu.blogspot.com/
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

// Structs

// Constants
const int N = 200008;
const int INF = 0x3f3f3f3f;

// Globals
int nOperatii, nHeap=1, loc[N];
pair<int,int> heap[N];

// Functions
int left(int x){
    return x * 2;
}
int right(int x){
    return left(x)+1;
}

int father(int x){
    return x/2;
}

void bubble_up(int x){
    while(heap[x].X < heap[x/2].X){
        swap(heap[x], heap[x/2]);
        loc[heap[x].Y] = x;
        loc[heap[x/2].Y] = x/2;
        x /= 2;
    }
}

void add(int x, int index){
    heap[nHeap].X = x;
    heap[nHeap].Y = index;
    loc[index] = nHeap++;
    bubble_up(loc[index]);
}

bool isWrong(pair<int, int> x, pair<int,int> y){
    return y.X && x.X>y.X;
}

void bubble_down(int x){
    while(isWrong(heap[x], heap[left(x) ]) || isWrong(heap[x], heap[right(x)])){
        int newLoc;
        if(heap[left(x)] < heap[right(x)] || !heap[right(x)].X)
            newLoc = left(x);
        else
            newLoc = right(x);
        swap(heap[x], heap[newLoc]);
        loc[heap[x].Y] = x;
        loc[heap[newLoc].Y] = newLoc;
        x = newLoc;
    }
}

void remove(int x){
    int newLocation = loc[x]; heap[loc[x]].X = heap[loc[x]].Y = 0; loc[x] = -1;
    loc[heap[nHeap-1].Y] = newLocation;
    swap(heap[nHeap-1], heap[newLocation]);
    nHeap--;
    bubble_down(newLocation);
}

void print_min(){
    printf("%d\n", heap[1].X);
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("heapuri.in","r",stdin);
	freopen("heapuri.out","w",stdout);
	#endif

	scanf("%d", &nOperatii);
	int nInserat = 1;
	for(int i=1; i<=nOperatii; i++){
        int op, x;
        scanf("%d", &op);
        switch(op){
            case 1:
                scanf("%d", &x);
                add(x, nInserat++);
                break;
            case 2:
                scanf("%d", &x);
                remove(x);
                break;
            case 3:
                print_min();
                break;
        }
	}




	return 0;
}

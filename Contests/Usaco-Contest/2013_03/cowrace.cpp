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
struct Segment{
    int speed, time;
};

// Constants
const int N = 1024;
const int INF = 0x3f3f3f3f;

// Globals
int nBesie, nElsie;
Segment besie[N], elsie[N];

// Functions
void readSegments(Segment v[N], int n){
    for(int i=0; i<n; i++){
        scanf("%d%d", &v[i].speed, &v[i].time);
        v[i].time += v[i-1].time;
    }
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("cowrace.in","r",stdin);
	freopen("cowrace.out","w",stdout);
	#endif

	scanf("%d%d", &nBesie, &nElsie);
	readSegments(besie, nBesie);
	readSegments(elsie, nElsie);

    int sol = 0;
    bool isSomeoneLeading = besie[0].speed != elsie[0].speed;
    bool isBesieLeading = 0;
    if(isSomeoneLeading)
        isBesieLeading = besie[0].speed > elsie[0].speed;

    int time = min(besie[0].time, elsie[0].time);
    int iBesie, iElsie;
    if(time == besie[0].time){
        iBesie = 1; iElsie = 0;
    }
    else{
        iBesie = 0; iElsie = 1;
    }
    int distBesie = time * besie[0].speed;
    int distElsie = time * elsie[0].speed;

    while((iBesie != nBesie) || (iElsie != nElsie)){
        int changeBesie = besie[iBesie].time - time;
        int changeElsie = elsie[iElsie].time - time;
        if(changeBesie<0) changeBesie=INF;
        if(changeElsie<0) changeElsie=INF;

        int timeSegment = min(changeBesie, changeElsie);
        distBesie += timeSegment * besie[iBesie].speed;
        distElsie += timeSegment * elsie[iElsie].speed;
        bool isSomeoneLeadingNow = distBesie != distElsie;
        if(isSomeoneLeadingNow){
            bool isBesieLeadingNow = distBesie > distElsie;
            if(!isSomeoneLeading){
                isSomeoneLeading = 1;
                isBesieLeading = isBesieLeadingNow;
            }
            else if(isBesieLeading != isBesieLeadingNow){
                sol++;
                isBesieLeading = isBesieLeadingNow;
            }
        }

        if(changeBesie == changeElsie){
            iBesie++; iElsie++;
        }
        else if (changeBesie < changeElsie)
            iBesie++;
        else iElsie++;

        time += timeSegment;

    }

    printf("%d\n", sol);

	return 0;
}

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
#define F first
#define S second
#define pb push_back
#define sz size()
#define mp make_pair

// Helpers
template <typename T> inline void db(const T x, const char * name){
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
template<typename T> void dbw(const std::vector<T>& t, const char * name){
	fprintf(stderr, "=== %s ===\n", name);
	unsigned n = t.size();
	for(typename std::vector<T>::size_type i=0; i<n; ++i)
		std::cerr << t[i] << ' ';
	cerr << '\n';
}

// Structs
struct Trie{
    int nCuvinte, nFii; char lit;
    Trie* fii[26];
    Trie(){
        nFii = nCuvinte = 0;
        memset(fii, 0, sizeof(fii));
    }
};

// Constants
const int N = 100;
const int INF = 0x3f3f3f3f;

// Globals
char s[N]; int n;
Trie *t = new Trie;
int nOp;

// Functions
int charToInt(char c){
    return c - 'a';
}
void fuck(int k){
    nOp++;
    if(nOp == 3249){
        if(k==1)    printf("cnt");
        else printf("pref");
    }

}
void ins(Trie *nod, char* s){
    while(*s){
        int k = charToInt(*s++);
        if(!nod->fii[k]){
            nod->fii[k] = new Trie;
            nod->fii[k]->lit = *(s-1);
            nod->nFii++;
        }
        nod = nod->fii[k];
    }
    nod->nCuvinte++;
}
void del(Trie *nod, char* s){
    while(*(s+1)){
        int k = charToInt(*s++);
        if(nod->fii[k])
            nod = nod->fii[k];
        else
            return;
    }
    Trie *last = nod->fii[charToInt(*s)];
    last->nCuvinte--;
    if(!last->nCuvinte && !last->nFii && last!=t){
        nod->nFii--;
        nod->fii[charToInt(*s)] = NULL;
        //nod->fii[charToInt(*s)] = NULL;
    }
}
int count(Trie *nod, char* s){
    fuck(1);
    while(*s){
        int k = charToInt(*s++);
        if(nod->fii[k])
            nod = nod->fii[k];
        else return 0;
    }
    return nod->nCuvinte;
}
int prefix(Trie *nod, char* s){
    fuck(2);
    int sol = 0;
    while(*s){
        int k = charToInt(*s);
        if(nod->fii[k]){
            nod = nod->fii[k];
            sol ++; *s++;
        }
        else return sol;
    }
    return sol;
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("trie.in","r",stdin);
	freopen("trie.out","w",stdout);
	#endif

    int op;
	while(!feof(stdin)){
        scanf("%d %s\n", &op, s); n = strlen(s);
        switch(op){
            case 0: ins(t, s); break;
            case 1: del(t, s); break;
            case 2: printf("%d\n", count(t, s)); break;
            case 3: printf("%d\n", prefix(t, s)); break;
        }
	}



	return 0;
}

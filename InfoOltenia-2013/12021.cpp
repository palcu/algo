/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2013
****************************************************/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <queue>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

//{Defines
#define NAME(n) #n
#define pr(x) db((x), (#x))
#define prv(v,n) dbv((v), (#v), (n))
#define prw(v) dbw((v), (#v))

//Constants
const int N = 128;
const int NLIT = 32;
const int INF = 0x3f3f3f3f;
const int NINDEX = 2<<13;

//Structs

//Global Vars
int nMatrice, nCuvant, nQuerys, nCuvantDublu;
unsigned char m[N][N];
unsigned char index[NINDEX][NLIT];
int nSubmatrice;

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
inline void debugMatrice(){
    int i,j;
	for(i=0; i<nMatrice; i++){
        for(j=0; j<nMatrice; j++)
            printf("%d ", m[i][j]);
        printf("\n");
	}
	printf("\n");
}
//}

//Solve Functions
void buildIndex(){
    char cIndex[NLIT];
    int i,j,row,k;
    for(row=0; row<nMatrice-nCuvant+1; row++){
        //construiesc matricea initiala
        memset(cIndex, 0, sizeof(cIndex));
        for(i=row; i<nCuvant+row; i++)
            for(j=0; j<nCuvant; j++)
                cIndex[m[i][j]]++;
        //prv(cIndex, NLIT);
        memcpy(index[nSubmatrice++], cIndex, sizeof(cIndex));
        //prv(index[nSubmatrice], NLIT);

        for(;j<nMatrice;j++){
            for(k=row; k<row+nCuvant; k++)
                cIndex[m[k][j-nCuvant]]--;
            for(k=row; k<row+nCuvant; k++)
                cIndex[m[k][j]]++;
            memcpy(index[nSubmatrice++], cIndex, sizeof(cIndex));
        }
    }
}

void q(){
    int sol=0, i;
    unsigned char qString[N];
    unsigned char qInt[NLIT];
    memset(qInt, 0, sizeof(qInt));
    scanf("%s\n", qString);
    for(i=0; i<nCuvantDublu; i++)
        qInt[qString[i] - 'A'] ++;
    //prv(qInt, NLIT);
    for(i=0; i<nSubmatrice; i++){
        //prv(index[i], NLIT);
        if(!memcmp(qInt, index[i], sizeof(qInt)))
            sol++;
    }
    printf("%d\n", sol);
}

int main(){
	freopen("aranjare.in","r",stdin);
	freopen("aranjare.out","w",stdout);

	int i, j;
	unsigned char row[N];
	scanf("%d %d %d\n", &nMatrice, &nCuvant, &nQuerys);
	nCuvantDublu = nCuvant * nCuvant;

	for(i=0; i<nMatrice; i++){
	    scanf("%s\n", row);
	    for(j=0; j<nMatrice; j++)
            m[i][j] = row[j] - 'A';
	}

    //debugMatrice();

	buildIndex();
	//prv(index[3], NLIT);

	for(i=0; i<nQuerys; i++)
        q();

	return 0;
}

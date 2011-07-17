/*
ID: palcu.ale1
PROG: frac1
LANG: C++
*/

/***************************************************
 * Author: Alexandru Palcuie
 * Country: Romania
 * Email: alex [dot] palcuie [at] gmail [dot] com
 * Website: http://palcu.blogspot.com/
 * Year: 2011
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
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef vector<int> VI;
typedef vector<pair<int,int> > VPI;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

//Structs
struct Fraction{
        int first, second;
        double value;
};

Fraction make_frac(int first, int second){
        Fraction frac;
        frac.first = first;
        frac.second = second;
        frac.value = (double)first/second;
        return frac;
}

//Constants
const int NMAX = 160;

//Global Vars
int n;
vector<Fraction> fracs;


//Solve Functions
inline bool cmp(Fraction a, Fraction b){
        return a.value<b.value;
}

inline int gcd(int a, int b){
        int r;
        while (b){
                r=a%b;
                a=b;
                b=r;
        }
        return a;
}

int main()
{
        #ifndef ONLINE_JUDGE
        freopen("frac1.in","r",stdin);
        freopen("frac1.out","w",stdout);
        #endif

        scanf("%d",&n);
        fracs.push_back(make_frac(0,1));
        fracs.push_back(make_frac(1,1));

        int i,j;
        for(i=2; i<=n; ++i){
                for(j=i-1;j>1;j--)
                        if(gcd(i,j) == 1){
                                fracs.push_back(make_frac(j,i));
                        }
                fracs.push_back(make_frac(1,i));
        }

        sort(fracs.begin(),fracs.end(),cmp);
        for(vector<Fraction>::iterator it=fracs.begin();it<fracs.end();++it)
                printf("%d/%d\n", it->first, it->second);

        return 0;
}

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

//Constants

//Global Vars

//Structs

//Solve Functions

int main()
{
        #ifndef ONLINE_JUDGE
        freopen("perechi.in","r",stdin);
        freopen("perechi.out","w",stdout);
        #endif

        int n;
        scanf("%d",&n);

        int sol = 1, fact;

        if (n%2==0){
                fact = 0;
                while(n%2==0){
                        fact++;
                        n/=2;
                }
                sol *= 2*fact + 1;
        }

        int rad = sqrt(n);
        for(int i=3; i<=rad; ++i){
                if (n%i == 0){
                        fact = 0;
                        while (n%i == 0){
                                ++fact;
                                n/=i;
                        }
                        sol *= 2*fact +1;
                }
        }

        if (n!=1)
                sol *= 3;

        printf("%d\n",(sol + 1)/2 );

        return 0;
}

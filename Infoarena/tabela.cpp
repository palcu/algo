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
inline int mod4(int x){
        if (!(x%4))
                x=4;
        else
                x%=4;
        return x;
}
 
int main()
{
        #ifndef ONLINE_JUDGE
        freopen("tabela.in","r",stdin);
        freopen("tabela.out","w",stdout);
        #endif
 
        int n, m;
        cin >> n >> m;
        --n; --m;
 
        int sol = n^m;
        cout << sol << '\n';
 
        return 0;
}

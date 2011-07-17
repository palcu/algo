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
const int NMAX = 2<<7;

//Global Vars
int x,y;
int m[NMAX][NMAX];


//Structs

//Solve Functions
void end(int a,int b){
        printf("NU\n%d %d\n",a,b);
        exit(0);
}

int main()
{
        #ifndef ONLINE_JUDGE
        freopen("spirala.in","r",stdin);
        freopen("spirala.out","w",stdout);
        #endif


        int i,j;
        scanf("%d%d",&x,&y);
        int a=x,b=y;
        for(i=0; i<x; ++i)
                for(j=0; j<y; ++j)
                        scanf("%d",&m[i][j]);

        int r = m[0][1] - m[0][0];

        int left,right,top,bottom;
        left = 0, right = b-1, top = 0, bottom = a-1;

        while (left<=right && top<= bottom){
                for(i=left; i<right; ++i){
                        a = m[top][i];
                        b = m[top][i+1];
                        if (b - a != r)
                                end(a,b);
                }
                ++top;
                if (top > bottom)
                        break;

                for(i=top-1; i<bottom; ++i){
                        a = m[i][right];
                        b = m[i+1][right];
                        if (b-a != r)
                                end(a,b);
                }
                --right;
                if (left > right)
                        break;

                for(i=right+1; i>left; --i){
                        a = m[bottom][i];
                        b = m[bottom][i-1];
                        if (b-a != r)
                                end(a,b);
                }
                --bottom;
                if (top > bottom)
                        break;

                for(i=bottom+1; i>top; --i){
                        a = m[i][left];
                        b = m[i-1][left];
                        if (b-a != r)
                                end(a,b);
                }
                ++left;
                if (left > right)
                        break;
        }

        printf("DA\n%d",m[0][0] + r*(x*y-1));

        return 0;
}

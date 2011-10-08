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

//Constants

//Global Vars
int n;

//Structs

//Solve Functions
void print_line(int k){
    int i,spaces;
    spaces = 2*(n-k);
    for(i=0;i<spaces;i++)
        printf(" ");
    if (k==0){
        printf("0\n");
        return;
    }
    for(i=0;i<=k;i++)
        printf("%d ",i);
    for(i=k-1;i>0;i--)
        printf("%d ",i);
    printf("0\n");
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);
    #endif

    cin >> n;
    int i,j;

    for(i=0;i<n;i++)
        print_line(i);
	for(i=n;i>=0;i--)
        print_line(i);

    return 0;
}

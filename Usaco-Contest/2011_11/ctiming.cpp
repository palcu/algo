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

//Structs

//Solve Functions

int main(){
    freopen("ctiming.in","r",stdin);
    freopen("ctiming.out","w",stdout);

    int d, h, m;
    cin >> d >> h >> m;
    d = d - 11;
    h = h - 11;
    m = m - 11;

	if (m<0){
        m += 60;
        --h;
	}
	if (h<0){
        h += 24;
        --d;
	}
	int sol = m + h*60 + d * 24 * 60;
	if (sol<0)
        printf("-1\n");
    else
        cout << sol << '\n';
    return 0;
}


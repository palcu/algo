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
const int NMAX = 10000;

//Global Vars

//Structs

//Solve Functions

int main(){
	    #ifndef ONLINE_JUDGE
	        freopen("patrat2.in","r",stdin);
		    freopen("patrat2.out","w",stdout);
		        #endif

			    int i, n, v[NMAX];
			        scanf("%d",&n);

				    for(i=1;v[i-2]<n;i++)
					            v[i-1] = i*i;
						        i-=2;
								while(n!=0){
									        if (v[i] <= n){
											            n-=v[i];
												                printf("%d\n",i+1);
														        }
															        else
																	            i--;
																		    	}

																			    return 0;
}


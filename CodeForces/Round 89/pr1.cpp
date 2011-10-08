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
const char vowel[6] = {'a', 'o', 'y', 'e', 'u', 'i'};

//Global Vars

//Structs

//Solve Functions
bool not_vowel(char a){
    for(int i=0; i<6; i++)
        if (a == vowel[i])
            return false;
    return true;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif

    string in,out;
    cin >> in;

    for(int i=0; i<in.size(); i++){
        if (in[i] >= 'A' && in[i] <= 'Z')
            in[i] += 32;
        if (not_vowel(in[i])){
            out.push_back('.');
            out.push_back(in[i]);
        }
    }
    cout << out;

    return 0;
}

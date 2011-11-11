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
const int N = 1000005;

//Global Vars
vector<string> v;

//Structs

//Solve Functions
bool mysort(string a, string b){
    return a.size()>b.size();
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif

    int i,j,k;
    string s;
    cin >> s;

    
    int len = s.size();

    for(i=len - 1; i>0; i--){
        static bool ok;
        ok=true;
        k=i;

        for(j=0; i<len; i++,j++){
            if(s[i] != s[j]){
                ok=false;
                break;
            }
        }

        if (ok){
            v.push_back(s.substr(k,len-k));
        }

        i=k;

    }

    sort(v.begin(),v.end(),mysort);

    string news;
    news = s.substr(1,len-2);

    bool ok = false;
    for(i=0; i<v.size(); i++)
        if(news.find(v[i]) != string::npos){
            cout<<v[i] << '\n';
            ok=true;
            break;
        }


    if(!ok){
        cout << "Just a legend" << '\n';
    }
    return 0;
}


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
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
 
using namespace std;
 
 
class TwiceString {
public:
  string getShortest(string s) {
    //try to find
    int i,j,k;
    bool isinmiddle=false;
    for(i=1;i<s.size();i++){
 
            if (s[i] == s[0]){
                bool ok =true;
 
                //we have a possibility
                for(j=i+1,k=1;j<s.size();j++,k++){
                    if (s[k] != s[j]){
                        ok=false;
                        break;
                    }
                }
 
                if (ok){
                    //this is good
                    int to_add = s.size() - i;
                    int old_size = s.size();
                    for(j=to_add;j<old_size;j++)
                        s.push_back(s[j]);
                    isinmiddle = true;
                    break;
                }
            }
    }
 
        if (!isinmiddle)
            s+=s;
    return s;
  }
};
 
 
 
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

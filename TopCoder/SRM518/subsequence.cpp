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
 
 
class LargestSubsequence {
public:
  string getLargest(string s) {
    char max = 'a' -1;
    int poz = 0,i;
    string sol;
 
    //get first max
    for(i=0;i<s.size();++i){
            if (s[i] > max){
                max = s[i];
                poz = i;
            }
    }
    
    //add max
        sol.push_back(max);
 
    while (poz != s.size()-1){
      max = s[++poz];
      
            //search for new one
            for(i=poz;i<s.size();i++){
                if (s[i] > max){
                max = s[i];
                poz = i;
                }
            }
            
            sol.push_back(max);
    }
 
    return sol;
  }
};
 
 
 
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

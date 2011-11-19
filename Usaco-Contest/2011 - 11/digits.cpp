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
int put2[] = {1, 2, 4 , 8, 16, 32, 64, 128, 256, 512, 1024};
int put3[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};

//Global Vars
const int NMAX = 16;
vector<int> cifreB2, cifreB3;
vector<int> possibleB2, possibleB3;

//Structs

//Solve Functions
int calcN(vector<int>& cifre, int* put){
    int n = 0;
    for(int i=cifre.size()-1; i>=0; i--){
        n += put[i] * cifre[i];
    }
    //cerr << n << endl;
    return n;
}

int main(){
    freopen("code.in","r",stdin);
    freopen("code.out","w",stdout);

    int b2, b3;
    int i;

    cin >> b2 >> b3;

    int tmp = b2;
    do{
        cifreB2.push_back(tmp%10);
    }while(tmp/=10);

    tmp = b3;
    do{
        cifreB3.push_back(tmp%10);
    }while(tmp/=10);

    for(i=0; i<cifreB2.size(); i++){
        cifreB2[i] = !cifreB2[i];
        possibleB2.push_back(calcN(cifreB2, put2));
        cifreB2[i] = !cifreB2[i];
    }

    for(i=0; i<cifreB3.size(); i++){
        tmp = cifreB3[i];
        for(int j=0; j<3; j++)
            if(tmp!=j){
                cifreB3[i] = j;
                possibleB3.push_back(calcN(cifreB3, put3));
            }
        cifreB3[i] = tmp;
    }
    int j;
    for(i=0;i<possibleB2.size();i++)
        for(j=0;j<possibleB3.size();j++)
            if(possibleB2[i] == possibleB3[j]){
                printf("%d\n", possibleB2[i]);
                return 0;
            }

    return 0;
}


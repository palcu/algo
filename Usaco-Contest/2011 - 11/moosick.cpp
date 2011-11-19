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
const int NMAX = 20005, NMAXSEVENTH = 16;

//Global Vars
int nChords, nSeventh;
int chords[NMAX];
int seventh[NMAXSEVENTH];
bitset<NMAXSEVENTH> isSeventh;
vector<int>sol;

//Structs

//Solve Functions
int positionInSeventh(int k){
    for(int i=0; i<nSeventh; i++)
        if(k == seventh[i])
            return i;
    return 0;
}

bool verify(vector<int>& v){
    for(int i=1; i<nSeventh; i++)
        if(v[i] - v[i-1] != seventh[i] - seventh[i-1])
            return false;
    return true;
}

int main(){
    freopen("moosick.in","r",stdin);
    freopen("moosick.out","w",stdout);

    int i;

    cin >> nChords;
    for(i=0; i<nChords; i++)
        scanf("%d", &chords[i]);

    cin >> nSeventh;
    for(i=0; i<nSeventh; i++)
        scanf("%d", &seventh[i]);
    sort(seventh, seventh + nSeventh);


    for(i=0; i<=nChords - nSeventh; i++){
        vector<int> v(chords+i, chords+i+nSeventh);
        sort(v.begin(), v.end());

        if(verify(v))
            sol.push_back(i+1);

        /*chords[i] = positionInSeventh(chords[i]);
        cerr << chords[i] << endl;*/
    }

    printf("%d\n", sol.size());
    for(i=0;i<sol.size();i++)
        printf("%d\n", sol[i]);
        /*if(x = positionInSeventh(chords[i])){
            if (isSeventh[i] == true){
                isSeventh.clear();
                isSeventh[i] = true;
            }
            else{
                isSeventh[i] = true;
                if (isSeventh.count() == 3){
                    printf("%d\n", i-3);
                    isSeventh[positionInSeventh(chords[i-3])] = false;
                }
            }
        }
        else
            isSeventh.clear();*/



    return 0;
}


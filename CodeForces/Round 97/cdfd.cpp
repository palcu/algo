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



//Structs
struct Pereche{
    int x, y;
    double dist;
};

//Global Vars
pair<int,int> v[8];
vector<Pereche> val;

Pereche make_pereche(int x, int y, double dist){
    Pereche p;
    p.x = x;
    p.y = y;
    p.dist = dist;
    return p;
}
bool sortare(Pereche a, Pereche b){
    return a.dist<b.dist;
}
double area(Pereche a, Pereche b, Pereche c){
        return (~( a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y) ) /2) +1;
}

//Solve Functions
double dist(pair<int,int> a, pair<int,int> b){
    double x,y;
    x = a.first - b.first;
    y = a.second - b.second;
    return sqrt(x*x + y*y);
}

void test(int start, int num){
    vector<Pereche> g;
    int i;
    for(i=start; i<start+num; i++)
        g.push_back(val[i]);
    do{
        set<int> s;
        for(i=0;i<4;i++){
            s.insert(val[i].x);
            s.insert(val[i].y);
        }
        if (s.size() == 4){ //bingo
            int vvv[9] = {0,0,0,0,0,0,0,0,0};

            set<int>::iterator it;
            for(it=s.begin(); it!=s.end(); it++){
                vvv[*it] = 1;
            }
            //check area
            vector<Pereche> toCheck;
            for(i=0; i<8; i++) if(!vvv[i]){
                toCheck.push_back(val[i]);
            }
            bool ok =true;
            do{
                if(area(toCheck[0],toCheck[1],toCheck[2]) == 0)
                    return;
            }while(next_permutation(toCheck.begin(), toCheck.end(), sortare));
            printf("YES\n");
            for(i=0;i<8;i++)
                if(vvv[i])
                    printf("%d ",i+1);
            printf("\n");
            for(i=0;i<8;i++)
                if(!vvv[i])
                    printf("%d ",i+1);
            exit(0);
        }
    } while(next_permutation(g.begin(), g.end(), sortare));
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif

    for(int i=0; i<8; i++)
        cin >> v[i].first >> v[i].second;

    for(int i=0; i<8; i++)
        for(int j=i+1; j<8; j++)
            val.push_back(make_pereche(i, j, dist(v[i], v[j])));

    sort(val.begin(), val.end(), sortare);
    int num = 1, start;
    for(int i=0;i<val.size();i++){
        if (val[i].dist == val[i-1].dist)
            num++;
        else{
            if (num >= 4)
                test(start, num);
            num=1;
            start = i;
        }
    }
    if (num >= 4)
        test(start, num);
    printf("NO");

    return 0;
}

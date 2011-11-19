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

int vx[4]={1,-1,0,0}, vy[4]={0,0,1,-1};
int n, m;

bool in(int a, int b){
    return (0<=a && a<n) && (0<=b && b<m);
}

bool beginSearch(int startx, int starty, vector<string> matrix){
	queue<pair<int,int> > coada;
	coada.push(make_pair(startx, starty));
	while(!coada.empty()){
	    int x = coada.front().first, y = coada.front().second;
	    coada.pop();
	    for(int i=0; i<4; i++){
            int newx = x + vx[i], newy = y + vy[i];
            if (in(newx,newy) && matrix[x][y]+1 == matrix[newx][newy]){
                if (matrix[newx][newy] == 'Z'){
                    return true;
                }
                coada.push(make_pair(newx,newy));
            }
	    }
	}
	return false;
}

class AlphabetPath {
public:
	string doesItExist(vector <string> letterMaze) {
	    n = letterMaze.size(), m = letterMaze[0].size();
		string tr = "YES", fl = "NO";
		for(int i=0; i<letterMaze.size(); i++)
			for(int j=0; j<letterMaze[i].size(); j++)
				if(letterMaze[i][j] == 'A')
					if(beginSearch(i,j,letterMaze))
                        return tr;
        return fl;
	}
};

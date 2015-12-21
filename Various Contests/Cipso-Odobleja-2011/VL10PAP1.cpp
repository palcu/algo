/***************************************************
 * Name: Alexandru Palcuie
 * Webiste: http://palcu.blogspot.com/
 * High School: Colegiul National Mircea cel Batran - Ramnicu Valcea
 * E-mail: alex [dot] palcuie [at] gmail [dot] com
 * Contest: Odobleja 2011
 * Problem: gradina
*****************************************************/

#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

//Constants
const int N = 8;
const int n = 8;
const int vx[] = {0,0,1,-1}, vy[] = {1,-1,0,0};
const int G = 69;

//Global vars
char m[N][N];
char color;

//Functions
inline void debug_matrix(){
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j)
			printf("%d ",m[i][j]);
		printf("\n");
	}
	printf("\n");
}

inline bool inbound(int x, int y){
	if (0<=x && 0<=y && x<n && y<n)
		return true;
	return false;
}

void fill_matrix(int startx, int starty){
	queue<pair<int,int> > q;
	q.push(make_pair(startx,starty));
	int x, y, xx, yy, i;
	m[startx][starty] = G;
	while (!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(i=0; i<4; ++i){
			xx = x + vx[i];
			yy = y + vy[i];
			if (inbound(xx,yy) && m[xx][yy] == color){
				m[xx][yy] = G;
				q.push(make_pair(xx,yy));
			}
		}
	}
}

int main(){
	freopen("gradina.in","r",stdin);
	freopen("gradina.out","w",stdout);
	
	int i,j;
	
	for(i=0; i<N; ++i){
		for(j=0;j<N;++j)
			scanf("%c ",&m[i][j]);
		scanf("\n");
	}
	scanf("%c",&color);
	
	//debug_matrix();
	
	for(i=0; i<n; ++i)
		if (m[i][n-1] == color){
			fill_matrix(i, n-1);
			//debug_matrix();
		}
	
	bool canPass = false;
	for(i=0; i<n; ++i)
		if (m[i][0] == G){
			printf("%d ",i+1);
			canPass = true;
		}
	if (!canPass)
		printf("0");
	
	printf("\n");
	return 0;
}

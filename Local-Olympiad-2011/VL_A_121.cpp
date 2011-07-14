#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

//EIUCLAP
//AI OJI 2011

using namespace std;

//Constants
const int NMAX = 1024;
const int INF = 20000000;
const int V=4;
const int vx[V]={0,0,1,-1},vy[V]={1,-1,0,0};

//Global
typedef int Matrix[NMAX][NMAX];
int n;
int m[NMAX][NMAX];
int zid[NMAX][NMAX];
Matrix tinta11,tinta21,tinta12,tinta22;
int b;
int tintax, tintay;
int sursa1x,sursa1y,sursa2x,sursa2y;
int robot1x,robot1y,robot2x,robot2y;

//Objects

//Functions
inline bool isInbound(int x, int y){
	if(x>=0 && x<n && y>=0 && y<n)
		return true;
	return false;
}

int lee(int a, int b){
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	int sol=1,i;
	int x,y,xx,yy;
	zid[a][b]=1;
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for(i=0;i<V;++i){
			xx=x+vx[i];
			yy=y+vy[i];
			if (isInbound(xx,yy) && zid[xx][yy]==-1){
				zid[xx][yy]=++sol;
				q.push(make_pair(xx,yy));
			}
		}
	}
	return sol;
}

void umple_tinta(Matrix a, Matrix b, int x, int y, int tx, int ty){
	int i,j;
	a[x][y]=b[x][y]=INF;
	if(x==tx){//umple pe orizontala
		if(x>tx){
			int aux=x;
			x=tx;
			tx=aux;
		}
		for(int i=x;i<=tx;++i)
			a[x][i]=b[x][i]=INF;
	}
	if(y==ty){//si pe verticala
		if(y>ty){
			int aux=y;
			y=ty;
			ty=aux;
		}
		for(int i=y;i<=ty;++i)
			a[x][i]=b[x][i]=INF;
	}
	//si acum de-a diagonala
	if (x-y == tx-ty || x+y == tx+ty){
		if(x-y == tx-ty){ //diagonala dreapta
			if (x>tx){
				int aux=x;
				x=tx;
				tx=aux;
				aux=y;
				y=ty;
				ty=aux;
			}
			for(i=x,j=y;i<=tx;++i,++j)
				a[i][j]=b[i][j]=INF;
		}
		else{ // diagonala stanga
			if (x<tx){
				int aux=x;
				x=tx;
				tx=aux;
				aux=y;
				y=ty;
				ty=aux;
			}
			for(i=x,j=y; x>=tx ;--i,++j)
				a[i][j]=b[i][j]=INF;
		}
	}
}

int lee_robot(int a, int b, Matrix m){
	int sol=1;
	queue<pair<int,int> > q;
	q.push(make_pair(a,b));
	int i;
	int x,y,xx,yy;
	m[a][b]=1;
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();
		for(i=0;i<V;++i){
			xx=x+vx[i];
			yy=y+vy[i];
			if (isInbound(xx,yy) && (!m[xx][yy] || m[xx][yy]==INF)){
				if(m[xx][yy]==INF)
					return m[x][y]+1;
				m[xx][yy]=m[x][y]+1;
				++sol;
				q.push(make_pair(xx,yy));
			}
		}
	}
	return sol;
}

int main(){
	freopen("ai.in","r",stdin);
	freopen("ai.out","w",stdout);
	
	//Variables
	int i,j;
	
	//Read
	scanf("%d",&n);
	scanf("%d%d",&tintax,&tintay);--tintax;--tintay;
	scanf("%d%d%d%d",&sursa1x,&sursa1y,&sursa2x,&sursa2y);--sursa1x;--sursa1y;--sursa2x;--sursa2y;
	scanf("%d%d%d%d",&robot1x,&robot1y,&robot2x,&robot2y);--robot1x;--robot1y;--robot2x;--robot2y;
	
	umple_tinta(tinta11,tinta12,sursa1x,sursa1y,tintax,tintay);
	
	umple_tinta(tinta21,tinta22,sursa2x,sursa2y,tintax,tintay);
	//blocam tinta
	tinta11[tintax][tintay]=tinta12[tintax][tintay]=tinta21[tintax][tintay]=tinta22[tintax][tintay]=-1;
	int nZid;
	scanf("%d",&nZid);
	int x,y;
	for(i=0; i<nZid; ++i){
		scanf("%d%d",&x,&y);--x;--y;
		tinta22[x][y]=tinta21[x][y]=tinta12[x][y]=tinta11[x][y]=m[x][y]=zid[x][y]=-1;
	}
	
	//Fill Ziduri
	int sol1=0,local;
	int k;
	for(i=0;i<n;++i) //parcurgere orizontala
		for(j=0;j<n;++j)
			if(zid[i][j]==-1)
			{
				local=0;
				zid[i][j]=-2;
				for(k=i;i<n && zid[i][k];++i){
					++local;
					zid[i][k]=-2;
				}
				if (local>sol1)
					sol1=local;
			}
	for(i=0;i<n;++i) //parcurgere orizontala
		for(j=0;j<n;++j)
			if(zid[i][j]==-2)
			{
				local=0;
				zid[i][j]=-3;
				for(k=i;i<n && zid[k][i];++i){
					++local;
					zid[j][k]=-3;
				}
				if (local>sol1)
					sol1=local;
			}
	printf("%d\n",sol1);
	
	int r1_t1,r2_t1,r1_t2,r2_t2;
	r1_t1=lee_robot(robot1x,robot1y,tinta11)-1;
	r2_t1=lee_robot(robot2x,robot2y,tinta21)-1;
	r1_t2=lee_robot(robot1x,robot1y,tinta22)-1;
	r2_t2=lee_robot(robot2x,robot2y,tinta12)-1;
	int s1=max(r1_t1,r2_t2);
	int s2=max(r1_t2,r2_t1);
	printf("%d\n",min(s1,s2));
	return 0;
}

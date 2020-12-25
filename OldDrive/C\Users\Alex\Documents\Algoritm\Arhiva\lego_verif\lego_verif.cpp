#include <cstdio>
#include<cstdlib>
#include<crandom>
int n,b,h;
void genTest(){
	srand();
bool canCont(int nr,int left,int v[],long s){
	if(left<=0)
		return false;
	if(nr>=h)
		return false;
	if(s+(h-nr)*3/2>n)
		return false;
	if(s+(h-nr+1)*(v[nr-1]+v[nr-1]+h-nr)<n)
		return false;
	return true;
}
bool gen(int nr,int left,int v[],long s){
if(left==0&&nr==h){
	for(int i=0;i<h;i++)
		printf("%d ",v[i]);
	return true;
}
else if(canCont(nr,left,v,s)){
	v[nr]=v[nr-1]+1;
	if(gen(nr+1,left-v[nr],v,s+v[nr]))
		return true;
	if(v[nr-1]>1){
		v[nr]=v[nr-1]-1;
		if(gen(nr+1,left-v[nr],v,s+v[nr]))
			return true;
		}	
	}
	return false;
}
void oldgen(int nr,int left,int v[]){
if(left==0&&nr==h){
	for(int i=0;i<h;i++)
		printf("%d ",v[i]);
	exit(0);
}
else if(left>0&&nr<h){
	v[nr]=v[nr-1]+1;
	oldgen(nr+1,left-v[nr],v);
	if(v[nr-1]>1){
		v[nr]=v[nr-1]-1;
		oldgen(nr+1,left-v[nr],v);
		}	
	}
}
int main(){
	int v[1000];
	freopen("lego.in","r",stdin);
	//freopen("lego.out","w",stdout);
	scanf("%d%d%d",&n,&b,&h);
	v[0]=b;
	gen(1,n-b,v,b);
	printf("\n");
	oldgen(1,n-b,v);
	printf("0");
	return 0;
}

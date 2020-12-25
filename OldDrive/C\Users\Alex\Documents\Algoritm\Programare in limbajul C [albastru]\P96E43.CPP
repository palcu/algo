#include <iostream.h>
//using namespace std;
int main(){
    int i,n,nc=0,x=0,n2,y,p,j;
    cin>>n; n2=n;
    while (n!=0) {
	  nc++;
	  n/=10;
    }
    nc--;
    for (i=1;i<=nc;i++){
	p=1;
	for (j=1;j<i;j++)
		p=p*10;
	x+=9*p;
        }
    nc++;
    y=x+(n2-x)*nc;
    cout<<y<<endl;
}


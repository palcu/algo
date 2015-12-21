#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	freopen("triunghi.in","r",stdin);
	freopen("triunghi.out","w",stdout);
	int n; scanf("%d", &n);
	float a,b;
	for(int i=0;i<n;i++){
	    scanf("%f %f",&a,&b);
        printf("%f\n", a*b/2);
	}


	return 0;
}

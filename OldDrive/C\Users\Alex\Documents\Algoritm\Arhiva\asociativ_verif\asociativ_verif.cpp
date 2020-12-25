#include <cstdio>
#include <list>
#include <cctype>
//#define DEBUG
using namespace std;
typedef list<int> Huge;
void MangledAdd(Huge& A, Huge B){
	while(A.size()<B.size())
		A.push_back(0);
	list<int>::iterator it2=B.begin();
	for(list<int>::iterator it1=A.begin();it1!=A.end()&&it2!=B.end();it1++,it2++){
		*it1+=*it2;
		if(*it1>10){
			int x=*it1;
			*it1=x/10;
			list<int>::iterator it3=it1;
			A.insert(it3,x%10);
			//it1--;
			
			///it1++;
		}
	}
}
void printHuge(Huge A){
	for(list<int>::iterator it=A.end();it!=A.begin();)
		printf("%d",*(--it));
	printf("\n");
}

int main(){
	freopen("asociativ.in","r",stdin);
	freopen("asociativ.out","w",stdout);
	int n;Huge a,b,c,t;char ch;
	scanf("%d",&n);
	while(!isdigit(ch))
		ch=getchar();
	ungetc(ch,stdin);
	for(int i=0;i<n;i++){
		a.clear();b.clear();c.clear();t.clear();
		ch=getchar();
		while(ch!=' '){
			a.push_front(ch-'0');
			t.push_front(ch-'0');
			ch=getchar();
		}
		ch=getchar();
		while(ch!=' '){
			b.push_front(ch-'0');
			ch=getchar();
		}
		ch=getchar();
		while(isdigit(ch)){
			c.push_front(ch-'0');
			ch=getchar();
		}
		while(!isdigit(ch)&&ch!=-1)
			ch=getchar();
		ungetc(ch,stdin);
 		MangledAdd(a,b);
		#ifdef DEBUG
			printHuge(a);
		#endif
		MangledAdd(a,c);
		#ifdef DEBUG
			printHuge(a);
		#endif
		MangledAdd(b,c);
		#ifdef DEBUG
			printHuge(b);
		#endif
		MangledAdd(b,t);
		#ifdef DEBUG
			printHuge(b);
		#endif
		if(mismatch(a.begin(),a.end(),b.begin()).first==a.end()){
			#ifdef DEBUG
				printf("result:");
			#endif
			printHuge(a);
		}
		else{
			#ifdef DEBUG
				printf("result:");
			#endif
			printf("0\n");
		}
	}
	return 0;
}

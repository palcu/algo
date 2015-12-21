/****************************************************
 * Name: Alexandru Palcuie
 * Website: http://palcu.blogspot.com/
 * Year: 2011
 * Contest: RoTopCoder
 * Problem: blog
*****************************************************/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

//Constants
const int NMAX = 2010;
const int NCHAR = 30;

//Global
char from[NMAX], to[NMAX];
int m[2][NMAX];

//Structs

//Functions

int main(){
	freopen("blog.in","r",stdin);
	freopen("blog.out","w",stdout);
	
	scanf("%s\n",from);
	scanf("%s\n",to);
	
	int lgTo = strlen(to);
	int lgFrom = strlen(from);
	char aux[NMAX];
	
	//change small to big
	if (lgTo>lgFrom){
		strcpy(aux,from);
		strcpy(from,to);
		strcpy(to,aux);
		int iaux;
		iaux=lgTo;
		lgTo=lgFrom;
		lgFrom=iaux;
	}
	
	//solve
	int i,j,f=1,s=0;
	int appeared,posLetter;
	bool hasPassed;
	for(i=0; i<lgFrom; ++i){
		f = !f;
		s = !s;
		for(j=0; j<lgTo; ++j){
			if (from[i] == to[j]){
				m[s][j] = m[f][j-1]+1;
			}
			else{
				m[s][j] = max(m[f][j],m[s][j-1]);
			}
		}
	}
	
	
	for(i=0, j=1; i<lgTo; ++i)
		if (m[s][i] == j ){
			++j;
			printf("%c",to[i]);
		}
	printf("\n");
	
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

//EIUCLAP
//EXPRESIE - OJI 2011

using namespace std;

//Constants
const int NMAX = 100024;

//Global
char v[NMAX];
char* p = v;
int nrnr;
int lgsir;

//Objects

//Functions
int EvalExpresie();
int EvalDinamic();
int EvalSort();
int EvalTermen();

inline bool ispalcuiedigit(char p){
	if(isdigit(p) || p=='-')
		return true;
	return false;
}

int EvalExpresie(){
	int r=0;
	
	while (*p){
		if(ispalcuiedigit(*p)){
			r+=EvalTermen();
			if (*p == ',') ++p; //leading ,
		}
		else if(*p == '('){
			r+=EvalDinamic();
			++p; //leading )
			if (*p == ',') ++p; //leading ,
		}
		else if (*p == '['){
			r+=EvalSort();
			++p; //leading ]
			if (*p == ',') ++p; //leading ,
		}
	}
	
	return r;
}

int EvalOExpresie(){
	int r;
	 if(*p == '('){
			r=EvalDinamic();
			++p; //leading )
		}
		else if (*p == '['){
			r=EvalSort();
			++p; //leading ]
		}
	return r;
}

int EvalDinamic(){
	vector<int> v;
	++p; // first (
	while(true){
		if(ispalcuiedigit(*p)){
			v.push_back(EvalTermen());
			if(*p == ')')
				break;
			if (*p == ',') ++p; //leading ,
		}
		else{
			v.push_back(EvalOExpresie());
			if (*p == ',') ++p; //leading ,
			if(*p == ')')
				break;
		}
	}
	
	int n=v.size();
	int i,j;
	int r=v[0];
	for(i=1;i<n;++i) //vector de sume
		v[i]+=v[i-1];
	for(i=1;i<n;++i)
		for(j=0;j<i;++j)
			if(v[i]-v[j]>r)
				r=v[i]-v[j];
	if(v[0]>r) r=v[0];
	if(v[n-1]>r) r=v[n-1];
	return r;
}

int EvalSort(){
	vector<int> v;
	++p; //first [
	while(true){
		if(ispalcuiedigit(*p)){
			v.push_back(EvalTermen());
			if(*p == ']')
				break;
			if (*p == ',') ++p; //leading ,
		}
		else{
			v.push_back(EvalOExpresie());
			if (*p == ',') ++p; //leading ,
			if(*p == ']')
				break;
		}
	}
	sort(v.begin(),v.end());
	int r=v.size();
	if (r%2)
		r=(r-1)/2;
	else
		r=r/2-1;
	return v[r];
}

int EvalTermen(){
	int r=0,ok=1;
	if(*p=='-'){
		ok=-1;
		++p;
	}
	while (ispalcuiedigit(*p)){
		r = r*10 + *p - '0';
		++p;
	}
	++nrnr;
	return r*ok;
}

int main(){
	freopen("expresie.in","r",stdin);
	freopen("expresie.out","w",stdout);
	
	//Read
	fgets(v,NMAX,stdin);
	lgsir=strlen(v);
	
	
	//Body
	printf("%d\n%d\n",nrnr,EvalExpresie());
	
	return 0;
}


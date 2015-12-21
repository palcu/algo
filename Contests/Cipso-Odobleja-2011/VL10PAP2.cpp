/***************************************************
 * Name: Alexandru Palcuie
 * Webiste: http://palcu.blogspot.com/
 * High School: Colegiul National Mircea cel Batran - Ramnicu Valcea
 * E-mail: alex [dot] palcuie [at] gmail [dot] com
 * Contest: Odobleja 2011
 * Problem: expresie
*****************************************************/

#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//Constants
const int NMAX = 256;
const double pi = M_PI;

//Global vars
char v[NMAX];
char *p = v;

//Functions
int eval_numar();
double eval_factor();
double eval_expres();

int eval_numar(){
	int sol = 0;
	while ('0' <= *p && *p <='9'){
		sol = sol * 10 + (*p-'0');
		++p;
	}
	return sol;
}

double eval_factor(){
		double sol,sexp;
		switch(*p){
			case ' ':
				++p;
				break;
			case '(':
				++p;
				sol = eval_expres();
				++p; //trailing )
				break;
			case 's':
				//sqrt sau sin
				++p;
				if (*p == 'q'){
					p+=4; //scap qrt(
					sol = sqrt((double)eval_expres());
					++p; //trailing )
				}
				else{
					p+=3; //scap de in(
					sol = sin((double)eval_expres());
					++p; //trailing )
				}
				break;
			case 'c':
				p+=4; //first cos(
				sexp = eval_expres();
				sol = cos((double)sexp);
				++p; //trailing )
				break;
			case 'l':
				p+=3; //first ln(
				sol = log ((double)eval_expres());
				++p; //trailing )
				break;
			case '\n':
				++p;
				break;
			default:
				sol = eval_numar();
				break;
		}
		return sol;
}

double eval_expres(){
	double sol = eval_factor();
	vector<pair<double,char> > v;
	v.push_back(make_pair(sol,'f'));
	while (*p != '\n' && *p != ')' && *p){
		switch (*p){
			case '+':
				++p;
				sol=eval_factor();
				v.push_back(make_pair(sol,'+'));
				break;
			case '-':
				++p;
				sol=eval_factor();
				v.push_back(make_pair(sol,'-'));
				break;
			case '*':
				++p;
				sol=eval_factor();
				v.push_back(make_pair(sol,'*'));
				break;
			case '/':
				++p;
				sol=eval_factor();
				v.push_back(make_pair(sol,'/'));
				break;
			default:
				++p;
				break;
		}
	}
	
	sol = v[v.size()-1].first;
	char semn;
	for(int i=v.size()-2; i>=0; --i){
		semn = v[i+1].second;
		switch(semn){
			case '+':
				sol+=v[i].first;
				break;
			case '-':
				sol=v[i].first-sol;
				break;
			case '*':
				sol*=v[i].first;
				break;
			case '/':
				sol=v[i].first/sol;
				break;
		}
	}
	
	return sol;
}

void parse_string(){
	char s[NMAX];
	int i,j;
	int vlen = strlen(v);
	for(i=0,j=0;i<vlen;++i)
		if (v[i]!=' ')
			s[j++] = v[i];
	strcpy(v,s);
}

int main(){
	freopen("expresii.in","r",stdin);
	freopen("expresii.out","w",stdout);
	
	fgets(v,NMAX,stdin);
	parse_string();
	
	double sol = eval_expres();
	cout.precision(2);
	//cout << sol << '\n';
	printf("%.2lf\n",sol);
	return 0;
}

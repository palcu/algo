#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
 
using namespace std;
 
bool sortare(pair<int,int> a, pair<int,int> b)
{
    if (a.first!=b.first)
        return a.first<b.first;
    else
        return a.second>b.second;
}
 
inline int caz(int a1,int a2,int b1,int b2)
{
    //printf("%d %d %d %d\n",a1,a2,b1,b2);
    if ((a2<b1 && a2!=b1) || (b2<a1 && b2!=a1))
        return 0;
    else
    {
        if (a1<=b1 && b1<=a2 && a2<=b2)
            return 1;
        else if (b1<=a1 && a2<=b2)
            return 2;
        else if (b1<=a1 && a1<=b2 && b2<=a2)
            return 3;
        else if (a1<=b1 && b2<=a2)
            return 4;
    }
    exit(69);
}
 
int main()
{
    freopen("reactivi.in","r",stdin);
    freopen("reactivi.out","w",stdout);
 
    int n,f=1; scanf("%d",&n);
    vector< pair<int,int> > v,frigider;
 
    for(int i=0;i<n;++i)
    {
        static int a,b;
        scanf("%d%d",&a,&b);
        v.push_back(make_pair(a,b));
    }
 
    sort(v.begin(),v.end(),sortare);
 
    frigider.push_back(v.front());
    for(vector< pair<int,int> >::iterator it=v.begin()+1;it<v.end();++it)
    {
        bool ok=true;
        for(vector< pair<int,int> >::iterator it2=frigider.begin();it2<frigider.end()&&ok;++it2)
        {
            //cout<<caz((*it2).first,(*it2).second,(*it).first,(*it).second)<<" caz"<<endl;
            switch(caz((*it2).first,(*it2).second,(*it).first,(*it).second))
            {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    (*it2).first=(*it).first;
                    ok=false;
                    break;
                }
                case 2:
                {
                    (*it2).first=(*it).first;
                    (*it2).second=(*it).second;
                    ok=false;
                    break;
                }
                case 3:
                {
                    (*it2).second=(*it).second;
                    ok=false;
                    break;
                }
                case 4:
                {
                    ok=false;
                    break;
                }
            }
        }
        if (ok)
            frigider.push_back(make_pair((*it).first,(*it).second));
    }
    printf("%d",frigider.size());
    return 0;
}

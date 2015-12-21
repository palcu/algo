//Good for learning new C functions ;)

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    /*freopen("tex.in","r",stdin);
    freopen("tex.out","w",stdout);*/

    char begin[3] = "``";
    char end[3] = "\'\'";

    bool opened = false;
    char s[128];
    while(fgets(s, 128, stdin)){
        if (s[0] == '\n')
            break;

        int len = strlen(s);
        for(int i=0;i<len;i++)
            if(s[i]=='"'){
                if (!opened)
                    fputs(begin,stdout);
                else
                    fputs(end,stdout);
                opened = !opened;
            }
            else
                putchar(s[i]);
    }

    return 0;
}

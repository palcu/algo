//In this problem, the X and Y axis are inverted X-(
//So it doesn't get the test cases... but I wrote this code :-P

#include <queue>
#include <utility>
#include <iostream>
#include <cstdio>

using namespace std;

char matrix[256][256];
char command[128] = {'A'};
int n,m;

inline void debug(){
    int i,j;
    for(i=1; i<=n; i++) {
        for(j=1; j<=m; j++)
            printf("%c",matrix[i][j]);
        printf("\n");
    }
}

void clear() {
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            matrix[i][j] = '0';
}

void create() {
    sscanf(command, "I %d %d", &n, &m);
    clear();
}

void color_pixel() {
    int x,y;
    char color;
    sscanf(command, "L %d %d %c", &x, &y, &color);
    matrix[y][x] = color;
}

void draw_vertical() {
    int x, y1, y2;
    char color;
    sscanf(command, "V %d %d %d %c", &x, &y1, &y2, &color);
    for(int i=y1; i<=y2; i++)
        matrix[i][x] = color;
}

void draw_horizontal() {
    int x1, x2, y;
    char color;
    sscanf(command, "H %d %d %d %c", &x1, &x2, &y, &color);
    for(int i=x1; i<=x2; i++)
        matrix[y][i] = color;
}

void draw_rectangle() {
    int x1, x2, y1, y2;
    char color;
    sscanf(command, "K %d %d %d %d %c", &x1, &y1, &x2, &y2, &color);
    int i,j;
    for(i=x1; i<=x2; i++)
        for(j=y1; j<=y2; j++)
            matrix[i][j] = color;
}

inline bool inbound(int x, int y) {
    bool isX = (0<x && x<=n);
    bool isY = (0<y && y<=m);
    return isX && isY;
}

void fill_region() {
    int vx[]= {1,-1,0,0}, vy[]= {0,0,1,-1};

    int x, y;
    char color;
    sscanf(command, "F %d %d %c", &x, &y, &color);

    char region_color = matrix[x][y];

    queue<pair<int, int> > coada;
    coada.push(make_pair(x,y));
    matrix[x][y] = color;

    while(!coada.empty()) {
        x = coada.front().first;
        y = coada.front().second;
        coada.pop();

        for(int i=0; i<4; i++) {
            int xx = x + vx[i];
            int yy = y + vy[i];
            if (inbound(xx,yy) && matrix[xx][yy] == region_color) {
                coada.push(make_pair(xx,yy));
                matrix[xx][yy] = color;
            }
        }

        //debug();
    }
}

void save_pic() {
    char name[100];
    sscanf(command, "S %s", name);
    printf("%s\n", name);
    debug();
}

int main() {
    freopen("graphic.in","r",stdin);
    //freopen("graphic.out","w",stdout);

    while(true) {
        fgets(command, 128, stdin);

        if (command[0] == 'X')
            break;

        switch(command[0]) {
        case 'I':
            create();
            break;
        case 'C':
            clear();
            break;
        case 'L':
            color_pixel();
            break;
        case 'V':
            draw_vertical();
            break;
        case 'H':
            draw_horizontal();
            break;
        case 'K':
            draw_rectangle();
            break;
        case 'F':
            fill_region();
            break;
        case 'S':
            save_pic();
            break;
        case 'X':
            return 0;
        }

        //debug();
    }

    return 0;
}

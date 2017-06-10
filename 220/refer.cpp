#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

char s[10][10];
char c;
int d[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool legal(int x, int y)
{
    return 1 <= x && x <= 8 && 1 <= y && y <= 8;
}

char next()
{
    return c == 'W' ? 'B' : 'W';
}

bool check_dir(int x, int y, int i)
{
    if (s[x][y] != '-') return false;
    int nx = x + d[i][0];
    int ny = y + d[i][1];
    if (!legal(nx, ny) || s[nx][ny] != next())
        return false;
    while (true) {
        nx += d[i][0];
        ny += d[i][1];
        if (!legal(nx, ny) || s[nx][ny] == '-')
            return false;
        if (s[nx][ny] == c) return true;
    }
}
bool can_set(int x, int y)
{
    for (int i = 0; i < 8; i ++) {
        if (check_dir(x, y, i)) {
            return true;
        }
    }
    return false;
}

void set(int x, int y)
{
    for (int i = 0; i < 8; i ++) {
        if (check_dir(x, y, i)) {
            int nx = x+d[i][0], ny = y+d[i][1];
            while (s[nx][ny] == next()) {
                s[nx][ny] = c;
                nx += d[i][0];
                ny += d[i][1];
            }
        }
    }
    s[x][y] = c;
}

P cnt()
{
    P res(0, 0);
    for (int i = 1; i <= 8; i ++) {
        for (int j = 1; j <= 8; j ++) {
            if (s[i][j] == 'B') res.first ++;
            if (s[i][j] == 'W') res.second ++;
        }
    }
    return res;
}

void print_chess()
{
    for (int i = 1; i <= 8; i ++) {
        for (int j = 1; j <= 8; j ++) {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{   
    int kase;
    char op[4];
    cin >> kase;
    for (int t = 1; t <= kase; t++) {
        for (int i = 1; i <= 8; i ++)
            scanf("%s", s[i]+1);
        scanf("%s", op);
        c = op[0];

        if (t > 1) printf("\n");
        while (scanf("%s", op)) {
            if (op[0] == 'L') {
                bool flag = false;
                bool first = true;
                for (int i = 1; i <= 8; i ++) {
                    for (int j = 1; j <= 8; j ++) {
                        if (can_set(i, j)) {
                            flag = true;
                            if (!first) printf(" ");
                            printf("(%d,%d)", i, j);
                            first = false;
                        } 
                    }
                }
                if (flag == false) printf("No legal move.");
                printf("\n");
            } else if(op[0] == 'M') {
                int x = op[1]-'0', y = op[2]-'0';
                if (can_set(x, y)) { set(x, y);}
                else { c = next(); set(x, y); }
                c = next();
                P num = cnt();
                printf("Black - %2d White - %2d\n", num.first, num.second);
            } else {
                print_chess();
                break;
            }
        }
    }

    return 0;
}
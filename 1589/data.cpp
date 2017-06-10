#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;


int main()
{
    freopen("rand.in", "w", stdout);
    srand(unsigned(time(0)));
    int maxn = 6, count = 0;
    int dir[11][10];
    const char s0[] = "RRCCHH";
    for (int s = (1<<maxn) - 1; s >= 1; s--)
        for (int num = 10; num; num--)
        {
            memset(dir, 0, sizeof(dir));
            int n = 0, is = 0;
            int r0 = 1 + rand() % 3, c0 = 4 + rand() % 3;//黑棋将的位置 
            dir[r0][c0] = 1;
            int r1 = 8 + rand() % 3, c1 = 4 + rand() % 3;//红棋将的位置 
           // while (c0 == c1)//目的是使黑红两将不在同一竖直位置 
             //   c1 = 4 + rand() % 3;
            dir[r1][c1] = 1;
            for (int i = 0; i < maxn; i++)//n值从6至1开始变化 
                if (s & (1<<i))
                    n++;
            printf("\n%d %d %d\nG %d %d\n",n + 1, r0, c0, r1, c1);//打印第一行，第二行 
            count++;
            for (int i = 0; i < maxn; i++)
            if (s & (1<<i))
            {
                int r = 1 + rand() % 10, c = 1 + rand() % 9;//车马炮位置 
                if (is == 0 && s0[i] != 'C')
                {
                    if (s0[i] != 'H')//车 
                    {
                        r = r0 + 1;
                        c = c0;
                        //printf("车%c\n",s0[i]);
                    }
                    else//马 
                    {
                        r = r0 + 2;
                        c = c0 + 1;
                        //printf("马%c\n",s0[i]);
                    }
                    is = 1;
            }
            else//炮车马
            {
                while (dir[r][c])
                {
                    r = 1 + rand() % 10;
                    c = 1 + rand() % 9;
                }
                //printf("炮车马%c\n",s0[i]);
            }
            dir[r][c] = 1;
            printf("%c %d %d\n", s0[i], r, c);
        }
    }
    printf("0 0 0\n");
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 15;
char array[maxn][maxn];
char s[6];

int x[maxn*maxn];
int y[maxn*maxn];
int status[maxn*maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int m,n;
	int cnt;
	int ncase = 0;
	while(scanf("%d",&m) && m != 0){
		if(ncase > 0){
			printf("\n");
		}
		++ncase;
		scanf("%d",&n);
		gets(s);
		for(int i=0;i<m;++i){
			gets(array[i]);
		}
		/*
		printf("m=%d n=%d\n",m,n);
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				printf("%c",array[i][j]);
			}
			printf("\n");
		}
		*/
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(status,0,sizeof(status));
		cnt = 0;
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				bool xs = array[i][j] != '*'  && ( (j == 0) || (array[i][j-1] == '*'));
				bool ys = array[i][j] != '*'  && ( (i == 0) || (array[i-1][j] == '*'));
				//cout<<"i="<<i<<" j="<<j<<" xs="<<xs<<" ys="<<ys<<endl;
				if(xs && !ys){
					x[cnt] = i;
					y[cnt] = j;
					status[cnt] = 1;
					++cnt;
				}else if (!xs && ys){
					x[cnt] = i;
					y[cnt] = j;
					status[cnt] = 2;
					++cnt;
				}else if(xs && ys){
					x[cnt] = i;
					y[cnt] = j;
					status[cnt] = 3;
					++cnt;
				}
			}
		}
		printf("puzzle #%d:\n",ncase);
		printf("Across\n");
		for(int i=0;i<cnt;++i){
			if(status[i] == 1 || status[i] == 3){
				printf("%3d.",i+1);
				int xx = x[i];
				int yy = y[i];
				char c = array[xx][yy];
				while(yy < n && c != '*') {
					printf("%c",c);
					++yy;
					c = array[xx][yy];
				}
				printf("\n");
			}
		}
		printf("Down\n");
		for(int i=0;i<cnt;++i){
			if(status[i] == 2 || status[i] == 3){
				printf("%3d.",i+1);
				int xx = x[i];
				int yy = y[i];
				char c = array[xx][yy];
				while(xx < m && c != '*') {
					printf("%c",c);
					++xx;
					c = array[xx][yy];
				}
				printf("\n");
			}
		}
	}
	return 0;
}
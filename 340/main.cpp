#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1005;
int ans[maxn];
int guess[maxn];

void match(int n,int& a,int& b){
	a = 0;
	b = 0;
	for(int i=0;i<n;++i){
		if(ans[i] == guess[i]){
			++a;
		}
	}
	int c1 = 0, c2 = 0;
	for(int i=1;i<=9;++i){
		c1 = 0;
		c2 = 0;
		for(int j=0;j<n;++j){
			//cout<<"j="<<j<<" guess[j]="<<guess[j]<<" ans[j]="<<ans[j]<<endl;
			if(guess[j] == i){
				++c1;
			}
			if(ans[j] == i){
				++c2;
			}
		}
		b += min(c1,c2);		
		//cout<<"i="<<i<<" b="<<b<<" c1="<<c1<<" c2="<<c2<<endl;
	}
	b -= a;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	int a,b;
	int game = 0;
	while(scanf("%d",&n) && n){
		++game;
		printf("Game %d:\n",game);
		for(int i = 0; i < n; ++i){
			scanf("%d",&ans[i]);
		}
		while(true){
			for(int i = 0; i < n; ++i){
				scanf("%d",&guess[i]);
			}
			if(guess[0] == 0){
				break;
			}
			match(n,a,b);
			printf("    (%d,%d)\n",a,b);
		}
	}
	return 0;
}
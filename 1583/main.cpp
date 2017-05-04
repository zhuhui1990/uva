#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100005;
int findgen[maxn];

void gen(){
	memset(findgen,0,sizeof(findgen));
	for(int i=0;i<maxn;++i){
		int j = i, k = i;
		while(j > 0){
			k += j % 10;
			j /= 10;
		}
		if(k < maxn && findgen[k] == 0){
			findgen[k] = i;
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,a;
	gen();
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a);
		printf("%d\n",findgen[a]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 25;
int array[maxn];

void process(int n,int k,int m){
	int cnt = n;
	int l = n-1,r = 0;
	while(cnt > 0){
		for(int i=0;i<k;++i){
			l = (l+1) % n;
			while(array[l] == 1){
				l = (l+1) % n;
			}
		}
		for(int i=0;i<m;++i){
			r = (r-1+n) % n;
			while(array[r] == 1){
				r = (r-1+n) % n;
			}
		}
		if(cnt != n){
			printf(",");
		}
		//cout<<"cnt="<<cnt<<" l="<<l<<" r="<<r<<endl;
		if(l != r){
			printf("%3d%3d",l+1,r+1);
			cnt -= 2;
			array[l] = 1;
			array[r] = 1;
		}else{
			printf("%3d",l+1);
			--cnt;
			array[l] = 1;
		}
		//l = (l+1) % n;
		//r = (r-1+n) % n;
	}
	printf("\n");
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,k,m;
	while(cin>>n>>k>>m && !(n == 0 && k == 0 && m == 0)){
		memset(array,0,sizeof(array));
		process(n,k,m);
	}
	return 0;
}
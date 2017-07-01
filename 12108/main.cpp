#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1000005;

int n;
int a[11],b[11],c[11];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int kase = 0;
	while(cin>>n && n != 0){
		++kase;
		for(int i=0;i<n;++i){
			cin>>a[i]>>b[i]>>c[i];
		}
		int t,count;
		for(t=1;t<maxn;++t){ //Ä£ÄâÊ±ÖÓ
			count = 0;
			for(int i=0;i<n;++i){
				if(c[i] <= a[i]){
					++count;
				}
			}
			if(count == n){
				break;
			}
			for(int i=0;i<n;++i){
				if(c[i] == a[i] + b[i]){
					c[i] = 0;
				}
				if(c[i] == a[i] && count >= n-count){
					c[i] = 0;
				}
				++c[i];
			}
		}
		if(t==maxn){
			t = -1;
		}
		cout<<"Case "<<kase<<": "<<t<<endl;
	}
	
	return 0;
}

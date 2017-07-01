#include <iostream>
#include <cstdio>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	long long n,sp,sq;
	while(cin>>n>>sp>>sq){
		long long best = 1ll<<62;
		long long aa=0,bb=0;
		for(long long a=0;a<32;++a){
			for(long long b=0;b<32;++b){
				long long cur = (((n-1)*sp+((n-1)*sp<<a))>>b)+sq;
				if(cur >= n*sq && cur < best){
					best = cur;
					aa = a;
					bb = b;
				}
			}
		}
		cout<<best<<" "<<aa<<" "<<bb<<endl;
	}
	return 0;
}
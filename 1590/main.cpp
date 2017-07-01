#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 1005;
unsigned long long ip[maxn];

void output(const unsigned long long & l){
	unsigned long long a,b,c,d;
	a = (l & (255ull<<24))>>24;
	b = (l & (255ull<<16))>>16;
	c = (l & (255ull<< 8))>> 8;
	d = l & 255ull;
	printf("%d.%d.%d.%d\n",a,b,c,d);
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	unsigned long long a,b,c,d;
	//long common;
	int bits;
	while(cin>>n){
		for(int i=0;i<n;++i){
			scanf("%d.%d.%d.%d",&a,&b,&c,&d);
			ip[i] = (a<<24)+(b<<16)+(c<<8)+d;
		}
		bits = 0;
		unsigned long long bb;
		bool flag = true;
		for(int j=31;j>=0;--j){
			unsigned long long m = 1ull<<j;
			bb = ip[0] & m;
			//cout<<"j="<<j<<" bb="<<bb<<endl;
			for(int i=1;i<n;++i){
				//cout<<"i="<<i<<" ip[i] & m ="<<(ip[i] & m)<<endl;
				if (bb != (ip[i] & m)){
					flag = false;
					break;
				}
			}
			if(flag){
				++bits;
			}else{
				break;
			}
		}
		//cout<<"bits="<<bits<<endl;
		unsigned long long mask = 0;
		for(int i=0;i<bits;++i){
			mask += 1ull << (31-i);
		}
		//mask = (1<<32) - mask;
		unsigned long long common = ip[0] & mask;
		output(common);
		output(mask);
	}
	return 0;
}
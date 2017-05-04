#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 4000;

int day[maxn];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int ncase;
	cin>>ncase;
	int n,m,t;
	for(int i=0;i<ncase;++i){
		cin>>n;
		fill_n(&day[0],n,0);
		cin>>m;
		for(int j=0;j<m;++j){
			cin>>t;
			int l=-1;
			while(l < n){
				l += t;
				if(l<n && l%7 != 5 && l%7!= 6){
					day[l] = 1;
					//if(i == 9){
					//	cout<<"j="<<j<<" t="<<t<<" l="<<l<<endl;
					//}
				}
			}
		}
		int cnt = 0;
		for(int j=0;j<n;++j){
			if(day[j]){
			//	cout<<"j="<<j<<endl;
				++cnt;
			}
		}
		cout<<cnt<<endl;
	}
}
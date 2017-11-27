#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	vector<int> dat;
	int n,q;
	int a,b;
	int kase = 0;
	while(cin>>n>>q && (n!=0)){
		++kase;
		cout<<"CASE# "<<kase<<":"<<endl;
		//cout<<"n="<<n<<" q="<<q<<endl;
		dat.clear();
		for(int i=0;i<n;++i){
			cin>>a;
			dat.push_back(a);
		}
		sort(dat.begin(),dat.end());
		for(int i=0;i<q;++i){
			cin>>a;
			b = find(dat.begin(),dat.end(),a)-dat.begin()+1;
			if(b <= n){
				cout<<a<<" found at "<<b<<endl;
			}else{
				cout<<a<<" not found"<<endl;
			}
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;++i){
		cin>>s;
		int res = 0;
		int cur = 0;
		for(int j=0;j<s.length();++j){
			if(s[j] == 'O'){
				++cur;
				res += cur;
			}else{
				cur = 0;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
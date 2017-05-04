#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool test(const string& s,int j){
	int len = s.length();
	for(int i=0;i+j<len;++i){
		if(s[i] != s[i+j]){
			return false;
		}
	}
	return true;
}

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
		//cout<<"s="<<s<<endl;
		int len = s.length();
		for(int j=1;j<=len;++j){
			//cout<<"j="<<j<<endl;
			if(len % j == 0){
				if(test(s,j)){
					cout<<j<<endl;
					if(i < n-1){
						cout<<endl;
					}
					break;
				}
			}
		}
	}
	return 0;
}
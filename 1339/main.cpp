#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int cnt1[26],cnt2[26];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	string s1,s2;
	int a;
	bool flag;
	while(cin>>s1>>s2){
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=0;i<s1.length();++i){
			a = s1[i] - 'A';
			++cnt1[a];
			a = s2[i] - 'A';
			++cnt2[a];
		}
		sort(cnt1,cnt1+26);
		sort(cnt2,cnt2+26);
		flag = true;
		for(int i=0;i<26;++i){
			if(cnt1[i] != cnt2[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
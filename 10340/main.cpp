#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	string s,t;
	int loc;
	bool flag;
	while(cin>>s>>t){
		loc = -1;
		flag = false;
		//cout<<"s.length="<<s.length()<<" t.length="<<t.length()<<endl;
		for(int i=0;i<s.length();++i){
			flag = false;
			for(int j=loc+1;j<t.length();++j){
				if(t[j] == s[i]){
					loc = j;
					flag = true;
					break;
				}
			}
			//cout<<"i="<<i<<" loc="<<loc<<endl;
			if(!flag){
				cout<<"No"<<endl;
				break;
			}
		}
		if(flag){
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}
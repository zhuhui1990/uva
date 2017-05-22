#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int alpha[26];

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int round;
	string s1,s2;
	int a;
	int res;
	int fail;
	bool flag;
	while(cin>>round && round != -1){
		memset(alpha,0,sizeof(alpha));
		cin>>s1>>s2;
		res = 0;
		for(int i=0;i<s1.length();++i){
			a = s1[i]-'a';
			if(alpha[a] == 0){
				alpha[a] = 1;
				++res;
			}
		}
		fail = 0;
		flag = true;
		for(int i=0;i<s2.length();++i){
			a = s2[i] - 'a';
			if(alpha[a] == 0){
				++fail;
				alpha[a] = -1;
			}else if(alpha[a] == 1){
				--res;
				alpha[a] = -1;
			}
			//cout<<"i="<<i<<" fail="<<fail<<endl;
			if(res == 0){
				break;
			}
			if(fail == 7){
				flag = false;
				break;
			}
		}
		cout<<"Round "<<round<<endl;
		if(!flag){
			cout<<"You lose."<<endl;
		}else if(res > 0){
			cout<<"You chickened out."<<endl;			
		}else{
			cout<<"You win."<<endl;
		}
	}
	return 0;
}
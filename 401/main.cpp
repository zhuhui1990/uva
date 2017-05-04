#include <iostream>
#include <string>
using namespace std;

char reverse[40] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string s;
	while(cin>>s){
		bool palin = true;
		bool mirror = true;
		int l = s.length();
		for(int i=0;i<l;++i){
			if(s[i] != s[l-1-i]){
				palin = false;
				break;
			}
		}
		for(int i=0;i<l;++i){
			int c;
			if(s[i]<='Z' && s[i]>='A'){
				c = s[i]-'A';
			}else if(s[i] >='1' && s[i]<='9'){
				c = s[i]-'0'+25;
			}
			//cout<<"s[i]="<<s[i]<<" c="<<c<<" reverse[c]="<<reverse[c]<<endl;
			if(s[l-1-i] != reverse[c]){
				mirror = false;
				break;
			}
		}
		if(!palin && !mirror){
			cout<<s<<" -- is not a palindrome."<<endl;
		}else if(palin && !mirror){
			cout<<s<<" -- is a regular palindrome."<<endl;
		}else if(!palin && mirror){
			cout<<s<<" -- is a mirrored string."<<endl;
		}else if(palin && mirror){
			cout<<s<<" -- is a mirrored palindrome."<<endl;
		}
		cout<<endl;
		
	}
	return 0;
}
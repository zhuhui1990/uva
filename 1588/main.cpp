#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

inline int min(int a,int b){
	return a < b ? a : b;
}

int minLen(const string& s1, const string& s2){
	int sumLen = s1.length()+s2.length();
	int minn = min(s1.length(),s2.length());
	int len = sumLen;
	for(int i=0;i<s1.length();++i){
		bool ok = true;
		int fix = min(s1.length()-i,minn); //重叠部分长度
		for(int j=0;j<fix;++j){
			if(s1[i+j] == '2' && s2[j] == '2'){
				ok = false;
				break;
			}
		}
		if(ok && len > sumLen-fix){
			len = sumLen - fix;
		}
	}
	return len;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string s1,s2;
	while(cin>>s1>>s2){
		cout<<min(minLen(s1,s2),minLen(s2,s1))<<endl;
	}
	return 0;
}
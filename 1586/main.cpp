#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

inline double mass(char c){
	switch(c){
	case 'C':
		return 12.01;
	case 'H':
		return 1.008;
	case 'O':
		return 16.00;
	case 'N':
		return 14.01;
	default:
		return 0.;
	}
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
		double res = 0.;
		char c = s[0];
		int num = 0;
		for(int j=1;j<s.length();++j){
			if(s[j] >= '0' && s[j] <= '9'){
				num = num * 10 + (s[j]- '0');
			} else {
				if(num == 0){
					num = 1;
				}
				//cout<<"num="<<num<<" c="<<c<<endl;
				res += num * mass(c);
				c = s[j];
				num = 0;
			}
		}
		if(num == 0){
			num = 1;
		}
		//cout<<"num="<<num<<" c="<<c<<endl;
		res += num * mass(c);
		printf("%.3lf\n",res);
	}
	return 0;
}
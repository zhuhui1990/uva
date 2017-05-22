#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>

//打表

using namespace std;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	
	double A[20][40];
	long B[20][40];
	
	//制表
	for(int m=0;m<=9;++m){
		for(int e=1;e<=30;++e){
			double mt = 1.-pow(2.,-1-m);
			double ex = pow(2.,e)-1.;
			double t = log10(mt)+ex*log10(2.);
			B[m][e] = t;
			A[m][e] = pow(10.,t-B[m][e]);
		}
	}
	
	string s;
	while(cin>>s && s!="0e0"){
		for(auto it = s.begin();it!=s.end();++it){
			if(*it == 'e'){
				*it = ' ';
				break;
			}
		}
		istringstream iss(s);
		double a;
		long b;
		iss>>a>>b;
		for(int m=0;m<=9;++m){
			for(int e=1;e<=30;++e){
				if(b == B[m][e] && fabs(a-A[m][e])<1e-5){
					cout<<m<<" "<<e<<endl;
					break;
				}
			}
		}
	}

	return 0;

}
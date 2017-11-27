//������std=c++11���룬�����segmentation fault
//set insert��c++11���в�ͬ��
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <set>

using namespace std;

set<string> dict;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif 
	string s,buf;

	while(cin>>s){
		for(int i=0;i<s.size();++i){
			if(isalpha(s[i])){
				s[i] = tolower(s[i]);
			}else{
				s[i] = ' ';
			}
		}
		stringstream ss(s);
		while(ss>>buf){
			dict.insert(buf);
		}
	}
	for(set<string>::iterator it = dict.begin();it!=dict.end();++it){
		cout<<*it<<endl;
	}
}

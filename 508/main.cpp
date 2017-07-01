#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

const int maxdif = 10000;
map<char,string> morse;
map<string,string> dict;

void encode(const string& word){
	string res;
	for(int i=0;i<word.size();++i){
		res += morse[word[i]];
	}	
	dict[word] = res;
}

int diff(const string& a,const string& b){
	if(a==b){
		return 0;
	}
	if(a.size()>b.size()){
		return diff(b,a);
	}
	if(a == b.substr(0,a.size())){
		return b.size()-a.size();
	}else{
		return maxdif;
	}
}

string solve(const string& code){
	string x = dict.begin()->second;
	string ans = dict.begin()->first;
	int min_dif = maxdif;
	for(auto it = dict.begin(); it != dict.end();++it){
		int d = diff(code,it->second);
		if(d < min_dif){
			min_dif = d;
			ans = it->first;
		}
		else if(d==0 && min_dif == 0 && ans.back() != '!'){
			ans += '!';
		}
	}
	if(min_dif > 0){
		ans += '?';
	}
	return ans;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string a,b;
	while(cin>>a && a != "*"){
		cin>>b;
		morse[a[0]] = b;
	}
	while(cin>>a && a != "*"){
		encode(a);
	}
	while(cin>>a && a != "*"){
		cout<<solve(a)<<endl;
	}
	return 0;
}
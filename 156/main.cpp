#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <string> 
#include <unordered_map>
#include <algorithm>

using namespace std;

string process(const string& s){
	string s1 = s;
	for(int i=0;i<s1.length();++i){
		s1[i] = tolower(s1[i]);
	}
	sort(s1.begin(),s1.end());
	return s1;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	vector<string> vec;
	string s,s1;
	unordered_map<string,int> ss;
	while(cin>>s && s != "#"){
		//cout<<"s="<<s<<endl;
		vec.push_back(s);
		s1 = process(s);
		//cout<<"s="<<s<<" s1="<<s1<<endl;
		if(!ss.count(s1)){
			ss[s1] = 0;
		}
		++ss[s1];
	}
	vector<string> ans;
	for(int i=0;i<vec.size();++i){
		s1 = process(vec[i]);
		if(ss[s1] == 1){
			ans.push_back(vec[i]);
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i){
		cout<<ans[i]<<endl;
	}
	return 0;
}
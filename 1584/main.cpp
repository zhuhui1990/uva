#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

bool lessthan(const string& s,int a,int b){
	int len = s.length();
	for(int i=0;i<len;++i){
		if(s[(a+i)%len] != s[(b+i)%len]){
			return s[(a+i)%len] < s[(b+i)%len];
		}
	}
	return false;
	
}

int findmin(const string& s){
	int len = s.length();
	int min = 0;
	for(int i=0;i<len;++i){
		if(lessthan(s,i,min)){
			min = i;
		}
	}
	return min;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	string s;
	scanf("%d",&n);
	int start;
	for(int i=0;i<n;++i){
		cin>>s;
		start = findmin(s);
		int len = s.length();
		for(int j=0;j<len;++j){
			printf("%c",s[(start+j)%len]);
		}
		printf("\n");
	}
	return 0;
}
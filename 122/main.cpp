#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

const int maxn = 1000005;
int node[maxn];
bool complete = true;
int maxp;

void process(){
	//check for completeness
	for(int i=0;i<=maxp;++i){
		if(node[i] > 0){
			int p = i;
			while(p > 0){
				p = (p-1)/2;
				if(node[p] <= 0){
					complete = false;
					break;
				}
			}
			if(!complete){
				break;
			}
		}
	}
	
	if(!complete){
		cout<<"not complete"<<endl;
		return;
	}
	cout<<node[0];
	for(int i=1;i<=maxp;++i){
		if(node[i] > 0){
			cout<<" "<<node[i];
		}
	}
	cout<<endl;
}

void parse(const string& s){
	istringstream iss(s);
	char ch;
	int dat;
	string s1;
	iss>>ch>>dat>>ch>>s1;
	int p = 0;
	if(s1 == ")"){
		p = 0;
	}else{
		for(int i=0;i<s1.length()-1;++i){
			if(s1[i]=='L'){
				p = p*2+1;
				maxp = p>maxp? p:maxp;
			}
			else if(s1[i] == 'R'){
				p = p*2+2;
				maxp = p>maxp? p:maxp;
			}
		}
	}
	//cout<<"dat="<<dat<<" p="<<p<<endl;
	if(node[p] > 0){
		complete = false;
	}else{
		node[p] = dat;
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	string s;
	memset(node,-1,sizeof(node));
	while(cin>>s){
		//cout<<"s="<<s<<endl;
		if(s == "()"){
			process();
			memset(node,-1,sizeof(node));
			complete = true;
			maxp = 0;
		}else{
			parse(s);
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;

int ID(Set x){
	if(IDcache.find(x) != IDcache.end()){
		//cout<<"ID="<<IDcache[x]<<endl;
		return IDcache[x];
	}
	Setcache.push_back(x);
	IDcache[x] = Setcache.size() - 1;
	//cout<<"ID="<<IDcache[x]<<endl;
	return IDcache[x];
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int ncase;
	cin>>ncase;
	for(int ii=0;ii<ncase;++ii){
		stack<int> s;
		int n;
		cin>>n;
		for(int i = 0; i < n; ++i){
			string op;
			cin>>op;
			//cout<<"i="<<i<<" op="<<op<<endl;
			if(op[0] == 'P'){
				s.push(ID(Set()));
			}else if(op[0] == 'D'){
				s.push(s.top());
			}else{
				Set x1 = Setcache[s.top()];
				s.pop();
				Set x2 = Setcache[s.top()];
				s.pop();
				Set x;
				if(op[0] == 'U') {
					set_union(ALL(x1),ALL(x2),INS(x));
				}
				if(op[0] == 'I'){
					set_intersection(ALL(x1),ALL(x2),INS(x));
				}
				if(op[0] == 'A'){
					x = x2;
					x.insert(ID(x1));
				}
				s.push(ID(x));
			}
			cout<<Setcache[s.top()].size()<<endl;
		}
		cout<<"***"<<endl; 	
	}
}
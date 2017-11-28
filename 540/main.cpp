#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

const int maxt = 1005;

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t,kase = 0;
	while(cin >> t && (t != 0)){
		cout<<"Scenario #"<<++kase<<endl;
		unordered_map<int,int> team;
		for(int i=0;i<t;++i){
			int n,x;
			cin>>n;
			for(int j=0;j<n;++j){
				cin>>x;
				team[x] = i;
			}
		}
		queue<int> q,q2[maxt];
		string cmd;
		while(true){
			int x;
			cin>>cmd;
			if(cmd[0] == 'S'){
				break;
			}else if(cmd[0] == 'D'){
				int t = q.front();
				cout<<q2[t].front()<<endl;
				q2[t].pop();
				if(q2[t].empty()){
					q.pop();
				}
			}else if(cmd[0] == 'E'){
				cin>>x;
				int t = team[x];
				if(q2[t].empty()){
					q.push(t);
				}
				q2[t].push(x);
			}
		}
		cout<<endl;
		
	}
	return 0;
}
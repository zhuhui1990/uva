#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int maxd = 10005;

struct Command{
	char c[5];
	int r1,c1,r2,c2;
	int a,x[20];
};

Command cmd[maxd];

int n;

bool simulate(int& r0, int& c0){
	for(int i=0;i<n;++i){
		if(cmd[i].c[0] == 'E'){
			if(cmd[i].r1 == r0 && cmd[i].c1 == c0){
				r0 = cmd[i].r2;
				c0 = cmd[i].c2;
			}else if(cmd[i].r2 == r0 && cmd[i].c2 == c0){
				r0 = cmd[i].r1;
				c0 = cmd[i].c1;
			}
		}else{
			int dr = 0, dc = 0;
			for(int j=0;j<cmd[i].a;++j){
				int x = cmd[i].x[j];
				if(cmd[i].c[0] == 'I'){
					if(cmd[i].c[1] == 'R' && x<= r0){
						++dr;
					}
					if(cmd[i].c[1] == 'C' && x <= c0){
						++dc;
					}
				}else{
					if(cmd[i].c[1] == 'R' && x == r0){
						return false;
					}
					if(cmd[i].c[1] == 'C' && x == c0){
						return false;
					}
					if(cmd[i].c[1] == 'R' && x < r0){
						--dr;
					}
					if(cmd[i].c[1] == 'C' && x < c0){
						--dc;
					}
				}
			}
			r0 += dr;
			c0 += dc;
		}
	}
	return true;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int r0,c0,q,kase=0;
	while(cin>>r0>>c0 && (r0 != 0 && c0 != 0)){
		cin>>n;
		//cout<<"r0="<<r0<<" c0="<<c0<<" n="<<n<<endl;
		++kase;
		for(int i=0;i<n;++i){
			cin>>cmd[i].c;
			if(cmd[i].c[0] == 'E'){
				cin>>cmd[i].r1>>cmd[i].c1>>cmd[i].r2>>cmd[i].c2;
			}else{
				cin>>cmd[i].a;
				for(int j=0;j<cmd[i].a;++j){
					cin>>cmd[i].x[j];
				}
			}
		}
		if(kase > 1){
			cout<<endl;
		}
		cout<<"Spreadsheet #"<<kase<<endl;
		cin>>q;
		//cout<<"q="<<q<<endl;
		
		while(q--){
			cin>>r0>>c0;
			cout<<"Cell data in ("<<r0<<","<<c0<<") ";
			if(!simulate(r0,c0)){
				cout<<"GONE"<<endl;
			}else{
				cout<<"moved to ("<<r0<<","<<c0<<")"<<endl;
			}
		}
		
	}	
	return 0;
}
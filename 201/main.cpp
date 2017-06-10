#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,m;
const int maxn = 10;
bool horizontal[maxn][maxn];
bool vertical[maxn][maxn];
int cnt[maxn];
int total;
char c;
int i,j;

bool square(int i,int j,int k){
	for(int m = 0; m < k; ++m){
		if(  horizontal[i][j+m] == false 
			|| horizontal[i+k][j+m] == false
			|| vertical[j][i+m] == false
			|| vertical[j+k][i+m] == false){
			return false;
		}
	}
	//cout<<"i="<<i<<" j="<<j<<" k="<<k<<endl;
	return true;
}


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif 
	int prob = 0;
	while(cin>>n>>m){
		++prob;
		memset(horizontal,false,sizeof(horizontal));
		memset(vertical,false,sizeof(vertical));
		memset(cnt,0,sizeof(cnt));
		total = 0;
		for(int ii=0;ii<m;++ii){
			cin>>c>>i>>j;
			if (c == 'H') {
				horizontal[i][j] = true;
			} else if (c == 'V') {
				vertical[i][j] = true;
			}
		}
		//枚举每个点，计算以其为左上角的正方形，枚举每个可能的尺寸
		for(int i = 1 ; i <= n; ++i){
			for(int j = 1 ; j <= n ; ++j){
				for(int k = 1; i + k <= n && j + k <= n; ++k){
					if(square(i,j,k)){
						++cnt[k];
						++total;
					}
				}
			}
		}
		if(prob >= 2){
			cout<<endl;
			cout<<"**********************************"<<endl;
			cout<<endl;
		}
		cout<<"Problem #"<<prob<<endl;
		cout<<endl;
		if(total == 0){
			cout<<"No completed squares can be found."<<endl;
		}else{
			for(int i = 1; i < n; ++i){
				if(cnt[i] > 0){
					cout<<cnt[i]<<" square (s) of size "<<i<<endl;
				}
			} 
		}
	}
	return 0;
}
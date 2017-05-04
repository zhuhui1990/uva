#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 105;

char array[maxn][maxn]; 

char count(int i,int j){
	int cnt=0;
	for(int ii=-1;ii<=1;++ii){
		for(int jj=-1;jj<=1;++jj){
			if(array[i+ii][j+jj] == '*'){
				++cnt;
			}
		}
	}
	return cnt;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif	
	int n,m;
	int cas=0;
	while(cin>>n>>m && (n || m)){
		//cout<<n<<" "<<m<<endl;
		if(cas>0){
			printf("\n");
		}
		++cas;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>array[i][j];
			}
		}
		//±ß½çÌî³äÒ»È¦
		for(int j=0;j<=m+1;++j){
			array[0][j]   = '.';
			array[n+1][j] = '.';
		}
		for(int i=0;i<=n+1;++i){
			array[i][0]   = '.';
			array[i][m+1] = '.';
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(array[i][j] == '.'){
					array[i][j] = count(i,j);
				}
			}
		}
		cout<<"Field #"<<cas<<":"<<endl;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(array[i][j] == '*'){
					printf("*");
				}else{
					printf("%d",array[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100005;

int array[maxn][10];

void init(){
	memset(array,0,sizeof(array));
	int num,c;
	for(int i=1; i<maxn; ++i){
		for(int j=0;j<10;++j){
			array[i][j] = array[i-1][j];
		}
		num = i;
		while(num > 0){
			c = num % 10;
			num /= 10;
			//cout<<"c="<<c<<endl;
			++array[i][c];
		}
	}
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int n;
	cin>>n;
	init();
	int a;
	for(int i=0;i<n;++i){
		cin>>a;
		for(int j=0;j<9;++j){
			cout<<array[a][j]<<" ";
		}
		cout<<array[a][9]<<endl;
	}
	return 0;
}
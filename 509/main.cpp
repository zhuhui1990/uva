#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxd = 7;
const int maxn = 6405;

char data[maxd][maxn];

bool mode;
int d,s,b,n;

bool solve(){
	for(int i=0;i<n;++i){
		bool k = false;
		int broke = -1;
		for(int j=0;j<d;++j){
			char c = data[j][i];
			if(c == '1'){
				k = !k;
			}
			if(c == 'x'){
				if(broke != -1){
					return false;
				}else{
					broke = j;
				}
			}
		}
		if(broke == -1 && k != mode){
			return false;
		}
		if(broke != -1){
			data[broke][i] = (k == mode ? '0' : '1');
		}
	}
	return true;
}

void print_ans(bool v){
	if(!v){
		cout<<"invalid."<<endl;
		return;
	}
	cout<<"valid, contents are: ";
	int num = 0, cnt = 0;
	for(int i=0;i<b;++i){
		int pos = i*s;
		for(int j = 0; j<d; ++j){
			if(i % d==j){
				continue; //Ð£Ñé¿é£¬Ìø¹ý
			}
			for(int k=0;k<s;++k){
				num <<= 1;
				num += (data[j][pos+k]=='1');
				++cnt;
				if((cnt %= 4) ==0){
					printf("%X",num);
					num = 0;
				}
			}
		}
	}
	if(cnt){
		printf("%X",num << (4-cnt));
	}
	printf("\n");
	return;
}

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	char c;
	int t = 0;
	while(cin>>d && d != 0){
		cin>>s>>b;
		n = s * b;
		cin>>c;
		if(c == 'E'){
			mode = false; //even
		} else if (c == 'O'){
			mode = true;
		}
		memset(data,0,sizeof(data));
		for(int i = 0; i < d; ++i){
			for(int j = 0; j < n; ++j){
				cin>>data[i][j];
			}
		}
		++t;
		cout<<"Disk set "<<t<<" is ";
		print_ans(solve());
	}
	return 0;
}
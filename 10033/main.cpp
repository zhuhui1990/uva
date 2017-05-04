#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn=10;
int reg[maxn];


int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	int cnt;
	int n;
	cin>>n;
	string s;
	getline(cin,s);
	getline(cin,s);
	char buff[5];
	for(int i=0;i<n;++i){
		cnt = 0;
		vector<int> mem;
		int temp;
		for(int j=0;j<10;++j){
			reg[j]=0;
		}
		//getline(cin,s);
		//cout<<s<<endl;
		while(getline(cin,s) && s.length()){
			//cout<<"i="<<i<<" s="<<s<<endl;
			temp=atoi(s.c_str());
			mem.push_back(temp);
		}
		/*
		for(int i=0;i<mem.size();++i){
			cout<<"i="<<i<<" mem[i]="<<mem[i] <<endl;
		}
		*/
		int com = mem[0];
		int loc=0;
		int a,b,c;
		int add;
		while(com != 100){
			//cout<<"com="<<com<<endl;
			++cnt;
			a = com/100;
			b = (com-a*100)/10;
			c = com%10;
			if(a >= 2 && a <= 9){
				++loc;
			}
			switch(a){
			case(2):
				reg[b] = c;
				reg[b] %= 1000;
				break;
			case(3):
				reg[b] += c;
				reg[b] %= 1000;
				break;
			case(4):
				reg[b] *= c;
				reg[b] %= 1000;
				break;
			case(5):
				reg[b] = reg[c];
				reg[b] %= 1000;
				break;
			case(6):
				reg[b] += reg[c];
				reg[b] %= 1000;
				break;
			case(7):
				reg[b] *= reg[c];
				reg[b] %= 1000;
				break;
			case(8):
				add = reg[c];
				reg[b] = mem[add];
				reg[b] %= 1000;
				break;
			case(9):
				add = reg[c];
				mem[add] = reg[b];
				mem[add] %= 1000;
				break;
			case(0):
				if(reg[c] != 0){
					loc = reg[b];
				}else{
					++loc;
				}
				break;
			default:
				break;
			}
			com = mem[loc];
		}
		++cnt;
		cout<<cnt<<endl;
		if(i < n - 1){
			cout<<endl;
		}
	}
	return 0;
} 
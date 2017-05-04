#include <iostream>
#include <string>
#include <vector>

using namespace std;

//°´±Ê»­´æ´¢
string b1 = "- -- -----";
string b2 = "|   ||| ||";
string b3 = "|||||  |||";
string b4 = "  ----- --";
string b5 = "| |   | | ";
string b6 = "|| |||||||";
string b7 = "- -- -- --";

int main(){
#ifdef LOCAL
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int s,n;
	string s1;
	int cnt=0;
	while(cin>>s>>s1 && (s || (s1[0]-'0'))){
		vector<int> nums;
		/*
		if( n == 0 ){
			nums.push_back(0);
		}else{
			while(n > 0){
				nums.push_back(n % 10);
				n /= 10;
			}
		}
		*/
		for(int i=s1.size()-1;i>=0;--i){
			nums.push_back(s1[i]-'0');
		}
		//b1
		for(int i = nums.size()-1; i>=0; --i){
			if (i != nums.size()-1){
				cout<<" ";
			}
			int num = nums[i];
			cout<<" ";
			for(int j = 0; j<s; ++j){
				cout<<b1[num];
			}
			cout<<" ";
		}
		cout<<endl;
		//b2 & b3
		for(int j=0;j<s;++j){
			for(int i = nums.size()-1; i>=0; --i){
				if (i != nums.size()-1){
					cout<<" ";
				}
				int num = nums[i];
				cout<<b2[num];
				for(int k = 0; k<s; ++k){
					cout<<" ";
				}
				cout<<b3[num];
			}
			cout<<endl;
		}
		//b4
		for(int i = nums.size()-1; i>=0; --i){
			if (i != nums.size()-1){
				cout<<" ";
			}
			int num = nums[i];
			cout<<" ";
			for(int j = 0; j<s; ++j){
				cout<<b4[num];
			}
			cout<<" ";
		}
		cout<<endl;
		//b5 & b6
		for(int j=0;j<s;++j){
			for(int i = nums.size()-1; i>=0; --i){
				if (i != nums.size()-1){
					cout<<" ";
				}
				int num = nums[i];
				cout<<b5[num];
				for(int k = 0; k<s; ++k){
					cout<<" ";
				}
				cout<<b6[num];
			}
			cout<<endl;
		}
		//b7
		for(int i = nums.size()-1; i>=0; --i){
			if (i != nums.size()-1){
				cout<<" ";
			}
			int num = nums[i];
			cout<<" ";
			for(int j = 0; j<s; ++j){
				cout<<b7[num];
			}
			cout<<" ";
		}
		cout<<endl;
		cout<<endl;
	}
	return 0;
}
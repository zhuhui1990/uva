#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

typedef long long LL;

const int coef[3] = {2,3,5};

int main(){
	priority_queue<LL,vector<LL>,greater<LL>> pq;
	unordered_set<LL> s;
	pq.push(1);
	s.insert(1);
	for(int i=1;;++i){
		LL x = pq.top();
		pq.pop();
		if(i == 1500){
			cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
			break;
		}
		for(int j=0;j<3;++j){
			LL x2 = x *coef[j];
			if(s.find(x2) == s.end()){
				s.insert(x2);
				pq.push(x2);
			}
		}
	}
	return 0;
}
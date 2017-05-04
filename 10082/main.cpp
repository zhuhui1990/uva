#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

//#define LOCAL


using namespace std;

const int maxn = 105;

unordered_map<char, char> res;

void initres(){
	res['1'] = '`';
	res['2'] = '1';
	res['3'] = '2';
	res['4'] = '3';
	res['5'] = '4';
	res['6'] = '5';
	res['7'] = '6';
	res['8'] = '7';
	res['9'] = '8';
	res['0'] = '9';
	res['-'] = '0';
	res['='] = '-';

	res['W'] = 'Q';
	res['E'] = 'W';
	res['R'] = 'E';
	res['T'] = 'R';
	res['Y'] = 'T';
	res['U'] = 'Y';
	res['I'] = 'U';
	res['O'] = 'I';
	res['P'] = 'O';
	res['['] = 'P';
	res[']'] = '[';
	res['\\'] = ']';

	res['S'] = 'A';
	res['D'] = 'S';
	res['F'] = 'D';
	res['G'] = 'F';
	res['H'] = 'G';
	res['J'] = 'H';
	res['K'] = 'J';
	res['L'] = 'K';
	res[';'] = 'L';
	res['\''] = ';';

	res['X'] = 'Z';
	res['C'] = 'X';
	res['V'] = 'C';
	res['B'] = 'V';
	res['N'] = 'B';
	res['M'] = 'N';
	res[','] = 'M';
	res['.'] = ',';
	res['/'] = '.';
	


}

int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	initres();
	string s;
	while (getline(cin, s)){
		for (unsigned int i = 0; i < s.length(); ++i){
			if (res.find(s[i]) != res.end()){
				cout << res[s[i]];
			}
			else if (s[i] == ' '){
				cout << ' ';
			}
		}
		cout << endl;
	}
#ifdef LOCAL
	system("pause");
#endif
	return 0;
}
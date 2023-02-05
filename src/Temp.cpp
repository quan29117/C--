#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll sqr(ll x) {
	return x * x;
}

ll stringToNum(string s) {
	ll ans = 0;
	for(ll i = 0; i < s.size(); ++i) 
		ans = ans * 10 + s[i] - '0';
	return ans;
}

ll POW_num(ll a, ll b, ll c) {
	if(b == 0) return 1 % c;
	if(b % 2 == 0) return sqr(POW_num(a,b/2,c)) % c;
	return a *(sqr(POW_num(a,b/2,c)) % c) % c;
}


ll superPowString(ll a, string b, ll len) {
    if(len <= 17) {
		ll num = stringToNum(b);
		return POW_num(a,num,1337);
	}
	else 
	{
		string cc = "";
		cc = cc + b[len - 1];
		ll e = stringToNum(cc);
		b.erase(len-1,1);

		return POW_num(a,e,1337)*POW_num(superPowString(a,b,len-1),10,1337) % 1337;
	}
}

int superPow (ll a, int b[], ll len) {
    string b_str = "";
    for(ll i = 0; i < len; ++i) {
        char t = char(b[i] + 49 - 1);
        b_str = b_str + t;
    }
    return superPowString(a,b_str,len);
}

int dem(int n, int m) {
	if (m==0) {
		if (n==0) return 1;
		return 0;
	}
	if (n>=m) {
		return dem(n,m-1) + dem(n-m,m-1);
	}
	return dem(n,m-1);
}

int loi_nhuan(vector <int> a, int i, int j, int m) {
	if (i<=j) {
		return max (loi_nhuan(a,i+1,j,m+1) + a[i]*m, loi_nhuan(a,i,j-1,m+1) + a[j]*m);
	}
	else return 0;
}

void towerofHN(int n, char from, char to, char aux) {
	if (n==0) return;
	towerofHN(n-1, from, aux, to);
	cout << from << " " << to << "\n";
	towerofHN(n-1,aux,to, from);
}

int main () {
    char *str = new char [10] {"ABC"};
	auto Len = strlen(str)+1;
	char *pString = new char [Len];
	strcpy_s(pString, Len, str);
	std::cout << pString;
    return 0;
}
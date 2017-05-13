#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;
const ll MOD=1e9+7;

char s[maxn];

ll qpow(ll n,ll k,ll p){
	ll res=1;
	while(k){
		if(k&1) res=(res*n)%p;
		n=(n*n)%p;
		k>>=1;
	}
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(~scanf("%s",s)){
		int len=strlen(s);
		ll res=0,A=0;
		for(int i=0;i<len;i++){
			if(s[i]=='a') A++;
			else res=(res+qpow(2,A,MOD)-1+MOD)%MOD;
		}
		printf("%lld\n",res);
	}
	return 0;
}




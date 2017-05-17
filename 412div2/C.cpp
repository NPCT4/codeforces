#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int T;
int x,y,p,q;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;cin>>T;
	while(T--){
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(p==0) puts(x==0?"0":"-1");
		else if(p==q) puts(x==y?"0":"-1");
		else if(1LL*x*q==1LL*y*p) puts("0");
		else{
			ll k1,k2,k3,k;
			// k1>=(y-x)/(q-p)
			ll A=y-x,B=q-p;
			if(A%B) k1=A/B+1;
			else k1=A/B;
			// k2>=x/p
			if(x%p) k2=x/p+1;
			else k2=x/p;
			// k3>=y/q;
			if(y%q) k3=y/q+1;
			else k3=y/q;
			k=max(k1,max(k2,k3));
			ll b=k*q-y;
			cout<<b<<endl;
		}
	}
	return 0;
}


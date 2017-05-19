#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;
const double EPS=1e-10;

int n,p;
int a[maxn],b[maxn];

bool check(double t){
	double s=0;
	for(int i=1;i<=n;i++) s+=max(a[i]*t-b[i],0.0);
	return p*t>s;
}

double bin(double l,double r){
	double res=l;
	for(int i=1;i<=1000;i++){
		double m=(l+r)/2;
		if(check(m)) res=max(res,m),l=m;
		else r=m;
	}
	if(res>1e13) return -1;
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>p){
		for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
		double res=bin(0,1e14);
		if(res<0) puts("-1");
		else printf("%.10f\n",res);
	}
	return 0;
}



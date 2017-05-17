#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;
const double EPS=1e-10;

int n;
int a[210][6];
int cnt[6],c[6];

int Sco(int t,int p,int q){
	if(t==-1) return 0;
	int sco;
	if(2*p>q) sco=500;
	else if(4*p>q) sco=1000;
	else if(8*p>q) sco=1500;
	else if(16*p>q) sco=2000;
	else if(32*p>q) sco=2500;
	else sco=3000;
	return sco*(250-t)/250;
}

bool Can(int m){
	for(int i=1;i<=5;i++) c[i]=cnt[i];
	for(int i=1;i<=5;i++){
		if(a[1][i]==-1) ;
		else{
			if(a[2][i]==-1) ;
			else{
				if(a[1][i]<=a[2][i]) ;
				else c[i]+=m;
			}
		}
	}
	int A=0,B=0;
	for(int i=1;i<=5;i++){
		A+=Sco(a[1][i],c[i],n+m);
		B+=Sco(a[2][i],c[i],n+m);
	}
	return A>B;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n){
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++){
				scanf("%d",&a[i][j]);
				if(~a[i][j]) cnt[j]++;
			}
		}
		int res=-1;
		for(int i=0;i<=n*32;i++){
			if(Can(i)){
				res=i;break;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
/*
2
5 15 40 70 115
50 45 40 30 15

3
55 80 10 -1 -1
15 -1 79 60 -1
42 -1 13 -1 -1

5
119 119 119 119 119
0 0 0 0 -1
20 65 12 73 77
78 112 22 23 11
1 78 60 111 62

4
-1 20 40 77 119
30 10 73 50 107
21 29 -1 64 98
117 65 -1 -1 -1
*/

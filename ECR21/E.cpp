#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n,m;
struct Node{
	int w,c;
	bool used;
	friend bool operator<(Node A,Node B){
		ll sa=1LL*A.c*B.w,sb=1LL*B.c*A.w;
		return sa==sb?A.w>B.w:sa>sb;
	}
};Node p[maxn];

ll test22_3(ll res){
	int A1=0,A2=0,B=0;
	for(int i=1;i<=n;i++){
		if(!p[i].used&&p[i].w==2){
			if(A1==0) A1=i;
			else if(A2==0){
				A2=i;break;
			}
		}
	}
	for(int i=n;i>=1;i--){
		if(p[i].used&&p[i].w==3){
			B=i;break;
		}
	}
	if(A1==0||A2==0||B==0) return res;
	return max(res,res+p[A1].c+p[A2].c-p[B].c);
}

ll test3_2(ll res){
	int A=0,B=0;
	for(int i=1;i<=n;i++){
		if(!p[i].used&&p[i].w==3){
			A=i;break;
		}
	}
	for(int i=n;i>=1;i--){
		if(p[i].used&&p[i].w==2){
			B=i;break;
		}
	}
	if(A==0||B==0) return res;
	return max(res,res+p[A].c-p[B].c);
}

ll test2_1(ll res){
	int A=0,B=0;
	for(int i=1;i<=n;i++){
		if(!p[i].used&&p[i].w==2){
			A=i;break;
		}
	}
	for(int i=n;i>=1;i--){
		if(p[i].used&&p[i].w==1){
			B=i;break;
		}
	}
	if(A==0||B==0) return res;
	return max(res,res+p[A].c-p[B].c);
}

ll work1(ll res){
	ll ans=res;
	ans=max(ans,test22_3(res));
	ans=max(ans,test3_2(res));
	ans=max(ans,test2_1(res));
	return res;
}

ll test3_1(ll res){
	int A=0,B=0;
	for(int i=1;i<=n;i++){
		if(!p[i].used&&p[i].w==3){
			A=i;break;
		}
	}
	for(int i=n;i>=1;i--){
		if(p[i].used&&p[i].w==1){
			B=i;break;
		}
	}
	if(A==0||B==0) return res;
	return max(res,res+p[A].c-p[B].c);
}

ll work2(ll res){
	return max(res,test3_1(res));
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n>>m){
		for(int i=1;i<=n;i++) scanf("%d%d",&p[i].w,&p[i].c),p[i].used=0;
		sort(p+1,p+n+1);
		ll res=0;
		for(int i=1;i<=n;i++){
			if(m>=p[i].w){
				m-=p[i].w;
				res+=p[i].c;
				p[i].used=1;
			}
		}
		cout<<"m="<<m<<endl;
		if(m==1) work1(res);
		else if(m==2) work2(res);
		cout<<res<<endl;
	}
	return 0;
}




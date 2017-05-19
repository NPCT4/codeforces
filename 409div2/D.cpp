#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000100;
const int INF=1e9+10;

int n;
struct Point{
	double x,y;
	void debug(){
		cout<<"x="<<x<<" y="<<y<<endl;
	}
	friend Point operator-(Point A,Point B){
		return (Point){A.x-B.x,A.y-B.y};
	}
	friend double operator*(Point A,Point B){
		return A.x*B.y-A.y*B.x;
	}
};Point p[maxn];

double dist(Point A,Point B){
	double tx=A.x-B.x,ty=A.y-B.y;
	return sqrt(tx*tx+ty*ty);
}

double work(Point B,Point A,Point C){
	double S=fabs((C-B)*(A-B));
	double a=dist(B,C);
	double h=S/a;
	return h/2;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	while(cin>>n){
		for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
		double res=1.0*INF*INF;
		for(int i=1;i<=n;i++){
			int L=i-1;
			if(L==0) L=n;
			int R=i%n+1;
			res=min(res,work(p[L],p[i],p[R]));
		}
		printf("%.10f\n",res);
	}
	return 0;
}


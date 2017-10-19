#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #define debug(...) printf(__VA_ARGS__)
#else
    #define debug(...) (void)0
#endif
#define LL long long
#define pii pair<int,int>

#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
//const int inf = 0x7fffffff; //beware overflow
//const LL INF = 0x7fffffffffffffff; //beware overflow
#define mem(x, y) memset(x, (y), sizeof(x) );
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
template<typename A, typename B>
ostream& operator <<(ostream &s, const pair<A,B> &p) {
     return s<<"("<<p.first<<","<<p.second<<")";
}
template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c) {
    s << "[ ";
    for (auto it : c) s << it << " ";
    s << "]";
    return s;
}
template<typename T>
ostream& operator << (ostream &o, const set<T> &st) {
    o << "{";
    for (auto it=st.begin(); it!=st.end(); it++) o << (it==st.begin() ? "" : ", ") << *it;
    return o << "}";
}
template<typename T1, typename T2>
ostream& operator << (ostream &o, const map<T1, T2> &mp) {
    o << "{";
    for (auto it=mp.begin(); it!=mp.end(); it++) {
        o << (it==mp.begin()?"":", ") << it->first << ":" << it->second;
    }
    o << "}";
    return o;
}
inline LL getint(){
   LL _x=0,_tmp=1; char _tc=getchar();
   while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
   if( _tc == '-' ) _tc=getchar() , _tmp = -1;
   while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
   return _x*_tmp;
}

#define maxn 1005
int G[maxn][maxn];
//int peo_sum[maxn];
//int pos_sum[maxn];
int N, C, M;

bool ok(int x, vector<int> v) {
//    if( *max_element(peo_sum, peo_sum+C) > x ) return false;
    for(int i=N-1;i>0;i--) {
        if( v[i] > x )
            v[i-1] += v[i]-x;
    }
    return v[0]<=x;
}
int decide(int x, vector<int> v) {
    int ret = 0;
    for(int i=N-1;i>0;i--) {
        if( v[i] > x )
            ret += v[i]-x;
    }
    return ret;
}

int main() {
    int T = getint();
    for(int testcase=1; testcase<=T; testcase++) {
        mem(G, 0);
//        mem(peo_sum, 0);

        N = getint(), C = getint(), M = getint();

        for(int i=0;i<M;i++) {
            int p = getint(), b = getint();
            p--, b--;
            G[p][b]++;
        }
//        for(int i=0;i<N;i++)for(int j=0;j<C;j++)printf("%d ", G[i][j]);

        vector<int> peo_sum(C);
        for(int j=0;j<C;j++) {
            int s = 0;
            for(int i=0;i<N;i++) s+=G[i][j];
            peo_sum[j] = s;
        }
        int mx = *max_element(ALL(peo_sum));
        // v is pos_sum
        vector<int> v(N);
        for(int i=0;i<N;i++) {
            int s=0;
            for(int j=0;j<C;j++) s += G[i][j];
            v[i] = s;
        }
        int lb = mx-1, ub = M;

        int ans=0;
        while(ub-lb>1) {
            int mid = (lb+ub)>>1;
            if(ok(mid,v)) ub = mid;
            else lb = mid;
        }
//        cout << v << endl;
        printf("Case #%d: %d %d\n", testcase, ub, decide(ub, v));

    }
}


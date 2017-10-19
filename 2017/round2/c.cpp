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
#define maxn 104
vector< pair<pair<int,int>, char> > res[maxn][maxn];
char grid[maxn][maxn];
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
/*
bool dfs(vector<pii> vv, int id) {
    if( id ==
}
*/
int main() {
    int T = getint();
    for(int testcase=1; testcase<=T; testcase++) {
        int R = getint(), C = getint();
        for(int i=0;i<R;i++)for(int j=0;j<C;j++)res[i][j].clear();

        for(int i=0;i<R;i++)  scanf("%s", grid[i]);
        bool fail = false;
        vector<pii> vv;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++) if( grid[i][j] == '-' || grid[i][j] == '|' ) {

            int a=0,b=0;
            bool hor = true, ver = true;
            for(int cc = j+1; cc < C; cc++) {
                if( grid[i][cc] == '#' ) break;
                if( grid[i][cc] == '-' || grid[i][cc] == '|' ) { hor = false; break; }
            }
            for(int cc = j-1; cc >=0; cc--) {
                if( grid[i][cc] == '#' ) break;
                if( grid[i][cc] == '-' || grid[i][cc] == '|' ) { hor = false; break; }
            }
            if( hor ) {
                for(int cc=j+1;cc<C;cc++) {
                    if( grid[i][cc] == '#' ) break;
                    if( grid[i][cc] == '.' ) res[i][cc].push_back( make_pair( make_pair(i, j), '-' )),a++;
                }
                for(int cc=j-1;cc>=0;cc--) {
                    if( grid[i][cc] == '#' ) break;
                    if( grid[i][cc] == '.' ) res[i][cc].push_back( make_pair( make_pair(i, j), '-' )),a++;
                }
            }

            for(int cr = i+1; cr < R; cr++) {
                if( grid[cr][j] == '#' ) break;
                if( grid[cr][j] == '-' || grid[cr][j] == '|' ) { ver = false; break; }
            }
            for(int cr = i-1; cr >=0; cr--) {
                if( grid[cr][j] == '#' ) break;
                if( grid[cr][j] == '-' || grid[cr][j] == '|' ) { ver = false; break; }
            }
            if( ver ) {
                for(int cr = i+1; cr < R; cr++) {
                    if( grid[cr][j] == '#' ) break;
                    if( grid[cr][j] == '.' ) res[cr][j].push_back( make_pair( make_pair(i, j), '|')),b++;
                }
                for(int cr = i-1; cr >=0; cr--) {
                    if( grid[cr][j] == '#' ) break;
                    if( grid[cr][j] == '.' ) res[cr][j].push_back( make_pair( make_pair(i, j), '|')),b++;
                }
            }
            if( hor ) {
                grid[i][j] = '-';
            }
            if( ver ) {
                grid[i][j] = '|';
            }
            if( !ver && !hor ) {
                fail = true;
                break;
            }
            if( ver && hor ) {
                if( a>b ) grid[i][j]='-';
                else grid[i][j]='|';
                vv.push_back( make_pair(i, j) );
            }
        }
        if( fail ) {
            printf("Case #%d: IMPOSSIBLE\n", testcase);
            continue;
        }
        vector<pii> vvv;
        for(int i=0;i<R;i++)for(int j=0;j<C;j++) if(grid[i][j]=='.') {
            if( fail ) break;

            if( res[i][j].empty() ) {
                printf("Case #%d: IMPOSSIBLE\n", testcase);
                fail = true;
                break;
            }
            vvv.push_back( make_pair(i, j));
        }
        if( fail ) continue;

        for(pii h : vvv ) {
            int r = h.first, c = h.second;
            bool ok = false;
            for(auto f : res[r][c]) {
                if( grid[f.first.first][f.first.second] == f.second )
                    ok = true;
            }
            if( !ok ) {
                fail = true;
                printf("Case #%d: IMPOSSIBLE\n", testcase);
                break;
            }
        }
        if(fail) continue;

        printf("Case #%d: POSSIBLE\n", testcase);
        for(int i=0;i<R;i++)printf("%s\n", grid[i]);
    }
}

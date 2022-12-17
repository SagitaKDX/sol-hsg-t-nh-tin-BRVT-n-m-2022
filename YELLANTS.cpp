#include <bits/stdc++.h>

using namespace std;
typedef long long  ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pli> vli;
typedef vector<pil> vil;

#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define mp make_pair
#define pb push_back
#define f first

#define s second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define ALL(x) begin(x), end(x)

void minimize(long long &x,long long y){
   if(x>y){
      x=y;
   }
}

void maximize(long long &x,long long y){
    if(x<y){
        x=y;
    }
}

template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}

long long pow_mod(long long a, long long b, long long m) {
     long long res = 1;
     while(b){
            res = res * (b & 1 ? a : 1) % m;
            a = a * a % m; b >>= 1;
     }
     return res;
}

long long GCD(long long a , long long b){
    while(b != 0 ){
         a = a % b;
         long long tmp = a;
         a = b;
         b = tmp;
    }
    return a;
}

long long minn(long long a ,long long b , long long c ,long long d){
    long long res = a;
    if(res > d) res = d;
    if(res > b) res = b;
    if(res > c) res = c;
    return res;
}
const ll INF = 1e18 + 7;
const ll MAXN= 1e3 + 7;
int  m , n;
int a[MAXN][MAXN];
int dx[] ={1 , 1 , 1};
int dy[] ={0 , -1  , 1};
struct item{
    ll val;
    int x , y;
    bool operator < (const item &other)const{
        return val > other.val;
    }
};
ll dis[MAXN][MAXN];
bool vis[MAXN][MAXN];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("new.inp" , "r" , stdin);
    freopen("new.out" , "w" , stdout);
    cin >> m >> n;
    for(int i = 1 ; i <= m ; i ++){
        for(int j = 1 ; j <= n ; j ++){
            cin >> a[i][j];
        }
    }
    priority_queue<item> qu;
    for(int i = 1 ; i <= n ; i ++){
        dis[1][i] = a[1][i];
        qu.push({a[1][i] , 1 , i});
    }
    item k;
    item cur;
    while(!qu.empty()){
        k = qu.top();
        qu.pop();
        if(vis[k.x][k.y]){
            continue;
        }
        vis[k.x][k.y] = true;
        for(int i = 0 ; i <= 2 ; i ++){
            cur.x = k.x + dx[i];
            cur.y = k.y + dy[i];
            if(cur.x < 1 || cur.y < 1 || cur.x > m || cur.y > n || a[cur.x][cur.y] <= a[k.x][k.y]){
                continue;
            }
            if(dis[cur.x][cur.y] < dis[k.x][k.y] + a[cur.x][cur.y]){
                dis[cur.x][cur.y] = dis[k.x][k.y] + a[cur.x][cur.y];
                cur.val = dis[cur.x][cur.y];
                qu.push(cur);
            }
        }
    }
    ll res = 0;
    for(int i = 1;  i <= n ; i ++){
        maximize(res , dis[m][i]);
    }
    cout << res << '\n';
    return 0;
}

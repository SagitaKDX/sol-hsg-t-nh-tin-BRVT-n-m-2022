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
#define double long double
const ll INF = 1e18 + 7;
const ll MAXN= 1e5 + 7;
int n ;
struct point{
    ll x , y;
};
point a[MAXN];
ll sqr(ll val){
    return val * val;
}
double cal(point u , point v){
    return (double) sqrt(sqr(u.x - v.x) + sqr(u.y - v.y));
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("new.inp" , "r" , stdin);
    freopen("new.out" , "w" , stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i].x >> a[i].y;
    }
    bool ok = false , ok2 = false ;
    ll max_x = -INF , max_y = -INF;
    ll min_x = INF , min_y = INF;
    for(int i = 1 ; i <= n ; i ++){
        if(a[i].y == 0){
            maximize(max_x , a[i].x);
            minimize(min_x , a[i].x);
            ok = true;
        }
        if(a[i].x == 0){
            maximize(max_y , a[i].y);
            minimize(min_y , a[i].y);
            ok2 = true;
        }
    }
    vector<point > save;
    if(ok){
        save.push_back({max_x , 0});
        save.push_back({min_x , 0});
    }
    if(ok2){
        save.push_back({0 , max_y});
        save.push_back({0 , min_y});
    }
    double res = -INF;
    for(int i = 0 ; i < save.size() ; i ++){
        for(int j = i + 1 ; j < save.size() ; j ++){
            res = max(res , cal(save[i] , save[j]));
        }
    }
    cout << setprecision(5)  << fixed << res ;
    return 0;
}

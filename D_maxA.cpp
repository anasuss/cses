    #include<bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
    #define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
    #define sz(x) (int)(x).size()
    #define yes cout << "YES\n"
    #define no cout << "NO\n"
    #define nope cout << "-1\n" ;
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define endl "\n"
 
    using namespace std;
    using namespace __gnu_pbds;
     
    template<typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    
    const int INF = 1000*1000*1000; // 1 e 9
    const ll inf = (ll)1e18;
    const int mod = 1e9+7 ;
    const int N = 550 ;
    ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
     
    ordered_set<int> s;
     
    int n,p,k;

    int m[N][N];
     
    void solve(){
        cin >> n >> p >> k ; 
        for (int i = 1 ; i<=n ; i++){
            for (int j = 1 ; j<=p ; j++){
                cin >> m[i][j] ;
                m[i][j] = (m[i][j] <= k) - (m[i][j] > k) ;
                m[i][j] = m[i][j] + m[i][j-1] + m[i-1][j] - m[i-1][j-1] ;
            }
        }
        int ans = 0;
        for (int i = 1 ; i<=n ; i++){
            for (int j = 1 ; j<=p ; j++){
                for (int x = 1 ; x<=min(n-i+1,p-j+1) ; x++){
                    int r1 = i+x-1, c1 = j+x-1 ;
                    if (r1 > n || c1 > p) continue;
                    int sum = m[r1][c1] - m[i-1][c1] - m[r1][j-1] + m[i-1][j-1] ;
                    if (sum >= 0) ans = max(ans, x*x) ;
                }
            }
        }
        cout << ans << endl ;
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        //cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }
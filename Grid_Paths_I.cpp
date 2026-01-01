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
    const int N = 1e3+100 ;
    ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
     
    ordered_set<int> s;
     
    int n ;
    
    char m[N][N];

    int dp[N][N];

    bool valide(int x, int y){
        return x>=0 && y>=0 && x<n && y<n && m[x][y] == '.';
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};

    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++){
                cin >> m[i][j];
            }
        }
        dp[0][0] =  m[0][0] == '.';
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<n ; j++){
                for (int k = 0 ; k<4 ; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (valide(x,y)){
                        dp[x][y] += dp[i][j];
                        dp[x][y] %= mod;
                    } 
                }
            }
        }
        cout << dp[n-1][n-1]%mod;
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
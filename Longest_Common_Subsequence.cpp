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
    const int N = 5e3+100 ;
    ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
          
    int n,m;
    int dp[N][N];
    int a[N],b[N];

    bool ok ;

    void solve(){
        cin >> n >> m;
        for (int i = 1 ; i<=n ; i++){
            cin >> a[i];
        }
        
        for(int i = 1 ; i<=m ; i++){
            cin >> b[i];
        }
        for(int i = 1 ; i<= n ; i++){
            for (int j = 1 ; j<=m ; j++){
                if (a[i] == b[j]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout << dp[n][m] << endl;
        vector<int> ans;
        int x = n , y = m;
        while(dp[x][y] != 0){
            if (dp[x-1][y] == dp[x][y-1] && dp[x][y] == dp[x-1][y-1]+1){
                ans.pb(a[x]);
                x--; y--;
            }else{
                if (dp[x-1][y]>dp[x][y-1]){
                    x-=1;
                }else{
                    y-=1;
                }
            }
        }
        reverse(all(ans));
        for (int e : ans) cout << e << ' ';
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
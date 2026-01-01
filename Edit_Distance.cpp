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
          
    string s , m; 
    int dp[N][N];

    int work(int i = 0, int j = 0){
        int &r = dp[i][j];
        if (r != -1)
            return r;
        if (j == sz(m) && i == sz(s)){
            return r = 0;
        }
        if (i == sz(s)){
            return r = abs(j - sz(m));
        }
        
        if (j == sz(m)){
            return r = abs(i - sz(s));
        }

        if (s[i] == m[j])
            return r = work(i+1,j+1);

        return r = min(work(i+1,j+1),min(work(i+1,j),work(i,j+1)))+1;
    }


    void solve(){
        cin >> s >> m;
        for (int i = 0 ; i <= sz(s) ; i++){
            for (int j = 0; j<= sz(m) ; j++){
                dp[i][j] = -1;
            }
        }
        for (int i = 0 ; i<=s.size() ; i++){
            dp[i][0] = i;
        }
        for (int i = 0 ; i<=m.size() ; i++){
            dp[0][i] = i;
        }
        for(int i = 1 ; i<= sz(s) ; i++){
            for (int j = 1 ; j<= sz(m) ; j++){
                if (s[i-1] == m[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                }
            }
        }
        // for(int i = 0 ; i<= sz(s) ; i++){
        //     for (int j = 0 ; j<= sz(m) ; j++){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        cout << dp[sz(s)][sz(m)];
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
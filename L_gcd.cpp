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
    const int N = 5e5+10 ;
    ll gcd(ll a, ll b) {
        while (b != 0) {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
          
    int n,q ;
     
    ll a[N] ;
    ll prefix[N], suffix[N] ;  
    void solve(){
        cin >> n ; 
        for (int i = 1 ; i<=n ; i++){
            cin >> a[i] ; 
        }
        prefix[0] = 0 ;
        for (int i = 1 ; i<=n ; i++){
            prefix[i] = gcd(prefix[i-1], a[i]) ;
        }
        suffix[n+1] = 0 ;
        for (int i = n ; i>=1 ; i--){
            suffix[i] = gcd(suffix[i+1], a[i]) ;
        }
        cin >> q;
        while(q--){
            int k; cin >> k;
            int l = 1, r = n ;
            bool found = false ;
            while(l<=r){
                int mid = (l+r)/2 ;
                if (prefix[mid] % k == 0){
                    l = mid + 1 ;
                    found = true ;
                } else {
                    r = mid - 1 ;
                }
            }
            if (l-1 == n || suffix[l+1] % k == 0){
                yes;
            }else{
                no;
            }
        }
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
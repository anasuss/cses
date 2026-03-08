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
    const int N = 1e6+100 ;
    ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
     
    ordered_set<int> s;
     
    ll n,p ;
     
    ll a[N] ;
    ll b[N] ;  
    
    vector<int> primes ;

    void sieveOfEratosthenes(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                primes.push_back(i);
            }
        }
        return;
    }

    void solve(){
        cin >> n >> p ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ; 
        }
        sort(a , a+n) ;
        int i;
        for (i = 0 ; i<n && a[i]<=p ; i++){
            auto it = lower_bound(all(primes) , a[i]) ;
            if (it!=primes.end() && *it==a[i]){
                p+=a[i] ;
                continue ;
            }
            for (int j = 0 ; j<sz(primes) && primes[j]<=a[i] ; j++){
                if (a[i]%primes[j]==0){
                    p+=primes[j] ;
                    break ;
                }
            }
        }
        cout << i << ' ' << p << endl ;
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        sieveOfEratosthenes(2e7+1) ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }
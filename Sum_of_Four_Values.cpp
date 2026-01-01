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
    const int N = 2e5+100 ;
    ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
     
    ordered_set<int> s;
     
    ll n,target ;
    
    ll a[N];

    map<ll,vector<pii>> mp;
    
    void solve(){
        cin >> n >> target; 
        for (ll i = 0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i = 0 ; i<n ; i++){
            for (int j = i+1 ; j<n ; j++){
                ll x = a[i]+a[j];
                mp[x].pb({i+1,j+1});
            }
        }
        for (auto it : mp){
            ll x = target - it.first;
            if (mp.find(x) != mp.end()){
                for(int i = 0 ; i<it.second.size() ; i++){
                    for (int j = 0 ; j<mp[x].size() ; j++){
                        set<int> s;
                        s.insert(it.second[i].first);
                        s.insert(it.second[i].second);
                        s.insert(mp[x][j].first);
                        s.insert(mp[x][j].second);
                        if (s.size() == 4){
                            for (int k : s){
                                cout << k << ' ';
                            }
                            return;
                        }
                    }
                }
            }
        }
        cout << "IMPOSSIBLE" ;
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
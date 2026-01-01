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
    const int N = 1e5 + 100;
    ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
     
    ordered_set<int> s;
     
    int n,m,k;
    vector<pll> adj[N];

    void dijkstra(int x){
        priority_queue <pll, vector<pll>, greater<pll>> pq ;
        vector<vector<ll>> dist(n+1);
        pq.push({0,x}) ; 
        while(!pq.empty()){
            ll w = pq.top().first ; 
            ll node = pq.top().second;
            pq.pop() ;
            if(dist[node].size() >= k) continue;
            dist[node].push_back(w);
            for (auto &x : adj[node]){
                ll child = x.second ; 
                ll wch = x.first ;
                pq.push({wch+w, child});
            }
        }
        sort(all(dist[n-1]));
        for (auto x : dist[n-1]) cout << x << ' ';
    }
 
    void solve(){
        cin >> n >> m >> k ;
        for (int i = 0 ; i<m ; i++){
            int x,y,w; cin >> x >> y >> w; --x; --y;
            adj[x].pb({w,y});
        }
        dijkstra(0);
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
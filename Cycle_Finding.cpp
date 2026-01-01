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
     
    int n,m ;
    
    vector<pair<ll,pll>> edges;
    ll dist[N];
    int parent[N];

    void bellmanFord(){
        for (int i = 0 ; i<n ; i++){
            dist[i] = inf;
        }
        dist[0] = 0;
        int node = -1;
        for (int i = 0 ; i<n ; i++){
            for (auto e : edges){
                ll p = e.first; ll c = e.second.first; ll w = e.second.second;
                if (i == n-1 && dist[c] > dist[p]+w){
                    node = c; 
                }
                if (dist[c]>dist[p]+w){
                    parent[c] = p;
                    dist[c] = min(dist[c], dist[p]+w);
                }
            }
        }
        if (node == -1){
            no; return;
        }
        for (int i = 0 ; i<n ; i++){
            node = parent[node];
        }
        vector<int> ans;
        yes;
        int x = node;
        ans.push_back(x);
        while (parent[node] != x)
        {
            ans.push_back(parent[node]);
            node = parent[node];
        }
        ans.push_back(x);
        reverse(all(ans));
        for (int v : ans) cout << v+1 << ' ';
    }

    void solve(){
        cin >> n >> m; 
        for (int i = 0 ; i<m ; i++){
            ll x,y,w; cin >> x >> y >> w; --x; --y;
            edges.pb({x,{y,w}});
        }
        bellmanFord();
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
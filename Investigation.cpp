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
         
    int n,m ;
    vector<pll> adj[N];
    vector<int>dijPath[N];
    int par[N];
    vector<int> topSort;
    bool vis[N];
    ll dist[N] , numberOfWays[N], shortestPath[N], longestPath[N];

    void dijkstra(){
        priority_queue<pll> pq;
        for(int i = 0 ; i<n ; i++){
            dist[i] = inf;
            shortestPath[i] = inf;
            longestPath[i] = -inf;
        }
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            ll node = pq.top().second;
            ll w = -pq.top().first;
            pq.pop();
            if (dist[node] != w) continue;
            for (auto e : adj[node]){
                ll v = e.first;
                ll wv = e.second;
                ll newDist = dist[node] + wv;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    pq.push({-dist[v], v});
                }
            }
        }
    }

    void dfs(int node){
        vis[node] = true;    
        for(int e : dijPath[node]){
            if (!vis[e]){
                dfs(e);
            }
        }
        topSort.push_back(node);
    }

    void solve(){
        cin >> n >> m;
        for (int i = 0; i<m ; i++){
            ll x,y,w; cin >> x >> y >> w; --x; --y;
            adj[x].push_back({y,w});
        }
        dijkstra();
        for(int u = 0; u < n; u++) {
            for(auto e : adj[u]) {
                ll w = e.second;
                ll v = e.first; 
                if(dist[u] + w == dist[v]) {
                    dijPath[u].push_back(v);
                }
            }
        }
        dfs(0);
        reverse(all(topSort));
        numberOfWays[0] = 1;
        shortestPath[0] = 0;
        longestPath[0] = 0;
        for(int u : topSort){
            for(int v : dijPath[u]){
                numberOfWays[v] = (numberOfWays[v]+numberOfWays[u])%mod;
                shortestPath[v] = min(shortestPath[v], shortestPath[u]+1);
                longestPath[v] = max(longestPath[v], longestPath[u]+1);
            }
        }
        cout << endl;
        cout << dist[n-1] << ' ' << numberOfWays[n-1] << ' ' << shortestPath[n-1] << ' ' << longestPath[n-1] ;
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
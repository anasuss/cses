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
    
    vector<pll> graph[N];
    pll par[N];
    int n,m;

    void dijkstra(){
        priority_queue <pair<ll,pll>, vector<pair<ll,pll>>, greater<pair<ll,pll>>> pq ;
        vector<vector<ll>> dist(n+1,vector<ll>(2,inf)) ; 
        pq.push({0,{0,0}}) ; 
        dist[0][0] = 0 ; 
        while(!pq.empty()){
            ll w = pq.top().first; 
            ll node = pq.top().second.first;
            ll used = pq.top().second.second; 
            pq.pop() ;
            if (dist[node][used] != w) continue;
            for (auto x : graph[node]){
                ll child = x.first ; 
                ll wch = x.second ; 
                if (dist[node][used]+wch<dist[child][used]){
                    dist[child][used] = dist[node][used]+wch ; 
                    pq.push({dist[child][used],{child,used}}) ; 
                }

                if (used == 0 && dist[node][used] + wch/2 < dist[child][1]){
                    dist[child][1] = dist[node][used] + wch/2;
                    pq.push({dist[child][1],{child,1}}) ;
                }
            }
        }
        cout << min(dist[n-1][0],dist[n-1][1]) << endl;
    }

    void solve(){
        cin >> n >> m;
        for (int i = 0 ; i<m ; i++){
            int x,y,w; cin >> x >> y >> w ; --x; --y;
            graph[x].pb({y,w});
        }
        dijkstra();
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
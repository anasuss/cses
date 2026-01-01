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
    vector<int> adj[N];

    int vis[N];
    int parents[N];

    vector<int> ans;

    bool complete = false;

    bool dfs(int node, int parent = -1){
        vis[node] = true;
        parents[node] = parent;

        for (int child : adj[node]){
            if (!vis[child]){
                if (dfs(child,node)){
                    return true;
                }
            }else if (child != parent){
                ans.pb(child + 1);
                int cur = node;
                while (cur != child) {
                    ans.push_back(cur + 1);
                    cur = parents[cur];
                }
                ans.push_back(child + 1);
                reverse(ans.begin(), ans.end());
                return true;
            }
        }
        return false;
    }

    void solve(){
        cin >> n >> m;
        for (int i = 0 ; i<m ; i++){
            int a,b; cin >> a >> b; --a; --b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for (int i = 0 ; i<n ; i++){
            if (!vis[i] && dfs(i)){
                break;
            }else{
                ans.clear();
            }
        }
        if (ans.size() == 0){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        cout << ans.size() << endl;
        for (int child : ans){
            cout << child << ' ';
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
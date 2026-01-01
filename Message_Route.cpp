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
    int level,found;
     
    vector<int> adj[N];

    bool vis[N];
    int prv[N];
    queue<int> q;
    vector<int> ans;

    void bfs(int node){
        q.push(node);
        prv[node] = -1;
        vis[node] = true;
        for ( ; !q.empty() && !found ; level++){
            int sz = q.size();
            while(sz--){
                int parent = q.front();
                q.pop();
                for (int child : adj[parent]){
                    if(vis[child]) continue;
                    prv[child] = parent;
                    if (child == n-1){
                        found = true;
                        break;
                    }
                    vis[child] = true;
                    q.push(child);
                }
            }
        }
    }

    void solve(){
        cin >> n >> m;
        for (int i = 0 ; i<m ; i++){
            int a,b; cin >> a >> b; --a; --b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        bfs(0);
        if (!found){
            cout << "IMPOSSIBLE"; return;
        }
        int node = n-1;
        while(prv[node] != -1){
            ans.pb(node);
            node = prv[node];
        }
        ans.pb(node);
        reverse(all(ans));
        cout << level + 1 << endl;
        for (int i : ans){
            cout << i + 1 << ' ';
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
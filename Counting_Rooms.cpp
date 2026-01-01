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
    const int N = 2e3+100 ;
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
    
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    bool visited[N][N];

    void dfs(int x, int y){
        if (x<0 || y<0 || x == n || y == m || visited[x][y])
            return;
        visited[x][y] = true;
        for (int k = 0; k<4 ; k++){
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            dfs(nx,ny);
        }
    }

    void solve(){
        cin >> n >> m ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                char c; cin >> c;
                visited[i][j] = c == '#';
            } 
        }
        int ans = 0;
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (!visited[i][j]){
                    ans+=1;
                    dfs(i,j);
                }
            }
        }
        cout << ans;
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
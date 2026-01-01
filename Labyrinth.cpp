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
    const int N = 1000+100 ;
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
    int sx,sy,ex,ey;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    bool visited[N][N];
    char mat[N][N];
    char steps[N][N];
    string ans = "";
    queue<pii> q;
    int level = 0, found = 0;
 
void buildPath(int x, int y) {
    while (x != sx || y != sy) {
        char c = steps[x][y];
        ans += c;

        if (c == 'D') {
            x -= 1;
        } else if (c == 'U') {
            x += 1;
        } else if (c == 'R') {
            y -= 1;
        } else if (c == 'L') {
            y += 1;
        }
    }
}
 
    void solve(){
        cin >> n >> m ; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                cin >> mat[i][j];
                if (mat[i][j] == 'A'){
                    sx = i,sy = j;
                }
                if (mat[i][j] == 'B'){
                    ex = i, ey = j;
                }
                visited[i][j] = (mat[i][j] == '#');
            } 
        }
    q.push({sx, sy});
    visited[sx][sy] = true;
    steps[sx][sy] = 'X'; // starting mark

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == ex && y == ey) {
            found = 1;
            break; // stop BFS
        }
        visited[x][y] = true;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (mat[nx][ny] == '#') continue; // if obstacles exist

            visited[nx][ny] = true;

                    if (dx[k] == 1){
                        steps[nx][ny] = 'D';
                    }else if (dx[k] == -1){
                        steps[nx][ny] = 'U';
                    }else if (dy[k] == 1){
                        steps[nx][ny] = 'R';
                    }else if (dy[k] == -1){
                        steps[nx][ny] = 'L';
                    }
                    q.push({nx,ny});


            q.push({nx, ny});
        }
    }
        if (!found){
            no;
            return;
        }
        buildPath(ex,ey);
        yes;
        cout << ans.size() << endl;
        reverse(all(ans));
        cout << ans << endl;
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
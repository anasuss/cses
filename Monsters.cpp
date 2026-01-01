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
    const int N = 1e3+10 ;
    ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}
    ll lcm(ll a , ll b) {return (a * b) / gcd(a , b);}
    ll inv(ll i) {if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;}  
    ll C(int n , int k){
        assert(n>=k) ; 
        //return fact[n]*inv(fact[k]*fact[n-k]%mod)%mod ; 
        return 0 ; 
    }
     
    int dx[] = {0,1,-1,0};
    int dy[] = {1,0,0,-1};
    
    int n,m ;
    
    char grid[N][N];

    queue<pii> qm,qa;

    int dist[N][N];

    bool visa[N][N],vism[N][N];

    bool found; 

    char path[N][N];

    bool isValidM(int x, int y){
        return x>=0 && y>=0 && x<n && y<m && !vism[x][y] && grid[x][y] != 'M';
    }
    
    bool isValidA(int x, int y, int level){
        return x>=0 && y>=0 && x<n && y<m && !visa[x][y] && level<dist[x][y] && grid[x][y] != 'A';
    }

    void bfsM(){
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                if (grid[i][j] != 'M')
                    dist[i][j] = N*N;
            }
        }
        int level = 1;
        while (!qm.empty())
        {
            int sz = qm.size();
            while(sz--){
                int x = qm.front().first;
                int y = qm.front().second;
                qm.pop();
                for (int k = 0 ; k<4 ; k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if (!isValidM(nx,ny)) continue;
                    vism[nx][ny] = true;
                    dist[nx][ny] = level;
                    qm.push({nx,ny});
                }
            }
            level++;
        }
        
    }

    string ans;

    int sx,sy,ex,ey;

    void buildPath(int x, int y) {
        while (x != sx || y != sy) {
            char c = path[x][y];
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

    void bfsA(){
        int level = 1;
        while (!qa.empty())
        {
            if (found){
                break;
            }
            int sz = qa.size();
            while(sz--){
                if (found){
                    break;
                }
                int x = qa.front().first;
                int y = qa.front().second;
                qa.pop();
                for (int k = 0 ; k<4 ; k++){
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if (!isValidA(nx,ny,level)) continue;
                    if (dx[k] == 1){
                        path[nx][ny] = 'D';
                    }else if (dx[k] == -1){
                        path[nx][ny] = 'U';
                    }else if (dy[k] == 1){
                        path[nx][ny] = 'R';
                    }else if (dy[k] == -1){
                        path[nx][ny] = 'L';
                    }
                    if (grid[nx][ny] == '#') yes;
                    if (nx == 0 || ny == 0 || nx == n-1 || ny == m-1){
                        found = true;
                        ex = nx, ey = ny;
                        break;
                    }
                    visa[nx][ny] = true;
                    qa.push({nx,ny});
                }
            }
            level++;
        }
        if (!found){
            no;
            return;
        }
        buildPath(ex,ey);
        if ((int)ans.size() == 0){
            no;
            return;
        }
        reverse(all(ans));
        yes;
        cout << ans.size() << endl;
        cout << ans << endl;
    }

    void solve(){
        cin >> n >> m; 
        for (int i = 0 ; i<n ; i++){
            for (int j = 0 ; j<m ; j++){
                cin >> grid[i][j];
                if (grid[i][j] == 'M'){
                    qm.push({i,j});
                }
                if (grid[i][j] == 'A'){
                    sx = i, sy = j;
                    qa.push({i,j});
                }
                visa[i][j] = vism[i][j] = grid[i][j] == '#';
            }
        }
        if (sx == 0 || sy == 0 || sx == n-1 || sy == m-1){
            yes;
            cout << 0 << endl;
            return;
        }
        bfsM();
        bfsA();
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
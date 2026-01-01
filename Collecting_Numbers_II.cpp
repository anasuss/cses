    #include<bits/stdc++.h>
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
    
    unordered_map<int,int> pos;

    int a[N];

    void solve(){
        cin >> n >> m ; 
        for (int i = 1 ; i<=n ; i++){
            cin >> a[i];
            pos[a[i]] = i;
        }
        int ans = 1;
        int lst = pos[1];
        for (int i = 2 ; i<=n ; i++){
            if (pos[i]<lst){
                ++ans;
            }
            lst = pos[i];
        }

        while(m--){
            int p1,p2; cin >> p1 >> p2;
            set<int> affected;
            for (int d = -1; d <= 1; d++) {
                int val1 = a[p1] + d;
                int val2 = a[p2] + d;
                if (val1 >= 1 && val1 <= n - 1) affected.insert(val1);
                if (val2 >= 1 && val2 <= n - 1) affected.insert(val2);
            }

            for (int x : affected) {
                if(x >= n) continue;
                if (pos[x] > pos[x + 1]) --ans;
            }          
            
            swap(a[p1],a[p2]);
            pos[a[p1]] = p1; 
            pos[a[p2]] = p2; 
                
            for (int x : affected) {
                if(x >= n) continue;
                if (pos[x] > pos[x + 1]) ++ans;
            }

            cout << ans << endl; 
        }
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        // cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }
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
     


    void solve(){
        cin >> n >> m ; 
        int closeTime = 1440 ;
        vector<int> allocatedBarbers(closeTime+10,0) ;
        for (int i = 0 ; i<n ; i++){
            string time; cin >> time;
            int x; cin >> x;
            int h = stoi(time.substr(0,2)) ;
            int mn = stoi(time.substr(3,2)) ;
            int startTime = h*60+mn;
            int finishTime = h*60+mn+x-1 ;
            if (finishTime>closeTime){
                continue ;
            }
            if (startTime - 1 >= 0){
                allocatedBarbers[startTime-1] += 1;
            }
            allocatedBarbers[finishTime] -= 1 ;
        }
        for (int i = closeTime; i>=0 ; i--){
            allocatedBarbers[i]+=allocatedBarbers[i+1] ;
            if (allocatedBarbers[i] * -1 > m){
                cout << "No\n" ;
                return ;
            }
        }   
        cout << "Yes\n" ;
        return ;
    }
     
     
     
    int main(){
        SaveTime
       // freopen("input.txt","r",stdin) ;
        int t = 1 ;
        cin >> t ;
        for (int i = 1 ; i<=t ; i++){
            solve() ;
        }
    }
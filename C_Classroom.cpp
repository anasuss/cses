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
     
    int n,k ;
     
    ll a[N] ;
    ll b[N] ;  
    map<ll,ll> mp ;
    map<ll,ll> negativeMp;
    void solve(){
        mp.clear() ;
        negativeMp.clear() ;
        cin >> n >> k ; 
        for (int i = 0 ; i<n ; i++){
            cin >> a[i] ;
            mp[a[i]] = i ; 
            negativeMp[-a[i]] = i ;
        }
        ll mid = k/2;
        ll longestDistance = 0 ;
        ll studentI = -1, studentJ = -1 ;
        for (int i = 0 ; i<n ; i++){
            ll clockWise = (a[i]+mid)%k ;
            if (clockWise == 0) clockWise = k ;
            ll antiClockWise = (a[i]+k-mid)%k ;
            if (antiClockWise == 0) antiClockWise = k ;
            auto it1 = mp.lower_bound(clockWise) ;
            auto it2 = mp.lower_bound(antiClockWise) ;
            auto it3 = negativeMp.lower_bound(-clockWise) ;
            auto it4 = negativeMp.lower_bound(-antiClockWise) ;
            if (it1 != mp.end()){
                ll distance = min((it1->first - a[i] + k)%k , (a[i] - it1->first + k)%k) ;
                if (distance > longestDistance){
                    longestDistance = distance ;
                    studentI = i ;
                    studentJ = it1->second ;
                }
            }
            if (it2 != mp.end()){
                ll distance = min((it2->first - a[i] + k)%k , (a[i] - it2->first + k)%k) ;
                if (distance > longestDistance){
                    longestDistance = distance ;
                    studentI = i ;
                    studentJ = it2->second ;
                }
            }
            if (it3 != negativeMp.end()){
                ll distance = min((-it3->first - a[i] + k)%k , (a[i] + it3->first + k)%k) ;
                if (distance > longestDistance){
                    longestDistance = distance ;
                    studentI = i ;
                    studentJ = it3->second ;
                }
            }
            if (it4 != negativeMp.end()){
                ll distance = min((-it4->first - a[i] + k)%k , (a[i] + it4->first + k)%k) ;
                if (distance > longestDistance){
                    longestDistance = distance ;
                    studentI = i ;
                    studentJ = it4->second ;
                }
            }
        }
        cout << studentI + 1 << " " << studentJ + 1 << endl ;
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
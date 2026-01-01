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
    
    typedef tree<
    pair<int,int>,              // (value, unique id)
    null_type,
    less<pair<int,int>>,        // lex order
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset1;
 
    typedef tree<
    pair<int,int>,              // (value, unique id)
    null_type,
    greater<pair<int,int>>,        // lex order
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_multiset2;
     
     
    int n ;
    
    vector<pair<pair<int,int>,int>> v1,v2;
    int ans1[N], ans2[N];
    ordered_multiset1 s2;
    ordered_multiset2 s1;
 
    void solve(){
        cin >> n ; 
        for (int i = 0 ; i<n ; i++){
            int x,y; cin >> x >> y;
            v1.push_back({{x,y},i});
            v2.push_back({{x,y},i});
        }
        
        sort(v1.begin(), v1.end(),
            [](const pair<pair<int,int>, int>& a, const pair<pair<int,int>, int>& b){
                if (a.first.first != b.first.first)
                    return a.first.first < b.first.first;
                return a.first.second >= b.first.second;
            });
        sort(v2.begin(), v2.end(),
            [](const pair<pair<int,int>, int>& a, const pair<pair<int,int>, int>& b){
                if (a.first.first != b.first.first)
                    return a.first.first > b.first.first;
                return a.first.second <= b.first.second;
            });
 
        for (int i = 0 ; i<n ; i++){
            s1.insert({v2[i].first.second,i});
            s2.insert({v1[i].first.second,i});
            ans1[v2[i].second] = s1.size() - s1.order_of_key({v2[i].first.second,i})-1;
            ans2[v1[i].second] = s2.size() - s2.order_of_key({v1[i].first.second,i*-1})-1;
        }
 
        for (int i = 0 ; i<n ; i++){
            cout << ans1[i] << ' ';
        }
        cout << endl;
        for (int i = 0 ; i<n ; i++){
            cout << ans2[i] << ' ';
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
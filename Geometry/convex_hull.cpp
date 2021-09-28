#include <bits/stdc++.h>
#define ll long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define PB push_back
#define MP make_pair
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define deb(x) std::cout << #x << " " << x << std::endl
#define PI 3.141592653589793238
 
using namespace std;

// struct for representing the 2-D points 
struct Point{
    ll x, y;
    Point() {}
    Point(ll a, ll b): x{a}, y{b} {}
};

// comparator function for sorting the points in polar counter-clockwise manner
bool comp(const Point &lft, const Point &rgt){
    return lft.x < rgt.x || (lft.x == rgt.x && lft.y < rgt.y);
}

bool cw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

bool ccw(Point a, Point b, Point c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}

// main algo
vector<Point> convexHull(vector<Point> points){
    int n=points.size();
    if(n < 3){
        return {};
    }

    sort(points.begin(), points.end(), comp);
    Point p1=points[0], p2=points.back();

    vector<Point> up, down, res;
    up.push_back(p1);
    down.push_back(p1);

    for(int i=1;i<n;i++){
        if (i == n - 1 || cw(p1, points[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], points[i]))
                up.pop_back();
            up.push_back(points[i]);
        }
        if (i == n - 1 || ccw(p1, points[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], points[i]))
                down.pop_back();
            down.push_back(points[i]);
        }
    }

    for (ll i = 0; i < (ll)up.size(); i++)
        res.push_back(up[i]);
    for (ll i = down.size() - 2; i > 0; i--)
        res.push_back(down[i]);

    return res;
}

int main(){
    fast;
    int n; cin>>n;
    vector<Point> points;
    for(int i=0;i<n;i++){
        ll a, b; cin>>a>>b;
        points.push_back({a,b}); 
    }

    vector<Point> con_hull = convexHull(points);
    cout<<con_hull.size()<<endl;
    for(auto e: con_hull){
        cout<<e.x<<" "<<e.y<<endl;
    }
    return 0;
}
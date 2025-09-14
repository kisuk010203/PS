#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using pt = pair<ld, ld>;

int N;
vector<pt> points;
vector<ld> lengths; // len[i] = dist(points[i], points[i + 1]);
vector<ld> accumLengths; // accL[i] = len[1]+...+len[i] = (1, 2) + ... + (i, i + 1)

void printPt(pt p) {
    cout << p.first << ", " << p.second << "| ";
}
pt getPoint(ld idx) {
    
    pt st = points[(int)idx];
    int enIdx = ceil(idx);
    pt en = points[(enIdx - 1) % N + 1];
    // pt en = points[enIdx];
    ld baby = idx - (int)idx;
    ld x = baby * en.first + (1 - baby) * st.first;
    ld y = baby * en.second + (1 - baby) * st.second;
    // cout << "getPoint " << idx << " = " << x << ", " << y << "\n";
    return {x, y};
}
ld dist(const pt &a, const pt &b) {
    return sqrt((b.first - a.first) * (b.first - a.first) 
        + (b.second - a.second) * (b.second - a.second));
}
ld det(const pt &a, const pt &b) {
    // printPt(a);
    // printPt(b);
    // cout << " det : " << a.first * b.second - a.second * b.first << endl;
    return a.first * b.second - a.second * b.first;
}
ld polyArea(vector<pt> &v) {
    ld res = 0.0L;
    for (int i = 0; i < v.size(); i++) {
        res += det(v[i], v[(i + 1) % v.size()]);
    }
    return abs(res / 2);
}
ld getLen(ld idx) {
    int giant = (int)idx;
    ld res = accumLengths[giant - 1];
    if (giant == lengths.size())
        return res;
    ld baby = idx - giant;
    res += baby * lengths[giant];
    return res;
}
ld binSearch(ld idx, ld targetLen) {
    ld top = N + 1, bot = idx;
    ld offset = getLen(idx);
    int E = 30;
    while(E-- && bot != top) {
        ld mid = (top + bot) / 2;
        ld midRes = getLen(mid) - offset;
        if (midRes > targetLen) 
            top = mid;
        else bot = mid;
    }
    return (top + bot) / 2;
}
ld getArea(ld st, ld en) {
    // cout << "st: " << st << " en: " << en << endl;
    if ((int)st == (int)en) return 0.0L;
    vector<int> v;
    for (int i = (int) st + 1; i <= (int)en; i++) {
        v.push_back(i);
    }
    // for (int item : v) cout << item << " "; cout << endl;
    assert(v.size() > 0);
    pt stPt = getPoint(st), enPt = getPoint(en);
    ld res = det(stPt, points[v[0]]);
    // cout << res << "??\n";
    for (int i = 0; i + 1 < v.size(); i++) {
        res += det(points[v[i]], points[v[i + 1]]);
        // cout << res << "?999!\n";
    }
    res += det(points[v[v.size() - 1]], enPt);
    // cout << "points[v[v.size() - 1]]: " ;printPt(points[v[v.size() - 1]]);
    // cout << "getPoint(en): " ;printPt(getPoint(en)) ;cout<< " where en = " << en << "\n";
    // cout << res << "??\n";
    res += det(enPt, stPt);
    // cout << res << "??\n";
    return abs(res) / 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    points.resize(N + 1);
    lengths.resize(N + 1);
    accumLengths.resize(N + 1);
    accumLengths[0] = 0;
    
    for (int i = 1; i <= N; i++) {
        ld x, y; cin >> x >> y;
        points[i] = {x, y};
    }
    ld targetArea = 0;
    for (int i = 1; i <= N; i++) {
        lengths[i] = dist(points[i], points[i % N + 1]);
        accumLengths[i] = accumLengths[i - 1] + lengths[i];
        targetArea += det(points[i], points[i % N + 1]);
    }
    targetArea = abs(targetArea) / 4;
    ld targetLen = getLen(N + 1) / 2;
    ld bot = 1.0L, top = binSearch(1, targetLen);
    ld botArea = getArea(1, top);
    ld topArea = targetArea * 2 - botArea;
    // cout << "top: " << top << endl;
    // cout << "botArea : " << botArea << " topArea : " << topArea << "\n";
    int E = 40;
    while(E--) {
        // cout << "\033[44;1mEPOCH : " << 10 - E << " bot : " << bot << " top: " << top << "\033[0m\n";
        ld mid = (bot + top) / 2;
        ld midEnd = binSearch(mid, targetLen);
        ld midArea = getArea(mid, midEnd);
        // cout << " midArea : " << midArea << "\n";
        bool inc = botArea < topArea;
        if (inc) { // bot < top
            if (midArea < targetArea) {
                bot = mid;
            } else {
                top = mid;
            }
        } else { // top < bot
            if (midArea > targetArea) {
                bot = mid;
            } else {
                top = mid;
            }
        }
    }
    cout << "YES\n";
    cout.precision(9);
    cout << (int) bot << " " << bot - (int)bot << "\n";
    ld other = binSearch(bot, targetLen);
    cout << (int) other << " " << other - (int)other << "\n";
    
    

    // for (auto len : lengths) cout << len << " "; cout << endl;
    // for (auto len : accumLengths) cout << len << " "; cout << endl;
    // cout << "2 " << getLen(2) << "\n";
    // cout << "2.3 " << getLen(2.3) << "\n";
    // cout << N + 1 << " " << getLen(N + 1) << endl;
    // cout << "Halfway : " << binSearch(1, getLen(N + 1) / 2) << endl;
    // cout << getLen(2.55279) << endl;
    // cout << getLen(2.5) << endl;
}

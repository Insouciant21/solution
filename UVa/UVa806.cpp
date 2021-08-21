#include <bits/stdc++.h>

using namespace std;

struct Node {
    int v;
    Node *nw, *ne;
    Node *sw, *se;
    explicit Node(int _v = 0, Node *l = nullptr, Node *r = nullptr, Node *s = nullptr, Node *u = nullptr)
        : v(_v), nw(l), ne(r), sw(s), se(u) {};
};

int n;

char mp[70][70];
vector<int> sequence;
vector<int> ans;

void init();
int quickPow(int, int);
void inputMap();
void inputSeq();
int graphMode(int, int, int);
void buildTreeFromGraph(int, int, int, Node *);
void dfs(string &, Node *);
void getSeqFromTree(Node *);
void buildTreeFromSeq();
void draw(int, int, int, int);

int main() {
    int kase = 0;
    while (cin >> n && n) {
        init();
        Node *g = new Node;
        cout << (kase ? "\n" : "");
        cout << "Image " << ++kase << endl;
        if (n > 0) {
            inputMap();
            buildTreeFromGraph(0, 0, n, g);
            getSeqFromTree(g);
        }
        if (n < 0) {
            n = abs(n);
            inputSeq();
            buildTreeFromSeq();
        }
    }
    return 0;
}

void init() {
    memset(mp, 0, sizeof mp);
    sequence.clear();
    ans.clear();
}

void inputMap() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> mp[i][j];
}

int quickPow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a;
        b >>= 1;
        a *= a;
    }
    return res;
}

int toDex(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) res += (s[i] - '0') * quickPow(5, i);
    return res;
}

void inputSeq() {
    int t;
    while (cin >> t && t != -1) sequence.push_back(t);
}

bool isBlack(int x, int y, int len) {
    for (int i = x; i < x + len; i++)
        for (int j = y; j < y + len; j++)
            if (mp[i][j] == '0') return false;
    return true;
}
bool isWhite(int x, int y, int len) {
    for (int i = x; i < x + len; i++)
        for (int j = y; j < y + len; j++)
            if (mp[i][j] == '1') return false;
    return true;
}

int graphMode(int x, int y, int len) {
    if (isBlack(x, y, len)) return 1;
    if (isWhite(x, y, len)) return 0;
    return -1;
}

void buildTreeFromGraph(int x, int y, int len, Node *last) {
    if (len < 1) return;
    last->v = graphMode(x, y, len);
    if (last->v != -1) return;
    last->nw = new Node, last->ne = new Node, last->sw = new Node, last->se = new Node;
    buildTreeFromGraph(x, y, len / 2, last->nw);
    buildTreeFromGraph(x, y + len / 2, len / 2, last->ne);
    buildTreeFromGraph(x + len / 2, y, len / 2, last->sw);
    buildTreeFromGraph(x + len / 2, y + len / 2, len / 2, last->se);
}

void dfs(string s, Node *f) {
    if (f->v == 1) {
        ans.push_back(toDex(std::move(s)));
        return;
    }
    if (f->v == -1) {
        dfs(s + '1', f->nw);
        dfs(s + '2', f->ne);
        dfs(s + '3', f->sw);
        dfs(s + '4', f->se);
    }
}

void getSeqFromTree(Node *f) {
    dfs("", f);
    sort(ans.begin(), ans.end());
    int cnt = 0;
    for (int i : ans) {
        cout << (cnt++ == 0 ? "" : " ") << i;
        if (cnt == 12) {
            cout << endl;
            cnt = 0;
        }
    }
    cout << (cnt == 0 ? "" : "\n") << "Total number of black nodes = " << ans.size() << endl;
}

void buildTreeFromSeq() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) mp[i][j] = '0';
    for (auto &i : sequence) draw(0, 0, n, i);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << (mp[i][j] == '1' ? '*' : '.');
        cout << endl;
    }
}

void draw(int x, int y, int len, int src) {
    if (src) {
        int way = src % 5;
        src /= 5;
        if (way == 1) draw(x, y, len / 2, src);
        if (way == 2) draw(x, y + len / 2, len / 2, src);
        if (way == 3) draw(x + len / 2, y, len / 2, src);
        if (way == 4) draw(x + len / 2, y + len / 2, len / 2, src);
    }
    else {
        for (int i = x; i < x + len; i++)
            for (int j = y; j < y + len; j++) mp[i][j] = '1';
        return;
    }
}

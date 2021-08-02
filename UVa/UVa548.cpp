#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    Node *left;
    Node *right;
    explicit Node(int a = 0, Node *c = nullptr, Node *d = nullptr) : id(a), left(c), right(d) {};
};

struct Tree {
    Node *root;
    explicit Tree() { root = new Node(); }
};

vector<int> In, Post;

void buildTree(int pos, int start, int end, Node *last_node, bool left) {
    if (start > end)
        return;
    int k = int(find(In.begin() + start, In.begin() + end, Post[pos]) - In.begin());
    Node *t = new Node;
    t->id = Post[pos];
    if (left)
        last_node->left = t;
    else
        last_node->right = t;
    int rightNum = end - k;
    buildTree(pos - rightNum - 1, start, k - 1, t, true);
    buildTree(pos - 1, k + 1, end, t, false);
}

int res, ans;

void dfs(Node *f, int sum) {
    if (sum > res)
        return;
    if (f->left == nullptr && f->right == nullptr && sum + f->id <= res) {
        if (sum + f->id < res)
            ans = f->id;
        if (sum + f->id == res)
            ans = min(f->id, ans);
        res = min(res, sum + f->id);
    }
    if (f->left != nullptr)
        dfs(f->left, sum + f->id);
    if (f->right != nullptr)
        dfs(f->right, sum + f->id);
}

int main() {
    while (true) {
        res = numeric_limits<int>::max();
        ans = 0;
        Tree g;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int v;
        while (ss >> v) In.push_back(v);
        if (In.empty())
            break;
        ss.clear();
        getline(cin, s);
        stringstream sss(s);
        while (sss >> v) Post.push_back(v);
        int k = int(find(In.begin(), In.end(), Post.back()) - In.begin());
        int n = int(Post.size()) - 1;
        g.root->id = Post.back();
        buildTree(k - 1, 0, k - 1, g.root, true);  // left
        buildTree(n - 1, k + 1, n, g.root, false); // right
        dfs(g.root, 0);
        cout << ans << endl;
        Post.clear();
        In.clear();
    }
    return 0;
}

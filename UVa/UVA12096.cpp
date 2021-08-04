#include <bits/stdc++.h>

std::vector<std::set<int>> set;
std::map<std::set<int>, int> ID;

int getID(std::set<int> &p) {
    if (ID[p])
        return ID[p];
    set.push_back(p);
    ID[p] = int(set.size() - 1);
    return ID[p];
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::stack<int> s;
        std::cin >> n;
        while (n--) {
            std::string command;
            std::cin >> command;
            if (command == "PUSH") {
                std::set<int> l;
                int i = getID(l);
                s.push(i);
            }
            if (command == "DUP") {
                std::set<int> l, r;
                l = set[s.top()];
                r = l;
                s.pop();
                s.push(getID(l));
                s.push(getID(r));
            }
            if (command == "UNION") {
                std::set<int> ans;
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                std::set_union(set[a].begin(), set[a].end(), set[b].begin(), set[b].end(), std::inserter(ans, ans.begin()));
                s.push(getID(ans));
            }
            if (command == "INTERSECT") {
                std::set<int> ans;
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                std::set_intersection(set[a].begin(), set[a].end(), set[b].begin(), set[b].end(), std::inserter(ans, ans.begin()));
                s.push(getID(ans));
            }
            if (command == "ADD") {
                std::set<int> ans;
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                ans = set[b];
                ans.insert(a);
                s.push(getID(ans));
            }
            std::cout << set[s.top()].size() << std::endl;
        }
        std::cout << "***" << std::endl;
    }
    return 0;
}

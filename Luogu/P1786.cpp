/*
 *	Problem: P1786
 *	Author: Insouciant21
 *	Time: 2020/8/23 14:28:24
 */

#include <bits/stdc++.h>

using namespace std;

int n;

enum work { BangZhu, FuBangZhu, HuFa, ZhangLao, TangZhu, JingYing, BangZhong };

struct Group {
    string name;
    work pos, newpos;
    long long contri;
    int level, id;
};

vector<Group> xingyue;

int cmp1(Group x, Group y) {
    if (x.contri == y.contri)
        return x.id < y.id;
    else
        return x.contri > y.contri;
}
int cmp2(Group x, Group y) {
    if (x.newpos == y.newpos) {
        if (x.level == y.level) return x.id < y.id;
        return x.level > y.level;
    }
    return x.newpos < y.newpos;
}

string _2str(work a) {
    switch (a) {
        case BangZhu:
            return "BangZhu";
            break;
        case FuBangZhu:
            return "FuBangZhu";
            break;
        case HuFa:
            return "HuFa";
            break;
        case ZhangLao:
            return "ZhangLao";
            break;
        case TangZhu:
            return "TangZhu";
            break;
        case JingYing:
            return "JingYing";
            break;
        case BangZhong:
            return "BangZhong";
            break;
        default:
            break;
    }
}

work _2work(string t) {
    work pos;
    switch (t[0]) {
        case 'B': {
            if (t == "BangZhu")
                pos = BangZhu;
            else
                pos = BangZhong;
            break;
        }
        case 'F':
            pos = FuBangZhu;
            break;
        case 'H':
            pos = HuFa;
            break;
        case 'T':
            pos = TangZhu;
            break;
        case 'J':
            pos = JingYing;
            break;
        default:
            pos = BangZhong;
            break;
    }
    return pos;
}

int main() {
    cin >> n;
    Group t;
    string m;
    xingyue.push_back(t);
    for (int i = 1; i <= n; i++) {
        cin >> t.name >> m >> t.contri >> t.level;
        t.pos = _2work(m);
        t.id = i;
        xingyue.push_back(t);
    }
    sort(xingyue.begin() + 4, xingyue.end(), cmp1);
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            xingyue[i].newpos = BangZhu;
        else if (i == 2 || i == 3)
            xingyue[i].newpos = FuBangZhu;
        else if (i == 4 || i == 5)
            xingyue[i].newpos = HuFa;
        else if (i >= 6 && i <= 9)
            xingyue[i].newpos = ZhangLao;
        else if (i >= 10 && i <= 16)
            xingyue[i].newpos = TangZhu;
        else if (i >= 17 && i <= 41)
            xingyue[i].newpos = JingYing;
        else
            xingyue[i].newpos = BangZhong;
    }
    sort(xingyue.begin() + 1, xingyue.end(), cmp2);
    for (int i = 1; i <= n; i++) {
        cout << xingyue[i].name << " " << _2str(xingyue[i].newpos) << " " << xingyue[i].level << endl;
    }
    return 0;
}
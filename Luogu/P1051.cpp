/*
  Problem: P1051
  Time: 2021/5/22 20:09
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> name;
    vector<int> avg_score, cla_score, pap, reward, index;
    vector<char> stu, wes;
    string tmp_n;
    int tmp_avg, tmp_cla, tmp_pap;
    char tmp_stu, tmp_wes;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp_n >> tmp_avg >> tmp_cla >> tmp_stu >> tmp_wes >> tmp_pap;
        name.push_back(tmp_n);
        avg_score.push_back(tmp_avg);
        cla_score.push_back(tmp_cla);
        pap.push_back(tmp_pap);
        stu.push_back(tmp_stu);
        wes.push_back(tmp_wes);
        reward.push_back(0);
        if (avg_score[i] > 80 && pap[i] >= 1)
            reward[i] += 8000;
        if (avg_score[i] > 85 && cla_score[i] > 80)
            reward[i] += 4000;
        if (avg_score[i] > 90)
            reward[i] += 2000;
        if (avg_score[i] > 85 && wes[i] == 'Y')
            reward[i] += 1000;
        if (cla_score[i] > 80 && stu[i] == 'Y')
            reward[i] += 850;
        index.push_back(reward[i]);
        total += reward[i];
    }
    sort(reward.begin(), reward.end());
    for (int i = 0; i < index.size(); i++) {
        if (index[i] == *(reward.end() - 1)) {
            cout << name[i] << endl;
            cout << index[i] << endl;
            cout << total << endl;
            break;
        }
    }
    return 0;
}

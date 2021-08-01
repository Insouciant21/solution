// WA 70

#include <bits/stdc++.h>

using namespace std;

bool ice[16][16][21];
bool vis[16][16][21];
int snow[16][16];

int n, m;
int H_M, H_R, H_C, H_X, H_Y;

int roof;

int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, -1, -1, -1, 0, 1, 1, 1};

int DR[] = {0, 0, 0, 0, 1, -1};
int DC[] = {-1, 1, 0, 0, 0, 0};
int DH[] = {0, 0, 1, -1, 0, 0};

int iceBlocks;

struct Position {
    int r, c, h;
    int needBlocks2Repair;
    bool wholeDoor;
};

void iceBarrage(int r, int c, int d, int s) {
    int k = 0;
    for (int i = 0; i <= s; i++) {
        if (r < 0 || r >= n || c < 0 || c >= n) break;
        if (ice[r][c][0]) break;
        snow[r][c]++;
        if (snow[r][c] == 5) snow[r][c] = 4, k--;
        r += dr[d];
        c += dc[d];
        k++;
    }
    cout << "CIRNO FREEZED " << k << " BLOCK(S)" << endl;
}

void makeIceBlock() {
    int madeBlocks = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (snow[i][j] == 4) {
                madeBlocks++;
                snow[i][j] = 0;
            }
        }
    }
    iceBlocks += madeBlocks;
    cout << "CIRNO MADE " << madeBlocks << " ICE BLOCK(S),NOW SHE HAS " << iceBlocks << " ICE BLOCK(S)" << endl;
}

bool hang(int r, int c, int h) {
    for (int i = 0; i < 6; i++) {
        int R = r + DR[i], C = c + DC[i], H = h + DH[i];
        if (R < 0 || R >= n || C < 0 || C >= n) continue;
        if (H < 0 || H >= H_M) continue;
        if (ice[R][C][H]) {
            memset(vis, 0, sizeof vis);
            queue<Position> q;
            q.push({R, C, H, 0, false});
            vis[R][C][H] = true;
            while (!q.empty()) {
                Position prs = q.front();
                q.pop();
                if (prs.h == 0) return false;
                for (int dx = 0; dx < 6; dx++) {
                    Position ftr = prs;
                    ftr.r += DR[dx], ftr.c += DC[dx], ftr.h += DH[dx];
                    if (ftr.r < 0 || ftr.r >= n || ftr.c < 0 || ftr.c >= n) continue;
                    if (ftr.h < 0 || ftr.h >= H_M) continue;
                    if (vis[ftr.r][ftr.c][ftr.h]) continue;
                    if (!ice[ftr.r][ftr.c][ftr.h]) continue;
                    vis[ftr.r][ftr.c][ftr.h] = true;
                    q.push(ftr);
                }
            }
        }
    }
    return true;
}

bool hangs(int r, int c, int h) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
        int R = r + DR[i], C = c + DC[i], H = h + DH[i];
        if (R < 0 || R >= n || C < 0 || C >= n) continue;
        if (H < 0 || H >= H_M) continue;
        cnt += ice[R][C][H];
    }
    if (cnt == 0 && h != 0)
        return true;
    else
        return false;
}

void putIceBlock(int r, int c, int h) {
    ice[r][c][h] = true;
    iceBlocks--;
    if (h == 0) snow[r][c] = 0;
}

void putIceBlockMain(int r, int c, int h) {
    if (iceBlocks == 0) {
        cout << "CIRNO HAS NO ICE_BLOCK" << endl;
        return;
    }
    if (hangs(r, c, h) || ice[r][c][h]) {
        cout << "BAKA CIRNO,CAN'T PUT HERE" << endl;
        return;
    }
    if (r < H_R || r > H_R + H_X - 1 || c < H_C || c > H_C + H_Y - 1) {
        cout << "CIRNO MISSED THE PLACE" << endl;
        return putIceBlock(r, c, h);
    }
    if (H_R + 1 <= r && r <= H_R + H_X - 2 && H_C + 1 <= c && c <= H_C + H_Y - 2) {
        cout << "CIRNO PUT AN ICE_BLOCK INSIDE THE HOUSE" << endl;
        return putIceBlock(r, c, h);
    }
    putIceBlock(r, c, h);
    cout << "CIRNO SUCCESSFULLY PUT AN ICE_BLOCK,NOW SHE HAS " << iceBlocks << " ICE_BLOCK(S)" << endl;
}

void removeIceBlock(int r, int c, int h) {
    if (!ice[r][c][h]) {
        cout << "BAKA CIRNO,THERE IS NO ICE_BLOCK" << endl;
        return;
    }
    int broken = 0;
    ice[r][c][h] = false;
    iceBlocks++;
    for (int i = 0; i < 6; i++) {
        int R = r + DR[i], C = c + DC[i], H = h + DH[i];
        if (R < 0 || R >= n || C < 0 || C >= n) continue;
        if (H < 0 || H >= H_M) continue;
        if (!ice[R][C][H]) continue;
        if (hang(R, C, H)) {
            memset(vis, 0, sizeof vis);
            queue<Position> qu;
            qu.push({R, C, H, 0, false});
            vis[R][C][H] = true;
            while (!qu.empty()) {
                Position prs = qu.front();
                qu.pop();
                for (int dx = 0; dx < 6; dx++) {
                    Position ftr = prs;
                    ftr.r += DR[dx], ftr.c += DC[dx], ftr.h += DH[dx];
                    if (ftr.r < 0 || ftr.r >= n || ftr.c < 0 || ftr.c >= n) continue;
                    if (ftr.h < 0 || ftr.h >= H_M) continue;
                    if (vis[ftr.r][ftr.c][ftr.h]) continue;
                    if (!ice[ftr.r][ftr.c][ftr.h]) continue;
                    vis[ftr.r][ftr.c][ftr.h] = true;
                    ice[ftr.r][ftr.c][ftr.h] = false;
                    broken++;
                    qu.push(ftr);
                }
            }
        }
    }
    if (broken)
        cout << "CIRNO REMOVED AN ICE_BLOCK,AND " << broken << " BLOCK(S) ARE BROKEN" << endl;
    else
        cout << "CIRNO REMOVED AN ICE_BLOCK" << endl;
}

inline bool onFrame(Position s) {
    return ((s.r == H_R || s.r == H_R + H_X - 1) || (s.c == H_C || s.c == H_C + H_Y - 1)) && s.h >= 0 && s.h <= roof;
}

void findRoof() {
    vector<bool> p;
    for (roof = 0; roof < H_M; roof++) {
        bool has = false;
        for (int r = H_R; r < H_R + H_X; r++) {
            for (int c = H_C; c < H_C + H_Y; c++) {
                if (r > H_R && r < H_R + H_X - 1 && c > H_C && c < H_C + H_Y - 1) continue;
                if (ice[r][c][roof]) {
                    has = true;
                    break;
                }
            }
            if (has) break;
        }
        p.push_back(has);
    }
    for (roof = int(p.size() - 1); roof >= 0; roof--) {
        if (p[roof]) {
            roof++;
            break;
        }
    }
}

bool removeExtraBlocks() {
    bool removed = false;
    int k1 = 0, k2 = 0;
    for (int r = H_R + 1; r < H_R + H_X - 1; r++) {
        for (int c = H_C + 1; c < H_C + H_Y - 1; c++) {
            for (int h = 0; h < roof; h++) {
                if (!ice[r][c][h]) continue;
                removed = true;
                k1++;
                iceBlocks++;
                ice[r][c][h] = false;
            }
        }
    }
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            for (int h = 0; h < H_M; h++) {
                if (r >= H_R && r < H_R + H_X && c >= H_C && c < H_C + H_Y && h <= roof) continue;
                if (!ice[r][c][h]) continue;
                removed = true;
                k2++;
                iceBlocks++;
                ice[r][c][h] = false;
            }
        }
    }
    cout << k1 << " ICE_BLOCK(S) INSIDE THE HOUSE NEED TO BE REMOVED" << endl;
    cout << k2 << " ICE_BLOCK(S) OUTSIDE THE HOUSE NEED TO BE REMOVED" << endl;
    return removed;
}

bool verifyIntact() {
    memset(vis, 0, sizeof vis);
    queue<Position> q;
    q.push({H_R, H_C, roof});
    vis[H_R][H_C][roof] = true;
    while (!q.empty()) {
        Position prs = q.front();
        q.pop();
        if (prs.h == 0) return true;
        for (int i = 0; i < 6; i++) {
            Position ftr = prs;
            ftr.r += DR[i], ftr.c += DC[i], ftr.h += DH[i];
            if (ftr.r < H_R || ftr.r >= H_R + H_X || ftr.c < H_C || ftr.c >= H_C + H_Y) continue;
            if (ftr.h < 0 || ftr.h > roof) continue;
            if (vis[ftr.r][ftr.c][ftr.h]) continue;
            if (!ice[ftr.r][ftr.c][ftr.h]) continue;
            vis[ftr.r][ftr.c][ftr.h] = true;
            q.push(ftr);
        }
    }
    return false;
}

void need2Repair(Position &s) {
    memset(vis, 0, sizeof vis);
    queue<Position> q;
    q.push({H_R + 1, H_C + 1, 0});
    vis[H_R + 1][H_C + 1][0] = true;
    while (!q.empty()) {
        Position prs = q.front();
        q.pop();
        if (onFrame(prs)) s.needBlocks2Repair += !(prs.r == s.r && prs.c == s.c);
        for (int i = 0; i < 6; i++) {
            Position ftr = prs;
            ftr.r += DR[i], ftr.c += DC[i], ftr.h += DH[i];
            if (ftr.r < H_R || ftr.r >= H_R + H_X || ftr.c < H_C || ftr.c >= H_C + H_Y) continue;
            if (ftr.h < 0 || ftr.h > 1) continue;
            if (ice[ftr.r][ftr.c][ftr.h]) continue;
            if (vis[ftr.r][ftr.c][ftr.h]) continue;
            vis[ftr.r][ftr.c][ftr.h] = true;
            q.push(ftr);
        }
    }
}

int verifyCorner() {
    int needToFix = 0;
    for (int r = H_R; r < H_R + H_X; r += H_X - 1)
        for (int c = H_C; c < H_C + H_Y; c += H_Y - 1)
            for (int h = 0; h < roof; h++)
                if (!ice[r][c][h]) needToFix++;
    return needToFix;
}

void makeRoof() {
    findRoof();
    int neededIceBlocks = H_X * H_Y;
    for (int r = H_R; r < H_R + H_X; r++) {
        for (int c = H_C; c < H_C + H_Y; c++) {
            neededIceBlocks -= ice[r][c][roof];
            ice[r][c][roof] = true;
        }
    }
    if (iceBlocks < neededIceBlocks) {
        cout << "SORRY CIRNO,NOT ENOUGH ICE_BLOCK(S) TO MAKE ROOF" << endl;
        return;
    }
    iceBlocks -= neededIceBlocks;
    if (roof < 2 || (H_X - 2) * (H_Y - 2) * roof < 2) {
        cout << "SORRY CIRNO,HOUSE IS TOO SMALL" << endl;
        return;
    }
    bool removed = removeExtraBlocks();
    if (!verifyIntact()) {
        cout << "SORRY CIRNO,HOUSE IS BROKEN WHEN REMOVING BLOCKS" << endl;
        return;
    }
    int g = verifyCorner();
    bool wallOK = true;
    for (int r = H_R; r < H_R + H_X; r++) {
        for (int c = H_C; c < H_C + H_Y; c++) {
            for (int h = 2; h <= roof; h++) {
                if (!onFrame({r, c, h})) continue;
                if (ice[r][c][h]) continue;
                wallOK = false;
                iceBlocks--;
                ice[r][c][h] = true;
                if (iceBlocks == -1) {
                    cout << "SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL" << endl;
                    return;
                }
            }
        }
    }
    Position best {0, 0, 0, 2147483647, false};
    for (int r = H_R; r < H_R + H_X; r++) {
        for (int c = H_C; c < H_C + H_Y; c++) {
            for (int h = 0; h <= 1; h++) {
                if (!onFrame({r, c, h})) continue;
                if (ice[r][c][h]) continue;
                Position k {};
                k.r = r, k.c = c, k.h = h;
                if (!ice[r][c][!h]) k.wholeDoor = true;
                need2Repair(k);
                if (k.needBlocks2Repair < best.needBlocks2Repair) best = k;
                if (k.needBlocks2Repair == best.needBlocks2Repair) {
                    if (H_X % 2 == 0 && (k.r == H_R + H_X / 2 || k.r == H_R + H_X / 2 - 1)) best = k;
                    if (H_Y % 2 == 0 && (k.c == H_C + H_Y / 2 || k.c == H_C + H_Y / 2 - 1)) best = k;
                    if (H_X % 2 == 1 && k.r == H_R + H_X / 2) best = k;
                    if (H_Y % 2 == 1 && k.c == H_C + H_Y / 2) best = k;
                }
            }
        }
    }
    iceBlocks -= best.needBlocks2Repair;
    if (best.needBlocks2Repair) wallOK = false;
    if (iceBlocks < 0) {
        cout << "SORRY CIRNO,NOT ENOUGH ICE_BLOCKS TO FIX THE WALL" << endl;
        return;
    }
    cout << "GOOD JOB CIRNO,SUCCESSFULLY BUILT THE HOUSE" << endl;
    if (best.wholeDoor)
        cout << "DOOR IS OK" << endl;
    else {
        cout << "HOUSE HAS NO DOOR" << endl;
        iceBlocks++;
    }
    if (!wallOK)
        cout << "WALL NEED TO BE FIXED" << endl;
    else
        cout << "WALL IS OK" << endl;
    if (!g)
        cout << "CORNER IS OK" << endl;
    else {
        cout << "CORNER NEED TO BE FIXED" << endl;
        iceBlocks = max(0, iceBlocks);
    }
    cout << "CIRNO FINALLY HAS " << iceBlocks << " ICE_BLOCK(S)" << endl;
    if (!removed && wallOK && best.wholeDoor && !g) {
        bool perfect = false;
        if (H_X % 2 == 0 && (best.r == H_R + H_X / 2 || best.r == H_R + H_X / 2 - 1)) perfect = true;
        if (H_Y % 2 == 0 && (best.c == H_C + H_Y / 2 || best.c == H_C + H_Y / 2 - 1)) perfect = true;
        if (H_X % 2 == 1 && best.r == H_R + H_X / 2) perfect = true;
        if (H_Y % 2 == 1 && best.c == H_C + H_Y / 2) perfect = true;
        if (perfect) cout << "CIRNO IS PERFECT!" << endl;
    }
}

int main() {
    memset(snow, 0, sizeof snow);
    cin >> n;
    cin >> H_M;
    cin >> H_R >> H_C >> H_X >> H_Y;
    cin >> m;
    while (m--) {
        string operation;
        cin >> operation;
        if (operation[0] == 'I') {
            int R, C, D, S;
            cin >> R >> C >> D >> S;
            iceBarrage(R, C, D, S);
        }
        if (operation[0] == 'M' && operation.size() == 14) makeIceBlock();
        if (operation[0] == 'P') {
            int R, C, H;
            cin >> R >> C >> H;
            putIceBlockMain(R, C, H);
        }
        if (operation[0] == 'R') {
            int R, C, H;
            cin >> R >> C >> H;
            removeIceBlock(R, C, H);
        }
        if (operation[0] == 'M' && operation.size() == 9) makeRoof();
    }
    return 0;
}
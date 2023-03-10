#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// 定义状态节点
struct node {
    string p;  // 存储当前状态字符串
    int w;     // 存储当前状态的步数
    string path;
    vector<int> previous;
    friend bool operator<(const node& a, const node& b) {
        return a.w + a.p.size() > b.w + b.p.size();
    }
};

unordered_map<string, bool> vis;
int steps = 1;
int dirx[4] = { 1, -1, 0, 0 }; // 4个方向
int diry[4] = { 0, 0, 1, -1 };
string goal = "123456789abcdef0"; // 还原的目标

// 判断当前状态是否为目标状态
bool check(string s) {
    return s == goal;
}

// 交换两个字符的位置
void swap(string& s, int a, int b) {
    char t = s[a];
    s[a] = s[b];
    s[b] = t;
}

int same_digits(string a) { // 有多少个数字和goal相同
    int cnt = 0;
    for (int i = 0; i < 16; i++) {
        if (a[i] == goal[i])
            cnt++;
    }
    return cnt;
}

// 枚举当前状态下所有可行的移动方式
vector<node> getNext(node x) {
    vector<node> res;
    int pos = x.p.find('0');
    int x0 = pos / 4, y0 = pos % 4;
    for (int i = 0; i < 4; ++i) {
        int nx0 = x0 + dirx[i], ny0 = y0 + diry[i];
        if (nx0 >= 0 && nx0 < 4 && ny0 >= 0 && ny0 < 4) {
            node t = x;
            swap(t.p, pos, nx0 * 4 + ny0);
            t.w++;
            t.previous.push_back(same_digits(x.p));
            if (!vis.count(t.p)) {
                string output;
                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 4; j++) {
                        output += x.p[i * 4 + j];
                        output += ' ';
                    }
                    output += '\n';
                }
                t.path = x.path + '\n' + output;
                res.push_back(t);
                vis[t.p] = 1;
            }
        }
    }
    return res;
}

int nodes, score;

int bfs(node start) {
    queue<node> q;
    nodes = 0;
    q.push(start);
    vis[start.p] = 1;
    int start_same = same_digits(start.p);
    clock_t start_time = clock();
    score = 0;
    while (!q.empty()) {
        node x = q.front();
        nodes++;
        score = max(score, same_digits(x.p));
        if (steps < x.w) {
            steps = x.w;
            cout << "info depth " << x.w - 1 << " nodes " << nodes << " score " << score << " time " << clock() - start_time << endl;
            if (x.w % 2 == 0) // 定期清除一下map
                vis.clear();
        }
        q.pop();
        if (check(x.p)) {
            cout << "steps: " << x.w << endl;
            cout << x.path << endl << x.p << endl;
            return 0;
        }
        vector<node> nexts = getNext(x);

        for (int i = 0; i < nexts.size(); ++i) {
            int maxn = 0;
            if (x.w > 4)
                maxn = max(same_digits(nexts[i].p), max(same_digits(x.p), max(x.previous.front(), x.previous[x.previous.size() - 2])));
            if (nexts[i].w > 7 && maxn <= 1) // 剪枝
                continue;
            int scoreMax = score - 3;
            if (score > 8)
                scoreMax = score - 4;
            if (score > 11)
                scoreMax = score - 5;
            if (nexts[i].w > 10 && maxn <= scoreMax)
                continue;
            q.push(nexts[i]);
        }
    }
    return -1;
}

int main() {
    node start;
    start.p = "                ";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int pos;
            cin >> pos;
            start.p[i * 4 + j] = (pos > 9 ? pos - 10 + 'a' : pos + '0');
        }
    }
    start.w = 0;
    vis[start.p] = 1;
    bfs(start);
    return 0;
}

#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>
#include <cstring>
#define MAX_N 100000
using namespace std;
int t, n, m, disc[MAX_N + 1], scc[MAX_N + 1], c, s, x, y, in[MAX_N + 1], r;
vector<vector<int>> vt;
stack<int> st;
int dfs(int here) {
    disc[here] = ++c;
    st.push(here);
    int ret = disc[here];
    for (int there : vt[here]) {
        if (!disc[there])
            ret = min(ret, dfs(there));
        else if (!scc[there])
            ret = min(ret, disc[there]);
    }
    if (ret == disc[here]) {
        s++;
        while (1) {
            int v = st.top();
            st.pop();
            scc[v] = s;
            if (v == here)break;
        }
    }
    return ret;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        r = c = s = 0;
        memset(disc, 0, sizeof(disc));
        memset(scc, 0, sizeof(scc));
        memset(in, 0, sizeof(in));
        scanf("%d%d", &n, &m);
        vt.clear();
        vt.resize(n + 1);
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &x, &y);
            vt[x].push_back(y);
        }
        for (int i = 1; i <= n; i++) {
            if (!disc[i])
                dfs(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int next : vt[i]) {
                if (scc[i] == scc[next])
                    continue;
                in[scc[next]]++;
            }
        }
        for (int i = 1; i <= s; i++) {
            if (!in[i])
                r++;
        }
        printf("%d\n", r);
    }
    return 0;
}

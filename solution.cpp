//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

vector<vector<int>> v(110);
int bfs(int n) {
	vector<int> len(v.size(), INT_MAX);
	queue<pair<int, int>> q;
	q.push( { n, 0 });
	len[n] = 0;
	int res = 0;
	while (!q.empty()) {
		int node = q.front().first;
		int dep = q.front().second;
		q.pop();
		for (int i = 0; i < v[node].size(); i++) {
			if (len[v[node][i]] > dep + 1) {
				q.push( { v[node][i], dep + 1 });
				len[v[node][i]] = dep + 1;
				res += (dep + 1);
			}
		}
	}
	return res;
}

//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
	// 5221 - Page Hopping && 821 - Page Hopping
	int from, to, idx = 1, t;
	bool end = false;
	vector<int> temp;
	int arr[110] = { 0 };
	while (cin >> from >> to) {
		if (from == to && from == 0) {
			if (end)
				return 0;
			float sum = 0;
			for (int i = 0; i < temp.size(); i++)
				sum += bfs(temp[i]);
			t = temp.size();
			sum /= (t * (t - 1));
			printf("Case %d: average length between pages = %.3f clicks\n",
					idx++, sum);
			end = true;
			for (int i = 0; i < v.size(); i++)
				v[i].clear();
			temp.clear();
			memset(arr, 0, sizeof(arr));
		} else {
			end = false;
			v[from].push_back(to);
			if (arr[from] == 0)
				temp.push_back(from);
			arr[from]++;
			if (arr[to] == 0)
				temp.push_back(to);
			arr[to]++;
		}
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}

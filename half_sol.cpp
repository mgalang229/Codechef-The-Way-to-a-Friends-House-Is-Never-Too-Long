#include <bits/stdc++.h>

using namespace std;

double GetDistance(double x1, double y1, double x2, double y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<pair<double, double>> v;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			v.emplace_back(make_pair(x, y));
		}
		// sort the pairs based on the rules in the problem statement
		sort(v.begin(), v.end(), [](const pair<double, double> a, const pair<double, double> b) -> bool {
			if (a.first == b.first) {
				return a.second > b.second;
			} else {
				return a.first < b.first;
			}
		});
		// calculate the total distance from start to end point
		double distance = 0;
		for (int i = 0; i < n - 1; i++) {
			distance += GetDistance(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
		}
		cout << fixed << setprecision(2) << distance << '\n';
	}
	return 0;
}

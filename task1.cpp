#include "stdafx.h"
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<bool, double> PointIsOver(const vector<pair<double, double>>& polygon_points_, const pair<double, double> point_) {
	double k = (polygon_points_[1].second - polygon_points_[0].second) / (polygon_points_[1].first - polygon_points_[0].first);
	double b = polygon_points_[1].second - k * polygon_points_[1].first; 
	if (point_.second - k * point_.first - b > 0)
		return make_tuple(true, k);
	else
		return make_tuple(false, k);
}
bool CrossCheck(const vector<pair<double, double>>& polygon_points_, const pair<double, double>& point_) {
	auto parametr = PointIsOver(polygon_points_, point_);
	double k = get<1>(parametr);
	bool over_position = get<0>(parametr);

	if (point_.second > polygon_points_[0].second && point_.second < polygon_points_[1].second) {
		if (point_.second == polygon_points_[0].second || point_.second == polygon_points_[1].second)
			return true; // cross if y_p = y1, y2
		if ((k > 0 && !over_position) || (k < 0 && over_position))
			return true; //cross
	}
	return false; //not cross
}

int main()
{
	int n = 0;
	int m = 0;
	vector<pair<double, double>> polygon_points;
	vector<pair<double, double>> verification_points;
	pair<double, double> point;

	cin >> n >> m;
	if (!(n >= 2) || m <= 0)
		cout << "input error";

	for (int i = 0; i < 2 * n; i++) {
		cin >> point.first >> point.second;
		polygon_points.push_back(point);
	}
	for (int i = 0; i < m; i++) {
		cin >> point.first >> point.second;
		verification_points.push_back(point);
	}
	int CrossCounter;
	int PointsInside = 0;
	vector<pair<double, double>> temp;
	for (const auto& p : verification_points) {
		CrossCounter = 0;
		for (int i = 0; i < polygon_points.size() - 1; i = i + 2) {
			temp.push_back(polygon_points[0 + i]);
			temp.push_back(polygon_points[1 + i]);
			if (CrossCheck(temp, p))
				CrossCounter++;
			temp.clear();
		}
		if (CrossCounter % 2 != 0)
			cout << CrossCounter << endl;
	}
    return 0;
}

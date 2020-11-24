#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <iomanip>
#define pi 3.141592
using namespace std;

struct Point {
	Point() {
		x = 0;
		y = 0;
	}
	Point(const int& x_, const int& y_) {
		x = x_;
		y = y_;
	}
	double x;
	double y;
};
ostream& operator<< (ostream& output, const Point& p) {
	output << setw(4) << p.x << ' ' << setw(4) << p.y << endl;
	return output;
}
double CalculateRadius(const Point& p) {
	return sqrt(p.x * p.x + p.y * p.y);
}
double CalculatePhi(const Point& p) {
	if (p.x > 0 && p.y > 0)
		return atan(abs(p.y) / abs(p.x)) / pi * 180;
	if (p.x < 0 && p.y > 0)
		return 180 - atan(abs(p.y) / abs(p.x)) / pi * 180;
	if (p.x < 0 && p.y < 0)
		return 180 + atan(abs(p.y) / abs(p.x)) / pi * 180;
	if (p.x > 0 && p.y < 0)
		return 360 - atan(abs(p.y) / abs(p.x)) / pi * 180;
}
int main()
{
	int n = 0;
	double R = 80;
	vector<Point> points;
	vector<Point> selected_points;
	Point p;

	srand((unsigned)time(NULL));
	cin >> n;
	for (int i = 0; i < n; i++) {
		p.x = rand() % 200 - 100;
		p.y = rand() % 200 - 100;
		points.push_back(p);
	}

	for (const auto& item : points) {
		double r = CalculateRadius(item);
		if (r > R && (r - R) < 10)
			selected_points.push_back(item);
	}

	sort(selected_points.begin(), selected_points.end(), 
		[](const Point& lhs, const Point& rhs) { return CalculatePhi(lhs) < CalculatePhi(rhs);});
	for (const auto& item : selected_points)
		cout << item << endl;
    return 0;
}

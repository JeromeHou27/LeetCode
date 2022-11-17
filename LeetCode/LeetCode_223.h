#pragma once

#include <iostream>

using namespace std;

class LeetCode_223
{
public:
	LeetCode_223() {
		int ax1 = -2;
		int ay1 = -2;
		int ax2 = 2;
		int ay2 = 2;
		int bx1 = 1;
		int by1 = 1;
		int bx2 = 3;
		int by2 = 3;

		printf("%d\n", computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2));
	}

	int calculateArea(int x1, int x2, int y1, int y2) {
		int area = (x2 - x1) * (y2 - y1);

		return area;
	}

	int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
		int dx1 = ax1 - bx1;
		int dx2 = ax2 - bx2;
		int dy1 = ay1 - by1;
		int dy2 = ay2 - by2;

		if (ax1 >= bx2 || ax2 <= bx1 || ay1 >= by2 || ay2 <= by1) {
			return calculateArea(ax1, ax2, ay1, ay2)
				+ calculateArea(bx1, bx2, by1, by2);
		}

		if (dx1 <= 0 && dx2 >= 0) {
			if (dy1 <= 0 && dy2 >= 0)  // 1
				return calculateArea(ax1, ax2, ay1, ay2);
			else if (dy1 >= 0 && dy2 <= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(bx1, bx2, ay1, ay2);
			}
			else if (dy1 >= 0 && dy2 >= 0)
			{ // 4
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(bx1, bx2, ay1, by2);
			}
			else if (dy1 <= 0 && dy2 <= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(bx1, bx2, by1, ay2);
			}
		}
		else if (dx1 >= 0 && dx2 <= 0) {
			if (dy1 >= 0 && dy2 <= 0)  // 2
				return calculateArea(bx1, bx2, by1, by2);
			else if (dy1 <= 0 && dy2 >= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(ax1, ax2, by1, by2);
			}
			else if (dy1 >= 0 && dy2 >= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(ax1, ax2, ay1, by2);
			}
			else if (dy1 <= 0 && dy2 <= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(ax1, ax2, by1, ay2);
			}
		}
		else if (dy1 <= 0 && dy2 >= 0)
		{
			if (dx1 >= 0 && dx2 >= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(ax1, bx2, by1, by2);
			}
			else if (dx1 <= 0 && dx2 <= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(bx1, ax2, by1, by2);
			}
		}
		else if (dy1 >= 0 && dy2 <= 0)
		{
			if (dx1 >= 0 && dx2 >= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(ax1, bx2, ay1, ay2);
			}
			else if (dx1 <= 0 && dx2 <= 0)
			{
				return calculateArea(ax1, ax2, ay1, ay2)
					+ calculateArea(bx1, bx2, by1, by2)
					- calculateArea(bx1, ax2, ay1, ay2);
			}
		}

		if (dx1 > 0 && dy1 > 0) {
			return calculateArea(ax1, ax2, ay1, ay2)
				+ calculateArea(bx1, bx2, by1, by2)
				- calculateArea(ax1, bx2, ay1, by2);
		}
		else if (dx1 > 0 && dy1 < 0) {
			return calculateArea(ax1, ax2, ay1, ay2)
				+ calculateArea(bx1, bx2, by1, by2)
				- calculateArea(ax1, bx2, by1, ay2);
		}
		else if (dx1 < 0 && dy1 > 0) {
			return calculateArea(ax1, ax2, ay1, ay2)
				+ calculateArea(bx1, bx2, by1, by2)
				- calculateArea(bx1, ax2, ay1, by2);
		}
		else if (dx1 < 0 && dy1 < 0) {
			return calculateArea(ax1, ax2, ay1, ay2)
				+ calculateArea(bx1, bx2, by1, by2)
				- calculateArea(bx1, ax2, by1, ay2);
		}

		return 0;
	}
};

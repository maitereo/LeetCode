#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string overlapped(const std::vector<int> &vx1, const std::vector<int> &vx2,
	const std::vector<int> &vy1, const std::vector<int> &vy2) {
	// find boundaries of rectangles
	int left1 = *std::min_element(vx1.begin(), vx1.end());
	int right1 = *std::max_element(vx1.begin(), vx1.end());
	int top1 = *std::max_element(vy1.begin(), vy1.end());
	int down1 = *std::min_element(vy1.begin(), vy1.end());
	int left2 = *std::min_element(vx2.begin(), vx2.end());
	int right2 = *std::max_element(vx2.begin(), vx2.end());
	int top2 = *std::max_element(vy2.begin(), vy2.end());
	int down2 = *std::min_element(vy2.begin(), vy2.end());

	// false if left1 >= right2 or right1 <= left2 or top1 <= down2 or down1 >= top2
	if (left1 >= right2 ||
		right1 <= left2 ||
		top1 <= down2 ||
		down1 >= top2) {
		return "NO";
	}

	return "YES";
}

int main(int argc, char *argv[]) {
	std::vector<int> vx1, vx2, vy1, vy2;

	for (int i = 0; i < 4; ++i) {
		int x, y;
		std::cin >> x >> y;
		vx1.push_back(x);
		vy1.push_back(y);
	}
	for (int i = 0; i < 4; ++i) {
		int x, y;
		std::cin >> x >> y;
		vx2.push_back(x);
		vy2.push_back(y);
	}

	std::cout << overlapped(vx1, vx2, vy1, vy2);

	return 0;
}

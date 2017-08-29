/*leetcode: largest-rectangle-in-histogram*/

/*遍历数组，每找到一个局部峰值，然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值*/
int largestRectangleArea(vector<int> &height) {
	int res = 0;
	for (int i = 0; i < height.size(); ++i) {
		if (i + 1 < height.size() && height[i] <= height[i + 1]) {
			continue;
		}
		int minH = height[i];
		for (int j = i; j >= 0; --j) {
			minH = min(minH, height[j]);
			int area = minH * (i - j + 1);
			res = max(res, area);
		}
	}
	return res;
}

/*
维护一个栈，用来保存递增序列，相当于上面那种方法的找局部峰值，
当当前值小于栈顶值时，取出栈顶元素，然后计算当前矩形面积，
然后再对比当前值和新的栈顶值大小，
若还是栈顶值大，则再取出栈顶，算此时共同矩形区域面积，
照此类推，可得最大矩形
*/
int largestRectangleArea(vector<int>& heights) {
	int res = 0;
	stack<int> s;
	heights.push_back(0);
	for (int i = 0; i < heights.size(); ++i) {
		while (!s.empty() && heights[s.top()] >= heights[i]) {
			int cur = s.top(); s.pop();
			res = max(res, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
		}
		s.push(i);
	}
	return res;
}
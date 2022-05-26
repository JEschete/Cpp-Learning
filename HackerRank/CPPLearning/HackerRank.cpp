#include "HackerRank.h"
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
	int a = 0;
	int b = 0;
	for (int i = 0; i < arr.size(); i++) {

		a = a + arr[i][i];
		b = b + arr[i][arr.size() - (i + 1)];
	}

	cout << a << "+" << b << "\n";

	return abs(a - b);
};
void plusMinus(vector<int> arr) {
	float pos = 0;
	float neg = 0;
	float zero = 0;

	for (int i : arr) {
		if (i > 0) {
			pos++;
		}
		else if (i < 0) {
			neg++;
		}
		else {
			zero++;
		}
	}

	pos = pos / arr.size();
	neg = neg / arr.size();
	zero = zero / arr.size();

	cout << setprecision(6) << fixed << pos << " \n";
	cout << setprecision(6) << fixed << neg << " \n";
	cout << setprecision(6) << fixed << zero << " \n";
};
void staircase(int n) {
	int spaces = n - 1;
	int staircase = n - (n - 1);
	
	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}
		
		spaces = spaces - 1;
		
		for (int j = 0; j < staircase; j++) {
			cout << "#";
		}
		
		staircase = staircase + 1;
		
		cout << "\n";
	}

};
void miniMaxSum(vector<int> arr) {

	vector<int> minArr(arr.begin(), arr.end());
	vector<int> maxArr(arr.begin(), arr.end());

	int maxPos = *max_element(minArr.begin(), minArr.end());
	int minPos = *max_element(maxArr.begin(), maxArr.end());

	minArr.erase(find(minArr.begin(), minArr.end(), maxPos));
	maxArr.erase(find(maxArr.begin(), maxArr.end(), minPos));

	unsigned long long int minSum = accumulate(minArr.begin(), minArr.end(), (unsigned long long int) 0);
	unsigned long long int maxSum = accumulate(maxArr.begin(), maxArr.end(), (unsigned long long int) 0);


	cout << minSum << " " << maxSum << "\n";


};
int birthdayCakeCandles(vector<int> candles) {
	int tallCandleCount = 0;
	int maxCandle = *max_element(candles.begin(), candles.end());
	for (int x : candles) {

		if (x == maxCandle) {
			tallCandleCount += 1;
		}
	}
	
	return tallCandleCount;
}
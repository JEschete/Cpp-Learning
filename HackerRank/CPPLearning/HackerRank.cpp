#include "HackerRank.h"
#include <iomanip>
#include <algorithm>
#include <numeric>

using namespace std;


// Given a square matrix, calculate the absolute difference between the sums of its diagonals.
// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true
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

// Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. 
// Print the decimal value of each fraction on a new line with  places after the decimal.
// https://www.hackerrank.com/challenges/plus-minus/problem?isFullScreen=true
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

// Write a program that prints a staircase of size n. 
// https://www.hackerrank.com/challenges/staircase/problem?isFullScreen=true
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

// Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. 
// Then print the respective minimum and maximum values as a single line of two space-separated long integers.  
// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true
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

// Given an array of "candle heights" find the maximum height and track how many times it occurs in the array. 
// https://www.hackerrank.com/challenges/birthday-cake-candles/problem?isFullScreen=true
int birthdayCakeCandles(vector<int> candles) {
	int tallCandleCount = 0;
	int maxCandle = *max_element(candles.begin(), candles.end());
	for (int x : candles) {

		if (x == maxCandle) {
			tallCandleCount += 1;
		}
	}
	
	return tallCandleCount;
};

// Round the grades given the provided criteria. 
// https://www.hackerrank.com/challenges/grading/problem?isFullScreen=true
vector<int> gradingStudents(vector<int> grades) {
	vector<int> newGrades; 
	for (int x : grades) {
		if (x < 38) {
			newGrades.push_back(x);
		}
		else {
			switch (x % 5) {
			case 3:
				newGrades.push_back(x + 2);
				break;
			case 4:
				newGrades.push_back(x + 1);
				break;
			default:
				newGrades.push_back(x);
				break;
			}
		}
	}
	return newGrades;
};

// Track how many of each type of object will land in the area prescribed. 
// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true
void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
	int appleHit = 0;
	int orangeHit = 0;

	for (int apple : apples) {
		int appleCheck = a + apple;
		if ((s <= appleCheck)&&(appleCheck <= t)) {
			appleHit += 1;
		}
	}
	for (int orange : oranges) {
		int orangeCheck = b + orange;
		if ((s <= orangeCheck) && (orangeCheck <= t)) {
			orangeHit += 1;
		}
	}

	cout << appleHit << "\n";
	cout << orangeHit << "\n";

};

// Write an algorithm that determines if two objects, given each a starting position and velocity, will ever collide. 
// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true
string kangaroo(int x1, int v1, int x2, int v2) {
	/* This problem was more of a math logic problem, you have to first see the kangaroos as points on a line.
	   use the equations y1 =m1x + b1 and y2 = m2x+b2 and set y1 = y2, solve for x, the result must be a whole number
	   in order for the problem to be solved. Y ou must also check for negative numbers as the cross can't happen in the past
	   and you must also check for divide by zero situations aka parallel lines.*/
	float ratio = ((x1 - x2) % (v2 - v1));

	if ((v2 - v1) == 0) {
		return "NO";
	}
	else if (((x1 - x2) / (v2 - v1)) < 0) {
		return "NO";
	}
	else if (ratio == 0) {
		return "YES";
	}
	else {
		return "NO";
	}
}

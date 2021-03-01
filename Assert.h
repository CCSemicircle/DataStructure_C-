#pragma once
#include<iostream>
#include<string>

using namespace std;

// Judge whether you can operate
void Assert(bool judgement, string warning) {
	if (judgement == 0) {
		cout << warning << endl;
		exit(1);
	}
}

#include<bits/stdc++.h>
using namespace std;

//To get ClearBit
int getBit(int n, int pos) {
	return (n & (1 << pos) != 0);
}
//To get SetBit
int setBit(int n, int pos) {
	return (n | (1 << pos));
}
//To GET ClearBit
int clearBit(int n, int pos) {
	int mask = ~(1 << pos);
	return (n & mask);
}
//To get UpdateBit
int updateBit(int n, int pos, int value) {
	//ClearBit
	int mask = ~(1 << pos);
	n = (n & mask);
	//SetBit
	return (n | (value << pos));

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << getBit(5, 2) << endl;
	cout << setBit(5, 1) << endl;
	cout << clearBit(5, 2) << endl;
	cout << updateBit(5, 1, 1) << endl;
	return 0;
}
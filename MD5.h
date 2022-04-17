#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

class MD5 {
private:
	unsigned int tempA, tempB, tempC, tempD, strlength;
	const static long A = 0x67452301;
	const static long B = 0xefcdab89;
	const static long C = 0x98badcfe;
	const static long D = 0x10325476;
	const char *str16 = "0123456789abcdef";

	const static unsigned int T[];

	const static unsigned int s[]; 


public:
	MD5();

	void reset();
	// F函数
	unsigned int F(unsigned int b, unsigned int c, unsigned int d);
	// G函数
	unsigned int G(unsigned int b, unsigned int c, unsigned int d);
	// H函数
	unsigned int H(unsigned int b, unsigned int c, unsigned int d);
	// I函数
	unsigned int I(unsigned int b, unsigned int c, unsigned int d);
	// 移位操作函数
	unsigned int shift(unsigned int a, unsigned int n);
	// 编码函数
	string encode(string src);
	// 循环压缩
	void iterateFunc(unsigned int* X, int size = 16);
	// 填充字符串
	vector<unsigned int> padding(string src);
	// 整理输出
	string format(unsigned int num);
};
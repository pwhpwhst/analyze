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
	// F����
	unsigned int F(unsigned int b, unsigned int c, unsigned int d);
	// G����
	unsigned int G(unsigned int b, unsigned int c, unsigned int d);
	// H����
	unsigned int H(unsigned int b, unsigned int c, unsigned int d);
	// I����
	unsigned int I(unsigned int b, unsigned int c, unsigned int d);
	// ��λ��������
	unsigned int shift(unsigned int a, unsigned int n);
	// ���뺯��
	string encode(string src);
	// ѭ��ѹ��
	void iterateFunc(unsigned int* X, int size = 16);
	// ����ַ���
	vector<unsigned int> padding(string src);
	// �������
	string format(unsigned int num);
};
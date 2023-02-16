#include <iostream>
using namespace std;

namespace fastio
{
    //inline int read()
    //{
    //	int s = 0; char ch = getchar(), last = '0';
    //	while (ch < '0' || ch>'9') last = ch, ch = getchar();
    //	while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    //	return last == '-' ? -s : s;
    //}

    char buf[1 << 23], * p1 = buf, * p2 = buf;
    #define _getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
    inline int read()
    {
        int s = 0;
        char ch = _getchar(), last = '0';
        while (ch < '0' || ch>'9') last = ch, ch = _getchar();
        while (ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = _getchar();
        return last == '-' ? -s : s;
    }

    int num[1 << 8];
    inline void write(int x)
    {
        if (x < 0) putchar('-'), x = -x;;
        int len = 0;
        do num[len++] = x % 10; while (x /= 10);
        while (len--) putchar(num[len] + '0');
    }
}

int main()
{
    int data = fastio::read();
	if (data != 0)
		fastio::write(data);
	else
		return 0;
	data = fastio::read();
	while (data != 0)
	{
		putchar(' ');
		fastio::write(data);
		data = fastio::read();
	}
	return 0;
}
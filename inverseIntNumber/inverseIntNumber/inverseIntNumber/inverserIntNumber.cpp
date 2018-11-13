#include <iostream>
using namespace std;
class Solution {
public:
	int pow(int x) {return (1 << (int)(x));}
    int reverse(int x) {
        if((x>(pow(31)-1))||(x < -pow(31)))
		{
			return 0;	
		}

		int iTemp = x, sign = 1, reminder = 0;
		long long int ret = 0;
		if(iTemp < 0)
		{
			sign = -1;
			iTemp = -iTemp;
		}	
		while(((reminder=iTemp%10)>=0)&&(iTemp>0))
		{
			ret = ret * 10 + reminder;
			iTemp = iTemp/10;
		}
		if(sign == -1)
			ret = -ret;
        if((ret>(pow(31)-1))||(ret < -pow(31)))
		{
			return 0;	
		}
		return (int)ret;
    }
};

void main(void)
{
	Solution ms;
	cout << ms.reverse(123) << endl;
	cout << ms.reverse(-123) << endl;
	cout << ms.reverse(1534236469) << endl;
	system("pause");
	return ;
}
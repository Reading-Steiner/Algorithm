#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//! 降序序列
vector<int> descend;
//! 升序序列
vector<int> ascend;

int main()
{
	int target;
	while (cin >> target)
	{
		//! upper_bound 从数组的begin位置到end-1位置，用二分法搜索大于target的第一个数据
		//! 使用greater<type>()参数，搜索小于target的第一个数据
		//! 找到返回该数字的地址，不存在则返回end。通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
		auto index1 = upper_bound(descend.begin(), descend.end(), target, greater<int>());
		if (index1 != descend.end())
			*index1 = target;
		else
			descend.push_back(target);
		//! lower_bound 从数组的begin位置到end-1位置，用二分法搜索大于或等于target的第一个数据
		auto index2 = lower_bound(ascend.begin(), ascend.end(), target);
		if (index2 != ascend.end())
			*index2 = target;
		else
			ascend.push_back(target);
		// for (auto value : descend)
		// {
		// 	cout << value << '\t';
		// }
		// cout << endl;
		// for (auto value : ascend)
		// {
		// 	cout << value << '\t';
		// }
		// cout << endl;
	}
	cout << descend.size() << endl << ascend.size();

	return 0;
}
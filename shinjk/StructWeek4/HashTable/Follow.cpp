#include<iostream>
#include<map>
#include<vector>

using namespace std;

class hash_map
{
public:
	vector<int> data;

	hash_map(size_t n) 
	{
		data = vector<int>(n, -1);
	}

	int hash_func(int value)
	{
		return value % data.size();
	}

	void insert(unsigned int value)
	{
		data[hash_func(value)] = value;
	}
};



//int main()
//{
//	hash_map* h = new hash_map(10);
//	h->insert(10);
//	h->insert(5);
//	h->insert(100);
//
//	for (int i = 0; i < h->data.size(); ++i)
//	{
//		cout<<h->data[i]<<endl;
//	}
//}
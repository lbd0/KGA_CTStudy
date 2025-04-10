#include <iostream>

int Change(int N)
{
	const int Coins[] = { 500, 100, 50, 10 };
	int count = 0;
	for (int Coin : Coins)
	{
		count += N / Coin;
		N -= Coin * (N / Coin);
	}
	return count;
}

int main()
 {
	std::cout << Change(1460) << std::endl;
	std::cout << Change(1890);
}

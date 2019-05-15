#include <bitset>
#include <iostream>
#include <cmath>


int main()
{
	while (true)
	{
		long double value;

		std::cin >> value;

		std::bitset<32> value32_bit;

		value32_bit[31] = value < 0 ? 1 : 0;

		long double bs = log(abs(value)) / log(2);

		bs = bs < 0 ? ceil(bs) : floor(bs);

		std::cout << "bs = " << bs << std::endl;

		long p = 127 + bs;

		std::bitset<8> value_power(p);

		std::cout << "Power = " << value_power << std::endl;

		int float_bits = 23 - bs;

		long float_part = round((abs(value) - pow(2, bs)) * pow(2, float_bits));

		std::cout << "(" << value << " - " << pow(2, bs) << ") * " << pow (2, float_bits) << float_part << std::endl;

		std::bitset<23> value_float_part(float_part);

		std::cout << value_float_part << std::endl;

		for (int i = 0; i < 31; i++)
		{
			value32_bit[i] = i < 23 ? value_float_part[i] : value_power[i - 23];
		}

		std::cout << "Result = " << value32_bit << std::endl;
	}

	return 0;
}
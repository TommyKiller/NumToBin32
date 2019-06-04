#include <bitset>
#include <iostream>
#include <cmath>
#include <string>


void FloatToBin(long double value)
{
	std::bitset<32> value32ieee754;
	value32ieee754[31] = value < 0 ? 1 : 0;

	float bs = log(abs(value)) / log(2);
	bs = bs < 0 ? ceil(bs) : floor(bs);
	int p = 127 + bs;
	std::bitset<8> value_int_part(p);

	int float_part_bits = 23 - bs;
	long float_part = round((abs(value) - pow(2, bs)) * pow(2, float_part_bits));
	std::bitset<23> value_float_part(float_part);

	for (int i = 0; i < 31; i++)
	{
		value32ieee754[i] = i < 23 ? value_float_part[i] : value_int_part[i - 23];
	}

	printf("\
		bs: %.0f						\n\
		p: %i							\n\
		Integer part: %s				\n\
		Float part = (%f - %.0f) * %.0f;\n\
		Float part: %s					\n\
		Result: %s						\n\
		Hex result: %X					\n", bs, p, value_int_part.to_string().c_str(), value, pow(2, bs), pow(2, float_part_bits),
		value_float_part.to_string().c_str(), value32ieee754.to_string().c_str(), value32ieee754);
}


int main()
{
	std::string input;
	printf("Input value: ");
	std::cin >> input;

	while (input != "exit" && input != "q")
	{
		FloatToBin(atof(input.c_str()));

		printf("Input value: ");
		std::cin >> input;
	}

	return 0;
}
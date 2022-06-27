#include <iostream>
#include <vector>
#include <string>


std::vector<int> prefix_pattern(std::string pattern)
{
	std::vector<int>LPS(pattern.length());
	LPS[0] = 0;
	int len = 0;
	int n = 1;
	while (n < pattern.length())
	{
		if (pattern[n] == pattern[len])
		{
			++len;
			LPS[n] = len;
			++n;
			continue;
		}
		else if (len == 0)
		{
			LPS[n] = 0;
			++n;
			continue;
		}
		else
		{
			len = LPS[len - 1];
			continue;
		}
	}
	return LPS;
}

void kmp_search(std::string str, std::string pattern)
{
	std::vector<int>LPS = prefix_pattern(pattern);
	int i = 0,j = 0;
	bool found = false;
	while (i < str.length())
	{
		if (str[i] == pattern[j])
		{
			++i;
			++j;
		}
		else if (str[i] != pattern[j])
		{
			if (j == 0)
			{
				++i;
			}
			else
			{
				j = LPS[j - 1];
			}
		}
		if (j == pattern.length())
		{
			std::cout << i - pattern.length()<<" ";
			j = LPS[j - 1];
			found = true;
		}
	}
	if (!found)
	{
		std::cout << "There is no repetitive pattern: ";
	}
}

int main()
{
	std::string str;
	std::string pattern;
	std::cout << "Enter str and pattern: " << std::endl;
	std::getline(std::cin, str);
	std::getline(std::cin, pattern);
	prefix_pattern(pattern);
	kmp_search(str, pattern);
}
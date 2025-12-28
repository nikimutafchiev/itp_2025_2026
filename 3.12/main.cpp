#include <iostream>

bool isUppercase(char c)
{
	return c >= 'A' && c <= 'Z';
}
bool isLowercase(char c)
{
	return c >= 'a' && c <= 'z';
}
char toLower(char c)
{
	if (isUppercase(c))
		return c - 'A' + 'a';
	return c;
}
void stringToLower(char *s)
{
	if (!s)
		return;
	while (*s)
	{
		*s = toLower(*s);
		s++;
	}
}
bool isAlpha(char c)
{
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}
bool isPangram(const char *s)
{
	if (!s)
		return false;
	bool letters[26] = {};
	while (*s)
	{
		if (isAlpha(*s))
		{
			letters[toLower(*s) - 'a'] = true;
		}
		s++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (!letters[i])
			return false;
	}
	return true;
}

bool areAnagram(const char *s1, const char *s2)
{
	int letters1[26] = {}, letters2[26] = {};

	while (*s1 && *s2)
	{
		if (isAlpha(*s1))
		{
			letters1[toLower(*s1) - 'a']++;
		}
		if (isAlpha(*s2))
		{
			letters1[toLower(*s2) - 'a']++;
		}
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return false;
	for (int i = 0; i < 26; i++)
	{
		if (letters1[i] != letters2[i])
			return false;
	}
	return true;
}

int strLen(const char *s)
{
	if (!s)
		return -1;
	int count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return count;
}
bool isPalindrome(char *s)
{
	if (!s)
		return false;
	char *r = s + strlen(s) - 1;
	while (r >= s)
	{
		if (*r != *s)
			return false;
		r--, s++;
	}
	return true;
}

bool uniqueLetters(const char *s)
{
	int letters[26] = {};
	while (*s)
	{
		if (isAlpha(*s))
		{
			letters[toLower(*s) - 'a']++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (letters[i] > 1)
			return false;
	}
	return true;
}
// if we have enough memory
void insert(char *s, char c, unsigned index)
{
	char *p = s + index;
	s += strlen(s);
	while (s > p)
	{
		*s = *(s - 1);
		s--;
	}
	*p = c;
}

char toUpper(char c)
{
	if (isLowercase(c))
	{
		return c - 'a' + 'A';
	}
	return c;
}
void capitalize(char *s)
{
	bool wasSpace = true;
	while (*s)
	{
		if (wasSpace && isAlpha(*s))
		{
			*s = toUpper(*s);
			wasSpace = false;
		}
		else if (*s == ' ')
			wasSpace = true;
		s++;
	}
}

void remove(char *s, char c)
{
	for (; *s; s++)
	{
		if (*s == c)
		{
			char *p = s;
			while (*p)
			{
				*p = *(p + 1);
				p++;
			}
		}
	}
}

void ceasar(char *s, int code)
{
	if (code < -26 || code > 26)
		return;
	while (*s)
	{
		if (isLowercase(*s))
			*s = (*s - 'a' + code + 26) % 26 + 'a';
		else if (isUppercase(*s))
			*s = (*s - 'A' + code + 26) % 26 + 'A';
		s++;
	}
}
// TODO fix the bug
bool regexMatch(const char *regex, const char *s)
{
	while (*s)
	{
		if (*regex == '.')
		{
			regex++;
			s++;
		}
		else if (*regex == '*')
		{
			char c = *s;
			while (*s == c)
				s++;
			regex++;
		}
		if (*regex != *s)
			return false;
		regex++;
		s++;
	}
	return *s == *regex;
}
int main()
{
	char s[] = "Hello, world!";
	ceasar(s, -3);
	std::cout << regexMatch("I lo*ve FMI", "I looooooove FMI");
}
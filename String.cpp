#include "String.h"

size_type String::count = 0;

String::String()
{
	++count;
	len = 0;
	str = new char[1];
	str = nullptr;
}

String::String(char* s1)
{
	++count;
	this->len = strlen(s1);
	str = new char[this->len + 1];
	strcpy(str, s1);
}

String::String(String & s)
{
	++count;
	this->len = s.len;
	str = new char[this->len + 1];
	strcpy(str, s.str);
}

String::~String()
{
	--count;
	delete[] str;
}

String & String::operator=(String & s)
{
	delete[] str;
	this->len = strlen(s.str);
	str = new char[this->len + 1];
	strcpy(str, s.str);
	return *this;
}

String & String::operator=(char * s)
{
	delete[] str;
	this->len = strlen(s);
	str = new char[this->len + 1];
	strcpy(str, s);
	return *this;
}

char & String::operator[](size_type i)
{
	return str[i];
}

const char & String::operator[](size_type i) const
{
	return str[i];
}

size_type String::HowMany()
{
	return count;
}

bool operator>(const String & str1, const String & str2)
{
	return (strcmp(str1.str, str2.str) > 0);
}

bool operator==(const String & str1, const String & str2)
{
	return (strcmp(str1.str,str2.str)==0);
}

std::ostream & operator<<(std::ostream & os, String & s)
{
	os << s.str << std::endl;
	return os;
}

std::istream & operator >> (std::istream & is, String & s)
{
	char temp[String::max_size];
	is.get(temp, String::max_size);
	if (is)
		s = temp;
	while (is&&is.get() != '\n')
		continue;
	return is;
}

bool operator<(const String & str1, const String & str2)
{
	return (strcmp(str1.str, str2.str) < 0);
}

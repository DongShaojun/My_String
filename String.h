#pragma once
#ifndef _STRING_H_
#define _STRING_H_

#include<vector>
#include<ostream>

typedef  std::vector<int>::size_type size_type;

class String
{
private:
	size_type len;
	char* str;
	static size_type count;
public:
	String();
	String(char* s1);
	~String();
	size_type length() { return len; };
	friend bool operator<(const String &str1, const String &str2);
	friend bool operator>(const String &str1, const String &str2);
	friend bool operator==(const String &str1, const String &str2);
	friend std::ostream &operator<<(std::ostream &os, String &s);
	char &operator[](size_type i);
	const char &operator[](size_type i) const;
	static size_type HowMany();
};
#endif // !_STRING_H_

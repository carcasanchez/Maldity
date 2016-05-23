#ifndef __MYSTRING_H__
#define __MYSTRING_H__


class String{
private:
	char* buffer;
	unsigned int mem;
	

public:

	String();
	String(const char* str);
	String(const String& str);
	~String();

	unsigned int Strlen()const;
	const char* C_str()const;
	bool Empty()const;
	bool Compare(const String& str)const;
	bool Compare(const char* str)const;
	void operator=(const String& str);
	void operator=(const char* str);
	char* operator+(const String& str)const;
	char* operator+(const char* str)const;
	void operator+=(const String& str);
	void operator+=(const char* str);
	unsigned int Memory()const;
	void Clean();
	void Shrink_to_fit();
	void Strtok(const char character, const int num_word, String& dest)const;
	void BackSpace();
};

#endif
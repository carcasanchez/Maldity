#include "mystring.h"
#include <string>

String::String()
{
	mem = 10;
	buffer = new char[mem];
}

String::String(const char* str)
{

	int len = strlen(str);
	mem = len + 1;
	buffer = new char[mem];
	strcpy_s(buffer, mem, str);

}

String::String(const String& str)
{

	int len = Strlen();
	mem = len + 1;
	buffer = new char[mem];
	strcpy_s(buffer, mem, str.buffer);

}

String::~String()
{
	delete[] buffer;
}

unsigned int String::Strlen() const
{
	return strlen(buffer);
}

const char* String::C_str()const
{
	return buffer;
}

bool String::Empty()const
{

	if (strlen(buffer) == 0)
		return true;
	else return false;

}

bool String::Compare(const char* str)const
{

	return (_strcmpi(buffer, str) == 0);

}

bool String::Compare(const String& str)const
{

	return (_strcmpi(buffer, str.buffer) == 0);

}

void String::operator=(const String& str)
{

	int len = str.Strlen();

	if (len >= mem)
	{
		mem = len + 1;
		delete[] buffer;
		buffer = new char[mem];
	}

	strcpy_s(buffer, len + 1, str.C_str());

}

void String::operator=(const char* str)
{
	int len = strlen(str);

	if (len >= mem)
	{
		mem = len + 1;
		delete[] buffer;
		buffer = new char[mem];

	}

	strcpy_s(buffer, len + 1, str);

}

char* String::operator+(const char* str)const
{
	char* new_string;

	int len = Strlen() + strlen(str) + 1;

	new_string = new char[len];
	strcpy_s(new_string, len, buffer);
	strcat_s(new_string, len, str);

	return new_string;
}

char* String::operator+(const String& str)const
{
	char* new_string;

	int len = Strlen() + str.Strlen() + 1;

	new_string = new char[len];
	strcpy_s(new_string, len, buffer);
	strcat_s(new_string, len, str.buffer);

	return new_string;
}


void String::operator+=(const String& str)
{

	int len1 = Strlen();
	int len2 = str.Strlen();
	mem = len1 + len2 + 1;
	char* temp;
	temp = new char[mem];

	strcpy_s(temp, mem, buffer);
	strcat_s(temp, mem, str.C_str());

	delete[] buffer;

	buffer = temp;


}

void String::operator+=(const char* str)
{

	int len1 = Strlen();
	int len2 = strlen(str);
	mem = len1 + len2 + 1;
	char* temp;
	temp = new char[mem];

	strcpy_s(temp, mem, buffer);
	strcat_s(temp, mem, str);

	delete[] buffer;

	buffer = temp;

}

unsigned int String::Memory()const
{
	return mem;
}

char* String::Strtok(const char character, const int num_word)const
{
	int i, j, num_char = 0;
	char* temp;
	int len = Strlen();

	for (i = 0, j = 0; i < len; i++)
	{
		if ((buffer[i] == character) || (buffer[i] == NULL))
			num_char++;
		if (num_char == num_word - 1)
			j++;
	}



	temp = new char[j + 1];


	for (i = 0, j = 0, num_char = 0; i < len; i++)
	{

		if ((buffer[i] == character) || (buffer[i] == NULL))
		{
		num_char++;
		i++;
		}

		if (num_char == num_word - 1)
		{
			temp[j] = buffer[i];
			j++;
		}
	}
	temp[j] = '\0';

	return temp;

}

void String::Clean()
{
	buffer[0] = '\0';
}

void String::Shrink_to_fit()
{
	char* temp;
	mem = Strlen() + 1;
	temp = new char[mem];
	strcpy_s(temp, mem, buffer);

	delete[] buffer;

	buffer = temp;


}



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

char* String::operator+(const char* str)const//const String&
{
	char* new_string;

	int len = Strlen() + strlen(str) + 1;

	new_string = new char[len];
	strcpy_s(new_string, len, buffer);
	strcat_s(new_string, len, str);

	return new_string;//return (*this)
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
	char* temp = nullptr;

	if (len1 + len2 + 1 > mem)
	{
		mem = len1 + len2 + 1;
		
		temp = new char[mem];
		strcpy_s(temp, mem, buffer);
		strcat_s(temp, mem, str.C_str());

		delete[] buffer;
		buffer = temp;
	}
	
	else
	{
		mem = len1 + len2 + 1;
		strcat_s(buffer, mem, str.C_str());
	}

	


}

void String::operator+=(const char* str)
{

	int len1 = Strlen();
	int len2 = strlen(str);
	
	
	if (len1 + len2 + 1 > mem)
	{
		mem = len1 + len2 + 1;
		char* temp;
		temp = new char[mem];

		strcpy_s(temp, mem, buffer);
		strcat_s(temp, mem, str);

		delete[] buffer;

		buffer = temp;
	}
	else
	{
		mem = len1 + len2 + 1;
		strcat_s(buffer, mem, str);
	}
}

unsigned int String::Memory()const
{
	return mem;
}

void String::Strtok(const char character, const int num_word, String& dest)const
{//TODO

	char* temp;
	int new_mem = 1;
	int current_word = 0;
	int k = 0;

	/*	int i, j, num_char = 0;
	
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

		dest = temp;
		delete[] temp;

		*/

	for (int i = 0, j = Strlen(); i < j; i++)
	{
		if (buffer[i] != character)
		{
			current_word++;
			while (buffer[i] != character && buffer[i] != '\0')
			{
				i++;
				if (current_word == num_word)
				{
					new_mem++;
				}
			}
		}

	}

	if (new_mem > 1)
	{
		temp = new char[new_mem];
		current_word = 0;

		for (int i = 0, j = Strlen(); i < j; i++)
		{
			if (buffer[i] != character && buffer[i] != '\0')
			{
				current_word++;
				while (buffer[i] != character && buffer[i] != '\0')
				{	
					if (current_word == num_word)
					{
						temp[k] = buffer[i];
						k++;
					}
					i++;
				}
			}

		}

		temp[k] = '\0';
		dest = temp;
		delete[] temp;
	}

	else dest = "";
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

void String::BackSpace()
{
	int size = Strlen();

	if (size != 0);
		buffer[size - 1] = NULL;
	

}


int String::FirstAscii()const
{
	return buffer[0] - 48;
}

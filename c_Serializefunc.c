#include "c_serializable.h"
#include <stdio.h>
#include <string.h>

Person::Person(char* name1, int age1)
{
    name = calloc(50, sizeof(char));
    memcpy(name, name1);
    memcpy(age, age1);
}

Person::~Person()
{
    free(name);
}

void Person::displayInfo() const
{
	printf("%s %d\n", name, age);
}

char* Person::serialize()
{
	char* result = calloc(50, sizeof(char));
    memcpy(result, name);
	int val = age;
	char* tmp = calloc(50, sizeof(char));
	
    int index = 0;
	while (val)
	{
		tmp[index] = (val % 10) + '0';
		val /= 10;
        ++index;
	}

    tmp[index] = '\0';
    ++index;

    int size = strlen(result);
	for (int i = 0; i < index - 1; ++i)
	{
		result[size + i] += tmp[index - i - 1];
	}
    result[size + index] = '\0';

    free(tmp);

	return result;
}

void Person::deserialize(const char* str)
{
	int index = 0;
	while (str[index])
	{
		if ('1' <= str[index] && str[index] <= '9')
		{
			break;
		}
		name[index] = str[index];
        ++index;
	}

	age = 0;
	
    while (str[index])
	{
		if (str[index] < '0' || str[index] > '9')
		{
			break;
		}
		age = age * 10 + (str[index] - '0');
	    ++index;
    }
}

int stringToInt(const std::string& str)
{
	int value = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		value = value * 10 + (str[i] - '0');
	}
	return value;
}

char* intToString(const int value)
{
	int tmp = value;
	std::string result;
	while (tmp)
	{
		result += (tmp % 10) + '0';
		tmp /= 10;
	}
	for (int i = 0; i < result.size() / 2; ++i)
	{
		std::swap(result[i], result[result.size() - i - 1]);
	}
	return result;
}

Integer::Integer() : m_value(0) {}

void Integer::set_value(const std::string& str)
{
	m_value = stringToInt(str);	
}

std::string Integer::get_value() const
{
	return intToString(m_value);
}

Float::Float() : m_value(0.0f) {}

void Float::set_value(const std::string& str)
{
	m_value = 0;
	int index = 0;
	for (; index < str.size(); ++index)
	{
		if (str[index] == '.')
		{
			break;
		}
		m_value = m_value * 10 + (str[index] - '0');
	}
	++index;
	double mult = 0.1;
	for (; index < str.size(); ++index)
	{
		m_value += mult * (str[index] - '0');
		mult /= 10;
	}
}

std::string Float::get_value() const
{
	std::string result = intToString(static_cast<int>(m_value));
	
	result += '.';
    double val = m_value - static_cast<int>(m_value);
    if (val != 0)
    {      
	    while (val != static_cast<int>(val))
	    {
		    val *= 10;
	    }
    }

    else
    {
        result += '0';
    }

	return result + intToString(val);
}

Boolean::Boolean() : m_value(0) {}

void Boolean::set_value(const std::string& str)
{
	if (str == "" || str == "0")
	{
		m_value = 0;
	}
	else
	{
		m_value = 1;
	}
}

std::string Boolean::get_value() const
{
	if (m_value)
	{
		return "1";
	}
	return "0";
}


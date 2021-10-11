#ifndef SC_STRING_H
#define SC_STRING_H

#include <string>

class SctString : public std::string
{
public:
	SctString() = default;

	explicit inline SctString(const std::string & string) :
		std::string(string)
	{
	}

	// cppcheck-suppress noExplicitConstructor ; implicit conversion needed for auto-generated code.
	inline SctString(const int number) :
		std::string(std::to_string(number))
	{
	}

	inline operator const char * () const
	{
		return c_str();
	}

	inline SctString & operator =(const int number)
	{
		assign(std::to_string(number));
		return *this;
	}
};

#endif // SC_STRING_H

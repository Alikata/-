#include "string_view.h"
string_view::string_view()
{
	data = nullptr;
	length = 0;
}

string_view::string_view(const string_view& other)
{
	data = other.data;
	length = other.length;
}

string_view::string_view(const char* raw)
{
	length = 0;
	for(size_t i = 0; raw[i] != '\0'; ++i)
		++length;
	data = raw;
}

string_view::string_view(const char* raw, size_t count)
{
	length = count;
	data = raw;
}

std::ostream& operator<<(std::ostream& os, const string_view& s)
{
	for(size_t i = 0; i < s.length; ++i)
		os << s.data[i];
	return os;
}

size_t string_view::size() const
{
	return length;
}

bool string_view::empty() const
{
	return length == 0;
}

bool string_view::starts_with(const string_view& view) const
{
	return substr(0, view.size()) == view;
}

bool string_view::starts_with(char c) const
{
	return (length != 0) && (data[0] == c);
}

bool string_view::starts_with(const char* c) const
{
	bool ret = true;
	for(size_t i = 0; (c[i] != '\0') || (i < length); ++i)
		if(c[i] != data[i])
			ret = false;
	return ret;
}

bool string_view::ends_with(const string_view& view) const
{
	if(length < view.length)
		return false;
	for(size_t i = length-view.length; i < length; ++i)
		if(data[i] != view[i])
			return false;
	return true;
}

bool string_view::ends_with(char c) const
{
	return (length != 0) && (data[length-1] == c);
}

bool string_view::ends_with(const char* c) const
{
	bool ret = true;

	size_t str_len = 0;

	for(str_len = 0; c[str_len] != '\0'; ++str_len)
	{}

	for(size_t i = length-1; (i >= 0) && (i >= length-str_len); --i)
		if(c[i-length+str_len] != data[i])
			ret = false;
	return ret;
}

string_view string_view::substr(size_t pos, size_t count) const
{
	if(pos > length)
		return string_view();

	return string_view(data+pos, count);
}

const char& string_view::operator[](size_t pos) const
{
	return data[pos];
}

bool operator==(const string_view& view, const string_view& other) 
{
	if(view.length != other.length)
		return false;

	for(size_t i = 0; i < view.length; ++i)
		if(view.data[i] != other.data[i])
			return false;

	return true;
}

void string_view::remove_suffix(size_t n)
{
	length -= n;
}

void string_view::remove_prefix(size_t n)
{
	data = data + n;
}

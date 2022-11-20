#pragma once

#include<iostream>
#include<string>
#include <cstdlib>

/**
  @class string_view Simple string_view implementation
**/
class string_view
{
private:

	const char* data;
	size_t length;

public:

	/**
	@brief Default constructor.
	@details Constructs empty string_view with data = nullptr and length = 0.
	**/
	string_view();

	/**
	@brief Copy constructor.
	@param other Other string_view instance. 
	@details Constructs string_view of same content as other with data = other.data and length = other.length.
	**/
	string_view(const string_view& other);

	/**
	@brief Constructor from raw pointer.
	@param raw Raw pointer string first item.
	@details Constructs a string_view instance of null-terminated char array pointed to by raw.
	**/
	string_view(const char* raw);

	/**
	@brief Constructor from raw pointer with count.
	@param raw Raw pointer string first item.
	@param count Number of elements to include in view.
	@details Constructs view of count elements.
	**/
	string_view(const char* raw, size_t count);

	/**
	@brief Output overloading.
	@param os Output stream.
	@param s string_view instance.
	@returns Output stream.
	**/
	friend std::ostream& operator<<(std::ostream& os, const string_view& s);

	/**
	@brief Get size.
	@returns Size of view in chars.
	**/
	size_t size() const;

	/**
	@brief Check if view is empty.
	@returns False if not empty, true otherwise.
	**/
	bool empty() const;

	/**
	@brief Check if view starts with another view.
	@param view View to check.
	@details Checks if this string_view instance starts with another view.
	@returns True if this view starts with another, false otherwise.
	**/
	bool starts_with(const string_view& view) const;
	/**
	@brief Check if view starts with given char.
	@param c Char to check.
	@details Checks if this string_view instance starts with given char .
	@returns True if this view starts with given char, false otherwise.
	**/
	bool starts_with(char c) const;
	/**
	@brief Check if view starts with raw string.
	@param c Raw char array pointer.
	@details Checks if this string_view instance starts with raw string.
	@returns True if this view starts with given raw string, false otherwise.
	**/
	bool starts_with(const char* c) const;

	/**
	@brief Check if view ends with another view.
	@param view View to check.
	@details Checks if this string_view instance ends with another view.
	@returns True if this view ends with another, false otherwise.
	**/
	bool ends_with(const string_view& view) const;
	/**
	@brief Check if view ends with given char.
	@param c Char to check.
	@details Checks if this string_view instance ends with given char.
	@returns True if this view ends with given char, false otherwise.
	**/
	bool ends_with(char c) const;
	/**
	@brief Check if view ends with raw string.
	@param c Raw char array pointer.
	@details Checks if this string_view instance ends with raw string.
	@returns True if this view ends with given raw string, false otherwise.
	**/
	bool ends_with(const char* c) const;

	/**
	@brief Get a substring of view.
	@param pos Position to start with.
	@param count Number of chars required.
	@returns Sub-view.
	@details Returns as substringview beginning from postion pos of count elements.
	**/
	string_view substr(size_t pos, size_t count) const;

	const char& operator[](size_t pos) const;

	/**
	@brief operator== overloading
	@details Lexicographically compares two string_view instances.
	**/
	friend bool operator==(const string_view& view, const string_view& other);

	/**
	@brief Remove suffix.
	@param n --- size of suffix to remove.
	@detailed Move the end of view n chars back.
	**/
	void remove_suffix(size_t n);

	/**
	@brief Remove prefix.
	@param n --- size of prefix to remove.
	@detailed Move the beginnig of view n chars forward.
	**/
	void remove_prefix(size_t n);




};

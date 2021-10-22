#pragma once

class Exception : public std::exception
{
public:
	Exception(const char* str) : m_str(str) {}
	const char* what() const noexcept { return m_str; }

private:
	const char* m_str;
};
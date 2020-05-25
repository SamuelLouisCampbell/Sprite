#pragma once
#include <vector>

template<typename T>
inline void remove_element(std::vector<T>& vec, size_t index)
{
	std::swap(vec[index], vec.back());
	vec.pop_back();
}
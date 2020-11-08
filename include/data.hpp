#ifndef DATA_HPP
#define DATA_HPP

#include <vector>
#include <cstdio>
#include <cstdint>

class data
{
	std::vector<uint8_t> * feature_vector;
	uint8_t label;

public:
	data();
	~data();

	void set_feature_vector(std::vector<uint8_t> *);
	void append_to_feature_vector(uint8_t);
	void set_label(uint8_t);

	uint8_t get_label();
	std::vector<uint8_t> * get_feature_vector();
};

#endif

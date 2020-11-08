#include "data.hpp"

data::data()
{
	feature_vector = new std::vector<uint8_t>;
	uint8_t label = 0xfe;
}

data::~data()
{

}

void data::set_feature_vector(std::vector<uint8_t> * vec)
{
	feature_vector = vec;
}

void data::append_to_feature_vector(uint8_t val)
{
	feature_vector->push_back(val);
}

void data::set_label(uint8_t val)
{
	label = val;
}

uint8_t data::get_label()
{
	return label;
}

std::vector<uint8_t> * data::get_feature_vector()
{
	return feature_vector;
}


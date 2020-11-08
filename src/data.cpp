#include "data.hpp"

data::data()
{
	feature_vector = new std::vector<uint8_t>;
	double_feature_vector = new std::vector<double>;
	class_vector = new std::vector<int>;
	label = 0xfe;
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

void data::set_feature_vector(std::vector<double> * vec)
{
	double_feature_vector = vec;
}

void data::append_to_feature_vector(double val)
{
	double_feature_vector->push_back(val);
}

void data::set_class_vector(int count)
{
	for(int i = 0; i < count; i++)
	{
		if(i == label)
		{
			class_vector->push_back(1);
		}
		else
		{
			class_vector->push_back(0);
		}
	}
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

std::vector<double> * data::get_double_feature_vector()
{
	return double_feature_vector;
}

std::vector<int> * data::get_class_vector()
{
	return class_vector;
}

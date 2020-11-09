#include "common.hpp"

void common_data::set_training_data(std::vector<data *> * vec)
{
	training_data = vec;
}

void common_data::set_test_data(std::vector<data *> * vec)
{
	test_data = vec;
}

void common_data::set_validation_data(std::vector<data *> * vec)
{
	validation_data = vec;
}


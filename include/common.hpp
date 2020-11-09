#ifndef COMMON_HPP
#define COMMON_HPP

#include "data.hpp"
#include <vector>

class common_data
{
	std::vector<data *> * training_data;
	std::vector<data *> * test_data;
	std::vector<data *> * validation_data;

public:
	void set_training_data(std::vector<data *> *);
	void set_test_data(std::vector<data *> *);
	void set_validation_data(std::vector<data *> *);
};

#endif

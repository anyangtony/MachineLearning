#ifndef DATA_HANDLER_HPP
#define DATA_HANDLER_HPP

#include <fstream>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <string>
#include <map>
#include "data.hpp"

class data_handler
{
	std::vector<data *> * data_array;
	std::vector<data *> * training_data;
	std::vector<data *> * test_data;
	std::vector<data *> * validation_data;

	int num_classes;
	std::map<uint8_t, int> class_map;

	const double TRAINING_SET_PERCENT = 0.75;
	const double TEST_SET_PERCENT = 0.20;
	const double VALIDATION_PERCENT = 0.05;

public:
	data_handler();
	~data_handler();

	void read_feature_vectors(std::string path);
	void read_feature_labels(std::string path);
	void split_data();
	void count_classes();

	uint32_t convert_to_little_endian(const uint8_t * bytes);

	int get_class_counts();

	std::vector<data *> * get_training_data();
	std::vector<data *> * get_test_data();
	std::vector<data *> * get_validation_data();
};

#endif

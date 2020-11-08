#include "data_handler.hpp"
#include <algorithm>

data_handler::data_handler()
{
	data_array = new std::vector<data *>();
	training_data = new std::vector<data *>();
	test_data = new std::vector<data *>();
	validation_data = new std::vector<data *>();
	num_classes = 0;
}

data_handler::~data_handler()
{
}

void data_handler::read_feature_vectors(std::string path)
{
	uint32_t header[4];	// | MAGIC | IMAGES_NUM | ROWS | COLS |
	uint8_t bytes[4];
	FILE * f = fopen(path.c_str(), "rb");
	if(f)
	{
		for(int i = 0; i < 4; i++)
		{
			if (fread(bytes, sizeof(bytes), 1, f))
			{
				header[i] = convert_to_little_endian(bytes);
			}
			else
			{
				printf("Error getting input file header.\n");
				exit(1);
			}
		}
		printf("Done getting input file header.\n");

		int image_size = header[2] * header[3];
		for(unsigned i = 0; i < header[1]; i++)
		{
			data * d = new data();
			uint8_t element[1];
			for(int j = 0; j < image_size; j++)
			{
				if(fread(element, sizeof(element), 1, f))
				{
					d->append_to_feature_vector(element[0]);
				}
				else
				{
					printf("Error reading input file.\n");
					exit(1);
				}
			}
			data_array->push_back(d);
		}
		printf("Successfully read and stored %zu feature vectors.\n", data_array->size());
	}
	else
	{
		printf("Could not find input file.\n");
		exit(1);
	}
	fclose(f);
}

void data_handler::read_feature_labels(std::string path)
{
	uint32_t header[2];	// | MAGIC | LABELS_NUM |
	uint8_t bytes[4];
	FILE * f = fopen(path.c_str(), "rb");
	if(f)
	{
		for(int i = 0; i < 2; i++)
		{
			if(fread(bytes, sizeof(bytes), 1, f))
			{
				header[i] = convert_to_little_endian(bytes);
			}
			else
			{
				printf("Error getting label file header.\n");
				exit(1);
			}
		}
		printf("Done getting label file header.\n");

		for(unsigned i = 0; i < header[1]; i++)
		{
			uint8_t element[1];
			if(fread(element, sizeof(element), 1, f))
			{
				data_array->at(i)->set_label(element[0]);
			}
			else
			{
				printf("Error reading input file.\n");
				exit(1);
			}
		}
		printf("Successfully read and stored labels.\n");
	}
	else
	{
		printf("Could not find label file.\n");
		exit(1);
	}
}

void data_handler::split_data()
{
	random_shuffle(data_array->begin(), data_array->end());

	int training_data_ptr = (int)(data_array->size() * TRAINING_SET_PERCENT);
	int test_data_ptr = training_data_ptr + (int)(data_array->size() * TEST_SET_PERCENT);
	int validation_data_ptr = (int)data_array->size();

	for(int i = 0; i < training_data_ptr; i++)
	{
		training_data->push_back(data_array->at(i));
	}
	for(int i = training_data_ptr; i < test_data_ptr; i++)
	{
		test_data->push_back(data_array->at(i));
	}
	for(int i = test_data_ptr; i < validation_data_ptr; i++)
	{
		validation_data->push_back(data_array->at(i));
	}
	printf("Done splited data.\n");
	printf("Training data size: %zu.\n", training_data->size());
	printf("Test data size: %zu.\n", test_data->size());
	printf("Validation data size: %zu.\n", validation_data->size());
}

void data_handler::count_classes()
{
	int count = 0;
	for(auto kv : *data_array)
	{
		if(class_map.find(kv->get_label()) == class_map.end())
		{
			class_map[kv->get_label()] = count++;
		}
	}
	num_classes = count;
	printf("Successfully extracted %d unique classes.\n", num_classes);
}

uint32_t data_handler::convert_to_little_endian(const uint8_t * bytes)
{
	return (uint32_t)(
			(bytes[0] << 24) | 
			(bytes[1] << 16) | 
			(bytes[2] << 8) | 
			(bytes[3]));
}

int data_handler::get_class_counts()
{
	return num_classes;
}

std::vector<data *> * data_handler::get_training_data()
{
	return training_data;
}

std::vector<data *> * data_handler::get_test_data()
{
	return test_data;
}

std::vector<data *> * data_handler::get_validation_data()
{
	return validation_data;
}

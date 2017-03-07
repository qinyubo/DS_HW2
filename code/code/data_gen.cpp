#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

string file_dir= "/Users/qybo123/Desktop/HW2/code/data";
string filename;

int main(int argc, char const *argv[])
{
	ofstream outputFile;
	string input_size_string;
	int size = atoi(argv[1]);
	input_size_string = to_string(size); //conver size to string

	filename = file_dir + "/data." + input_size_string;

	outputFile.open(filename.c_str());
	srand((unsigned)time(NULL));
	for (int i=0; i<size; i++) {
		outputFile << rand()%size << endl;
	}

	outputFile.close();
	return 0;
}
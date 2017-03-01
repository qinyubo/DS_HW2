//
//  main.cpp
//  q4_1 Recursive QuichSort
//
//  Created by Yubo Qin on 3/1/17.
//  Copyright (c) 2017 Yubo Qin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
//#include <vector>


using namespace std;

int array_size = 32768;
int * data = new int[array_size];
int position = 0;

int input_size=0;
int inputFileName[6] = {1024, 2048, 4096, 8192, 16384, 32768};
string filename;
string file_dir ="/Users/qybo123/Desktop/HW2/";
int compar_counter = 0;


int readData(){
    string input_size_string;
    
    input_size_string = to_string(input_size); //convert int to string
    filename = file_dir + "data1." + input_size_string;
    
    ifstream myfile (filename.c_str());
    
    if (myfile.is_open())
    {
        while (!myfile.eof() && position < input_size)
        {
            myfile >> data[position];
            position++;
        }
        
    }
    else cout << "unable to open file." << endl;
    
    myfile.close();
    
    return 0;
}

int printVector()
{
    for (int i=0; i<position; i++)
    {
        cout << data[i] << endl;
    }
    
    cout << "position= "<< position <<endl;
    
    return 0;
}

int partition(int* a, int lo, int hi)
{
    int i = lo, j = hi+1;
    int temp;
    
    while(true)
    {
        while (a[++i] <= a[lo])
            if (i == hi) break;
        while (a[--j] > a[lo])
            if (j == lo) break;
        
        if (i >= j) break;
        
        //swap i j
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    //swap with partition item
    temp = a[lo];
    a[lo] = a[j];
    a[j] = temp;
    
    return j;
    
}


void sort(int* a, int lo, int hi)
{
    //base case
    if (hi <= lo) return;
    
    int j = partition(a, lo, hi);
    sort(a, lo, j-1);
    sort(a, j+1, hi);
}

int main()
{
    double time_spend;
    
    for (int i=1; i<2; i++)
    {
        input_size = inputFileName[i];
        compar_counter = 0;
        position = 0;
        
        readData();
        
        clock_t begin = clock();
        sort(data, 0, input_size-1);
        clock_t end = clock();
        
        time_spend = double(end - begin) / CLOCKS_PER_SEC;

        cout << "Time spent: " << time_spend << " sec." << endl;
        
    }
    
    return 0;
}

















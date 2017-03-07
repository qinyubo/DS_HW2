//
//  main.cpp
//  q3_1
//  This implement Top-down Mergesort
//
//  Created by Yubo Qin on 2/28/17.
//  Copyright (c) 2017 Yubo Qin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
//#include <vector>


using namespace std;

int array_size = 32768;
int * data = new int[array_size];
int position = 0;

int input_size=0;
int inputFileName[6] = {1024, 2048, 4096, 8192, 16384, 32768};
string filename;
string file_dir ="/Users/qybo123/Desktop/HW2/code/data/";
int compar_counter = 0;


int readData(){
    string input_size_string;
    
    input_size_string = to_string(input_size); //convert int to string
    filename = file_dir + "data0." + input_size_string;
    
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


void merge(int* a, int lo, int mid, int hi)
{
    int * aux = new int[input_size];
    
    //copy
    for (int k=lo; k<=hi; k++)
    {
        aux[k] = a[k];
    }
    
    //merge
    int i = lo;
    int j = mid + 1;
    
    for (int k=lo; k<=hi; k++)
    {
        compar_counter++;
        if (i > mid)                a[k] = aux[j++];
        else if (j > hi)            a[k] = aux[i++];
        else if (aux[j] <= aux[i])  a[k] = aux[j++];
        else                        a[k] = aux[i++];
    }
    
}

void sort(int* a, int lo, int hi)
{
    //base case
    if (hi <= lo) return;
    
    int mid = lo + (hi - lo)/2;
    
    sort(a, lo, mid);
    sort(a, mid+1, hi);
    
    merge(a, lo, mid, hi);
    
}



int main()
{
    
    for (int i=0; i<6; i++)
    {
        input_size = inputFileName[i];
        position = 0; //init
        compar_counter = 0;
    
        readData();
    
        sort(data, 0, input_size-1);

       // printVector();
        cout << "Num of comparison of input size "<< input_size << " is " << compar_counter << endl;
        
    }
    
    return 0;
}




























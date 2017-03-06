//
//  main.cpp
//  q4_2 Interative QuichSort
//
//  Created by Yubo Qin on 3/1/17.
//  Copyright (c) 2017 Yubo Qin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include "Stack.h"



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

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* a, int lo, int hi)
{
    int low_val = a[lo]; //smallest value
    
    do{
        
        while (lo < hi && a[hi] >= low_val) { //traversal right hand side
            --hi;
        }
        if (lo < hi)
        {
            //swap larger value with smallest one
            a[lo] = a[hi];
            ++lo;
        }
        
        while (lo < hi && a[lo] <= low_val) {
            ++lo;
        }
        if (lo < hi) {
            //swap smaller value with larger one
            a[hi] = a[lo];
            --hi;
        }
    }while(lo != hi);
    
    a[lo] = low_val;
    
    return lo; //return the index
}

void sort(int* a, int lo, int hi)
{
    //using stack to mimic recursive call
    Stack<int> st;
    
    if (lo < hi)
    {
        int mid = partition(a, lo, hi);
        if (lo < mid - 1) {
            st.push(lo);
            st.push(mid - 1);
        }
        
        if (hi > mid + 1) {
            st.push(mid + 1);
            st.push(hi);
        }
        
        while (!st.isEmpty()) {
            int q = st.pop();
            int p = st.pop();
            
            mid = partition(a, p, q);
            
            if (p < mid-1) {
                st.push(p);
                st.push(mid-1);
            }
            
            if (q > mid+1) {
                st.push(mid+1);
                st.push(q);
            }
        }
    }



}





int main()
{
    double time_spend;
    
    for (int i=0; i<6; i++)
    {
        input_size = inputFileName[i];
        compar_counter = 0;
        position = 0;
        
        readData();
        
        clock_t begin = clock();
        sort(data, 0, input_size-1);
        clock_t end = clock();
        
        time_spend = double(end - begin) / CLOCKS_PER_SEC;
        
        //        printVector();
        cout << "Time spent: " << time_spend << " sec." << endl;
        
    }
    
    return 0;
}

















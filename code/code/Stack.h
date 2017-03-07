//
//  Stack.h
//  q4_2
//
//  Created by Yubo Qin on 3/5/17.
//  Copyright (c) 2017 Yubo Qin. All rights reserved.
//

#include <iostream>

template <class T>
class Stack
{
private:
    struct node {
        T data;
        node *next;
        node( const T &x, node *N=NULL)
        {data = x; next = N;}
        node():next(NULL) {}
        ~node() {}
    };
    
    node *elem;
    
public:
    Stack() {elem = NULL;}
    ~Stack() {
        node *tmp;
        while(elem != NULL) {
            tmp = elem;
            elem = elem->next;
            delete tmp;
        }
    }
    
    bool isEmpty() const {
        return elem == NULL;
    }
    
    void push(const T &x) {
        node *tmp = new node(x,elem);
        elem = tmp;
    }
    
    T pop() {
        node *tmp = elem;
        T x = tmp->data;
        elem = elem->next;
        delete tmp;
        return x;
    }
    
    T top() const {
        return elem->data;
    }
};
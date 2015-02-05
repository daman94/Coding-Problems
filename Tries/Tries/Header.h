//
//  Header.h
//  Tries
//
//  Created by Daman Saroa on 05/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#ifndef Tries_Header_h
#define Tries_Header_h
#include <vector>
using namespace std;

class node {
    unsigned int prefix_count;
    bool end_word;
    vector <node*> children;
    
public:
    node(): prefix_count(0), end_word(false) , children(26, NULL) {
    }
    
    void increment_prefix_count() {
        prefix_count++;
    }
    void setEndWord() {
        end_word = true;
    }
    bool getEndWord() {
        return end_word;
    }
    unsigned int getPrefixCount() {
        return prefix_count;
    }
    vector<node*> &getChildren() {
        return children;    // vector return by copy hence return by reference
    }
    
};

class Trie {
    node* root;
public:
    Trie() {
        root = new node;
    }
    void insertWord(char *str){
        node* temp = root;
        while (*str != '\0')
        {
            temp->increment_prefix_count();
            vector<node*> &ch = temp->getChildren();
            
            if (ch[*str - 97] == NULL)
            {
                ch[*str - 97] = new node;
            }
            temp = ch[*str-97];
            str++;
        }
        temp->increment_prefix_count();
        temp->setEndWord();
    }
};



































#endif

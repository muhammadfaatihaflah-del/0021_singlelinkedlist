#include<iostream>
#include <string>
using namespace std;

class node{
public:
    int noMhs;
    int *next;
};

class linkedlist{
    node *start;

public:
    linkedlist()
    {
        start = NULL;

    }
    void addnode()
    {
        int nim;
        cout << "n\masukkan nomor mahasiswa : ";
        cin >>nim;

        node *nodebaru = new node;
        nodebaru->noMhs = nim; 

        if (start == NULL || nim <= start ->noMhs)
        {
            
        } 
        }
};

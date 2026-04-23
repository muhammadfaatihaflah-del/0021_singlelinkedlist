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
        cout << "\nmasukkan nomor mahasiswa : ";
        cin >>nim;

        node *nodebaru = new node;
        nodebaru->noMhs = nim; 

        if (start == NULL || nim <= start ->noMhs)
        {
            if (start != NULL && nim == start ->noMhs)
            {
                cout << "\nduplikasi noMhs tidak diijinkan\n";
                return;
            }
            nodebaru->next = start;
            start= nodebaru;
            return;
        } 
        node *previous = start;
        node *current = start;

        while (current != NULL && nim > current -> noMhs)
        {
            if(nim == current ->noMhs)
            {
                cout <<"\n duplikasi noMhs tidak diijinkan";
                return;
            }
            previous = current;
            current = current->next;
        }
        nodebaru->next=current;
        previous->next= nodebaru;
     }
     bool listempty()
};

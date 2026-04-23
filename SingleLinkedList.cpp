#include<iostream>
#include <string>
using namespace std;

class node{
public:
    int noMhs;
    node *next;
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
     {
        return(start == NULL);
     }

     bool search (int nim , node *&previous,node *&current)
     {
        previous=start;
        current=start;

        while (current != NULL && nim != current->noMhs)
        {
            previous=current;
            current=current->next;
        }
        return(current!= NULL);
     }
     bool delnode (int nim)
     {
        node *current ,*previous;

        if (!search (nim,previous,current))
            return false;
        if (current == start)
            start=start->next;
        else    
            previous->next = current->next;
            delete current;
            return true;
     }
     void tranvers()
     {
        if (listempty())
        {
            cout << "\nlist kosong\n";
        }
        else {
            cout << "\ndata didalam list adalah : \n";
            node *currentnode =start;

            while (currentnode != NULL)
            {
                cout<< currentnode ->noMhs <<endl;
                currentnode = currentnode->next;
            }
            cout << endl;
        }
     }
};

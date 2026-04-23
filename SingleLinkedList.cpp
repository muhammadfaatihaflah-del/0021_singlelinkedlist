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
int main()
{
    linkedlist mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Menambah data ke dalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Mencari data dalam list" << endl;
        cout << "5. Keluar" << endl;

        cout << "\nMasukkan pilihan (1-5): ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            mhs.addnode();
            break;

        case '2':
            if (mhs.listempty())
            {
                cout << "\nList Kosong" << endl;
                break;
            }

            cout << "\nMasukkan no mahasiswa yang akan dihapus : ";
            cin >> nim;
            
            if (mhs.delnode(nim) == false)
            cout << "\nData tidak ditemukan" << endl;
            else
                cout << "\nData dengan nomor mahasiswa " << nim << " berhasil dihapus";
            break;

        case '3':
            mhs.tranvers();
            break;

        case '4':
            {
                 if (mhs.listempty())
                {
                    cout << "\nList Kosong\n";
                    break;
                }

                 node *previous, *current;
                 cout << "\nMasukkan no mahasiswa yang dicari : ";
                 cin >> nim;

                 if (mhs.search(nim, previous, current) == false)
                    cout << "\nData tidak ditemukan\n";
                 else
                {
                    cout << "\nData ditemukan\n";
                    cout << "NIM Mahasiswa : " << current->noMhs << endl;
                }
                break;
            }

            case '5':
                break;
            
            default:
                cout << "\nPilihan salah!\n";
        }

    } while (ch != '5');

    return 0;
}
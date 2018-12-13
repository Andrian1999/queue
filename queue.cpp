
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct myLinkedList
{
    string nama, posisi;
    int no;
    myLinkedList *next;
}mylist;

mylist *head; mylist *tail;

void enqueue()
{
    mylist *New;
    New = new mylist;
    cout<<"Nama : "; cin>>New->nama;
    cout<<"no punggung : "; cin>>New->no;
    cout<<"posisi : "; cin>>New->posisi;
    New->next = NULL;
    if (head == NULL)
    {
        head = New;
        tail = New;
    }
    else
    {
        tail->next=New; tail=New;
    }
}
void dequeue()
{
    mylist *bantu; bantu = new mylist;
    mylist *hapus; hapus = new mylist;
    if(head==NULL)
    {
      cout<<"data kosong"<<endl;
    }
    else if(head==tail)
    {
        hapus = head;
        delete hapus;
    }
    hapus = head;
    head = head->next;
    delete hapus;
}
void tampil()
{
    mylist *backup;
    backup = new mylist;
    backup = head;

    while(backup!=NULL)
    {
        cout<<backup->no<<" ==> "<<backup->nama<<" ==> "<<backup->posisi<<endl;
        backup=backup->next;
    }
}

main()
{
    int pil;
    do{
        system("cls");
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Tampil"<<endl;
        cout<<"0. Exit "<<endl;
        cout<<"Pilih :"; cin>>pil;
        switch(pil)
        {
        case 1 : enqueue();
            break;
        case 2 : dequeue();
            break;
        case 3 :if(head==NULL)
                    cout<<"Data Kosong"<<endl;
                else
        tampil(); system("pause");
            break;
        }
    }while(pil!=0);
}

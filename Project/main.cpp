#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "TreeClass.h"


using namespace std;

int main()
{
    //read in the file
    int maincount=0;
    ifstream myfile;
    string word;
    int arrSize=97;
    string arr[arrSize];
    int i=0;
    myfile.open("loclist.txt", ifstream::in);
    while(getline(myfile, word, ';')){
        arr[i]=word;
        maincount++;
        //cout<<mess[i]<<endl;
        i++;
    }
    //creating the trees
    Tree *biz;
    Tree *rez;
    Tree *rest;
    biz=new Tree();
    rez=new Tree();
    rest=new Tree();

    //adding the locations to the correct trees
    for(int j=0;j<arrSize;j+=3){
        arr[i].erase(0,1);
        if(arr[j]=="Business"){
            Location *Broot;
            Broot=biz->getroot();
            maincount++;
            biz->addLocation(Broot, arr[j+1], arr[j+2]);
        }//end biz
        if(arr[j]=="Residential"){
            Location *Rezroot;
            Rezroot=rez->getroot();
            maincount++;
            rez->addLocation(Rezroot, arr[j+1], arr[j+2]);

        }//end rez
        if(arr[j]=="Restaurant"){
            Location *Restroot;
            Restroot=rest->getroot();
            maincount++;
            rest->addLocation(Restroot, arr[j+1], arr[j+2]);
        }//end rest
    }

    //getting the roots
    Fav *Froot;
    Froot=new Fav("Root", "Root");
    maincount++;
    Fav *Fhead;
    Fav *Ftrail;
    Location *Broot;
    Broot=biz->getroot();
    maincount++;
    Location *Rezroot;
    Rezroot=rez->getroot();
    maincount++;
    Location *Restroot;
    Restroot=rest->getroot();
    maincount++;
    cout<<maincount+biz->getOp()+rez->getOp()+rest->getOp()<<endl;
    int q=1;
    while(q==1||q==2||q==3){
            cout<<"What do you want to do?"<<endl<<"[1]Find location"<<endl<<"[2]Open favorites list"<<endl<<"[3]Exit"<<endl;
            cin>>q;
            cout<<endl;
        //for q=1 depending on the type of location it calls the search function for the correct tree and prints the info
        if(q==1){
            int h=0;
            while(h!=1&&h!=2&&h!=3){
                cout<<"What is location type?"<<endl<<"[1]Business"<<endl<<"[2]Residential"<<endl<<"[3]Restaurant"<<endl;
                cin>>h;
                cout<<endl;
            }//end 1 2 3
            string nameIn;
            if(h==1){
                cout<<"What is the name of the Business?"<<endl;
                cin.ignore();
                getline(cin, nameIn);
                cout<<endl;
                Location *result;
                result=biz->search_Title(Broot, nameIn);
                if(result==NULL){
                    cout<<"Location not found"<<endl<<endl;
                }
                else{
                    cout<<result->getName()<<endl<<result->getAddress()<<endl<<endl;
                }
            }//end1
            if(h==2){
                cout<<"What is the name of the Residential?"<<endl;
                cin.ignore();
                getline(cin, nameIn);
                cout<<endl;
                Location *result;
                result=rez->search_Title(Rezroot, nameIn);
                if(result!=NULL){
                    cout<<result->getName()<<endl<<result->getAddress()<<endl<<endl;

                }
                else{
                    cout<<"Location not found"<<endl<<endl;
                }
            }//end2
            if(h==3){
                cout<<"What is the name of the Restaurant?"<<endl;
                cin.ignore();
                getline(cin, nameIn);
                cout<<endl;
                Location *result;
                result=rest->search_Title(Restroot, nameIn);
                if(result==NULL){
                    cout<<"Location not found"<<endl<<endl;
                }
                else{
                    cout<<result->getName()<<endl<<result->getAddress()<<endl<<endl;
                }
            }//end3

        }//endQ1
        if(q==2){
            //for q2 you have the options to print friends list add friends and delete friends
            int e=0;
            while(e!=1&&e!=2&&e!=3){
                cout<<"[1]Print favorites list"<<endl<<"[2]]Add to favorites list"<<endl<<"[3]Delete from favorites list"<<endl;
                cin>>e;
            }

            if(e==1){
                //printing everything in the list
                Fav *Ptemp;
                Ptemp=Froot;
                while(Ptemp->getNext()!=NULL){
                    Ptemp=Ptemp->getNext();
                    cout<<Ptemp->getFName()<<endl<<Ptemp->getFAddress()<<endl<<endl;
                }
            }// end1
            if(e==2){
                    //adding the location by using the search function in the tree class then creating a new node in fav list
                    int h=0;
                    while(h!=1&&h!=2&&h!=3){
                        cout<<"What is location type?"<<endl<<"[1]Business"<<endl<<"[2]Residential"<<endl<<"[3]Restaurant"<<endl;
                        cin>>h;
                        cout<<endl;
                    }//end 1 2 3
                    string nameIn;
                    if(h==1){
                        cout<<"What is the name of the Business?"<<endl;
                        cin.ignore();
                        getline(cin, nameIn);
                        cout<<endl;
                        Location *result;
                        result=biz->search_Title(Broot, nameIn);
                        if(result==NULL){
                            cout<<"Location not found"<<endl<<endl;
                        }
                        else{
                            if(Froot->getNext()==NULL){
                                Fhead=new Fav(result->getName(), result->getAddress());
                                Froot->setNext(Fhead);
                                Fhead->setPrev(Froot);
                                Ftrail=Fhead;
                            }
                            else{
                                Fhead=new Fav(result->getName(), result->getAddress());
                                Ftrail->setNext(Fhead);
                                Fhead->setPrev(Ftrail);
                                Ftrail=Fhead;
                            }
                        }
                    }//end1
                    if(h==2){
                        cout<<"What is the name of the Residential?"<<endl;
                        cin.ignore();
                        getline(cin, nameIn);
                        cout<<endl;
                        Location *result;
                        result=rez->search_Title(Rezroot, nameIn);
                        if(result==NULL){
                            cout<<"Location not found"<<endl<<endl;
                        }
                        else{
                            if(Froot->getNext()==NULL){
                                Fhead=new Fav(result->getName(), result->getAddress());
                                Froot->setNext(Fhead);
                                Fhead->setPrev(Froot);
                                Ftrail=Fhead;
                            }
                            else{
                                Fhead=new Fav(result->getName(), result->getAddress());
                                Ftrail->setNext(Fhead);
                                Fhead->setPrev(Ftrail);
                                Ftrail=Fhead;
                            }
                        }
                    }//end2
                    if(h==3){
                        cout<<"What is the name of the Restaurant?"<<endl;
                        cin.ignore();
                        getline(cin, nameIn);
                        cout<<endl;
                        Location *result;
                        result=rest->search_Title(Restroot, nameIn);
                        if(result==NULL){
                            cout<<"Location not found"<<endl<<endl;
                        }
                        else{
                            if(Froot->getNext()==NULL){
                                Fhead=new Fav(result->getName(), result->getAddress());
                                Froot->setNext(Fhead);
                                Fhead->setPrev(Froot);
                                Ftrail=Fhead;
                            }
                            else{
                                Fhead=new Fav(result->getName(), result->getAddress());
                                Ftrail->setNext(Fhead);
                                Fhead->setPrev(Ftrail);
                                Ftrail=Fhead;
                            }
                        }
                    }//end3


                }//end e2
            if(e==3){
                    //searching through the linked list, resetting the pointers and deleting the node
                    string del;
                    cout<<"What is the name of the location to Delete?"<<endl;
                    cin.ignore();
                    getline(cin, del);
                    cout<<endl;
                    Fav *Stemp;
                    Fav *Stemp2;
                    Stemp=Froot;
                    int con=0;
                    while(con==0&&Stemp->getNext()!=NULL){
                        Stemp=Stemp->getNext();
                        if(Stemp->getFName()==del){
                            con=1;
                            Stemp2=Stemp->getPrev();
                            Stemp2->setNext(Stemp->getNext());
                            if(Stemp->getNext()!=NULL){
                                Stemp2=Stemp->getNext();
                                Stemp2->setPrev(Stemp->getPrev());
                            }
                            cout<<"Location Deleted"<<endl<<endl;
                            delete Stemp;
                        }

                    }
                    if(con==0&&Stemp->getNext()==NULL){
                        con=2;
                        cout<<"Location not found"<<endl<<endl;
                        }
                }

        }//end Q2
        if(q==3){
            //q3 exits the main function
            return 0;
        }



    }
    return 0;



}

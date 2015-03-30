#include <iostream>
#include "TreeClass.h"
#include <string>
using namespace std;

Fav::Fav(string fna, string fa){
    fname=fna;
    faddress=fa;
    Next=NULL;
    Prev=NULL;
}
Fav::~Fav(){
    //deconstructor
}
//getters and setters for fav
void Fav::setNext(Fav *n){
    Next=n;
}

Fav* Fav::getNext(){
    return Next;

}

void Fav::setPrev(Fav *n){
    Prev = n;

}
Fav* Fav::getPrev(){
    return Prev;
}
string Fav::getFName(){
    return fname;
}
string Fav::getFAddress(){
    return faddress;
}

//this is the location class
Location::Location(string na, string a){
    name=na;
    address=a;
    for(int i=0;i<name.length();i++){
        myHash+=name[i];
    }
    leftChild = NULL;
    rightChild = NULL;
    parent = NULL;
}

Location::~Location(){
    cout<<"calling destructor"<<endl;
}
//set and get methods for everything I need
void Location::setLeftChild(Location *n){
    leftChild = n;
}
Location* Location::getLeftChild(){
	return leftChild;
}

void Location::setRightChild(Location *n){
    rightChild = n;
}
Location* Location::getRightChild(){
	return rightChild;
}

void Location::setParent(Location *n){
    parent = n;
}
Location* Location::getParent(){
	return parent;
}
string Location::getName(){
    return name;
}
string Location::getAddress(){
    return address;
}
int Location::getHash(){
    return myHash;
}



//start of the tree class

Tree::Tree(){
    root = NULL;
    operations=0;
}
Tree::~Tree(){
}
//get root Location
Location* Tree::getroot(){
    return root;
}
//get the operations
int Tree::getOp(){
    return operations;
}
//this function is used for the locations that are being added into the tree but have not been created yet
int Tree::getNewHash(string nam){
    int sum=0;
    for(int i=0;i<nam.length();i++){
        sum+=nam[i];
    }
    return sum;
}

//print all Locations in the tree using recursion. used for my own benefit when testing
void Tree::printInventory(Location *f){
    if(f->getLeftChild()!=NULL){
        printInventory(f->getLeftChild());
    }
    if(f->getRightChild()!=NULL){
        printInventory(f->getRightChild());
    }
    cout<<f->getName()<<endl;

}

//if Location title matches then return the pointer
Location* Tree::search_Title(Location *u, string temp){
    if(u->getName()==temp){
        return u;

    }
    else if(u->getLeftChild()!=NULL&&getNewHash(temp)<u->getHash()){
        return search_Title(u->getLeftChild(), temp);
    }
    else if(u->getRightChild()!=NULL&&getNewHash(temp)>=u->getHash()){
        return search_Title(u->getRightChild(), temp);
    }


    return NULL;



}

//count nodes is from previous lab but it works here as well;
int Tree::countnodes_R(Location *h){
    counter++;
    //while there is a left child open the function again
    if(h->getLeftChild()!=NULL){
        countnodes_R(h->getLeftChild());
    }
    //while there is a right child run the function again;
    if(h->getRightChild()!=NULL){
        countnodes_R(h->getRightChild());
    }
    return counter;
}

void Tree::addLocation(Location *c, string na, string a){
        operations++;
        //do we have an empty tree
        Location *n;
        //if this is the first Location then this code will run
        if(root == NULL){
            operations++;
            n = new Location(na, a);

            root = n;
            c=root;
            //cout<<"root added"<<endl;

        }else{
            //if there is a root Location and this Location matches the given parent Location
            if(getNewHash(na)<c->getHash()){
                    //is the left open to add?
                if(c->getLeftChild()==NULL){
                    n=new Location(na, a);
                    operations++;
                    n->setParent(c);
                    operations++;
                    c->setLeftChild(n);
                    //cout<<"Location added"<<endl;
                }
                else{
                    addLocation(c->getLeftChild(), na, a);
                }
            }//end less than
            if(getNewHash(na)>=c->getHash()){
                if(c->getRightChild()==NULL){
                    n=new Location(na, a);
                    operations++;
                    n->setParent(c);
                    operations++;
                    c->setRightChild(n);
                    //cout<<"Location added"<<endl;
                }
                else{
                    addLocation(c->getRightChild(), na, a);
                }
            }
        }
}




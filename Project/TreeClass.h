#ifndef LINKEDLISTEX_H_INCLUDED
#define LINKEDLISTEX_H_INCLUDED

#include <string>

using namespace std;

class Fav{
    private:
    string fname;
    string faddress;
    Fav *Next;
    Fav *Prev;

    public:
        Fav(string fna, string fa);
        ~Fav();
        Fav *getNext();
        void setNext(Fav *n);
        Fav *getPrev();
        void setPrev(Fav *n);
        string getFName();
        string getFAddress();;

};


class Location{
	private:
	string name;
	string address;
	int myHash;
	Location *leftChild;
	Location *rightChild;
	Location *parent;

	public:
	Location(string na, string a);
	~Location();
	Location *getLeftChild();
	void setLeftChild(Location *n);
	Location *getRightChild();
	void setRightChild(Location *p);
	Location *getParent();
	void setParent(Location *p);
	string getName();
	string getAddress();
	int getHash();


};

class Tree{
private:
    Location *root;
    int operations;
    int counter;
    int count2;
public:
    Tree();
    ~Tree();
    int getOp();
    int getNewHash(string nam);
    int countnodes_R(Location *h);
    Location *search_Title(Location *u, string temp);
    void printInventory(Location *f);
    Location *getroot();
    void addLocation(Location *c, string n, string a);
};


#endif // LINKEDLISTEX_H_INCLUDED

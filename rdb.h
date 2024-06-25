//Assignment::3
//Name:Hunny chandra
//Roll no :21CS30024
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<tuple>
#include <algorithm>
using namespace std;
class Attr
{
    // Base class for attributes
    // Add operators for different attribute type in derived classes
public:
    virtual bool operator==(const Attr &right) = 0;

public:
    virtual bool operator!=(const Attr &right) = 0;

public:
    virtual bool operator<(const Attr &right) = 0;

public:
    virtual bool operator>(const Attr &right) = 0;

public:
    virtual bool operator<=(const Attr &right) = 0;

public:
    virtual bool operator>=(const Attr &right) = 0;
};

class integerAttribute : public Attr           //derived class integer Attribute  prototype
{                            
private:
    int value;

public:
    integerAttribute(int i) ;
    bool operator==(const Attr &right) override
   ;
    bool operator!=(const Attr &right) override
   ;
    bool operator>=(const Attr &right) override
   ;
    bool operator<=(const Attr &right) override
    ;
    bool operator>(const Attr &right) override
  ;
    bool operator<(const Attr &right) override
   ;
    int getvalue()
    ;
};
class floatAttribute : public Attr                 //derived class integer Attribute  prototype
{
private:
    float value;

public:
    floatAttribute(float i);
    bool operator==(const Attr &right) override
    ;
    bool operator!=(const Attr &right) override
   ;
    bool operator>=(const Attr &right) override
    ;
       
    
    bool operator<=(const Attr &right) override
    ;
    bool operator>(const Attr &right) override
    ;
    bool operator<(const Attr &right) override
    ;
    float getvalue()
   ;
};
class stringAttribute :public Attr                 //derived class float Attribute  prototype
{
private:
    string value;

public:
    stringAttribute(string s) ;
    bool operator==(const Attr &right) override
    ;
    bool operator>=(const Attr &right) override
    ;
    bool operator<=(const Attr &right) override
    ;
    bool operator>(const Attr &right) override
    ;
    bool operator<(const Attr &right) override
  ;
    bool operator!=(const Attr &right) override;
  
    string getvalue()
   ;
};
class Record                               //derived class string Attribute  prototype
{ // storing data for each record
private:
    vector<Attr *> attrptr;

public:
    void addAttr(Attr *attr) ;
    Attr *getAttr(int index) ;
    int size() const;
    ~Record();
    
    void deleteattr(int index);
 
};
class Relation
{ // storing a relation
private:
    int nattr = 0, nrecs = 0; // number of attributes and records
    vector<string> attrnames; // schema
    vector<string> datatype;  // datatype
    vector<int> attrinds;     // mapping schema to indices
    list<Record *> recs;      // list of records
                              // methods
                              // Relation(int na = 0, int nr = 0) : nattr(na), nrecs(nr) {}
public:
    void addAttrName(string attrname);  
   

    void type(string s);
   
    void addRecord(Record *record);
   
    int getAttrIndex(string attrname) const;
    
    void deleteAttr(string attrname);
    
    void reversedeleteAttr(int c);
   
    void rename(int i, string s2);
    
    Record *getRecord(int index);
    
    void deleterecord(int index);
   
    string gettype(string s);
   

    int size() const;
    int numAttrs() const ;
    vector<string> getAttrNames() const ;
    vector<string> gettypes() const ;
    int reverseindex(string s);
  
    void setAttrIndex();
    
    ~Relation();
    
};
struct DNFformula                    //struct DNFformula datatype
{
    list<list<tuple<string, char, Attr *>>> ops;
};
DNFformula *DNFinput(Relation *R, vector<int> &v);                   //   DNFinput prototype
Relation *union_(Relation *R1, Relation *R2);                   // union_  prototype
Relation *difference(Relation *R1, Relation *R2);                  //difference        prototype
Relation *catersianproduct(Relation *R1, Relation *R2);                  //catersianproduct      prototype
Relation *projection(Relation *R1, list<string> &projectattrs);                  //projection      prototype
Relation *difference(Relation *R1, string s1, string s2);                  //difference(overloaded)      prototype
Relation *union_(Relation *R1, DNFformula *f);                  //union_ (overloaded)      prototype
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> &joinattr);                  //naturaljoin      prototype
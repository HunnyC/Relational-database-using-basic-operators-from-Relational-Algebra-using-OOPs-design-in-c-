//Assignment::3
//Name:Hunny chandra
//Roll no :21CS30024
#include"rdb.h"   // A header file (rdb.h) which has all the Library API.
using namespace std;
// A c++ file (rdb-attr.cpp) with implementations of all supported attribute 
//types.
//

 integerAttribute::integerAttribute(int i) : value(i) {}          //constructor fo interAttribute class
    bool integerAttribute::  operator==(const Attr &right)         //operator == overloading for integerAttribute class               
    {
        return value == dynamic_cast<const integerAttribute &>(right).value;
    }
   bool integerAttribute::  operator!=(const Attr &right)          //operator  !=  overloading for integerAttribute class      
    {
        return value != dynamic_cast<const integerAttribute &>(right).value;
    }
  bool integerAttribute::   operator>=(const Attr &right)         //operator >=overloading for integerAttribute class
    {
        return value >= dynamic_cast<const integerAttribute &>(right).value;
    }
  bool integerAttribute::   operator<=(const Attr &right)         //operator <=overloading for integerAttribute class
    {
        return value <= dynamic_cast<const integerAttribute &>(right).value;
    }
  bool integerAttribute::   operator>(const Attr &right)         //operator >overloading for integerAttribute class
    {         
        return value > dynamic_cast<const integerAttribute &>(right).value;
    }
  bool integerAttribute::   operator<(const Attr &right)         //operator <overloading for integerAttribute class
    {
        return value < dynamic_cast<const integerAttribute &>(right).value;
    }
   int integerAttribute:: getvalue()              //get value function
    {
        return value;
    }


   floatAttribute:: floatAttribute(float i) : value(i) {}  //constructor for floatAttribue class
    bool floatAttribute:: operator==(const Attr &right)             //operator  ==    for float Attribute clas
    {
        return value == dynamic_cast<const floatAttribute &>(right).value;
    }
    bool floatAttribute::operator!=(const Attr &right)            //operator  !=    for float Attribute clas
    {
        return value != dynamic_cast<const floatAttribute &>(right).value;
    }
    bool floatAttribute::operator>=(const Attr &right)            //operator  >=    for float Attribute clas
    {
        return value >= dynamic_cast<const floatAttribute &>(right).value;
    }
    bool floatAttribute::operator<=(const Attr &right)            //operator  <=    for float Attribute clas
    {
        return value <= dynamic_cast<const floatAttribute &>(right).value;
    }
    bool floatAttribute::operator>(const Attr &right)            //operator   >   for float Attribute clas
    {
        return value > dynamic_cast<const floatAttribute &>(right).value;
    }
    bool floatAttribute::operator<(const Attr &right)            //operator   <   for float Attribute clas
    {
        return value < dynamic_cast<const floatAttribute &>(right).value;
    }
    float floatAttribute::getvalue()    //get function 
    {
        return value;
    }


   stringAttribute:: stringAttribute(string s) : value(s) {}  //constructor for stringAttribue class
    bool stringAttribute:: operator==(const Attr &right)             //operator  ==    for stringAttribute class
    {
        return value == dynamic_cast<const stringAttribute &>(right).value;
    }
    bool stringAttribute::operator>=(const Attr &right)             //operator  >=    for stringAttribute class
    {
        return value >= dynamic_cast<const stringAttribute &>(right).value;
    }
    bool stringAttribute::operator<=(const Attr &right)             //operator  <=    for stringAttribute class
    {
        return value <= dynamic_cast<const stringAttribute &>(right).value;
    }
    bool stringAttribute::operator>(const Attr &right)             //operator   >   for stringAttribute class
    {
        return value > dynamic_cast<const stringAttribute &>(right).value;
    }
    bool stringAttribute::operator<(const Attr &right)             //operator  <    for stringAttribute class
    {
        return value < dynamic_cast<const stringAttribute &>(right).value;
    }
    bool stringAttribute::operator!=(const Attr &right)             //operator  !=    for stringAttribute class
    {
        return value != dynamic_cast<const stringAttribute &>(right).value;
    }
    string stringAttribute::getvalue()  //get function
    {
        return value;
    }




    void Record::addAttr(Attr *attr) { attrptr.push_back(attr); }    //addAttribute functio
    Attr *Record::getAttr(int index) { return attrptr[index]; }       //getattr index
    int Record:: size() const { return attrptr.size(); }
   Record:: ~Record()           //deconstructor for record class
    {
        for (auto attr : attrptr)
        {
            delete attr;
        }
    }
    void Record::deleteattr(int index)       //function to delete attribute
    {
        auto it = attrptr.begin() + index;
        attrptr.erase(it);
    }


    void Relation::addAttrName(string attrname) //function to attrname
    {
        attrnames.push_back(attrname);
        nattr++;
    }

    void Relation::type(string s)        //giving type for attribute name
    {
        datatype.push_back(s);
    }
    void Relation::addRecord(Record *record) //add rrcord in relation
    {
        recs.push_back(record);
        nrecs++;
    }
    int Relation::getAttrIndex(string attrname) const      //function to get attribute index
    {
        for (unsigned int i = 0; i < attrnames.size(); i++)
        {
            if (attrnames[i] == attrname)
            {
                return i;
            }
        }
        return -1;
    }
    void Relation::deleteAttr(string attrname)       //function to delete attr
    {
        int c = getAttrIndex(attrname);
        auto it = attrnames.begin() + c;
        attrnames.erase(it);
        auto itr=datatype.begin()+c;
        datatype.erase(itr);
        nattr--;
    }
    void Relation::reversedeleteAttr(int c)     //functon to delete same name attr
    {
        
        auto it = attrnames.begin() + c;
        attrnames.erase(it);
        auto itr=datatype.begin()+c;
        datatype.erase(itr);
        nattr--;
    }
    void Relation::rename(int i, string s2) //helps in renaming
    {
        attrnames[i] = s2;
    }
    Record *Relation::getRecord(int index)    //getrecord function
    {

        auto it = recs.begin();
        advance(it, index);
        return *it;
    }
    void Relation::deleterecord(int index) //deleterecord function
    {
        auto it = recs.begin();
        advance(it, index);
        recs.erase(it);
        nrecs--;
    }
    string Relation::gettype(string s)  //gettype function
    {
        int c = getAttrIndex(s);
        return datatype[c];
    }

    int Relation::size() const { return nrecs; }        //give no of records
    int Relation::numAttrs() const { return nattr; }       //give no of attr
    vector<string> Relation::getAttrNames() const { return attrnames; }  //get attr funtion
    vector<string> Relation::gettypes() const { return datatype; }   //get type func
    int Relation::reverseindex(string s)    //get reverse index of attr for same name attr
    {
        auto it = attrnames.rbegin();
        int k = 0;
        for (; it != attrnames.rend(); it++)
        {
            if (*it == s)
            {
                return attrnames.size() - k - 1;
            }
            k++;
        }
    }
    void Relation::setAttrIndex()      //set attrindex functio
    {
        for (unsigned int i = 0; i < attrnames.size(); i++)
        {
            attrinds.push_back(getAttrIndex(attrnames[i]));
        }
    } 
    Relation::~Relation()         //deconstructor
    {
        for (auto record : recs)
        {
            delete record;
        }
    }

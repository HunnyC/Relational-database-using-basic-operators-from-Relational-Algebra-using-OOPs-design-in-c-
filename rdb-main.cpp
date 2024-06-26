
//Name:Hunny chandra
//Roll no :21CS30024
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <iomanip> 
#include "rdb.h"                  //   A header file (rdb.h) which has all the Library API
using namespace std;
Relation *newrelation()            //creating new relation
{
    Relation *r = new Relation;
    int n, m;
    string attributes, type;
    cout << "ENTER NO. OF ATTRIBUTES " << endl;
    cin >> n;
    cout << "ENTER NO. OF RECORDS" << endl;
    cin >> m;
    cout << "ENTER ATTRIBUTES NAME WITH DATATYPE" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter attribute name:  ";
        cin >> attributes;
        cout << endl;
        r->addAttrName(attributes);
        cout << "Enter type: ";
        cin >> type;
        r->type(type);
        cout << endl;
    }
    vector<Record *> v(m);

    cout << "ENTER RECORDS" << endl;
    auto attrNames = r->getAttrNames();
    auto types = r->gettypes();
    for (int i = 0; i < m; i++)
    {

        v[i] = new Record;
        for (int j = 0; j < n; j++)
        {

            cout << "ENTER"
                 << " " << attrNames[j] << ": " << endl;
            if (types[j] == "i")
            {
                int x;
                cin >> x;
                v[i]->addAttr(new integerAttribute(x));
            }
            else if (types[j] == "f")
            {
                float x;
                cin >> x;
                v[i]->addAttr(new floatAttribute(x));
            }
            else
            {
                string s;
                cin >> s;
                v[i]->addAttr(new stringAttribute(s));
            }
        }
        r->addRecord(v[i]);
    }
    return r;
}
void printRelation(Relation *r)         //Printing relation
{
    // Print attribute names
    auto attrNames = r->getAttrNames();
    for (unsigned int i = 0; i < attrNames.size(); i++)
    {
        cout <<std::setw(15) <<attrNames[i];
        if (i < attrNames.size() - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    // Print records
    for (int i = 0; i < r->size(); i++)
    {
        auto record = r->getRecord(i);
        for (unsigned int j = 0; j < attrNames.size(); j++)
        {
            auto attr = record->getAttr(j);
            integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr);
            floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr);
            stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr);

            if (intAttr)
            {

                cout <<std::setw(15) << intAttr->getvalue();
            }
            else if (floatAttr)
            {
                cout <<std::setw(15) << floatAttr->getvalue();
            }
            else if (stringAttr)
            {
                cout << std::setw(15) <<stringAttr->getvalue();
            }
            if (j < attrNames.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
void func(list<string>&l,vector<string> &v1, vector<string> &v2)
{                                                                          //function to find common attribute

    for (int i = 0; i < v1.size(); i++)
    {
        if (i < v2.size())
        {
            auto it = find(v1.begin(), v1.end(), v2[i]);
            if (it != v1.end())
            {
                l.push_back(*it);
            }
        }
        else
            break;
    }
   
}
void toprint()
{                                                                 //guide manaual
    cout << "FOLLOW GUIDE TO RUN :" << endl;
    cout << "Command to Create Relation: cr" << endl;
    cout << "Command to Exit:e " << endl;
    cout << "Command to see guide:g" << endl;
    cout << "Command to see list:pl " << endl;
    cout << "Command to make union:u" << endl;
    cout << "Command to delete relation:dr " << endl;
    cout << "Command to make difference operation:diff" << endl;
    cout << "Command to make projection operation:pj " << endl;
    cout << "Command to cartesian product operation:cp" << endl;
    cout << "Command to rename attribute:rn " << endl;
    cout << "Command for selection operation:s" << endl;
    cout << "Command to make join operation:nj" << endl;
    cout << "Command to make deleted record:drec" << endl;
    cout << "Command to make deletion of all records:allrec" << endl;
    cout << "Command to make adding records:addrec" << endl;
    cout << "Command to print particular relation of index :pri" << endl;
}

list<Relation *> listrel;
int main()
{
    cout << "*****************************21CS30024(RDMS)**************************** " << endl;
    toprint();
    string s;
    while (1)
    {   
        cin >> s; 
        if (s == "e")                                           //program will exit
        { 
            cout << "Program exit successfully" << endl;
            break;
        }
        else if (s == "cr")                                   //creating new relation
        {
            Relation *r = newrelation();
            printRelation(r);
            listrel.push_back(r);
            cout << "Program saved in List of Relation" << endl;
        }
        else if (s == "g")                                        //giving guide
        {
            cout << '\n';
            toprint();
        }
        else if (s == "pl")
        {
            int i = 0;
            for (auto x : listrel)
            {
                cout << i << endl;
                printRelation(x);
                i++;
            }
        }
        else if (s == "u")                      //union of two relation
        {
            int x, y;
            cout << "SET index from list for union" << endl;
            while (1)
            {

                cout << "Relation first: ";
                cin >> x;
                cout << endl;
                cout << "Relation second: ";
                cin >> y;
                if (x < listrel.size() && y < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            cout << endl;
            auto it = listrel.begin();
            advance(it, x);
            auto itr = listrel.begin();
            advance(itr, y);
            Relation *r = union_(*it, *itr);
            if (r != NULL)
            {
                printRelation(r);
                listrel.push_back(r);
                cout << "union saved in list successfully" << endl;
            }
            else
                cout << "union not possible" << endl;
        }
        else if (s == "dr")                            //deletion of relation from list
        {
            int x;
            cout << "SET index from list for deletion relation" << endl;
            while (1)
            {

                cin >> x;
                if (x < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            auto it = listrel.begin();
            advance(it, x);
            listrel.erase(it);
            cout << "Delete successfully" << endl;
        }

        else if (s == "diff")                       //finding difference of relation
        {
            int x, y;
            cout << "SET index from list for difference operation " << endl;
            while (1)
            {
                cout << "Relation first: ";
                cin >> x;
                cout << endl;
                cout << "Relation second: ";
                cin >> y;
                if (x < listrel.size() && y < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            cout << endl;
            auto it = listrel.begin();
            advance(it, x);
            auto itr = listrel.begin();
            advance(itr, y);
            Relation *r = difference(*it, *itr);
            if (r != NULL)
            {
                printRelation(r);
                listrel.push_back(r);
                cout << "difference  saved in list successfully" << endl;
            }
            else
                cout << "difference Not possible" << endl;
        }
        else if (s == "nj")                                 //natural join
        {
            int x, y;
            cout << "SET index from list for natural join " << endl;
            while (1)
            {

                cout << "Relation first: ";
                cin >> x;
                cout << endl;
                cout << "Relation second: ";
                cin >> y;
                if (x < listrel.size() && y < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            cout << endl;
            auto it = listrel.begin();
            advance(it, x);
            auto itr = listrel.begin();
            advance(itr, y);
            list<string> l;
            vector<string> v1 = (*it)->getAttrNames();
            vector<string> v2 = (*itr)->getAttrNames();
            if (v1.size() > v2.size())
            {
               func(l,v1, v2);
            }
         
            else
            {
                 func(l,v2, v1);
            }
               
            Relation *r = naturaljoin(*it, *itr, l);
            printRelation(r);
            listrel.push_back(r);
            cout << "Naturaljoin  saved in list successfully" << endl;
        }
        else if (s == "pj")                           //projection of relation
        { 
            int x;
            cout << "SET index from list for projection relation" << endl;
            while (1)
            {

                cin >> x;
                if (x < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            auto it = listrel.begin();
            advance(it, x);
            int n = 0;
            cout << "Enter number of projectionattr: " << endl;
            cin >> n;
            vector<string> v = (*it)->getAttrNames();
            for (auto &x : v)
            {
                cout << x << " ";
            }
            cout << endl;
            list<string> l;
            cout << "Enter list of projectionattr: " << endl;
            for (int i = 0; i < n; i++)
            {
                string s;
                cout << i << ": ";
                cin >> s;
                l.push_back(s);
            }
            Relation *r = projection((*it), l);
            printRelation(r);
            listrel.push_back(r);
            cout << "Projection saved in list successfully" << endl;
        }
        else if (s == "cp")         ///cartesian product of relation
        {
            int x, y;
            cout << "SET index from list for cartesianproduct" << endl;
            while (1)
            {

                cout << "Relation first: ";
                cin >> x;
                cout << endl;
                cout << "Relation second: ";
                cin >> y;
                if (x < listrel.size() && y < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            cout << endl;
            auto it = listrel.begin();
            advance(it, x);
            auto itr = listrel.begin();
            advance(itr, y);
            Relation *r = catersianproduct(*it, *itr);
            printRelation(r);
            listrel.push_back(r);
            cout << "Catersianproduct in list successfully" << endl;
        }
        else if (s == "rn")         //rename attribute name
        {
            int x;
            cout << "SET index from list for rename" << endl;
            while (1)
            {

                cin >> x;
                if (x < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            auto it = listrel.begin();
            advance(it, x);
            string s1, s2;
            cout << "ENTER attribute to be renamed:  ";
            cin >> s1;
            cout << "ENTER new name for attribute:  ";
            cin >> s2;
            (*it) = difference((*it), s1, s2);
            printRelation((*it));
            cout << "Renamed successfully" << endl;
        }
        else if (s == "s")                       //selection operatin in relation
        {
            int x;
            cout << "SET index from list for Selection operation" << endl;
            while (1)
            {

                cin >> x;
                if (x < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            auto it = listrel.begin();
            advance(it, x);
            vector<int> v;
            int i = 1;
            cout << "ENTER SIZES OF LISTS AND PRESS 0 AFTER INPUTING to break loop" << endl;
            while (i)
            {
                cout << "List 1 size:  ";
                cin >> i;
                if (i == 0)
                {
                    break;
                }
                v.push_back(i);
            }
            DNFformula *f = DNFinput((*it), v);
            Relation *r = union_(*it, f);
            printRelation(r);
            listrel.push_back(r);
            cout << "Selection  saved in list successfully" << endl;
        }
        else if (s == "drec")             //deleting a record
        {
            int x;
            cout << "SET index from list for deleting records" << endl;
            while (1)
            {

                cin >> x;
                if (x < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            auto it = listrel.begin();
            advance(it, x);
            cout << "Enter index of record to be deleted :  ";
            cin >> x;
            (*it)->deleterecord(x);
            printRelation(*it);
            cout << "Record deleted successfully" << endl;
        }
        else if (s == "allrec")         //deleting all records

        {
            int x;
            cout << "SET index from list for deletion all records" << endl;
            while (1)
            {

                cin >> x;
                if (x < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            auto it = listrel.begin();
            advance(it, x);
            x = (*it)->size();
            for (int i = 0; i < x; i++)
            {
                (*it)->deleterecord(0);
            }
            printRelation(*it);
            cout << "All records deleted successfully" << endl;
        }
        else if (s == "addrec")            //add record in relation
        {
            int x;
            cout << "SET index from list for adding records" << endl;
            while (1)
            {

                cin >> x;
                if (x < listrel.size())
                    break;
                else
                    cout << "Enter valid index" << endl;
            }
            auto it = listrel.begin();
            advance(it, x);
            Record *r = new Record;
            auto v = (*it)->gettypes();
            auto v1 = (*it)->getAttrNames();
            for (int i = 0; i < (*it)->numAttrs(); i++)
            {
                if (v[i] == "i")
                {
                    cout << "Enter" << v1[i] << ": ";
                    int x;
                    cin >> x;
                    r->addAttr(new integerAttribute(x));
                }
                else if (v[i] == "i")
                {
                    cout << "Enter" << v1[i] << ": ";
                    float x;
                    cin >> x;
                    r->addAttr(new floatAttribute(x));
                }
                else
                {
                    cout << "Enter" << v1[i] << ": ";
                    string x;
                    cin >> x;
                    r->addAttr(new stringAttribute(x));
                }
            }
            (*it)->addRecord(r);
            printRelation(*it);
            cout << "Record added successfully" << endl;
        }
        else if (s == "pri")           //printing particular index of relation from list
        {
            cout << "Enter index of relation:" << endl;
            int c;
            cin >> c;
            auto it = listrel.begin();
            advance(it, c);
            printRelation(*it);
            cout << endl;
        }

        else
        {
            cout << "INVALID COMMAND" << endl;
            cout << "ENTER VALID  " << endl;
            cout<<"type g to see guide"<<endl;
           
        }
    }
}
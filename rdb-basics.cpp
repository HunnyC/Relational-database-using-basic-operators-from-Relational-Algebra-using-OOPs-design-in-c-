//Assignment::3
//Name:Hunny chandra
//Roll no :21CS30024
#include"rdb.h"   //   A header file (rdb.h) which has all the Library API

using namespace std;

//A c++ file (rdb-basics.cpp) with implementations of all the basic operators
DNFformula *DNFinput(Relation *R, vector<int> &v)                //function for inputs for DNFORMULA TYPE
{
    DNFformula *p = new DNFformula;
    string s;
    char c;
    list<tuple<string, char, Attr *>> l;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<"LIST "<<i+1<<endl;
        for (int j = 0; j < v[i]; j++)
        {

            cout << "ENTER STRING:  ";
            cin >> s;
            cout << endl;
            cout << "ENTER SYMBOL: ";
            cin >> c;
            cout << endl;
            cout << "ENTER attr: ";

            if (R->gettype(s) == "i")
            {

                int a;
                cin >> a;

                l.push_back({s, c, new integerAttribute(a)});
            }
            else if (R->gettype(s) == "f")
            {
                float f;
                cin >> f;
                l.push_back({s, c, new floatAttribute(f)});
            }
            else
            {
                string a;
                cin >> a;

                l.push_back({s, c, new stringAttribute(a)});
            }
        }
        p->ops.push_back(l);
        l.clear();
    }
    return p;
}
bool search(Relation *R, Record *r)            ///fuction to search record in relation
{

    int c = 0;
    int flag = 1;
    vector<string> x = R->gettypes();

    for (int i = 0; i < R->size(); i++)
    {
        auto s = R->getRecord(i);

        c = 0;
        flag = 1;
        for (int j = 0; j < R->numAttrs(); j++)
        {

            if (flag == 1)
            {

                if (x[j] == "i")
                {

                    auto attr = s->getAttr(j);

                    auto i2 = dynamic_cast<integerAttribute *>(r->getAttr(j));
                    auto i1 = dynamic_cast<integerAttribute *>(attr);

                    if (i1->getvalue() == i2->getvalue())
                        c++;
                    else
                        flag = 0;
                }

                else if (x[j] == "f")
                {
                    floatAttribute *i1 = dynamic_cast<floatAttribute *>(s->getAttr(j));
                    auto i2 = dynamic_cast<floatAttribute *>(r->getAttr(j));

                    if (i1->getvalue() == i2->getvalue())
                        c++;
                    else
                        flag = 0;
                }
                else
                {

                    stringAttribute *i1 = dynamic_cast<stringAttribute *>(s->getAttr(j));

                    auto i2 = dynamic_cast<stringAttribute *>(r->getAttr(j));

                    if (i1->getvalue() == i2->getvalue())
                    {
                        c++;
                    }
                    else
                        flag = 0;
                }
            }
            else
                break;
        }
        if (c == R->numAttrs())
            return 0;
    }
    return 1;
}
Record *copyrecord(Record *p, vector<string> v)         //fuction to cop record
{

    Record *r = new Record;
    for (int i = 0; i < v.size(); i++)
    {

        if (v[i] == "i")
        {

            r->addAttr(new integerAttribute(dynamic_cast<integerAttribute *>(p->getAttr(i))->getvalue()));
        }
        else if (v[i] == "f")
        {
            r->addAttr(new floatAttribute(dynamic_cast<floatAttribute *>(p->getAttr(i))->getvalue()));
        }
        else
        {

            // cout<<dynamic_cast<stringAttribute *>(p->getAttr(i))<<endl;
            r->addAttr(new stringAttribute(dynamic_cast<stringAttribute *>(p->getAttr(i))->getvalue()));
        }
    }
    return r;
}
Relation *union_(Relation *R1, Relation *R2)           //union operation function
{
    int flag = 0;
    if (R1->numAttrs() != R2->numAttrs())
    { 
      
        return NULL;
    }

    else

    {

        auto R1_ = R1->getAttrNames();
        auto r=R2->getAttrNames();
        for (int i = 0; i < R1_.size(); i++)
        {
            int d = R2->getAttrIndex(R1_[i]);
            if(R1_[i]!=r[i])return NULL;
            if (d == -1)
                return NULL;
        }
        flag = 1;
       
    }
    if (flag == 1)
    {

        Relation *newrel = new Relation;
        auto vi = R1->getAttrNames();
        for (int i = 0; i < R1->numAttrs(); i++)
        {
            newrel->addAttrName(vi[i]);
        }
        vector<Record *> v(R1->size() + R2->size());
        /*for(int i=0;i<v.size();i++)
        {
          v[i]= new Record;}*/

        if (R1->size() > R2->size())
        {

            int j = 0;
            for (j = 0; j < R1->size(); j++)
            {
                v[j] = new Record;
                Record *r = R1->getRecord(j);
                for (int i = 0; i < R1->numAttrs(); i++)
                {
                    auto attr = r->getAttr(i);

                    if (integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr))
                    {

                        v[j]->addAttr(new integerAttribute(intAttr->getvalue()));
                    }
                    else if (floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr))
                    {

                        v[j]->addAttr(new floatAttribute(floatAttr->getvalue()));
                    }
                    else if (stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr))
                    {

                        v[j]->addAttr(new stringAttribute(stringAttr->getvalue()));
                    }
                }
                newrel->addRecord(v[j]);
            }

            for (int i = 0; i < R2->size(); i++)
            {

                Record *r = R2->getRecord(i);
                if (search(R1, R2->getRecord(i)))
                {

                    v[j] = new Record;
                    for (int k = 0; k < R1->numAttrs(); k++)
                    {

                        auto attr = r->getAttr(k);

                        if (integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr))
                        {

                            v[j]->addAttr(new integerAttribute(intAttr->getvalue()));
                        }
                        else if (floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr))
                        {

                            v[j]->addAttr(new floatAttribute(floatAttr->getvalue()));
                        }
                        else if (stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr))
                        {

                            v[j]->addAttr(new stringAttribute(stringAttr->getvalue()));
                        }
                    }

                    newrel->addRecord(v[j]);
                    j++;
                }
            }
            return newrel;
        }
        else
        {
            int j = 0;
            for (j = 0; j < R2->size(); j++)
            {
                v[j] = new Record;
                Record *r = R2->getRecord(j);
                for (int i = 0; i < R2->numAttrs(); i++)
                {
                    auto attr = r->getAttr(i);

                    if (integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr))
                    {

                        v[j]->addAttr(new integerAttribute(intAttr->getvalue()));
                    }
                    else if (floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr))
                    {

                        v[j]->addAttr(new floatAttribute(floatAttr->getvalue()));
                    }
                    else if (stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr))
                    {

                        v[j]->addAttr(new stringAttribute(stringAttr->getvalue()));
                    }
                }
                newrel->addRecord(v[j]);
            }

            for (int i = 0; i < R1->size(); i++)
            {
                v[j] = new Record;
                Record *r = R1->getRecord(i);

                if (search(R2, r))
                {

                    for (int k = 0; k < R2->numAttrs(); k++)
                    {

                        auto attr = r->getAttr(k);

                        if (integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr))
                        {

                            v[j]->addAttr(new integerAttribute(intAttr->getvalue()));
                        }
                        else if (floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr))
                        {

                            v[j]->addAttr(new floatAttribute(floatAttr->getvalue()));
                        }
                        else if (stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr))
                        {

                            v[j]->addAttr(new stringAttribute(stringAttr->getvalue()));
                        }
                    }

                    newrel->addRecord(v[j]);
                    j++;
                }
            }
            return newrel;
        }
    }
}
Relation *difference(Relation *R1, Relation *R2)        ///difference operation function
{
    int flag = 0;
    if (R1->numAttrs() != R2->numAttrs())
        return NULL;

    else

    {

        auto R1_ = R1->getAttrNames();
        for (int i = 0; i < R1_.size(); i++)
        {
            int d = R2->getAttrIndex(R1_[i]);
            if (d == -1)
                return NULL;
        }
        flag = 1;
    }
    if (flag == 1)
    {
        int k = 0;
        Relation *newrel = new Relation;
        auto vi = R1->getAttrNames();
        for (int i = 0; i < R1->numAttrs(); i++)
        {
            newrel->addAttrName(vi[i]);
        }
        vector<Record *> v(R1->size());
        for (int j = 0; j < R1->size(); j++)
        {
            v[k] = new Record;
            Record *r = R1->getRecord(j);
            if (search(R2, r))
            {
                for (int i = 0; i < R1->numAttrs(); i++)
                {
                    auto attr = r->getAttr(i);

                    if (integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr))
                    {

                        v[k]->addAttr(new integerAttribute(intAttr->getvalue()));
                    }
                    else if (floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr))
                    {

                        v[k]->addAttr(new floatAttribute(floatAttr->getvalue()));
                    }
                    else if (stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr))
                    {

                        v[k]->addAttr(new stringAttribute(stringAttr->getvalue()));
                    }
                }
                newrel->addRecord(v[k]);
                k++;
            }
        }
        return newrel;
    }
}
Relation *catersianproduct(Relation *R1, Relation *R2)  //cartesian product function
{
    Relation *newrel = new Relation;
    int k = 0;
    auto vi = R1->getAttrNames();
    auto q = R1->gettypes();

    for (int i = 0; i < R1->numAttrs(); i++)
    {
        newrel->addAttrName(vi[i]);
        newrel->type(q[i]);
    }
    auto vii = R2->getAttrNames();

    auto q1 = R2->gettypes();

    for (int i = 0; i < R2->numAttrs(); i++)
    {
        newrel->addAttrName(vii[i]);
        newrel->type(q1[i]);
    }

    vector<Record *> v((R1->size()) * (R2->size()));
    for (int i = 0; i < R1->size(); i++)
    {
        auto r = R1->getRecord(i);

        for (int j = 0; j < R2->size(); j++)
        {
            auto z = R2->getRecord(j);

            v[k] = copyrecord(r, q);

            for (int a = 0; a < R2->numAttrs(); a++)
            {

                auto attr = z->getAttr(a);

                if (integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr))
                {

                    v[k]->addAttr(new integerAttribute(intAttr->getvalue()));
                }
                else if (floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr))
                {

                    v[k]->addAttr(new floatAttribute(floatAttr->getvalue()));
                }
                else
                {
                    stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr);
                    v[k]->addAttr(new stringAttribute(stringAttr->getvalue()));
                }
            }
            newrel->addRecord(v[k]);

            k++;
        }
    }
    return newrel;
}
Relation *projection(Relation *R1, list<string> &projectattrs)     ///projection function for projectin operation
{
    Relation *newrel = new Relation;
    auto itr = projectattrs.begin();
    vector<string> x = R1->gettypes();
    vector<string> y = R1->getAttrNames();

    for (int i = 0; itr != projectattrs.end();)
    {

        if (*itr == y[i])
        {

            newrel->addAttrName(*itr);
            newrel->type(x[i]);
            itr++;
        }
        i++;
    }
 
    auto s = R1->getAttrNames();
    auto a = R1->gettypes();
    vector<Record *> v(R1->size());
 
    for (int j = 0; j < R1->size(); j++)
    {
        v[j] = new Record;
        Record *r = R1->getRecord(j);
        for (int i = 0; i < R1->numAttrs(); i++)
        {
            auto it = find(projectattrs.begin(), projectattrs.end(), s[i]);
            if (it != projectattrs.end())
            {   
                   
                auto attr = r->getAttr(i);

                if (a[i] == "i")
                {
                    integerAttribute *intAttr = dynamic_cast<integerAttribute *>(attr);
                    v[j]->addAttr(new integerAttribute(intAttr->getvalue()));
                }
                else if (a[i] == "f")
                {
                    floatAttribute *floatAttr = dynamic_cast<floatAttribute *>(attr);
                    v[j]->addAttr(new floatAttribute(floatAttr->getvalue()));
                }
                else if (a[i] == "s")
                {
                    stringAttribute *stringAttr = dynamic_cast<stringAttribute *>(attr);
                    v[j]->addAttr(new stringAttribute(stringAttr->getvalue()));
                }
            }
        }
        if (j)
        {
            

            if (search(newrel, v[j]))
            {
                newrel->addRecord(v[j]);
               
            }
        }
        else
        {

            newrel->addRecord(v[j]);
            // printRelation(newrel);
           
        }
    }

    return newrel;
}
Relation *difference(Relation *R1, string s1, string s2)    //difference function for rename operation
{
    int i = R1->getAttrIndex(s1);
    if(i!=-1){
    R1->rename(i, s2);
    return R1;}
    else 
    {    
        cout<<"attribute not present"<<endl;
        return R1;
    }
}
bool check(Relation *R, Record *r, tuple<string, char, Attr *> t)  //function to check if tuple is present or not in given record of given relation
{

    string s = R->gettype(get<0>(t));
    int i = R->getAttrIndex(get<0>(t));
    auto a = r->getAttr(i);
    if (get<1>(t) == '=')
    {

        if (s == "i")
        {
            if (dynamic_cast<integerAttribute *>(get<2>(t))->getvalue() == dynamic_cast<integerAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
        else if (s == "f")
        {
            if (dynamic_cast<floatAttribute *>(get<2>(t))->getvalue() == dynamic_cast<floatAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
        else
        {
            if (dynamic_cast<stringAttribute *>(get<2>(t))->getvalue() == dynamic_cast<stringAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
    }
    else if (get<1>(t) == '>')
    {

        if (s == "i")
        {
            if (dynamic_cast<integerAttribute *>(get<2>(t))->getvalue() > dynamic_cast<integerAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
        else if (s == "f")
        {
            if (dynamic_cast<floatAttribute *>(get<2>(t))->getvalue() > dynamic_cast<floatAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
        else
        {
            if (dynamic_cast<stringAttribute *>(get<2>(t))->getvalue() > dynamic_cast<stringAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
    }
    else
    {

        if (s == "i")
        {
            if (dynamic_cast<integerAttribute *>(get<2>(t))->getvalue() < dynamic_cast<integerAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
        else if (s == "f")
        {
            if (dynamic_cast<floatAttribute *>(get<2>(t))->getvalue() < dynamic_cast<floatAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
        else
        {
            if (dynamic_cast<stringAttribute *>(get<2>(t))->getvalue() < dynamic_cast<stringAttribute *>(a)->getvalue())
                return 1;
            else
                return 0;
        }
    }
}
Relation *selection(Relation *R, Relation *r, list<tuple<string, char, Attr *>> p) 
   ////selection function checks if   record satisfy list of tuple 
{

    auto it = p.begin();
    for (int i = 0; i < R->size(); i++)
    {
        int k = 0;
        auto re = R->getRecord(i);
        for (it = p.begin(); it != p.end(); it++)
        {
            if (check(R, re, *it))
            {

                k++;
            }
            else
                break;
        }

        if (k == p.size() && r->size() == 0)
        {
            auto v = R->getAttrNames();
            auto v2 = R->gettypes();
            for (int i = 0; i < R->numAttrs(); i++)
            {
                r->addAttrName(v[i]);
                r->type(v2[i]);
            }
            auto newr = copyrecord(re, v2);
            r->addRecord(newr);
        }
        else
        {
            if (k == p.size() && r->size() > 0)
            {

                if (search(r, re))
                {
                    auto newr = copyrecord(re, R->gettypes());

                    r->addRecord(newr);
                }
            }
        }
    }
    return r;
}
Relation *union_(Relation *R1, DNFformula *f)        //union_function for selection operation

{

    Relation *newrel = new Relation;
    auto it = f->ops.begin();

    for (; it != f->ops.end(); it++)
    {
        newrel = selection(R1, newrel, *it);
    }
    return newrel;
}
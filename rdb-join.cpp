//Assignment::3
//Name:Hunny chandra
//Roll no :21CS30024
#include"rdb.h"   //   A header file (rdb.h) which has all the Library API
using namespace std;
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> &joinattr)
{
    Relation *R = catersianproduct(R1, R2);                   //natural join operation function

    auto it = joinattr.begin();
                                                                 // A c++ file (rdb-join.cpp) with implementation of the join operation.
    for (int i = 0; i < R->size();)
    {
        int flag = 1;
        auto r = R->getRecord(i);
        for (it = joinattr.begin(); it != joinattr.end(); it++)
        {

            int c = R->getAttrIndex(*it);

            int k = R->reverseindex(*it);

            string s = R->gettype(*it);

            if (s == "i")
            {
                if (dynamic_cast<integerAttribute *>(r->getAttr(c))->getvalue() != dynamic_cast<integerAttribute *>(r->getAttr(k))->getvalue())
                    flag = 0;
            }
            else if (s == "f")
            {
                if (dynamic_cast<floatAttribute *>(r->getAttr(c))->getvalue() != dynamic_cast<floatAttribute *>(r->getAttr(k))->getvalue())
                    flag = 0;
            }
            else
            {
                if (dynamic_cast<stringAttribute *>(r->getAttr(c))->getvalue() != dynamic_cast<stringAttribute *>(r->getAttr(k))->getvalue())
                    flag = 0;
            }

            if (flag == 0)
            {

                R->deleterecord(i);

                break;
            }
        }
        if (flag == 1)
        {
            i++;
        }
    }
  cout<<endl;
  
    for (auto it = joinattr.begin(); it != joinattr.end(); it++)
    {
        int k = R->reverseindex(*it);
   
        for (int i = 0; i < R->size(); i++)
        {

            auto r = R->getRecord(i);
            r->deleteattr(k);
        }
        R->reversedeleteAttr(k);
    }
    return R;
}
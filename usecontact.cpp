#include<bits/stdc++.h>
#include"contact_book.h"
using namespace std;
int main()
{ contact_book list1;
    list1.add("qwerty","worry","+911234567890");
    list1.add("qwert","woryynot","+911234567890");
    list1.add("qwer","worrryyyy","+911234567890");
    list1.add("qwertyy","worryyyyyy","+911244567890");
    if(!list1.add("qwereee","list","12fj"))
    cout<<"Invalid Phone No.\n";
    vector<contact>ans=list1.pre_search("+91123",3);
    cout<<"Total Res:"<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
    cout<<i+1<<". First Name: "<<ans[i].first_name<<", Last Name: "<<ans[i].last_name<<", Phone Number: "<<ans[i].phone_no<<endl;
    }
    vector<contact>ans1=list1.exact_search("+911244567890",3);
    cout<<"Total Res:"<<ans1.size()<<endl;
    for(int i=0;i<ans1.size();i++)
    {
    cout<<i+1<<". First Name: "<<ans1[i].first_name<<", Last Name: "<<ans1[i].last_name<<", Phone Number: "<<ans1[i].phone_no<<endl;
    }
return 0;
}

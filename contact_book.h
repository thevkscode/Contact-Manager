#include<vector>
#include<string>
#include<iostream>
using namespace std;
class contact{
    public:
    string first_name;
    string last_name;
    string phone_no;
    contact(string fname,string lname,string phone)
    {
        this->first_name=fname;
        this->last_name=lname;
        this->phone_no=phone;
    }
};
class contact_book{
    vector<contact> contact_list;
    public:
    bool add(string,string,string);
     vector<contact> pre_search(string,int); //for partial search
     vector<contact> exact_search(string,int);//for exact search
};
bool contact_book::add(string fname,string lname,string phone)
{
    contact c(fname,lname,phone);
    if(phone[0]!='+'||phone.size()<12||phone.size()>13)
    {
            return false;
    }
    for(int i=1;i<phone.size();i++)
    {
        if(phone[i]>'9'||phone[i]<'0')
        {
            return false;
        }
    }
    contact_list.push_back(c);
    return 1;
}
vector<contact> contact_book::exact_search(string s,int type)
{
    vector<contact>ans;
    //type:1:-first name search
    //type:2:-last name search
    //type:3-phone number search
    transform(s.begin(), s.end(), s.begin(), ::tolower);
int n=contact_list.size();
for(int i=0;i<n;i++)
{
    contact curr=contact_list[i];
    transform(curr.first_name.begin(), curr.first_name.end(), curr.first_name.begin(), ::tolower);
    transform(curr.last_name.begin(), curr.last_name.end(), curr.last_name.begin(), ::tolower);
    if(type==1&&curr.first_name==s||type==2&&curr.last_name==s||type==3&&curr.phone_no==s)
    {
        ans.push_back(curr);
    }
}
return ans;
}
bool compare_string(string given,string required)
{
    transform(given.begin(), given.end(), given.begin(), ::tolower);
    transform(required.begin(), required.end(), required.begin(), ::tolower);
    if(required.size()>given.size())
    return false;
    for(int i=0;i<required.size();i++)
    {
        if(given[i]!=required[i])
        return false;
    }
    return true;
}
vector<contact> contact_book::pre_search(string s,int type)
{
    //type:1:-first name search
    //type:2:-last name search
    //type:3-phone number search
 vector<contact> ans;  
    int n=contact_list.size();
for(int i=0;i<n;i++)
{
    contact curr=contact_list[i];
    transform(curr.first_name.begin(), curr.first_name.end(), curr.first_name.begin(), ::tolower);
    transform(curr.last_name.begin(), curr.last_name.end(), curr.last_name.begin(), ::tolower);
    if(type==1&&compare_string(curr.first_name,s)||type==2&&compare_string(curr.last_name,s)||type==3&&compare_string(curr.phone_no,s))
    ans.push_back(curr);
}
return ans;
}
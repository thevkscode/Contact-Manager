#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
// contact entitiy
class contact
{
public:
    string first_name;
    string last_name;
    string phone;
    contact(string fname, string lname, string phone)
    {
        this->first_name = fname;
        this->last_name = lname;
        this->phone = phone;
    }
};
// trie class
class TrieNode
{
public:
    TrieNode *children[26];
    bool ending_here;
    vector<contact> contacts_till_here;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        ending_here = false;
    }
};
// phonebook
class contact_book
{
    TrieNode *first = new TrieNode();
    TrieNode *last = new TrieNode();
    TrieNode *phone_no = new TrieNode();
    void insert_trie(string, TrieNode *, contact, bool);
    vector<contact> bfs_search(TrieNode *);
    vector<contact> exact_search(string, int);
    vector<contact> pre_search(string, int);
    string mssg = "";
    bool isValidNumber(string);
    bool isValidString(string);

public:
    bool insert(string, string, string);
    vector<contact> search(string, int, int);
    string message() { return mssg; }
};
vector<contact> contact_book::search(string key, int type, int search_type)
{
    // searchtype=1:-exact search
    // searchtype=2:-partial search

    // type=1: first name search
    // type=2: last name search
    // type=3: phone number search
    if (search_type == 1)
    {
        return exact_search(key, type);
    }
    else if (search_type == 2)
    {
        return pre_search(key, type);
    }
}
void contact_book::insert_trie(string key, TrieNode *root, contact c, bool isPhone)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    int size = key.size();
    TrieNode *temp = root;
    char ch;
    int i = 0;
    if (!isPhone)
        ch = 'a';
    else
    {
        ch = '0';
        i = 1;
    }

    for (; i < key.size(); i++)
    {
        int index = key[i] - ch;
        if (temp->children[index] == NULL)
        {
            TrieNode *node = new TrieNode();
            temp->children[index] = node;
        }
        if (i == size - 1)
        {
            temp->ending_here = true;
            temp->contacts_till_here.push_back(c);
        }
        temp = temp->children[index];
    }
}
bool contact_book::isValidNumber(string phone)
{
    if (phone[0] != '+' || phone.size() < 8 || phone.size() > 16)
        return false;
    for (int i = 1; i < phone.size(); i++)
    {
        if (phone[i] < '0' || phone[i] > '9')
            return false;
    }
    return true;
}
bool contact_book::isValidString(string str)
{
    if (str == "")
        return false;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'))
            return false;
    }
    return true;
}
bool contact_book::insert(string fname, string lname, string phone)
{
    if (!isValidNumber(phone))
    {
        mssg = "Invalid phone number of Last Input";
        return false;
    }
    if (isValidString(fname) == false || isValidString(lname) == false)
    {
        mssg = "invalid input";
        return false;
    }
    mssg = "Last Input Inserted Successfully";
    contact c(fname, lname, phone);
    insert_trie(fname, first, c, false);
    insert_trie(lname, last, c, false);
    insert_trie(phone, phone_no, c, true);
    // cout << fname << " " << lname << " " << phone << endl;
    return true;
}
vector<contact> contact_book::exact_search(string key, int type)
{
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    int size = key.size();
    TrieNode *temp = first;
    char ch = 'a';
    if (type == 2)
        temp = last;
    else if (type == 3)
    {
        temp = phone_no;
        ch = '0';
    }
    vector<contact> result;
    for (int i = 0; i < size; i++)
    {
        if (type == 3 && i == 0)
            continue;
        int index = key[i] - ch;
        if (!temp->children[index])
            break;
        if (i == size - 1)
        {
            if (temp->ending_here)
            {
                result = temp->contacts_till_here;
            }
        }
        temp = temp->children[index];
    }
    return result;
}
vector<contact> contact_book::bfs_search(TrieNode *root)
{
    vector<contact> res;
    TrieNode *temp = root;
    queue<TrieNode *> q;
    if (!root)
        return res;
    q.push(root);
    while (!q.empty())
    {
        TrieNode *front = q.front();
        if (front->ending_here)
        {
            int size = front->contacts_till_here.size();
            for (int i = 0; i < size; i++)
            {
                res.push_back(front->contacts_till_here[i]);
            }
        }
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            if (front->children[i])
                q.push(front->children[i]);
        }
    }
    return res;
}
vector<contact> contact_book::pre_search(string key, int type)
{
    char ch = 'a';
    int i = 0;
    vector<contact> result;
    TrieNode *temp = first;
    if (type == 2)
        temp = last;
    else if (type == 3)
    {
        temp = phone_no;
        ch = '0';
        i = 1;
    }
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    int size = key.size();
    TrieNode *root = temp;
    for (; i < key.size(); i++)
    {
        int index = key[i] - ch;
        if (temp->children[index] == NULL)
        {
            break;
        }
        temp = temp->children[index];
        if (i == size - 1)
            root = temp;
    }
    result = bfs_search(root);
    return result;
}
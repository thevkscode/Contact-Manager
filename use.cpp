#include <bits/stdc++.h>
#include <fstream>
#include "contactbook.h"
using namespace std;
int main()
{
    contact_book phone_book;
    int option;
    do
    {
        cout << "0 to exit\n";
        cout << "1.add using csv file\n";
        cout << "2.add contact details one by one\n";
        cout << "3.search\n";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            ifstream contactfile;
            contactfile.open("vvv.csv");
            while (contactfile.good())
            {
                string fname, lname, phone;
                getline(contactfile, fname, ',');
                getline(contactfile, lname, ',');
                getline(contactfile, phone, '\n');
                cout << fname << " " << lname << " " << phone << endl;
                phone_book.insert(fname, lname, phone);
                cout << phone_book.message() << endl;
            }
            contactfile.close();
            break;
        }
        case 2:
        {
            string fname, lname, phone;
            cout << "insert first name,last name,phone number\n";
            cin >> fname >> lname >> phone;
            phone_book.insert(fname, lname, phone);
            break;
        }
        case 3:
        {
            int search_type;
            int type;
            cout << "Press 1 to for exact search\n";
            cout << "Press 2 to for partial search\n";
            cin >> search_type;
            cout << "Press 1 to for first name search\n";
            cout << "Press 2 to for last name search search\n";
            cout << "Press 3 to for phone number search\n";
            cin >> type;
            string req;
            cout << "enter the value to search\n";
            cin >> req;
            vector<contact> ans = phone_book.search(req, type, search_type);
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i].first_name << " " << ans[i].last_name << " " << ans[i].phone << endl;
            }
            break;
        }
        default:
            break;
        }
    } while (option != 0);
}
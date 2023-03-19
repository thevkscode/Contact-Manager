/**
 * Name:Vivek Kumar Singh
 * Email:singhvivek02099@gmail.com
 */
/*This is file is to test the contact book which allows to read file from storage and perform the operations*/
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
        cout << "Kindly Press" << endl;
        cout << "0 to exit\n";
        cout << "1 to add using csv file\n";
        cout << "2 to add contact details one by one\n";
        cout << "3 to search\n";
        cout << "4 to View All Contact\n";
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
            cout << endl;
            cout << "Press 1 to for first name search\n";
            cout << "Press 2 to for last name search search\n";
            cout << "Press 3 to for phone number search\n";
            cin >> type;
            cout << endl;
            string req;
            cout << "enter the value to search\n";
            cin >> req;
            cout << endl;
            vector<contact> ans = phone_book.search(req, type, search_type);
            if (ans.size() > 0)
            {
                cout << "Match found!" << endl;
                cout << "Total count: ";
                cout << ans.size() << endl;
                for (int i = 0; i < ans.size(); i++)
                {
                    cout << i + 1 << ". " << ans[i].first_name << " " << ans[i].last_name << " " << ans[i].phone << endl;
                }
                cout << endl;
            }
            else
            {
                cout << "No Match Found!" << endl;
            }
            break;
        }
        case 4:
        {
            vector<contact> ans = phone_book.getList();
            cout << "Total Contacts Found: " << ans.size();
            cout << endl;
            for (int i = 0; i < ans.size(); i++)
            {
                cout << i + 1 << ". " << ans[i].first_name << " " << ans[i].last_name << " " << ans[i].phone << endl;
            }
            cout << endl;
            break;
        }
        default:
            break;
        }
        cout << endl;
    } while (option != 0);
}
/**
 * Name:Vivek Kumar Singh
 * Email:singhvivek02099@gmail.com
 */
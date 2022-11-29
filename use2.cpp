#include <bits/stdc++.h>
#include <fstream>
#include "contactbook.h"
using namespace std;
int main()
{
    contact_book x;
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("fsadfas", "Caldarera", "+91346783468");
    x.insert("Kiafsley", "Caldarera", "+91346783468");
    x.insert("aafds", "afdsasfd", "+91346783468");
    x.insert("vcxzczx", "fdsfdsa", "+91346783468");
    x.insert("zvxc", "Caldarera", "+91346783468");
    x.insert("zcxvzc", "vczxvz", "+91346783468");
    x.insert("refsfdsv", "Caldarera", "+91346783468");
    x.insert("fszsf", "Caldarera", "+91346783468");
    x.insert("asdf", "Caldarera", "+91346783468");
    x.insert("hgxc", "Caldarera", "+91346783468");
    x.insert("gfdssfd", "Caldarera", "+91346783468");
    x.insert("trsgds", "Caldarera", "+91346783468");
    x.insert("ergdf", "Caldarera", "+91346783468");
    x.insert("sgdtgd", "Caldarera", "+5434333");
    x.insert("tegsdf", "Caldarera", "+91346783468");
    x.insert("tewte", "fmnsbm", "+91346783468");
    x.insert("Kiwteley", "Caldarera", "+91346783468");
    x.insert("tewqwe", "fnmsmn", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("vmgfsdhb", "Caldarera", "+91346783468");
    x.insert("fsdmnv", "Caldarera", "+91346783468");
    x.insert("gbmfnmn", "fdsmng", "+91346783468");
    x.insert("rweewr", "fsdsd", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("sfsfds", "bmnfsdm", "+91346783468");
    x.insert("fdsmn", "Caldarera", "+91346783468");
    x.insert("fsndm", "fdsnm", "+91346783468");
    x.insert("fdsnmf", "dnsfm ", "+91346783468");
    x.insert("Kiley", "fddafa", "+91346783468");
    x.insert("fdsafa", "Caldarera", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    x.insert("Kiley", "Caldarera", "+91346783468");
    vector<contact> ans = x.search("fds", 1, 2);
    cout << x.message() << endl;
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first_name << " " << ans[i].last_name << " " << ans[i].phone << endl;
    }
}
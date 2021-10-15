#include "MyUnique_ptr/MyUnique_ptr.h"
#include "MyShared_ptr/MyShared_ptr.h"

#include <iostream>

using namespace std;

int main()
{
    MyUnique_ptr<string> u_ptr1(new string("C++"));
    MyUnique_ptr<string> u_ptr2(nullptr);
    cout << "MyUnique_ptr test" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "At begin:" << endl;
    cout << "ptr1 = " << u_ptr1.get() << " => " << u_ptr1.operator bool() << endl;
    cout << "*ptr1 = " << *u_ptr1 << endl;
    cout << "ptr2 = " << u_ptr2.get() << " => " << u_ptr2.operator bool() << endl << endl;

    u_ptr2.swap(u_ptr1);
    cout << "After ptr2.swap(ptr1):" << endl;
    cout << "ptr1 = " << u_ptr1.get() << " => " << u_ptr1.operator bool() << endl;
    cout << "ptr2 = " << u_ptr2.get() << " => " << u_ptr2.operator bool() << endl;
    cout << "*ptr2 = " << *u_ptr2 << endl << endl;

    MyUnique_ptr<string> u_ptr3(u_ptr2.release());
    cout << "After ptr2.release() and assigment ptr2 data to ptr3:" << endl;
    cout << "ptr2 =" << u_ptr2.get() << " => " << u_ptr2.operator bool() << endl;
    cout << "ptr3 = " << u_ptr3.get() << " => " << u_ptr3.operator bool() << endl;
    cout << "*ptr3 = " << *u_ptr3 << endl << endl;

    u_ptr3.reset();
    cout << "After ptr3.reset():" << endl;
    cout << "ptr3 = " << u_ptr3.get() << " => " << u_ptr3.operator bool() << endl << endl;

    u_ptr3 = nullptr;
    cout << "After ptr3 = nullptr:" << endl;
    cout << "ptr3 = " << u_ptr3.get() << " => " << u_ptr3.operator bool() << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;

    MyShared_ptr<char> s_ptr1(new char('E'));
    MyShared_ptr<char> s_ptr2(s_ptr1);
    MyShared_ptr<char> s_ptr3(new char('P'));
    cout << "MyUnique_ptr test" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << "At begin:" << endl;
    cout << "ptr1 is unique: " << boolalpha << s_ptr1.unique() << endl;
    cout << "ptr2 is unique: " << boolalpha << s_ptr2.unique() << endl;
    cout << "ptr2.use_count(): " << s_ptr2.use_count() << endl;
    cout << "*ptr1 = *ptr2 = " << *s_ptr1 << " => " << s_ptr1.operator bool() << endl;
    cout << "ptr3 is unique: " << boolalpha << s_ptr3.unique() << endl;
    cout << "ptr3.use_count(): " << s_ptr3.use_count() << endl;
    cout << "*ptr3 = " << *s_ptr3 << " => " << s_ptr3.operator bool() << endl << endl;

    s_ptr1.reset();
    cout << "After s_ptr1.reset():" << endl;
    cout << "ptr2 is unique: " << boolalpha << s_ptr2.unique() << endl;
    cout << "ptr2.use_count(): " << s_ptr2.use_count() << endl;
    cout << "*ptr2 = " << *s_ptr2 << " => " << s_ptr2.operator bool() << endl << endl;

    MyShared_ptr<char> s_ptr4;
    s_ptr4 = s_ptr3;
    cout << "After s_ptr4 = s_ptr3:" << endl;
    cout << "ptr3 is unique: " << boolalpha << s_ptr3.unique() << endl;
    cout << "ptr4 is unique: " << boolalpha << s_ptr4.unique() << endl;
    cout << "ptr3.use_count(): " << s_ptr3.use_count() << endl;
    cout << "*ptr3 = *ptr4 = " << *s_ptr3 << " => " << s_ptr3.operator bool() << endl << endl;

    s_ptr3.swap(s_ptr2);
    cout << "After s_ptr3.swap(s_ptr2):" << endl;
    cout << "ptr2 is unique: " << boolalpha << s_ptr2.unique() << endl;
    cout << "ptr2.use_count(): " << s_ptr2.use_count() << endl;
    cout << "*ptr2 = " << *s_ptr2 << " => " << s_ptr2.operator bool() << endl;
    cout << "ptr3 is unique: " << boolalpha << s_ptr3.unique() << endl;
    cout << "ptr3.use_count(): " << s_ptr3.use_count() << endl;
    cout << "*ptr3 = " << *s_ptr3 << " => " << s_ptr3.operator bool() << endl << endl;

    s_ptr2 = s_ptr1;
    cout << "After s_ptr2 = s_ptr1:" << endl;
    cout << "ptr4 is unique: " << boolalpha << s_ptr4.unique() << endl;
    cout << "ptr4.use_count(): " << s_ptr4.use_count() << endl;
    cout << "*ptr4 = " << *s_ptr4 << " => " << s_ptr4.operator bool() << endl;
    cout << "-------------------------------------------------------------------" << endl << endl;

    return 0;
}
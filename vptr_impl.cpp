#include <iostream>

void printInfoBase() {
    std::cout << "This is Base class Info:\n";
}

void printInfoDerived() {
    std::cout << "This is Derived class Info:\n";
}

struct VTable {
    void (*m_print)(void);

    VTable(void (*print)(void)) : m_print(print) {}
};

struct Base {
    int m_data;
    VTable* vptr;

    // Provide a constructor that takes a function pointer for initializing vptr
    Base(int data, void (*print)(void) = printInfoBase) : m_data(data), vptr(new VTable(print)) {}

    ~Base() {
        delete vptr;
        std::cout << "Base destructor called:\n";
    }
};

struct Derived {
    Base base;

    // Ensure the base class destructor is called explicitly
    Derived(int data) : base(data, printInfoDerived) {}

    ~Derived() {
        std::cout << "Derived destructor called:\n";
    }
};

Derived cast(const Base& obj) {
    return Derived(obj.m_data);
}

int main() {
    Derived obj = 3;
    Base* ptr = &obj.base;
    ptr->vptr->m_print();

    Base obj1 = 2;  // Provide a function pointer to initialize vptr
    obj1.vptr->m_print();

    Derived obj2 = cast(obj1);
    obj2.base.vptr->m_print();

    return 0;
}

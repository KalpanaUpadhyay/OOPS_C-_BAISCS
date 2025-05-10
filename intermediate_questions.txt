Here are some intermediate-level C++ OOPs interview questions with brief explanations or answers. These go beyond the basics but aren't too advanced, making them ideal for 1–3 years of experience.

🔹 1. What is the difference between virtual and pure virtual functions?
Answer:

A virtual function has a base implementation and can be overridden in a derived class.

A pure virtual function has no implementation in the base class (declared using = 0) and must be overridden, making the class abstract.

class Base {
public:
    virtual void show() { cout << "Base show\n"; }
    virtual void display() = 0;  // Pure virtual
};
🔹 2. Can a constructor be virtual?
Answer:
❌ No, constructors cannot be virtual.
However, destructors should be virtual in base classes to ensure proper cleanup in inheritance hierarchies.

🔹 3. What is the use of virtual destructors?
Answer:
To ensure the destructor of the derived class is called when an object is deleted through a base class pointer. Prevents memory leaks.

🔹 4. What is an abstract class?
Answer:
A class that contains at least one pure virtual function. It cannot be instantiated directly and serves as a base for derived classes.

🔹 5. What is object slicing?
Answer:
Occurs when a derived class object is assigned to a base class object — the derived part gets "sliced off".

class A { int x; };
class B : public A { int y; };

A a = B(); // y is sliced off
🔹 6. What is vtable and vptr?
Answer:

vtable: A table of function pointers used for dynamic dispatch of virtual functions.

vptr: A hidden pointer in an object that points to its class's vtable.

🔹 7. What happens if you don’t declare a virtual destructor in a base class?
Answer:
If you delete a derived object via a base pointer, only the base destructor is called, leading to memory/resource leaks.

🔹 8. Can a class have both a constructor and a pure virtual function?
Answer:
✅ Yes. An abstract class can have a constructor — it's used to initialize base class members during inheritance.

🔹 9. What is the difference between private, protected, and public inheritance?
Inheritance Type	Base Class Members in Derived Class
Public	public → public, protected → protected
Protected	public → protected, protected → protected
Private	public/protected → private

🔹 10. Can a pure virtual function have a body?
Answer:
✅ Yes, you can provide a definition outside the class. It’s rare, but useful for shared logic.

class A {
public:
    virtual void foo() = 0;
};

void A::foo() {
    cout << "Base implementation\n";
}


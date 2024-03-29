# Advanced Programming - Lab H

This tutorial introduces the reader to linked lists in C++.

---

## Q1. PersonNode

We are going to implement an Address Book as a Single Linked List (SLL).

The `PersonNode` class will be instantiated to create nodes for our SLL that will hold the name `m_name` and age `m_age` of each person, and will also hold a pointer to the next `m_next` `PersonNode` in the SLL.

This class already has a constructor that can set a name and age.

Add member methods to `PersonNode` so that the name and age can be changed and returned (setters and getters).

We will be required to set and return the `m_next` pointer to the `AddressBookSLL` class so that we can navigate through the SLL.  The `m_next` data member pointer is private, which means that if we add the functionality for `PersonNode` class to return this pointer then it should be returned as a `const` pointer.  This will unfortunately mean that we cannot navigate through the SLL very easily.  Therefore, on this occasion the use of the keyword `friend` is applicable, especially as these two classes are clearly coupled together and cannot be used without each other.  Therefore, inside of the `PersonNode.h` file make the `AddressBookSLL` class a friend of the `PersonNode` class, so that `AddressBookSLL` can access the private data members of `PersonNode`.

#### [Lab Book - Add your code and describe what you have done]

---

## Q2. AddressBookSLL

The `AddressBookSLL` class is required to have the functionality to allow for manipulation of the `PersonNodes` that are contained within the SLL.  The `AddressBookSLL` class has a head `PersonNode` called `m_head`.  This will point to the first `PersonNode` in the list.

We require the functionality to add a new person’s details into  `AddressBookSLL`.  Therefore implement the functionality of a public member method using the following method prototype:

```c++
void AddPerson(const string& name, int age);
``` 

This `AddPerson()` method should add a new `PersonNode` to the SLL according to the following pseudo code (it is suggested that you draw a diagram of what is happening before you start to implement this code):

1. If the `m_head` pointer is `nullptr` (i.e. the SLL is empty) then assign a new `PersonNode` to the `m_head` pointer using the provided name and age.
2. Otherwise, if the `m_head` pointer is not `nullptr` and the `m_head` pointer has a `m_next` pointer that is `nullptr` (i.e. there is only one element in the SLL) then assign the new `PersonNode` to this `m_next` pointer.
3. Otherwise, navigate through each linked `PersonNode` in the SLL until we find a `PersonNode` that has a `m_next` pointer that is `nullptr`, then assign the new `PersonNode` to this `m_next`. 

To test your code, add the following code to your `main()` method:
```c++
	book.AddPerson("Darren", 21);
	book.AddPerson("Dawn", 42);
	book.AddPerson("Steven", 18);
	book.AddPerson("Sue", 27);
```

We are instantiating a new `PersonNode` on the heap therefore we are required to take care of our own memory management.  Therefore add the following functionality in the AddressBookSLL’s destructor that will delete any memory that has been created in the `AddressBookSLL` and linked `PersonNode`.

```c++
AddressBookSLL::~AddressBookSLL(void)
{
   while (m_head->m_next != nullptr) {
      PersonNode* previous = m_head;
      PersonNode* current = m_head;
      while (current->m_next != nullptr)
      {
         previous = current;
         current = current->m_next;
      }
      delete current;
      previous->m_next = nullptr;
   }
   delete m_head;
   m_head = nullptr;
}
```

#### [Lab Book - Add your code and describe what you have done]

---

## Q3. Find, Delete, Output

Add the following functionality to the `AddressBookSLL` class:

1. The ability to find a person from the SLL by using their name:

```c++
const PersonNode* FindPerson(const string& name) const;
```

This method should return the `PersonNode` if the `PersonNode` is found or return `nullptr` if it is not found.

2. The ability to delete a person from the SLL by using their name:

```c++
bool DeletePerson(const string& name);
```

This method should return `true` if the `PersonNode` was deleted or return `false` if it is not deleted (i.e. not found).

3. The ability to output all of the people’s names and ages that our in the AddressBookSLL to an `ostream`.

#### [Lab Book - Add your code and describe what you have done]

---

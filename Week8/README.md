# Advanced Programming - Lab H
### Week8
This tutorial introduces the reader to linked lists in C++.

---

## Q1. PersonNode
### Question
We are going to implement an Address Book as a Single Linked List (SLL).

The `PersonNode` class will be instantiated to create nodes for our SLL that will hold the name `m_name` and age `m_age` of each person, and will also hold a pointer to the next `m_next` `PersonNode` in the SLL.

This class already has a constructor that can set a name and age.

Add member methods to `PersonNode` so that the name and age can be changed and returned (setters and getters).

We will be required to set and return the `m_next` pointer to the `AddressBookSLL` class so that we can navigate through the SLL.  The `m_next` data member pointer is private, which means that if we add the functionality for `PersonNode` class to return this pointer then it should be returned as a `const` pointer.  This will unfortunately mean that we cannot navigate through the SLL very easily.  Therefore, on this occasion the use of the keyword `friend` is applicable, especially as these two classes are clearly coupled together and cannot be used without each other.  Therefore, inside of the `PersonNode.h` file make the `AddressBookSLL` class a friend of the `PersonNode` class, so that `AddressBookSLL` can access the private data members of `PersonNode`.

#### [Lab Book - Add your code and describe what you have done]

### Answer

**PersonNode.cpp**
```cpp
#include "PersonNode.h"

PersonNode::PersonNode(void) : m_name(""), m_age(0), m_next(nullptr)
{
}

PersonNode::PersonNode(const string& name, int age) : m_name(name), m_age(age), m_next(nullptr)
{
}

PersonNode::~PersonNode(void)
{
}
```

**PersonNode.h**

```cpp
#pragma once

#include <string>
using namespace std;

class PersonNode
{
public:
	PersonNode(void);
	PersonNode(const string& name, int age);
	~PersonNode(void);

	void SetName(const string& name) { m_name = name; }
	string GetName() const { return m_name; }

	void SetAge(int age) { m_age = age; }
	int GetAge() const { return m_age; }

	void SetNext(PersonNode* next) { m_next = next; }
	PersonNode* GetNext() const { return m_next; }

	friend class AddressBookSLL;



private:
	string m_name;
	int m_age;
	PersonNode* m_next;
};
```

**main.cpp**

```cpp

#include <iostream>
using namespace std;
#include "AddressBookSLL.h"

/*
	This program will act as a Contacts Address Book using a Single Linked Lists
*/

int main(int argc, char **argv) {

	PersonNode* person = new PersonNode("Jayden", 20);
	cout << person->GetAge() << "\n";
	cout << person->GetName() << "\n";

	person->SetAge(21);
	person->SetName("Jayd");

	cout << person->GetAge() << "\n";
	cout << person->GetName() << endl;

   delete person;

	AddressBookSLL book;
	system("PAUSE");
}
```

```
20
Jayden
21
Jayd
Press any key to continue . . .
```

The PersonNode header file now includes setters and getters for its data. These are very simple methods that simply return the data if it is a getter, and set the data if it is a setter. I have also added AddressBookSLL as a friend class so it can access the private data members of PersonNode. This is because when we create a new item in our list, we ourselves will not call ```PersonNode* person = new PersonNode("Jayden", 20);``` or ```person->SetAge(21);```, but we will create methods of the AddressBookSLL that will do that for us. This is because the AddressBookSLL is in charge of allocating the pointers to form a chain of PersonNodes, rather than us manually trying to create that chain with ```person->SetNext(new PersonNode("Jayden", 20));```. I will explain in the next question why not only this is impractical, but dangerous.

In my main function I have added some code to create a new pointer to a new PersonNode object created on the heap named 'person' with data name of 'Jayden' and age '20'. The default constructor will give this a next pointer of 'null'. I print the name and age of person to the console before setting its data to new values and printing them again, all to show that my methods are working. Finally, we delete person as to not leave it left over and cause a memory leak.

---

## Q2. AddressBookSLL
### Question

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

### Answer

**AddressBookSLL.h**
```cpp
#pragma once

#include "PersonNode.h"

class AddressBookSLL
{
public:
	AddressBookSLL(void);
	~AddressBookSLL(void);

	void AddPerson(const string& name, int age);
	void DisplayAll() const;

private:
	PersonNode* m_head;
};
```
**AddressBookSLL.cpp**
```cpp
#include "AddressBookSLL.h"
#include <iostream>

AddressBookSLL::AddressBookSLL(void) : m_head(nullptr)
{
}

AddressBookSLL::~AddressBookSLL(void)
{
	PersonNode* current = m_head;
	PersonNode* next = nullptr;

	while (current != nullptr)
	{
		next = current->GetNext();
		delete current;
		current = next;
	}
}

void AddressBookSLL::AddPerson(const string& name, int age)
{
	PersonNode* newPerson = new PersonNode(name, age);
	if (m_head == nullptr)
	{
		m_head = newPerson;
	}
	else
	{
		PersonNode* current = m_head;
		while (current->GetNext() != nullptr)
		{
			current = current->GetNext();
		}
		current->SetNext(newPerson);
	}
}

void AddressBookSLL::DisplayAll() const
{
	PersonNode* current = m_head;
	int index = 1;

	while (current != nullptr)
	{
		std::cout << "Person " << index++ << "\n";
		std::cout << "Name: " << current->GetName() << "\n";
		std::cout << "Age: " << current->GetAge() << "\n" << std::endl;
		current = current->GetNext();
	}
}
```

**main.cpp**
```cpp

#include <iostream>
using namespace std;
#include "AddressBookSLL.h"

/*
	This program will act as a Contacts Address Book using a Single Linked Lists
*/

int main(int argc, char **argv) {

	AddressBookSLL book;

	book.AddPerson("Darren", 21);
	book.AddPerson("Dawn", 42);
	book.AddPerson("Steven", 18);
	book.AddPerson("Sue", 27);

	book.DisplayAll();

	system("PAUSE");
}
```

**Output**
```
Person 1
Name: Darren
Age: 21

Person 2
Name: Dawn
Age: 42

Person 3
Name: Steven
Age: 18

Person 4
Name: Sue
Age: 27

Press any key to continue . . .
```

This AddressBookSLL class is essential for managing PersonNodes into a proper linked list. Instead of using ```PersonNode* person = new PersonNode("Jayden", 20);``` we can instead use ```book.AddPerson("Jayden", 20);``` which will dynamically sift through the list and only add it at the end, when the program sees a null pointer.

This is the essence of what ```AddPerson``` does, however, I will go into more detail on my specific implementation when ```book.AddPerson("Jayden", 20);``` is called. First, it creates a new pointer to a PersonNode freshly created on the heap, with the age being '20', the name being 'Jayden', and the next pointer being null. Even though we have no specified the next pointer in ```PersonNode* newPerson = new PersonNode(name, age);```, the constructor will take care of that and assign it as null for us. Then it looks at the head of the AddressBook, if the AddressBook pointer is null, meaning that there is not a starting item in the list, it will assign the head pointer to the newly created person pointer.

If the list is not empty, it will initialise a new pointer 'current' to traverse the list from the beginning of the list, iterating through it until it finds a PersonNode which has a 'next' pointer of null. Once it has found this, meaning once it has found the end of the list, it sets the 'next' pointer of the current last node to point to the new node, effectively adding a new PersonNode to the end of the list. 

This took me longer than I would like to admit wrapping my head around this. 

I also added a simple ```DisplayAll``` function early so I can see if this logic was working.

---

## Q3. Find, Delete, Output
### Question
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

### Answer

**AddressBookSLL.h**
```cpp
#pragma once

#include "PersonNode.h"

class AddressBookSLL
{
public:
	AddressBookSLL(void);
	~AddressBookSLL(void);

	void AddPerson(const string& name, int age);
	void DisplayAll() const;
	const PersonNode* FindPerson(const string& name) const;
	void DisplayPerson(const string& name) const;
	bool DeletePerson(const string& name);

private:
	PersonNode* m_head;
};
```

**AddressBookSLL.cpp**
```cpp
#include "AddressBookSLL.h"
#include <iostream>

AddressBookSLL::AddressBookSLL(void) : m_head(nullptr)
{
}

AddressBookSLL::~AddressBookSLL(void)
{
	PersonNode* current = m_head;
	PersonNode* next = nullptr;

	while (current != nullptr)
	{
		next = current->GetNext();
		delete current;
		current = next;
	}
}

void AddressBookSLL::AddPerson(const string& name, int age)
{
	PersonNode* newPerson = new PersonNode(name, age);
	if (m_head == nullptr)
	{
		m_head = newPerson;
	}
	else
	{
		PersonNode* current = m_head;
		while (current->GetNext() != nullptr)
		{
			current = current->GetNext();
		}
		current->SetNext(newPerson);
	}
}

void AddressBookSLL::DisplayAll() const
{
	PersonNode* current = m_head;
	int index = 1;

	while (current != nullptr)
	{
		std::cout << "Person " << index++ << "\n";
		std::cout << "Name: " << current->GetName() << "\n";
		std::cout << "Age: " << current->GetAge() << "\n" << std::endl;
		current = current->GetNext();
	}
}

const PersonNode* AddressBookSLL::FindPerson(const string& name) const
{
	PersonNode* current = m_head;

	while (current != nullptr)
	{
		if (current->GetName() == name)
		{
			return current;
		}
		current = current->GetNext();
	}
	return nullptr;
}

void AddressBookSLL::DisplayPerson(const string& name) const
{
	const PersonNode* person = FindPerson(name);
	if (person != nullptr)
	{
		std::cout << "Name: " << person->GetName() << "\n";
		std::cout << "Age: " << person->GetAge() << "\n" << std::endl;
	}
	else
	{
		std::cout << "Person not found" << std::endl;
	}
}

bool AddressBookSLL::DeletePerson(const string& name)
{
	PersonNode* current = m_head;
	PersonNode* previous = nullptr;

	while (current != nullptr)
	{
		if (current->GetName() == name)
		{
			if (previous != nullptr)
			{
				previous->SetNext(current->GetNext());
			}
			else
			{
				m_head = current->GetNext();
			}
			delete current;
			return true;
		}
		previous = current;
		current = current->GetNext();
	}
	return false;
}	
```

**main.cpp**
```cpp

#include <iostream>
using namespace std;
#include "AddressBookSLL.h"

/*
	This program will act as a Contacts Address Book using a Single Linked Lists
*/

int main(int argc, char **argv) {

	AddressBookSLL book;

	book.AddPerson("Darren", 21);
	book.AddPerson("Dawn", 42);
	book.AddPerson("Steven", 18);
	book.AddPerson("Sue", 27);

	book.DisplayAll();

	book.DisplayPerson("Darren");

	book.DeletePerson("Darren");

	book.DisplayAll();

	system("PAUSE");
}
```
**Output**
```
Person 1
Name: Darren
Age: 21

Person 2
Name: Dawn
Age: 42

Person 3
Name: Steven
Age: 18

Person 4
Name: Sue
Age: 27

Name: Darren
Age: 21

Person 1
Name: Dawn
Age: 42

Person 2
Name: Steven
Age: 18

Person 3
Name: Sue
Age: 27

Press any key to continue . . .
```

I will go through each of my new methods in my AddressBookSLL class.

My ```DisplayAll``` method was the easiest for me to implement, I had actually already created it before I reached this section and saw it was a requirement because it made testing easier. First, it creates a PersonNode pointer called current and assigns it to the start of the list. Then it iterates through the list, printing out the data of each PersonNode until it reaches the final null pointer. I added an index here because I wanted to make sure it worked properly and was accurately displaying the index of each PersonNode.

My method for finding a PersonNode using its name data has two parts. The first part is my ```FindPerson``` method where it creates a PersonNode pointer, assigns it to the head, then iterates through the list until it finds a PersonNode with the desired name data parameter. If it does, it returns the pointer, if not, it returns a null pointer. My second method ```DisplayPerson``` then takes this pointer to the PersonNode with the desired name, checks if it is null or not, and if not displays the details of the PersonNode at that pointer. If ```FindPerson``` could not find a PersonNode with the desired name, therefore passing it into ```DisplayPerson```, ```DisplayPerson``` accounts for this by printing 'Person not found' to the console.

My method ```DeletePerson``` was for me the most confusing one out of the three, as it has too not only find the PersonNode with the desired name data, but also change the previous PersonNode to point to the PersonNode after the newly deleted one. It does this by keeping two pointers, 'current' and 'previous', iterating through the list with 'current' until it is able to find the name. If so, the PersonNode at 'previous' gets their 'next' pointer set to the PersonNode after 'current', so we can delete the PersonNode at 'current' and return true. If the PersonNode with the desired name is the first PersonNode after the head pointer (the first in the list), the program changes the head pointer to point to the PersonNode after the current one. If it cannot find a PersonNode with the desired name, it simply returns false. You can see how this one was the most complicated one to wrap my head around. 

---

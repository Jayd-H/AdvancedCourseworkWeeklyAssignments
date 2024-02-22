# Week 1

## Q1 Hello World

I ran the program and it printed "Hello World"

## Q2 Creating a new project

### Question

Create a new Empty C++ Console project called Temperature by using the project application wizard. This is done by right clicking on the 500083-Lab-A solution in the Solution Explorer Window and selecting Add » New Project.

NB: Be careful to select a C++, Empty Project

Create a new cpp file within the temperature project by right clicking on the Temperature project in the Solution Explorer Window and select Add » Add New Item.

Write a program to input a Fahrenheit measurement, convert it and output a Celsius value. The conversion formula is

celsius = 5/9 * (fahrenheit-32)
NB: You may want to select the Temperature project as the default project; to do this right click on the Temperature project and select Set as Startup Project.

Also what happens if you dividing two integers?

### Answer

I followed the instructions and created a new project and coded my fahrenheit-celcius converter. After I wrote the program, I had a logic error where no matter what I inputted as the fahrenheit temperature, celcius would always appear as 0. I fixed this by changing the integers used in my conversion equations to include a decimal point.

### Code
```cpp
	#include <iostream>
	using namespace std;

	int main(int argc, char** argv) {

		std::cout << "Input fahrenheit: " << endl;

		float ftemp;
		std::cin >> ftemp;

		const float ctemp = (5.0 / 9.0 * (ftemp - 32.0));

		std::cout << "Fahrenheit:" << ftemp << endl;
		std::cout << "Celcius:" << ctemp << endl;

	}
```
##  Q3 Types

### Question

Using the “Hello World” program as a starting point, write a program that prints out the size in bytes of each of the fundamental data types in C++.

Hint: Make use of the sizeof() operator, that returns the size of any data type.

Remember to include both the signed and unsigned versions of each data type.

### Answer

I wrote a simple program to declare each of the fundamental datatypes, both signed and unsigned, and printed out the size of them all in memory.

### Code
```cpp
	#include <iostream>
	using namespace std;

	int main (int argc, char **argv) {

		cout << "Hello World" << endl;

		// Short
		const short shortnum = 5;
		cout << "Short: " << shortnum << " Size: " << sizeof(shortnum) << endl;

		const unsigned short ushortnum = 5;
		cout << "Unsigned Short: " << ushortnum << " Size: " << sizeof(ushortnum) << endl;

		// Long
		const short longnum = 5;
		cout << "Long: " << longnum << " Size: " << sizeof(longnum) << endl;

		const unsigned short ulongnum = 5;
		cout << "Unsigned Long: " << ulongnum << " Size: " << sizeof(ulongnum) << endl;

		// Int
		const int intnum = 5;
		cout << "Integer: " << intnum << " Size: " << sizeof(intnum) << endl;

		const unsigned int uintnum = 5;
		cout << "Unsigned Integer: " << uintnum << " Size: " << sizeof(uintnum) << endl;

		// Char
		const char *letter = "G";
		cout << "Char: " << letter << " Size: " << sizeof(letter) << endl;

		const char word[] = "GG";
		cout << "Char: " << word << " Size: " << sizeof(word) << endl;

		// Float
		const float fnum = 5.0;
		cout << "Float: " << intnum << " Size: " << sizeof(float) << endl;

	}
```
## Q4 Floating point precision

### Question

In the lectures we discussed the precision of floating point numbers within C++, and how due to this precision the equality operator was unreliable.

Write a simple program that includes the lines:
```cpp
	double x = 10.0;
	double y = 10.0;
	if (x == y)
		cout << “X and Y are identical” << endl;
```
Did the program execute as expected?
Now try y = 20.0  / 2.0 and execute the program again.
Then try a more complex calculation for y e.g.
```cpp
	const double x = 100000.123456789;
	const double a = 200000.123456789;
	double y = (x + a) / x;
	double z = 1.0 + (a / x);
	if (y == z) 
	cout << “y and z are identical” << endl;
```
Now try different values for x and a

Printing out the values of x, y and z, may be useful in helping you form an opinion of what is happening.

Once you’re confident you understand the logic, investigate:

double z = x / y;
How small does y have to be before you get a “divide by zero” error? Does the value of x affect the result?

### Answer

I ran this code

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	const double x = 10.0;
	const double y = 10.0;
	if (x == y) {
		std :: cout << "X and Y are identical" << endl;
	}
}
```
And got the expected "X and Y are identical" output. I ran it multiple times and consistently got the same output.

However, when I ran this code

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	const double x = 100000.123456789;
	const double a = 200000.123456789;
	double y = (x + a) / x;
	double z = 1.0 + (a / x);
	if (y == z) {
		std :: cout << "X and Y are identical" << endl;
	}
}
```

I got no resulted output. I modified the code to print out all the values, which follow.

x = 100000
a = 200000
y = 3
z = 3

I wanted to see how small I could get a number before a divide by zero error, so I wrote a simple program to test that.

```cpp
double oldvalue = 100.0;
double divisor = 1.0;
bool divisable = true;
while (divisable) {
	if (divisor == 0) {
		std::cout << "Divisor has reached zero" << endl;
		divisable = false;
	}
	double newvalue = oldvalue / divisor;
	std::cout << "Old value: " << oldvalue << "  Divisor: " << divisor << "  New value: " << newvalue << endl;
	divisor /= 2;
}
```

In this code, the divisor should never reach 0, only infinitely approach it. The program falsely claims the divisor has reached 0 after it has done 4.94066e-324 / 2. Honestly, I thought it would have reached that conclusion earlier than it did. To test if oldvalue effected this, I modified the code slightly.

```cpp
oldvalue = oldvalue / divisor;
std::cout << "Old value: " << oldvalue << "  Divisor: " << divisor << endl;
```

This did not effect the outcome, with the program still claiming the divisor has reached 0 after it has done 4.94066e-324 / 2.

## Q5 C#/C++ Iteration Comparison (for loop)

### Question

In the lectures we have looked at constructs and iterators.

Below is some C# code that calculates the factorial of a number (see https://www.mathsisfun.com/numbers/factorial.html for details of a factorial).

```cpp
static void Main(string[] args)
{
   int factorialNumber = 5;
   int factorialTotal = 1;

   for(int n = 2; n <= factorialNumber; ++n)
   {
      factorialTotal *= n;
   }

   System.Console.WriteLine(factorialTotal);
}
```

Port the above C# code in to C++ using the provided Main.cpp file.

[LAB BOOK - Add your C++ code to your lab book. Then reflect on what you have to change (or not change) from C# to C++ in terms of the iteration]

### Answer

While converting this code from C# to C++ I was a little confused as the only things I had to change was the output of the total. I thought I must have misread it or something but I think I see the that the point is that C# and C++ share the same method for creating for loops. I also returned zero at the end because I read that it is good practice to do so, as it shows that the program completed successfully, even if the compiler will insert it for me, it's nice for readability.

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	int factorialNumber = 5;
	int factorialTotal = 1;
	for (int n = 2; n <= factorialNumber; ++n) {
		factorialTotal *= n;
	}

	std::cout << factorialTotal << endl;

	return 0;
}
```

## Q6 Calculate Average using Iteration (while loop)

### Question

Q6. Calculate Average using Iteration (while loop)
Using a while loop (or do-while loop), calculate the average value of values provided by the user from the console (cin). You should calculate the average after the user either enters a negative number or the user enters a non-number value (e.g. a letter).

The following C++ code will get an int value from the user.
```cpp
cout << "Please enter an int value, then press Enter" << endl;
int n = 0;
cin >> n;
```
[LAB BOOK - Add your C++ code to your lab book. Then reflect on what you have learnt]

### Answer

I have created a simple program to do as intended.

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	int sum = 0;
	int divisor = 0;
	do {
		std::cout << "Enter an integer, enter '-1' to stop." << endl;
		int n = 0;
		cin >> n;

		if (n < 0) {
			break;
		}

		divisor += 1;
		sum += n;
		float total = static_cast<float>(sum) / divisor;

		std::cout << "Total:" << total << endl;
		std::cout << endl;

	} while (true);

	return 0;
}
```

I initially had trouble getting this line to work as intended due to the equation not acting correctly between a float and an integer. This was corrected using static_cast.

```cpp
float total = static_cast<float>(sum) / divisor;
```

keep in mind this program lacks input validation and can be improved but that is not necessary.
# Reflection

During this lab, I have started to grasp the basics of C++ and the core differences of it and C#. I have gone through all the necessary functionality, including output, input, if statements, for loops, and while loops. Whilst the tasks were straightforward and easy, I appreciated the simplicity in order to highlight the beginning fundamentals of C++. I did not really have much trouble with creating any of these programs and I am excited gain a deeper understanding of the languages in the forthcoming weeks. 

# Week 2

## Q0

### Question

Locate the Solution Explorer within Visual Studio and select the Streaming project.

The code provided takes an integer and then a floating point number from the user and then displays the two numbers in the console window.
```cpp
#include <iostream>

int main(int argn, char* argv[])
{
   int i;
   float f;
   // take an int and float from the console - seperated by a space, e.g. "1 6.7"
   std::cin >> i >> f;
   // output the int and float to the console
   std::cout << "i=" << i << ", x=" << f << std::endl;
}
```

This code creates an integer variable called i and a float variable called f. It then takes the user input from the console (cin) by storing two numbers from the user into the two variables. The code then outputs to the console the values of the two variables.

Run this code and enter into the console window an integer followed by a space and then followed by a floating point number before pressing the return key (e.g. 23  4.567). The program should output the values of the two numbers.

### Answer

I ran the program and entered "56 2.1", the program returned "i=56, f=2.1".

## Q1 The Good >> Streaming Operator

### Question

Add the following line of code below the #include.
```cpp
using namespace std;
```
This allows us to use the namespace std without explicitly adding std:: before any object or function defined in that namespace.

Remove the std:: from the cin and cout and endl.

Your code should still compile and run.

Add a third variable that is a string type. You will need to add #include <string>.

Take a string value from the user after you take the float value (the user can enter something like 23  4.586  Hello into the console window).

Then output the string value to the console after you output the float value.

[LAB BOOK - Add your code to your lab book and describe your code]

### Answer

I modified the code to look like this.
```cpp
#include <iostream>
#include <string>
using namespace std;

int main(int argn, char* argv[])
{
	int i;
	float f;
	string s;
	cin >> i >> f >> s;
	cout << "i=" << i << ", f=" << f << ", s=" << s << endl;
}
```
I then entered "32 3.4 thirtyfour" and the program returned with "i=34, f=3.4, s=thirtyfour". This is done by first taking three inputs from the user on the same line followed by a space, an int, a float, a string, then outputting them back through the console.


## Q2 The Bad >> Streaming Operator

### Question

The streaming operator >> can be used on most fundamental types and standard objects like string. However, it can lead to unexpected issues when storing values into an array.
```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
   char c[5];
   cin >> c;
   cout << "c=" << c << endl;
}
```
The above code will store characters from the console window into the char array called c.

Place a break point on the cout line of the code. Run the above program. In the console, enter the values 123 before selecting the return key.

In Visual Studio, select from the menu, Debug -> Windows -> Autos. This will allow you to inspect values and memory addresses of variables etc.

Click on the triangle next to the variable c, and you should see the following output: alt text

You can see that this variable can hold 5 chars as we defined it to do. However, we are only using the first three and so we have the end of array character \0 so that the system knows we are not using the whole array. Continue to step threw the rest of the code so that you can see the output etc.

Run the program again, but this time enter the values 123456789 before selecting the return key. Look at the value of c in the Autos window and you may see only the first 5 values but your code has tried to enter all 9 values into our variable. Notice that we cannot see the \0 end of array character - it is there but it is further along in memory from the start of the array so we cannot see it in the Autos window. Continue to step throw your code and you should receive a Run-Time Check Failure that is alerting you of this issue.

In Visual Studio, change the build to Release and then select from the menu, Debug -> Start Without Debugging. The whole 9 values should now be outputted because release will blindly output from the start of the array until it reaches the end array character.

The >> streaming operator is great for storing values into different types, but it should be avoided to store values into an array.

Replace cin >> c with the following code:
```cpp
cin.get(c, 5);
```
This code will store up to 4 values followed by the end of array character. Run your code as a normal Debug build and with the Debugger and inspect and document the values and see the output. get() is usually safer for storing multiple characters in an array that the >> operator.

[LAB BOOK - reflect on the nature and uses of the >> streaming operator and the get() function]

### Answer

I first ran the code above. 

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
   char c[5];
   cin >> c;
   cout << "c=" << c << endl;
}
```

I inputted '123' and inspected the 'c' array with the autos window. I saw the first 3 values with '1','2', and '3' respectively, followed by '\0' and'Ì' as the last value. When I stepped through the output from the console was the expected 'c=123'. I then ran the program again, inputted '123456789', and saw with the autos window that the array only stored the first 5 values in the array "1", "2", "3", "4", and "5". As I stepped through, the program gave me the error "Run-Time Check Failure #2 - Stack around the variable 'c' was corrupted.".

When I changed to release mode and inputted "123456789" into the console, the program outputted the whole array of characters, however visual studio seemed to have realised something was wrong and gave me this error "Unhandled exception at 0x00C11DB9 in Streaming.exe: Stack cookie instrumentation code detected a stack-based buffer overrun.".

I then altered by code accordingly.

```cpp
#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
	char c[5];
	cin.get(c, 5);
	cout << "c=" << c << endl;
}
```

I put a breakpoint on line 8, ran the program and inputted "1234", and inspected the values with the auto window. As expected, it correctly stored the 4 characters with an end of array character at the end, and outputted "c=1234". I reran the program, this time inputting "123456789" and checked the autos window to the same result, the first four characters saved with an end of array character at the end. The program still outputted "c=1234".

the .get() function seems to be superior than the >> streaming operator when dealing with arrays like these due to its reliability and robustness, always only storing the valid number of characters possible.

## Q3 Assembly Language

### Question

Locate the Solution Explorer within Visual Studio and select the Assembly project.

The source.cpp file contains the following code:
```cpp
#include <iostream>
using namespace std;

void main(int, char**) {
     const int start = 3;
     const int end = 10;
     int total = 0;

     int count = start;
     while (count < end) {
       total += count;
       count++;
     }

     cout << "Total= " << total << endl;
     system("PAUSE");
}
```
The program executes a single loop, adding the value of the loop counter to a running total.

Compile and run the program.

Debugging
View source.cpp within Visual Studio.

Place a breakpoint on line:
```cpp
const int start = 3;
```
The easiest way to place the breakpoint is to click in the margin of the main.cpp file. The break point appears as a red circle.

Make sure that Debug mode is selected on the menu bar.

Run the program.

Execution should halt at your breakpoint.

Single step through your programme by pressing F10. This executes one line of C++ code with each press.

Now open the Local variable windows by selecting Debug->Windows->Local. This shows the values of all the C++ variables currently in scope.

Hit F5 to execute the program to completion.

Getting lost
Restart your programme and execute to the same break point as before.

Last time we used F10 to execute a line of code. If the code is a function call e.g. the streaming operator, then F10 will execute the function call in a single press.

F11 is similar to F10, but it will attempt to single step through a function.

Press F11 until you enter the streaming operator.

Now you’re debugging the C++ streaming library! Provided the source code is available, it is possible to debug any library in C++.

To avoid getting too lost, you can press Shift-F11 to jump back out of the most recent function.

Press shift-F11 now.

Hit F5 to execute the program to completion.

Disassemble
Restart your programme and execute to the same break point as again.

Now disassemble your code, by selecting Debug->Windows->Disassembly

You should get:
```cpp
   const int start = 3;
001D5EA8 mov         dword ptr [start],3 
   const int end = 10;
001D5EAF  mov         dword ptr [end],0Ah 
   int total = 0;
001D5EB6  mov         dword ptr [total],0  
   int count = start;
001D5EBD  mov         dword ptr [count],3 
   while (count < end) {
001D5EC4  cmp         dword ptr [count],0Ah 
001D5EC8  jge         main+5Eh (01D5EDEh) 
      total += count;
001D5ECA  mov         eax,dword ptr [total] 
001D5ECD  add         eax,dword ptr [count] 
001D5ED0  mov         dword ptr [total],eax 
      count++;
001D5ED3  mov         eax,dword ptr [count] 
001D5ED6  add         eax,1 
001D5ED9  mov         dword ptr [count],eax 
   }
001D5EDC  jmp         main+44h (01D5EC4h) 
```
Familiarize yourself with the display. You should see your C++ instruction above a series of assembly language instructions. Reading the assembly language from left to right you should see the memory location, operation and finally the operands. Note the memory locations will vary between executions.

Notice also that the execution point (yellow arrow) has moved from the C++ instruction to the assembly instruction

Hit F5 to execute the program to completion.

Registers
Execute your programme to the same break point as before, and open the Disassembly window.

Now open the Register window, by selecting Debug->Windows->Registers

Single step through the code by pressing F10

The execution point moves to the next assembly instruction and any registers that change are highlighted within the register window, in red. In this case the EIP (instruction pointer) and EFL (flags) have changed.

Continue to execute your code one line at a time, taking note of the change in registers.

Stack
Execute your programme to the same break point as before, and open the Disassembly window.

Now open the Memory window, by selecting Debug->Windows->Memory

Copy the address of the stack from the stack pointer within the Register window.

Paste the address into the edit field at the top of the Memory window. You should now see the stack’s contents in the window.

Single step through the code and observe any changes to the stack. You should be able to see changes to the contents of variables count and total.

Release mode
Now select Release mode on the menu bar

Recompile the programme.

Execute your programme to the same break point as before, and open the Disassembly window.

Notice that the breakpoint has been moved, automatically. The following line no longer has any associated assembly instructions
```cpp
const int start = 3;
```
The optimizer has been at work!!!

Step through your code. If it still exists it has been greatly optimized. Much of the function overhead has been removed.

In release mode it is virtually impossible to associate a piece of assembly with its original C++.

Enjoy assembly language!!

### Answer

I opened 'Source.cpp' and placed a breakpoint on line 5. I ran the program and stepped through it with the locals window open, watching the 'total' value begin at 3 during its first pass, then change to 7, 12, 18, 25, 33, and ending with 42, with confirmation from a console output "Total= 42".

I then re ran my code with the same break point and used the dissasembler to see the assembly.

```cpp
#include <iostream>
using namespace std;

int main(int, char**) {
003D2490  push        ebp  
003D2491  mov         ebp,esp  
003D2493  sub         esp,0F0h  
003D2499  push        ebx  
003D249A  push        esi  
003D249B  push        edi  
003D249C  lea         edi,[ebp-30h]  
003D249F  mov         ecx,0Ch  
003D24A4  mov         eax,0CCCCCCCCh  
003D24A9  rep stos    dword ptr es:[edi]  
003D24AB  mov         ecx,offset _9FCC0E96_Source@cpp (03DF066h)  
003D24B0  call        @__CheckForDebuggerJustMyCode@4 (03D1398h)  
	const int start = 3;
003D24B5  mov         dword ptr [start],3  
	const int end = 10;
003D24BC  mov         dword ptr [end],0Ah  
	int total = 0;
003D24C3  mov         dword ptr [total],0  

	int count = start;
003D24CA  mov         dword ptr [count],3  
	while (count < end) {
003D24D1  cmp         dword ptr [count],0Ah  
003D24D5  jge         __$EncStackInitStart+4Fh (03D24EBh)  
		total += count;
003D24D7  mov         eax,dword ptr [total]  
003D24DA  add         eax,dword ptr [count]  
003D24DD  mov         dword ptr [total],eax  
		count++;
003D24E0  mov         eax,dword ptr [count]  
003D24E3  add         eax,1  
003D24E6  mov         dword ptr [count],eax  
	}
003D24E9  jmp         __$EncStackInitStart+35h (03D24D1h)  

	cout << "Total= " << total << endl;
003D24EB  mov         esi,esp  
003D24ED  push        offset std::endl<char,std::char_traits<char> > (03D103Ch)  
003D24F2  mov         edi,esp  
003D24F4  mov         eax,dword ptr [total]  
003D24F7  push        eax  
003D24F8  push        offset string "Total= " (03D9B30h)  
003D24FD  mov         ecx,dword ptr [__imp_std::cout (03DD0D8h)]  
003D2503  push        ecx  
003D2504  call        std::operator<<<std::char_traits<char> > (03D11B3h)  
003D2509  add         esp,8  
003D250C  mov         ecx,eax  
003D250E  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (03DD0A0h)]  
003D2514  cmp         edi,esp  
003D2516  call        __RTC_CheckEsp (03D129Eh)  
003D251B  mov         ecx,eax  
003D251D  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (03DD0A4h)]  
003D2523  cmp         esi,esp  
003D2525  call        __RTC_CheckEsp (03D129Eh)  

	return 0;
003D252A  xor         eax,eax  
}
003D252C  pop         edi  
003D252D  pop         esi  
003D252E  pop         ebx  
003D252F  add         esp,0F0h  
003D2535  cmp         ebp,esp  
003D2537  call        __RTC_CheckEsp (03D129Eh)  
003D253C  mov         esp,ebp  
003D253E  pop         ebp  
003D253F  ret  
```

I then opened the registers window.

EAX = 003DF066 EBX = 0110B000 ECX = 003DF066 EDX = 00000001 ESI = 003D1023 EDI = 0136FA28 EIP = 003D24B5 ESP = 0136F92C EBP = 0136FA28 EFL = 00000246 
0x0136FA20 = CCCCCCCC 

I then stepped through my program, seeing specific registers change and highlighted in red when they do so. I opened the memory 1 window and changed the address from "0x0029F7E0" to the ESP address "008FFC58". I then stepped through the program with this open and saw specific values of the variables used in the program being changed, highlighting in red when they do so.

I changed to release mode and opened the assembly code once more.

```cpp
	const int start = 3;
	const int end = 10;
	int total = 0;

	int count = start;
	while (count < end) {
		total += count;
		count++;
	}

	cout << "Total= " << total << endl;
00581000  mov         ecx,dword ptr [__imp_std::cout (0583060h)]  
00581006  push        offset std::endl<char,std::char_traits<char> > (0581300h)  
0058100B  push        2Ah  
0058100D  call        std::operator<<<std::char_traits<char> > (05810F0h)  
00581012  mov         ecx,eax  
00581014  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0583034h)]  
0058101A  mov         ecx,eax  
0058101C  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (058303Ch)]  

	return 0;
00581022  xor         eax,eax  
}
00581024  ret  
```

I stepped through the program with the memory window open and watched it execute the assembly line by line, almost mesmerised.

## Reflection
During this lab I have gained a deeper knowledge of the best practices for creating arrays in c++, when and when not to use >> over alternative methods when taking user inputs. More interestingly, I have began to understand what is actually happening line by line whilst executing code, familiarising myself with assembly and the various windows available for debugging. I am glad to have learnt this knowledge and am excited to bring these new tools with me when creating programs in c++.

# Week 3

## Q0
### Question
This lab introduces the reader to using File IO and function call mechanism in C++.

---
Locate the **Solution Explorer** within Visual Studio and select the **File Input Output** project.

Compile and run the provided code.

The program will display in the console something like:

```code
Usage: G:\500083\File-Input-Output\Debug\Copy.exe <input filename> <output filename>
```

The program displays this message because we have not provided the filename of an input file or an output file.  Look at the code in Main.cpp.  The program checks to see whether or not the user has passed these arguments to the program, as follows:

```c++
if (argn != 3) {
   cerr << "Usage: " << argv[0] << " <input filename> <output filename>" << endl;
   int keypress; cin >> keypress;
   return -1;
}
```

Firstly the code checks to see whether 3 arguments have been passed to the program.   The operating system will always pass at least one argument when the program is run, namely the file path to the program is passed to the program in `argv[0]`.  Therefore any argument that you pass to the program will be the second, third, fourth, etc.

---

### Answer

I ran the program and saw the expected results.

## Q1. Passing Command Arguments

### Question

Our program will be required to copy a text file.
Therefore the program requires the user to send an input filename and an output filename as arguments.
One can do this in Visual Studio.
Select **Project**, then the project **Properties**, and then **Debugging**.
Then click inside of the **Command Arguments** box.
Here is where you enter the parameters to send to the program when it is run.
You should enter `input.txt output.txt` into the **Command Arguments** box as shown below.

![alt text](README-arguments.png "Enter command arguments")

This will mean that `argv[1]` will contain `input.txt` and `argv[2]` will contain `output.txt`.
Enter the two program arguments and then compile and run your program and you should not get any error message.

### Answer
I added the required arguments into my program through the debug window and ran the code. The program responded with "Copy successful", however it did not actually copy "input.txt" as the functionality for that does not exist yet.
---

## Q2. Copying a Text File

Complete the functionality inside of the `Copy(char filenamein[], char filenameout[])` function.
You need to add code that will try to open a text file given by the `filenamein` array as the name of the input file.
You need to add code to create and output file using the `filenameout` array as the name of the ouput file.
Then you can add code that will take each char from the input file and put it in the output file.

Make sure that you check for the input and output files existence before trying to copy.

Test your code thoroughly, e.g. try providing filenames that do not exist.

**[LAB BOOK - Add you code to your lab book and reflect on how you tested your code]**

### Answer

I have completed the program to copy a file.

```cpp
#include <iostream>
#include <fstream>
using namespace std;

bool Copy(char filenamein[], char filenameout[])
{
    ifstream inFile;
    ofstream outFile;

    inFile.open(filenamein, ios::in);
    if (!inFile.is_open()) {
        cout << "Failed to open input file: " << filenamein << endl;
        return false;
    }

    outFile.open(filenameout, ios::out);
    if (!outFile.is_open()) {
        cout << "Failed to create output file: " << filenameout << endl;
        inFile.close(); 
        return false;
    }

    char ch;
    while (inFile.get(ch)) { 
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();

    return true;
}


int main(int argn, char* argv[])
{

    for (int i = 0; i < argn; i++)
    {
		cout << "argv[" << i << "] = " << argv[i] << endl;
	}

	if (argn != 3) {
		cerr << "Usage: " << argv[0] << " <input filename> <output filename>" << endl;
		int keypress; cin >> keypress;
		return -1;
	}

	if (Copy(argv[1], argv[2]))
	{
		cout << "Copy successful" << endl;
	}
	else
	{
		cout << "Copy error" << endl;
	}
	system("PAUSE");
}
```
The program first confirms the number of arguments passed into it, verifying that there is only an input file and an output file argument. I added a for loop to show me how many arguments were being passed in. This is for debugging purposes so I knew how the program responded depending on different/number of arguments.

```cpp
int main(int argn, char* argv[])
{

    for (int i = 0; i < argn; i++)
    {
		cout << "argv[" << i << "] = " << argv[i] << endl;
	}

	if (argn != 3) {
		cerr << "Usage: " << argv[0] << " <input filename> <output filename>" << endl;
		int keypress; cin >> keypress;
		return -1;
	}

	if (Copy(argv[1], argv[2]))
	{
		cout << "Copy successful" << endl;
	}
	else
	{
		cout << "Copy error" << endl;
	}
	system("PAUSE");
}
```

Here is the output of the program with incorrect arguments.

```cpp
argv[0] = D:\Files\Documents\#UNIY2\AP\AdvancedCourseworkWeeklyAssignments\Week3\Classroom\x64\Debug\File Input Output.exe
argv[1] = neovim
argv[2] = emacs
argv[3] = vi
Usage: D:\Files\Documents\#UNIY2\AP\AdvancedCourseworkWeeklyAssignments\Week3\Classroom\x64\Debug\File Input Output.exe <input filename> <output filename>
```


The pogram declares the input and output files based on the arguments, then verifies that it can open the input file. If not, then the function returns false and informs the user of the issue.
```cpp
ifstream input;
ofstream output;

input.open(filenamein, ios::in);
if (!input.is_open()) {
    cout << "Failed to open input file: " << filenamein << endl;
    return false;
}
```

Here is the output of the program in this event.

```
argv[0] = D:\Files\Documents\#UNIY2\AP\AdvancedCourseworkWeeklyAssignments\Week3\Classroom\x64\Debug\File Input Output.exe
argv[1] = jayden.txt
argv[2] = output.txt
Failed to open input file: jayden.txt
Copy error
```

Then, it does the same with the output file, verfiying that it can open it, and if it can't, informing the user of the issue.

```cpp
 output.open(filenameout, ios::out);
 if (!output.is_open()) {
     cout << "Failed to create output file: " << filenameout << endl;
     input.close(); 
     return false;
 }
```

If the program passed both of these checks, it goes onto a while loop. This while loop checks if there is a character in the input file, and if so, copies that character to the output file, including line breaks. After this process is finished, it closes both of the files and returns true to let the user know that the copy has been successful.

```cpp
char ch;
while (input.get(ch)) { 
    output.put(ch);
}

input.close();
output.close();

return true;
```

I thought about instead of doing this character by character, doing it line by line. Character by character is more straightforward to implement, to my understanding more efficient with memory, and can support binary files better (as it copies every byte exactly as is without interpretting the data). However, copying line by line is generally faster for text files as it reduces the number of read/write operations, and it also allows convenience for text processing if you want to manipulate the data (such as filtering lines). For this use case I went with character by character as we have no need for text processing and performance is not an issu (and also because the question specified to).

---

## Q3. Function call mechanism

### Question

Locate the **Solution Explorer** within Visual Studio and select the **Functions** project.

The `source.cpp` file contains the following code:

```c++
#include <iostream>
using namespace std;

int mymax(int a, int b) {
   if(a > b)
     return a;
   else
     return b;
}

int main(int, char **) {
   int a = 10;
   int b = 20;

   int max = mymax(a,b);

   return 0;
}
```

We want our program to calculate which of the two variable `a` and `b` is the largest.

Compile and run the program.

#### Disassemble

View `source.cpp` within Visual Studio.

Place a breakpoint on line:

```c++
int a = 10;
```

This was covered in the previous lab.

Make sure that **Debug** mode is selected on the menu bar.

Run the program.

Execution should halt at your breakpoint.

Now disassemble your code, by selecting **Debug->Windows->Disassembly**.

You should get:

```asm
     int a = 10;
004131EE mov         dword ptr [a],0Ah  
     int b = 20;
004131F5  mov         dword ptr [b],14h 
     int max = mymax(a,b);
004131FC  mov         eax,dword ptr [b] 
004131FF  push        eax 
00413200  mov         ecx,dword ptr [a] 
00413203  push        ecx 
00413204  call        mymax (040124Eh) 
00413209  add         esp,8 
0041320C  mov         dword ptr [max],eax
```

Familiarise yourself with the display.  You should see your C++ instruction above a series of assembly language instructions.

### Functions

Execute your programme to the same breakpoint, and open the **Disassembly** window as before.

Now open the **Register** window, by selecting **Debug->Windows->Registers**

Single-step through the code by pressing **F11**

Continue to execute your code one line at a time, taking note of the change in register values.

Execute the following line:

```
00413204  call        mymax (040124Eh)
```

Notice that you move to a strange memory location before jumping again to your actual function.  This is just a Debug step added by the compiler.  It does not exist in **Release** mode.

Stop executing when you are at the following section of code

```asm
int mymax(int a, int b) {
00412350  push        ebp
00412351  mov         ebp,esp 
00412353  sub         esp,0C0h 
00412359  push        ebx 
0041235A  push        esi 
0041235B  push        edi 
0041235C  lea         edi,[ebp-0C0h] 
00412362  mov         ecx,30h 
00412367  mov         eax,0CCCCCCCCh 
0041236C  rep stos    dword ptr es:[edi]
```

This is the parameter passing section described in the lecturers.

Familiarize yourself with the code and continue executing until you return to your main programme.

It is recommended that you step through the previous section of code several times to fully understand how functions are called in C++.

Execute to the highlighted line.

```asm
cout << "a=" << a << ", b=" << b << endl;
0041320F  push        401505h 
00413214  mov         eax,dword ptr [b] 
00413217  push        eax 
00413218  push        4C96A0h 
0041321D  mov         ecx,dword ptr [a] 
00413220  push        ecx 
00413221  push        4C96A8h 
00413226  push        4EDFA8h 
0041322B  call        std::operator<<<std::char_traits<char> > (0401663h)   
```

Sometimes it is convenient to execute a line of assembly without actually seeing all the details.  This can be achieved by pressing **F10**.

Now ‘step over’ the call to the streaming function.  Notice how the function is executed (look in the command prompt window), but you have not entered the function.

Hit **F5** to execute the program to completion.

### Memory

Execute your programme to the previous breakpoint, and open the **Disassembly** window as before.

Execute to the highlighted line.

```asm
int max = mymax(a,b);
004131FC  mov         eax,dword ptr [b]  
004131FF  push        eax 
00413200  mov         ecx,dword ptr [a] 
00413203  push        ecx 
00413204  call        mymax (040124Eh) 
00413209  add         esp,8 
0041320C  mov         dword ptr [max],eax
```

Execute the next instruction and note the value of the EAX register.

The next instruction pushes the contents of the EAX register onto the stack.  Before we execute the instruction we will look at the stack in memory.

Open a **Memory** window, by selecting **Debug->Windows->Memory->’Memory 1’**.  This window shows the contents of an area of memory.

We need to move this window to look at the stack.  The location of the stack can be found in the stack pointer (ESP).  Look for this in the **Register** Window and copy the address.  Paste the address into the **Memory** window’s address box and press ENTER

You should now see your stack in the memory window.

Scroll UP the memory window by 4 lines.

Execute the next instruction and note change in the stack’s contents (The change is highlighted in red).  The reason for scrolling the window is so that you can observe the write to memory.  Otherwise, the PUSH instruction would write to memory above your visible window.

Execute the next 2 instructions and note the change in stack’s contents

Your stack should look similar to the stack dump below

```code
0x0018FE15  cc cc cc cc cc cc cc cc cc cc cc cc cc  ÌÌÌÌÌÌÌÌÌÌÌÌÌ
0x0018FE22  cc cc cc cc cc cc cc cc cc cc cc cc cc  ÌÌÌÌÌÌÌÌÌÌÌÌÌ
0x0018FE2F  cc 0a 00 00 00 14 00 00 00 00 00 00 00  Ì............
0x0018FE3C  00 00 00 00 00 e0 fd 7e cc cc cc cc cc  .....àý~ÌÌÌÌÌ
0x0018FE49  cc cc cc cc cc cc cc cc cc cc cc cc cc  ÌÌÌÌÌÌÌÌÌÌÌÌÌ
0x0018FE56  cc cc cc cc cc cc cc cc cc cc cc cc cc  ÌÌÌÌÌÌÌÌÌÌÌÌÌ 
```

Hit **F5** to execute the program to completion.

#### Data sizes

In `source.cpp` we use variables `a` and `b`.  How many bytes do each of these variables occupy in memory?

Look at the memory dump above; can you verify your answer?

Each of the registers we have used so far in this program have been 32-bits in size e.g. EAX.  Look at the register window.  The values in each register are represented by 8 digits; 2 digits for each byte.

#### Parameter types

Now modify the code and add in your own function that takes 3 parameters each of a different type.

From what you have learnt in the previous exercises, use the Debugger and Disassembly to investigate how the C++ parameter passing mechanism deals with these new parameters.

### Answer

I ran the program and verified that it worked. I placed a breakpoint and got this assembly.

```asm
int main(int, char**) {
00A024F0  push        ebp  
00A024F1  mov         ebp,esp  
00A024F3  sub         esp,0E4h  
00A024F9  push        ebx  
00A024FA  push        esi  
00A024FB  push        edi  
00A024FC  lea         edi,[ebp-24h]  
00A024FF  mov         ecx,9  
00A02504  mov         eax,0CCCCCCCCh  
00A02509  rep stos    dword ptr es:[edi]  
00A0250B  mov         ecx,offset _1941878C_Source@cpp (0A0F066h)  
00A02510  call        @__CheckForDebuggerJustMyCode@4 (0A0139Dh)  

	int a = 10;
00A02515  mov         dword ptr [a],0Ah  
	int b = 20;
00A0251C  mov         dword ptr [b],14h  

	int max = mymax(a, b);
00A02523  mov         eax,dword ptr [b]  
00A02526  push        eax  
00A02527  mov         ecx,dword ptr [a]  
00A0252A  push        ecx  
00A0252B  call        mymax (0A011DBh)  
00A02530  add         esp,8  
00A02533  mov         dword ptr [max],eax  

	cout << "a=" << a << ", b=" << b << endl;
00A02536  mov         esi,esp  
00A02538  push        offset std::endl<char,std::char_traits<char> > (0A0103Ch)  
00A0253D  mov         edi,esp  
00A0253F  mov         eax,dword ptr [b]  
00A02542  push        eax  
00A02543  push        offset string ", b=" (0A09B30h)  
00A02548  mov         ebx,esp  
00A0254A  mov         ecx,dword ptr [a]  
00A0254D  push        ecx  
00A0254E  push        offset string "a=" (0A09B38h)  
00A02553  mov         edx,dword ptr [__imp_std::cout (0A0D0D8h)]  
00A02559  push        edx  
00A0255A  call        std::operator<<<std::char_traits<char> > (0A011B3h)  
00A0255F  add         esp,8  
00A02562  mov         ecx,eax  
00A02564  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A0D0A0h)]  
00A0256A  cmp         ebx,esp  
00A0256C  call        __RTC_CheckEsp (0A012A3h)  
00A02571  push        eax  
00A02572  call        std::operator<<<std::char_traits<char> > (0A011B3h)  
00A02577  add         esp,8  
00A0257A  mov         ecx,eax  
00A0257C  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A0D0A0h)]  
00A02582  cmp         edi,esp  
00A02584  call        __RTC_CheckEsp (0A012A3h)  
00A02589  mov         ecx,eax  
00A0258B  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A0D0A4h)]  
00A02591  cmp         esi,esp  
00A02593  call        __RTC_CheckEsp (0A012A3h)  
	cout << "max=" << max << endl;
00A02598  mov         esi,esp  
00A0259A  push        offset std::endl<char,std::char_traits<char> > (0A0103Ch)  
00A0259F  mov         edi,esp  
00A025A1  mov         eax,dword ptr [max]  
00A025A4  push        eax  
00A025A5  push        offset string "max=" (0A09B3Ch)  
00A025AA  mov         ecx,dword ptr [__imp_std::cout (0A0D0D8h)]  
00A025B0  push        ecx  
00A025B1  call        std::operator<<<std::char_traits<char> > (0A011B3h)  
00A025B6  add         esp,8  
00A025B9  mov         ecx,eax  
00A025BB  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A0D0A0h)]  
00A025C1  cmp         edi,esp  
00A025C3  call        __RTC_CheckEsp (0A012A3h)  
00A025C8  mov         ecx,eax  
00A025CA  call        dword ptr [__imp_std::basic_ostream<char,std::char_traits<char> >::operator<< (0A0D0A4h)]  
00A025D0  cmp         esi,esp  
00A025D2  call        __RTC_CheckEsp (0A012A3h)  

	return 0;
00A025D7  xor         eax,eax  
}
00A025D9  pop         edi  
00A025DA  pop         esi  
00A025DB  pop         ebx  
00A025DC  add         esp,0E4h  
00A025E2  cmp         ebp,esp  
00A025E4  call        __RTC_CheckEsp (0A012A3h)  
00A025E9  mov         esp,ebp  
00A025EB  pop         ebp  
00A025EC  ret  
```
After taking note of how the mymax function is being executed in assembly, I had a look at the output stream function too. I stepped through and watched the program "draw" the output to the console window, starting with "a=" and a few steps later adding the value, before going onto the next. 

I executed the program again, stepping to the desired line and noted the EAX register of "00000014". I used the stack pointer address to see the memory change when executing through the instructions of the function mymax.

Because both variable, "a", and "b", are integers, they take up four bytes of memory. I can confirm this by looking at the memory dump of where the stack pointer is when they are initialised. A = 0a 00 00 00. B = 14 00 00 00.

I modified the program to take in three parameters, checking which integer is larger. 

```cpp
#include <iostream>
using namespace std;

int mymax(int a, int b, int c)
{
	if (a > b && a > c)
		return a;
	else if (b > a && b > c)
		return b;
	else
		return c;

}

int main(int, char**) {

	int a = 10;
	int b = 20;
	int c = 30;

	int max = mymax(a, b, c);

	cout << "a=" << a << ", b=" << b << endl;
	cout << "max=" << max << endl;

	return 0;
}
```

The assembly code changed accordingly

```asm
	int max = mymax(a, b, c);
00AC252A  mov         eax,dword ptr [c]  
00AC252D  push        eax  
00AC252E  mov         ecx,dword ptr [b]  
00AC2531  push        ecx  
00AC2532  mov         edx,dword ptr [a]  
00AC2535  push        edx  
00AC2536  call        mymax (0AC1451h)  
00AC253B  add         esp,0Ch  
00AC253E  mov         dword ptr [max],eax  
```

---

## Reflection
This week I have gained further knowledge of using the library 'fstream' which provides facilities for file-based input and output. Using my newly found knowledge of arguments in C++, I created a basic file copy-paste program. Through this, I have also learnt when and when not to use a string or char datatype when copying data from one file to another. I have also increased my familiarity with debugging in visual studio, getting more comfortable with viewing variable data in the memory dump. Through assembly, I have began to grasp the basics of how functions work at a fundamental level, with this hands-on experience being beneficial to my future with C++, when I innevitably work with much more complex programs. Overall, the ideas I have gone through today represent very valuable, useful knowledge I can take into future projects. I am excited too see a more in-depth use-case of the things I learnt today and feel more confident in my understanding of them.


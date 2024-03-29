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
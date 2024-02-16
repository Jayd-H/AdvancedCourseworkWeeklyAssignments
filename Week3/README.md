# Advanced Programming - Lab C

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

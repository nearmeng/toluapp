This version of tolua++ DO NOT uses SCons to compile, use cmake instead (win/linux cross platform).

modified by nearmeng, support lua-5.3.
<br/>
* Installation

	1. Asume you are in toluapp base dir
	2. mkdir build && cd build
	3. If you use Linux: just use command:  
        ```cmake .. ```   
        or if you use Windows: use command below:   
        ```cmake -G"Visual Studio 15 2017 Win64" ..```
	4. In Linux:   
        ```make```   
       And in Windows: just open the .sln file and compile
<br/>
* What you get

	- an executable to generate binding code in ./bin;
	- the C library to be linked in your application in ./lib;
	- the include file needed to compile your application in ./inc;  
  These are the only directories you need for development, besides Lua.   
<br/>
* Compile detail (you can ignore)  
    when build executable, we will build a toluapp_bootstrap first, and then use it to generate the lua binary code, and recompile the executable with the binary code. After this operation, toluapp will 
	have the featrue of the exported lua files.

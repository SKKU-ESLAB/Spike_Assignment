SKKU Spike RISC-V ISA Simulator assignment
============================
 
About
-------------
Spike, the RISC-V ISA Simulator, implements a functional model of one or more
RISC-V harts.
 
 
Build Steps
---------------
```
 $ apt-get install device-tree-compiler
 $ cd Spike_Assignment
 $ mkdir build
 $ cd build
 $ ../spike/configure
 $ make
 $ [sudo] make install
```
 
Running a Simple C Program
-------------------------------------------
 
Now you can simulate the program atop the proxy kernel:
 ```
 $ cd ..
 $ ./build/spike ./pk/pk bench/test1
 ```
 
Interactive Debug Mode
---------------------------
 
To invoke interactive debug mode, launch spike with -d:
 ```
 $ spike -d pk hello
 ```
To see the contents of an integer register (0 is for core 0):
 ```
 : reg 0 a0
 ```
To see the contents of a floating point register:
 ```
 : fregs 0 ft0
 ```
or:
 ```
 : fregd 0 ft0
 ```
depending upon whether you wish to print the register as single- or double-precision.


To see the contents of a memory location (physical address in hex):

    : mem 2020

To see the contents of memory with a virtual address (0 for core 0):

    : mem 0 2020

You can advance by one instruction by pressing the enter key. You can also
execute until a desired equality is reached:

    : until pc 0 2020                   (stop when pc=2020)
    : until reg 0 mie a                 (stop when register mie=0xa)
    : until mem 2020 50a9907311096993   (stop when mem[2020]=50a9907311096993)

Alternatively, you can execute as long as an equality is true:

    : while mem 2020 50a9907311096993

You can continue execution indefinitely by:

    : r

At any point during execution (even without -d), you can enter the
interactive debug mode with `<control>-<c>`.

To end the simulation from the debug prompt, press `<control>-<c>` or:

    : q

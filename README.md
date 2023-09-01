# Python/C API module example
Building a 'stringutil' that has a single function named 'trim' that removes all the whitespaces from a string.
Python header file usually in a 'NIX system is located under `/usr/include/python3.x/Python.h`.

## usage 
run 
```shell
docker build -t cpython .
```
then 
``` shell
docker run --rm -it -v .:/app cpython
```

## output preview
This is a usage example inside a simple docker container using Debian Slim Bookworm
```shell
root@68a073f32dbe:/app# ls
Dockerfile  setup.py  stringutilmodule.c
root@68a073f32dbe:/app# python3 setup.py build_ext --inplace
running build_ext
building 'stringutil' extension
creating build
creating build/temp.linux-x86_64-cpython-313
gcc -fno-strict-overflow -Wsign-compare -DNDEBUG -g -O3 -Wall -fPIC -I/usr/local/include/python3.13 -c stringutilmodule.c -o build/temp.linux-x86_64-cpython-313/stringutilmodule.o
creating build/lib.linux-x86_64-cpython-313
gcc -shared build/temp.linux-x86_64-cpython-313/stringutilmodule.o -o build/lib.linux-x86_64-cpython-313/stringutil.cpython-313-x86_64-linux-gnu.so
copying build/lib.linux-x86_64-cpython-313/stringutil.cpython-313-x86_64-linux-gnu.so ->
root@68a073f32dbe:/app# python3
Python 3.13.0a0 (heads/main:9c03215a3e, Aug 31 2023, 08:22:53) [GCC 12.2.0] on linux
Type "help", "copyright", "credits" or "license" for more information.
>>> from stringutil import trim
>>> trim("hello world")
'helloworld'
>>> exit()
```
    

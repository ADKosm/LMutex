# LMutex
Lamport Mutex on C++

To build this project, you need cmake 3.5 or higher.

```
git clone https://github.com/ADKosm/LMutex.git
cd LMutex
cmake .
make
```

After that, in bin/ will be all files, which you can execute. Go to this directory

```
cd bin/
```

To run Unit test, run the following:

```
./runTests
```

To run stress test with N nodes, run the following:

```
./launcher.py stress N
```

To run user test with N nodes, run the following:

```
./launcher.py user N
```

Example of session in this mode:

```
lock 1
lock 2
unlock 1
unlock 2
kill
```

To run logger checker run the following after running system (in user or stress mode):

```
./checker.py
```

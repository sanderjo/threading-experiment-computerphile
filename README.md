# threading-experiment-computerphile

Based on "Why Multi-Threaded Code Can Sometimes Misbehave (Weak Memory Concurrency) - Computerphile" https://youtu.be/E3hvLz717zM

Code copied from / based on https://youtu.be/E3hvLz717zM?t=276

<img width="1035" height="641" alt="image" src="https://github.com/user-attachments/assets/ad21214f-37aa-46cf-be7c-b3eb81195790" />

## compile and run

```
make # which does: g++ -std=c++17 test.cpp -o test
./test
```

## Example output
```
sander@zwarte:~/git/threading-experiment-computerphile$ ./test 
count = 0
count = 10000
count = 20000
Reordering detected!
count = 25146, a = 0, b = 0
Final result: count = 25146, a = 0, b = 0
count = 25146, a = 0, b = 0
```
... or it takes longer:

```
...
count = 460000
count = 470000
count = 480000
Reordering detected!
count = 480052, a = 0, b = 0
Final result: count = 480052, a = 0, b = 0
```

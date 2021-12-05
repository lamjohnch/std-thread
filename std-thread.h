#include <functional>
#include <iostream>
#include <cstdint>
#include <vector>
#include <thread>
#include <atomic>
#include <mutex>

#include <pthread.h>

using namespace std; 

class testthread 
{
public:
    uint32_t f1(string &s);
    static uint32_t f2(string *pS2, int&, float);
 //   uint32_t f3(string *pS);

protected:
    int m_int;
    string s = "member s old"; 
    string *pS = new string("member pS old");
    testthread* pNextThread; 
};

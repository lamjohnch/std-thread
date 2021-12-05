
#include "std-thread.h"

std::mutex g_display_mutex;


uint32_t testthread::f1(string &s)
{
    int i = 0;
    while ( i < 20) {
        i++;
          g_display_mutex.lock();
        cout << "f1, #" << i << endl;
        //cout << s << endl;
          g_display_mutex.unlock();

    }
    return 1; 
}

//uint32_t testthread::f2(testthread* pTestTh)
uint32_t testthread::f2(string *pS2, int &a, float y)
{
    int i = 0;
    while (i<5) {
        i++;
              g_display_mutex.lock();    
        cout << "f2 thread, #" << i << endl;
         cout << "f2 thread, ps2 = " << pS2 << " , a = " << a << "float = " << y << endl;
        // s = "new";
        // cout << "f2 thread, change s string = " << s << endl;
        //pS2 = new string("inside f2");
          g_display_mutex.unlock();
    }
    //delete pS2; 
    return 2; 

}

//uint32_t testthread::f3(string *pS)
//uint32_t f3(string *pS)
uint32_t f3(string s)
{
    int i = 0; 
    while (i < 20) {
        i++;
              g_display_mutex.lock();    
        cout << "f3, #" << i << endl;
        //cout << s << endl;
              g_display_mutex.unlock();
    }
    return 3; 
}

int main(int argc, char* argv[]) 
{

    int n = 99; 
    string s1 = "t1";
    string *pS = nullptr; // = new string("pS");
    
//        int policy = SCHED_RR;
//        int minPrio = sched_get_priority_min(policy);
//        int maxPrio = sched_get_priority_max(policy);
//     cout << "SCHED_RR = " << SCHED_RR << endl;
//     cout << "min prio = " << minPrio << endl;
//     cout << "max prio = " << maxPrio << endl << endl;
    
//     cout << "SCHED_FIFO = " << SCHED_FIFO << endl;
//    minPrio = sched_get_priority_min(SCHED_FIFO);
//     maxPrio = sched_get_priority_max(SCHED_FIFO);
//  cout << "min prio = " << minPrio << endl;
//     cout << "max prio = " << maxPrio << endl << endl;

//     cout << "SCHED_OTHER = " << SCHED_OTHER << endl;
//     minPrio = sched_get_priority_min(SCHED_OTHER);
//     maxPrio = sched_get_priority_max(SCHED_OTHER);
//    cout << "min prio = " << minPrio << endl;
//     cout << "max prio = " << maxPrio << endl << endl;   

    // std::thread t2(f1, n + 1); // pass by value
    // std::thread t3(f2, std::ref(n)); // pass by reference
//     std::thread t4(std::move(t3)); // t4 is now running f2(). t3 is no longer a thread
//     std::thread t5(&foo::bar, &f); // t5 runs foo::bar() on object f
//     class foo, void bar() member func, f is foo object (foo f;) 
//     std::thread t6(b); // t6 runs baz::operator() on a copy of object b
       //std::this_thread::sleep_for(std::chrono::seconds(1));

    testthread th1; 
    //testthread th2; 

     std::thread t1(&testthread::f1, &th1, std::ref(s1)); //
     //std::thread t2(&testthread::f2, std::ref(pS)); // 
     //std::thread t3(&testthread::f3, std::ref(pS)); //
     //std::thread t3(f3, std::ref(pS)); // 
     std::thread t3(f3, "t3"); // 

   //std::cout << "Before join(), t1 joinable: " << t1.joinable() << '\n';

    //std::vector<std::thread> threads; 
   // threads.push_back(t1);
    //threads.push_back(t3);

      sched_param sch1, sch3;
      int policy1, policy3; 
    //     //  struct sched_param {
    //     //        int sched_priority;     /* Scheduling priority */
    //     //    };
     pthread_getschedparam(t1.native_handle(), &policy1, &sch1);
              g_display_mutex.lock(); 
     cout << "orig t1 policy = " << policy1 << " , priority = " << sch1.sched_priority << endl;      
           g_display_mutex.unlock();
    sch1.sched_priority = 50;
    // pthread_setschedparam(t1.native_handle(), SCHED_RR, &sch1);
    //  pthread_getschedparam(t1.native_handle(), &policy1, &sch1);
    //           g_display_mutex.lock(); 
    //  cout << "new t1 policy = " << policy1 << " , priority = " << sch1.sched_priority << endl;      
    //        g_display_mutex.unlock();

    //sch3.sched_priority = 10;
    //pthread_setschedparam(t3.native_handle(), SCHED_RR, &sch3);
       pthread_getschedparam(t3.native_handle(), &policy3, &sch3);
              g_display_mutex.lock(); 
     cout << "t3 policy = " << policy3 << " , priority = " << sch3.sched_priority << endl;      
        g_display_mutex.unlock();

           g_display_mutex.lock();
    std::cout << "synchronizing all threads...\n";
              g_display_mutex.unlock();
    //for (auto& th : threads) th.join();
    t1.join();
    //t2.join();
    t3.join();

    //return 1;
    exit(1); 

}

#ifndef __LIB_TM__
#define __LIB_TM__
#include <iostream>
using namespace std;

class LibTM
{
private:
public:
    LibTM(/* args */){};
    void run() {
        step1();
        if(step2()) {
            step3();
        };
        step4();
        step5();
    };
    virtual ~LibTM() {};
protected: 
    void step1() {
        cout << "step 1" << endl;
    };
    void step3() {
        cout << "step 3" << endl;
    };
    void step5() {
        cout << "step 5" << endl;
    }

    virtual bool step2() = 0;
    virtual void step4() = 0;
};

#endif
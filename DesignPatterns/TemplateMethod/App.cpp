#include <iostream>
#include "Lib.h"
#include "LibTM.h"
using namespace std;

class App {
public:
    bool step2() {
        cout << "Step 2" << endl;
        return true;
    };

    void setp4() {
        cout << "Step 4" << endl;
    };
};

class APPTM : public LibTM
{
private:
    /* data */
public:
    APPTM(/* args */);
    ~APPTM();
protected:
    virtual bool step2() {
        cout << "step 2" << endl;
        return true;
    }
    virtual void step4() {
        cout << "step 4" << endl;
    }
};

APPTM::APPTM(/* args */)
{
}

APPTM::~APPTM()
{
}


int main() {
    Libary lib;
    App app;
    cout << "normal design" << endl;
    lib.step1();

    if(app.step2()) {
        lib.step3();
    }

    app.setp4();
    lib.step5();

    cout << "template method design" << endl;
    // template method
    LibTM *plib = new APPTM();
    plib->run();

    delete plib;

    return 0;
};
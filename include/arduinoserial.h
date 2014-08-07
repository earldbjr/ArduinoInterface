#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H
#include <fcntl.h>
#include <termios.h>
//using namespace std;
class ArduinoSerial
{
    public:
        ArduinoSerial(char);
        void closePort();
        int openPort(char);
        int transmit();
        void changePort(int value);
        void setDevice(int value);
        void setFunction(int value);
        void setInstruction(int value);
        void setOpt1(int value);
        void setOpt2(int value);
        int getDevice();
        int getFunction();
        int getInstruction();
        int getOpt1();
        int getOpt2();
    protected:
    private:
        char chInstruction[5];
        char PORT;
        int fd;
};

#endif // ARDUINOSERIAL_H

#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H
#include <fcntl.h>
#include <termios.h>
//using namespace std;
class ArduinoSerial
{
    public:
        ArduinoSerial(char[13], int);
        void closePort();
        int openPort();
        int transmit();
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
        char chInstruction[6];
        char PORT[13];
        int BAUD;
        int fd;
};

#endif // ARDUINOSERIAL_H

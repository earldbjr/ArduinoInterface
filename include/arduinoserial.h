#ifndef ARDUINOSERIAL_H
#define ARDUINOSERIAL_H
#include <fcntl.h>
#include <termios.h>
//using namespace std;
class ArduinoSerial
{
    public:
        ArduinoSerial();                //Constructor, initializes chInstruction
        void closePort();               //Closes fd
        int openPort(int);              //Opens fd
        int transmit();                 //Transmits chInstruction to Arduino
        void changePort(int value);     //Changes variable PORT, used by openPort()
        void setDevice(int value);      //chInstruction[0]
        void setFunction(int value);    //chInstruction[1]
        void setInstruction(int value); //chInstruction[2]
        void setOpt1(int value);        //chInstruction[3]
        void setOpt2(int value);        //chInstruction[4] (chInstruction[5]='\0')
        int getDevice();
        int getFunction();
        int getInstruction();
        int getOpt1();
        int getOpt2();
    protected:
    private:
        char chInstruction[5];          //5 digit char array of options to be sent to Arduino
        char PORT;                      //# in /dev/ttyACM#
        int fd;                         //Serial port
};

#endif // ARDUINOSERIAL_H

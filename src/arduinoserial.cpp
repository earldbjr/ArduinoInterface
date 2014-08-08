#include "arduinoserial.h"
#include <fcntl.h>
#include <termios.h>
int ArduinoSerial::openPort(int _PORT)
{
    char chPortName[13];//="/dev/ttyACM1";
    sprintf(chPortName, "/dev/ttyACM%i", _PORT);
    //chPortName[13] = chPORT;

    int fd = open(chPortName, O_RDWR | O_NOCTTY | O_NDELAY);

    struct termios config;

    if(tcgetattr(fd, &config) < 0)
    {
        //  cout << "tcgetattr: fd < 0";
    }

    config.c_iflag  &= ~(IGNBRK | BRKINT  | ICRNL | INLCR | PARMRK | INPCK | ISTRIP | IXON);
    //~(Turn off processing | Convert break to null byte | No CR->NL | No NL->CR | Ignore Parity Errors | Dont strip high bit | no flow control);
    config.c_oflag = 0;
    config.c_lflag &= ~(ECHO | ECHONL | ICANON | IEXTEN | ISIG);
    config.c_cflag &= ~(CSIZE | PARENB);
    config.c_cflag  |= CS8;
    config.c_cc[VMIN] = 1;
    config.c_cc[VTIME] = 0;
    if(cfsetispeed(&config, B9600)  < 0 || cfsetospeed(&config, B9600) < 0)
    {
        //  cout << "Problem setting Baud to 9600";
    }
    if(tcsetattr(fd, TCSAFLUSH, &config) < 0)
    {
        //  cout << "Problem setting attributes to fd";
    }
    if(fd == 2){
        ArduinoSerial::closePort();
        return(fd);
    }
    return(fd);
}

void ArduinoSerial::closePort()
{
    close(fd);
}

ArduinoSerial::ArduinoSerial()
{
        chInstruction[0]='1';
        chInstruction[1]='0';
        chInstruction[2]='0';
        chInstruction[3]='0';
        chInstruction[4]='0';
        chInstruction[5]='\0';
}

int ArduinoSerial::transmit()
{
    ArduinoSerial::openPort(PORT);
    char buf[5];
    chInstruction[4]='4';//debugging
    int len = sprintf(buf, "%s", chInstruction);
    int result =(write(fd, buf, len));//-1 = fail
    ArduinoSerial::closePort();
    return result;
}

void ArduinoSerial::changePort(int newPORT)
{
    static int port0Initialized=0, port1Initialized=0, port2Initialized=0, port3Initialized=0, port4Initialized=0;
    static signed int oldPORT= -1;
    PORT = newPORT;
    //Forces the Arduino to reset once we select the correct port.
    //Useful for finding the Arduino, and makes it ready for the first command.
        if(oldPORT != PORT){
        switch(PORT)
            {
            case 0:
                if(port0Initialized==0){
                    port0Initialized=1;
                    goto InitializePort;
                }
                break;
            case 1:
                if(port1Initialized==0){
                    port1Initialized=1;
                    goto InitializePort;
                }
                break;
            case 2:
                if(port2Initialized==0){
                    port2Initialized=1;
                    goto InitializePort;
                }
                break;
            case 3:
                if(port3Initialized==0){
                    port3Initialized=1;
                    goto InitializePort;
                }
                break;
            case 4:
                if(port4Initialized==0){
                    port4Initialized=1;
                    goto InitializePort;
                }
                break;
            default:
                break;
            InitializePort:
        ArduinoSerial::openPort(PORT);
        ArduinoSerial::transmit();
        oldPORT = newPORT;
        ArduinoSerial::closePort();
        }

    }
}

void ArduinoSerial::setDevice       (int value){chInstruction[0] = (char)value+48;} //48 = ASCII 0
void ArduinoSerial::setFunction     (int value){chInstruction[1] = (char)value+48;}
void ArduinoSerial::setInstruction  (int value){chInstruction[2] = (char)value+48;}
void ArduinoSerial::setOpt1         (int value){chInstruction[3] = (char)value+48;}
void ArduinoSerial::setOpt2         (int value){chInstruction[4] = (char)value+48;}

int ArduinoSerial::getDevice()      {return chInstruction[0];}
int ArduinoSerial::getFunction()    {return chInstruction[1];}
int ArduinoSerial::getInstruction() {return chInstruction[2];}
int ArduinoSerial::getOpt1()        {return chInstruction[3];}
int ArduinoSerial::getOpt2()        {return chInstruction[4];}
//chInstruction[5] reserved for \0

#include "arduinoserial.h"
#include <fcntl.h>
#include <termios.h>
ArduinoSerial::ArduinoSerial(char a[], int b)
{
    for(int i=0; i<14; i++){
        PORT[i] = a[i];
    }
    BAUD = b;
        chInstruction[0]='1';
        chInstruction[1]='0';
        chInstruction[2]='0';
        chInstruction[3]='0';
        chInstruction[4]='0';
        chInstruction[5]='\0';
}

void ArduinoSerial::closePort()
{
    close(fd);
}

int ArduinoSerial::openPort()
{

    fd = open(PORT, O_RDWR | O_NOCTTY | O_NDELAY);

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
    if(fd == -1){
        ArduinoSerial::closePort();
    }
    return(fd);
}

int ArduinoSerial::transmit()
{
    char buf[5];
    int len = sprintf(buf, "%s", chInstruction);
    return(write(fd, chInstruction, len));//-1 = fail
}

void ArduinoSerial::setDevice(int value){chInstruction[0] = value;}
void ArduinoSerial::setFunction(int value){chInstruction[1] = value;}
void ArduinoSerial::setInstruction(int value){chInstruction[2]  = value;}
void ArduinoSerial::setOpt1(int value){chInstruction[3] = value;}
void ArduinoSerial::setOpt2(int value){chInstruction[4] = value;}

int ArduinoSerial::getDevice(){return chInstruction[0];}
int ArduinoSerial::getFunction(){return chInstruction[1];}
int ArduinoSerial::getInstruction(){return chInstruction[2];}
int ArduinoSerial::getOpt1(){return chInstruction[3];}
int ArduinoSerial::getOpt2(){return chInstruction[4];}
//chInstruction[5] reserved for \0

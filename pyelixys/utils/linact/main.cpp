#include <stdio.h>
#include <linact.hpp>

using namespace IAI;
LinActBuf lbuf;
LinearActuator linact;

int main() {
    printf("Linear Actuator\r\n");
    lbuf.buf[0] = 0x3f;
    lbuf.buf[1] = 0x03;
    lbuf.buf[2] = 0xf7;
    lbuf.buf[3] = 0x00;
    lbuf.buf[4] = 0x00;
    lbuf.buf[5] = 0x02;
    lbuf.len = 6;
    lbuf.calc_crc();
    printf("%s\r\n", lbuf.as_string());

    linact.getGwStatusStr();
    printf("GWSTATUS: %s\r\n", linact.buffer.as_string());
    linact.getGwStartStr();
    printf("GWSTART: %s\r\n", linact.buffer.as_string());

    linact.getAxisStatus(0);
    printf("Get AXIS 0 Status: %s\r\n", linact.buffer.as_string());

    linact.getAxisStatus(1);
    printf("Get AXIS 1 Status: %s\r\n", linact.buffer.as_string());

    linact.getAxisPos(0);
    printf("Get AXIS0 Pos: %s\r\n", linact.buffer.as_string());

    linact.getSetAxisPos(1, 1000);
    printf("Get Set AXIS0 Pos: %s\r\n", linact.buffer.as_string());
}

#ifndef MODBUSRELAY_H
#define MODBUSRELAY_H

#include <SoftwareSerial.h>

#define RXPin     14 // PIN_D5  // Serial Receive pin
#define TXPin      2 // PIN_D4  // Serial Transmit pin

#define Relay_Open  0x01
#define Relay_Close 0x00

#define Relay1 0x00
#define Relay2 0x01
#define Relay3 0x02
#define Relay4 0x03

#define BroadCast 0x00

struct MB_Relay {
private:
  byte message[8];
  byte BusAddr;
  SoftwareSerial *con;
  byte setAddress (const byte adr);
   
public:
  MB_Relay (SoftwareSerial *connect, const byte MB_Address);
  uint16_t MsgCRC16 (byte *nData);  // writes 2 byte CRC16 after the first 6 bytes
  void switchRelay (byte rel, byte state);
  byte getAddress ();
  uint32_t HardwareVersion ();
  uint64_t InputState ();
};

#endif

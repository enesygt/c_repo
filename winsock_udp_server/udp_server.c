#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <conio.h>

#pragma comment(lib, "ws2_32.lib")

#define BUFFERSZ    1024
#define PORT        19010

typedef enum
{
  BLOCKING    = 0,
  NONBLOCKING = 1
} BLOCKING_MODE;

int main(void) {
  struct sockaddr_in UserApp;
  struct sockaddr_in Server;

  int ServerLen = sizeof(Server);
  int ReceivedDataLen;
  UINT8 ReceiveBuffer[BUFFERSZ];

  WORD wVersionRequested = MAKEWORD(2, 2);
  WSADATA wsaData;
  SOCKET ListenSocket;
  UINT32 Mode = (UINT32)NONBLOCKING;
  UINT32 bufferdata;

  int loop;

  if (WSAStartup(wVersionRequested, &wsaData) == 0)
  {
    /* Create UDP socket */
    if ( ( ListenSocket =
             WSASocketW(AF_INET, SOCK_DGRAM, IPPROTO_UDP, NULL, 0,
                        WSA_FLAG_OVERLAPPED) ) != INVALID_SOCKET )
    {
      int SocketOption = 1;
      setsockopt( ListenSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&SocketOption,
                  sizeof(SocketOption) );

      UserApp.sin_family      = AF_INET;
      UserApp.sin_port        = htons(PORT);
      UserApp.sin_addr.s_addr = htonl(INADDR_ANY);
      while (1)
      {
        // Bind socket
        if (bind( ListenSocket, (PSOCKADDR)&UserApp,
                  sizeof(UserApp) ) != SOCKET_ERROR)
        {
          while (1)
          {
            /* Using ioctlsocket() */
            if (ioctlsocket(ListenSocket, FIONBIO, &Mode) != SOCKET_ERROR)
            {
              ioctlsocket(ListenSocket, FIONREAD, &bufferdata);

              /* Read data from buffer */
              if (bufferdata != 0)
              {
                ReceivedDataLen = recvfrom(ListenSocket,
                                           ReceiveBuffer,
                                           BUFFERSZ,
                                           0,
                                           (struct sockaddr *)&Server,
                                           &ServerLen);
                for (loop = 0; loop < ReceivedDataLen; loop++)
                {
                  printf("%c", ReceiveBuffer[loop]);
                }

                printf("\n");
              }
              memset( ReceiveBuffer, 0, sizeof(ReceiveBuffer) );

              /* Display received data */

              /*printf("\n%d :: \n", __LINE__);
               * for (loop = 0; loop < ReceivedDataLen; loop++)
               * {
               *  printf("%02X ", ReceiveBuffer[loop]);
               * }
               * printf("\n");*/
            }

            /* Using select() */
            FD_SET ReadSet;
            FD_ZERO(&ReadSet);

            FD_SET(ListenSocket, &ReadSet);

            struct timeval TimeOut;
            TimeOut.tv_usec = 100000;             /* 0.1sec timeout */
            bufferdata      = 0;
            bufferdata      = select(0, &ReadSet, NULL, NULL, &TimeOut);

            if (bufferdata != 0)
            {
              ReceivedDataLen = recvfrom(ListenSocket,
                                         ReceiveBuffer,
                                         BUFFERSZ,
                                         0,
                                         (struct sockaddr *)&Server,
                                         &ServerLen);
              /* Display received data */
              for (loop = 0; loop < ReceivedDataLen; loop++)
              {
                printf("%c", ReceiveBuffer[loop]);
              }

              printf("\n");
            }
            memset( ReceiveBuffer, 0, sizeof(ReceiveBuffer) );
          }
        }
      }
    }
    closesocket(ListenSocket);
  }

  WSACleanup();

  _getch();
  return(0);
}

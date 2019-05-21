// ������

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winsock2.h>

typedef int WSADATA;
int main()
{


    //  ������������� ������

    WSADATA wsaData;

    if (WSAStartup(2.0,&wsaData))
    {
        printf("WinSock not be initialized");
        WSACleanup();
        return 0;
    }


    struct sockaddr_in peer;                                        //    ����� ���������� ����� �������� � ������� ���������
    int s;                                                          //    sockaddr_in, ������� ���������� ������� connect.
    int rc;                                                         //
    char buf[ 1 ] ;                                                 //


    //  ���������� ������ �������
                                                                    //    ��������� ��������� sockaddr_in, ��������� � ��
    peer.sin_family = AF_INET;                                      //    ���� ����� ����� (7500) � �����. 127.0.0.1 -
    peer.sin_port = htons( 7500 );                                  //    ��� ���������� �����, ������� ��������, ���
    peer.sin_addr.s_addr = inet_addr( "127.0.0.1");                 //    ������ ��������� �� ��� �� ������, ��� � ������.


    //  ��������� ������ � ���������� � ��������

    s = socket( AF_INET, SOCK_STREAM, 0 );                          //    �������� ����� ���� SOCK_STREAM.
    if (s < 0)                                                      //    �������� TCP, ������ ���������,
    {                                                               //    ������� ������ ������ ������.
        perror ( "'socket' call error" );                           //    ������������ ��������: 0 - ���������,
        return 1;                                                   //    -1 (UNIX) ��� �� 0 (Windows) - ������.
    }                                                               //

    rc = connect( s, ( struct sockaddr * )&peer, sizeof(peer));     //    ������������� ���������� � ��������,
    if ( rc )                                                       //    ��������� � ���������� ������connect.
    {                                                               //    ���� ����� �����, ����� �������� ����
        perror ( "'connect' call error" );                          //    ����� �������.
         return 1;                                                  //
    }                                                               //


    //  �������� � ��������� ������ �����

    rc = send( s , "1" , 1, 0 ) ;                                   //    �������� ���� ���� �������
    if ( rc <= 0 )                                                  //
    {                                                               //
        perror ( "'send' call error" );                             //
        return 1;                                                   //
    }                                                               //

    rc = recv( s, buf, 1, 0 );                                      //    ������ �� ������ ���� ����, ����������
    if ( rc <= 0 )                                                  //    ���������� ���� � �����
        perror ( "'recv' call error" );                             //
    else                                                            //
        printf ( "%c\n", buf[ 0 ] );                                //    ����� ����������� ��������� �� �����

    getch();
    return 0;
}

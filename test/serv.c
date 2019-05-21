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


    struct sockaddr_in local;                                           //    ����� ���������� ����� �������� � ������� ���������
    int s;                                                              //    sockaddr_in, ������� ���������� ������� connect.
    int s1;                                                             //
    int rc;                                                             //
    char buf[ 1 ];                                                      //


    //  ���������� �������� ��������� � ��������� ������

    local.sin_family = AF_INET;                                         //  ��������� ��������� sockaddr_in, ��������� � �� ����
    local.sin_port = htons( 7500 );                                     //  ��������� ����� � ����� �����.
    local.sin_addr.s_addr = htonl( INADDR_ANY );                        //

    s = socket( AF_INET, SOCK_STREAM, 0 );                              //  �������� ����� ���� SOCK_STREAM,
    if ( s < 0 )                                                        //  ������� � ����� ��������������.
    {                                                                   //
        perror ( "'socket' call error" );                               //
        return 1;                                                       //
    }                                                                   //


    //  �������� ���������� ����� � ����� listen

    rc = bind( s, ( struct sockaddr * )&local, sizeof( local ) );       //  ����������� ��������� ���� � �����,
    if ( rc < 0 )                                                       //  ���������� � ��������� lo c a l,
    {                                                                   //  � ����������� ������.
        perror ( "'bind' call error" );                                 //
        return 1;                                                       //
    }                                                                   //

    rc = listen( s, 5 ) ;                                               //  �������� listen , �����
    if ( rc )                                                           //  �������� ����� ��� ��������������.
    {                                                                   //
        perror( "'listen' call error" );                                //
        return 1;                                                       //
    }                                                                   //

    printf ("Waiting connection...");

    //  �������� ����������

    s1 = accept( s, NULL, NULL );                                       //  �������� accept ��� ������ ����� ����������.
    if ( s1 < 0 )                                                       //  ����� accept ��������� ����������
    {                                                                   //  ��������� �� ��� ���, ���� �� ��������
        perror ( "'accept' call error" );                               //  ������ �� ����������, ����� ����
        return 1;                                                       //  ���������� ����� ����� ��� ����� ����������.
    }                                                                   //


    //  ����� �������

    rc = recv( s1, buf, 1, 0 );                                         //  ������ ���� �� ��������� 1,
    if ( rc <= 0 )                                                      //  ���������� �� �������.
    {                                                                   //
        perror ( "'recv' call error" ) ;                                //
        return 1;                                                       //
    }                                                                   //

    printf ( "%c\n", buf[ 0 ] );                                        //  �������� ���� ����.

    rc = send( s1, "2", 1, 0 );                                         //  �������� ���� ���� �� ��������� 2
    if ( rc <= 0 )                                                      //  ����� �������.
        perror ( "'send' call error" );                                 //

    getch();
    return 0;
}

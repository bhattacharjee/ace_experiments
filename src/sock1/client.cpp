#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Connector.h"
#include "ace/Log_Msg.h"







int ACE_TMAIN(int, ACE_TCHAR *[])
{
    int bc;
    char buf[64];
    ACE_SOCK_Connector connector;
    ACE_SOCK_STREAM peer;
    ACE_INET_Addr srvr(50000, ACE_LOCALHOST);

    if (-1 == connector.connect(peer, srvr))
    {
	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n"),
			ACE_TEXT("connect")), 1);
    }

    peer.send_n ("uptime\n", sizeof("uptime\n"));
    bc = peer.recv(buf, sizeof(buf));
    write(1, buf, bc);
    peer.close();

    return 0;
}

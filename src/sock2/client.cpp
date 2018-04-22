#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Connector.h"
#include "ace/Log_Msg.h"







int ACE_TMAIN(int, ACE_TCHAR *[])
{
    int bc;
    char buf[64];
    ACE_SOCK_Connector connector;
    ACE_SOCK_STREAM status;
    ACE_INET_Addr addr;
    ACE_OS::last_error(0);

    addr.set ("HAStatus", ACE_LOCALHOST);
    addr.set ("HALog", ACE_LOCALHOST);

    ACE_SOCK_Connector statusConnector(status, addr);

    if (ACE_OS::last_error())
    {
	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n"),
		    ACE_TEXT("status")), 100);
    }

    status.send_n ("uptime\n", sizeof("uptime\n"));
    bc = status.recv(buf, sizeof(buf));
    write(1, buf, bc);
    status.close();

    return 0;
}

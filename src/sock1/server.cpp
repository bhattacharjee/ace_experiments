#include "ace/INET_Addr.h"
#include "ace/SOCK_Stream.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Log_Msg.h"


int ACE_TMAIN(int, ACE_TCHAR *[])
{
    ACE_INET_Addr	port_to_listen(50000);
    ACE_SOCK_Acceptor	acceptor;

    if (-1 == acceptor.open(port_to_listen, 1))
    {
	ACE_ERROR_RETURN((LM_ERROR, ACE_TEXT("%p\n"),
		    ACE_TEXT("acceptor.open")), 100);
    }

    while (1)
    {
	ACE_SOCK_Stream		peer;
	ACE_INET_Addr		peer_addr;
	ACE_Time_Value		timeout(10, 0);

	if (-1 == acceptor.accept(peer, &peer_addr, &timeout, 0))
	{
	    if (EINTR == ACE_OS::last_error())
	    {
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) Interrrupted while ")
			ACE_TEXT("waiting for connection")));
	    }
	    else if (ETIMEDOUT == ACE_OS::last_error())
	    {
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) timed out while ")
			ACE_TEXT("waiting for connection")));
	    }
	    else
	    {
		ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) unknown error")));
	    }
	}
	else
	{
	    ACE_TCHAR	peer_name[MAXHOSTNAMELEN];
	    char	buffer[4096];
	    ssize_t	bytes_received;
	    
	    peer_addr.addr_to_string(peer_name, MAXHOSTNAMELEN);
	    ACE_DEBUG((LM_DEBUG, ACE_TEXT("(%P|%t) Connection from %s\n"),
			peer_name));

	    while (0 < (bytes_received = peer.recv(buffer, sizeof(buffer))))
	    {
		peer.send_n (buffer, bytes_received);
	    }

	    peer.close();
	}
    }

    return 0;
}







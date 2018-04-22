#include "ace/Log_Msg.h"

void foo()
{
    ACE_TRACE(ACE_TEXT("%Ifoo"));
}

int ACE_TMAIN(int, ACE_TCHAR *[])
{
    ACE_TRACE(ACE_TEXT("main"));
    ACE_DEBUG((LM_INFO, ACE_TEXT("%Idebug main\n")));

    //ACE_LOG_MSG->priority_mask(LM_TRACE|LM_DEBUG|LM_NOTICE, ACE_Log_Msg::PROCESS);
    ACE_LOG_MSG->priority_mask(LM_DEBUG|LM_NOTICE, ACE_Log_Msg::THREAD);

    ACE_DEBUG((LM_INFO, ACE_TEXT("%Idebug main\n")));

    return 0;
}

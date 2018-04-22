CPPFLAGS += -lACE -L$(ACE_ROOT)/lib -I$(ACE_ROOT) -g
CXXFLAGS += -lACE -L$(ACE_ROOT)/lib -I$(ACE_ROOT) -g
CFLAGS += -g -DACE_NTRACE=0
LDFLAGS += -lACE -L$(ACE_ROOT)/lib
INCLUDES += -I$(ACE_ROOT)


CXX = gcc

all: $(BIN)

$(BIN): $(SRC)
	$(CXX) -o $(BIN) $(SRC) $(CFLAGS) $(LDFLAGS) $(INCLUDES)


clean:
	rm -f $(BIN)

#include $(ACE_ROOT)/include/makeinclude/wrapper_macros.GNU
#include $(ACE_ROOT)/include/makeinclude/macros.GNU
#include $(ACE_ROOT)/include/makeinclude/rules.common.GNU
##include $(ACE_ROOT)/include/makeinclude/rules.nontested.GNU
#include $(ACE_ROOT)/include/makeinclude/rules.bin.GNU
#include $(ACE_ROOT)/include/makeinclude/rules.local.GNU
#include $(ACE_ROOT)/include/makeinclude/platform_linux.GNU

#include $(ACE_ROOT)/include/makeinclude/all_in_one.GNU

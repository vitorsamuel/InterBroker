extern "C" {
#include "tcp/server.h"
#include "tcp/listener.h"
//Database connection Test
//#include "database/lib_version.h"
//#include "database/server_version.h"
}

#include <cstdio>


int main()
{
	char* message;

    printf("Starting!!\n");

	//Database connection Test
	//version();
	//con_test();
	

	//Server Listener
	message = listen_entry();
	
	
    return 0;
}
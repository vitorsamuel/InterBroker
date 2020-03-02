#pragma once

#include <postgresql/libpq-fe.h>

#ifndef SERVER_VERSION_H 
#define SERVER_VERSION_H

void do_exit(PGconn *conn);

int con_test();


#endif
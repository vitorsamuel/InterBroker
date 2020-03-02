#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>


void do_exit(PGconn *conn) {
    
    PQfinish(conn);
    exit(1);
}

int con_test() {
    
    PGconn *conn = PQconnectdb("user=vitor password=vitor123 dbname=broker");

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
        do_exit(conn);
    }
    
    char *user = PQuser(conn);
    char *db_name = PQdb(conn);
    char *pswd = PQpass(conn);
    
    printf("User: %s\n", user);
    printf("Database name: %s\n", db_name);
    printf("Password: %s\n", pswd);
    
    PQfinish(conn);

    return 0;
}
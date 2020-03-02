#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>



int create() {
    
	PGconn *conn = PQconnectdb("user=vitor password=vitor123 dbname=broker");

    if (PQstatus(conn) == CONNECTION_BAD) {
        
        fprintf(stderr, "Connection to database failed: %s\n",
            PQerrorMessage(conn));
            
        PQfinish(conn);
        exit(1);
    }

    PGresult *res = PQexec(conn, "DROP TABLE IF EXISTS Entity");
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);
    }
    
    PQclear(res);
    
    res = PQexec(conn, "CREATE TABLE Entity(Id INTEGER PRIMARY KEY," \
        "Name VARCHAR(20), Version INT)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res); 
    }
    
    PQclear(res);
    
    res = PQexec(conn, "INSERT INTO Entity VALUES(1,'Account',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) 
        do_exit(conn, res);     
    
    PQclear(res);    
    
    res = PQexec(conn, "INSERT INTO Entity VALUES(2,'User',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);   
    }
    
    PQclear(res);    
    
    /*res = PQexec(conn, "INSERT INTO Entity VALUES(3,'Skoda',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);   
    }
    
    PQclear(res);  
    
    res = PQexec(conn, "INSERT INTO Entity VALUES(4,'Volvo',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);   
    }
    
    PQclear(res);      
    
    res = PQexec(conn, "INSERT INTO Entity VALUES(5,'Bentley',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);   
    }
    
    PQclear(res);  
    
    res = PQexec(conn, "INSERT INTO Entity VALUES(6,'Citroen',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);   
    }
    
    PQclear(res);  
    
    res = PQexec(conn, "INSERT INTO Entity VALUES(7,'Hummer',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);   
    }
    
    PQclear(res);  
    
    res = PQexec(conn, "INSERT INTO Entity VALUES(8,'Volkswagen',1)");
        
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        do_exit(conn, res);   
    }
    
    PQclear(res);  */
    PQfinish(conn);

    return 0;
}
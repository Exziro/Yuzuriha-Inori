/* J. David's webserver */  
/* This is a simple webserver. 
 * Created November 1999 by J. David Blackstone. 
 * CSE 4344 (Network concepts), Prof. Zeigler 
 * University of Texas at Arlington 
 */  
/* This program compiles for Sparc Solaris 2.6. 
 * To compile for Linux: 
 *  1) Comment out the #include <pthread.h> line. 
 *  2) Comment out the line that defines the variable newthread. 
 *  3) Comment out the two lines that run pthread_create(). 
 *  4) Uncomment the line that runs accept_request(). 
 *  5) Remove -lsocket from the Makefile. 
 */  
#include <stdio.h>  
#include <sys/socket.h>  
#include <sys/types.h>  
#include <netinet/in.h>  
#include <arpa/inet.h>  
#include <unistd.h>  
#include <ctype.h>  
#include <strings.h>  
#include <string.h>  
#include <sys/stat.h>  
#include <pthread.h>  
#include <sys/wait.h>  
#include <stdlib.h>  
  
#define ISspace(x) isspace((int)(x))  
  
#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"  
void accept_request(int);  
void bad_request(int);  
void cat(int, FILE *);  
void cannot_execute(int);  
void error_die(const char *);  
void execute_cgi(int, const char *, const char *, const char *);  
int get_line(int, char *, int);  
void headers(int, const char *);  
void not_found(int);  
void serve_file(int, const char *);  
int startup(u_short *);  
void unimplemented(int);  
  
/**********************************************************************/  
/* A request has caused a call to accept() on the server port to 
 * return.  Process the request appropriately. 
 * Parameters: the socket connected to the client */  
/**********************************************************************/ 
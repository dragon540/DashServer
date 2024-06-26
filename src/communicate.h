//
// Created by shobhit on 19/2/24.
//

#ifndef DASHSERVER_COMMUNICATE_H
#define DASHSERVER_COMMUNICATE_H

#include <stdint.h>

enum Content_Type {
    PLAIN,
    HTML,
};

enum Request_Type {
    GET,
    PUT,
    POST
};

// returns the pointer to a dynamically created string
// containing the first 256 characters
// free the memory from the caller side
char* recvdData_dyn(int communicateSock_fd);

// send() doesn't guarantee to send full data at once
// handles partial sends
// exits on error
void sendCompleteResponse(int sockfd, char *msg);

// returns socket id of the connection and sets
// char *url as url requested in the HTTP request
// sets reqType according to whether request tpe is GET, PUT, POST
int readReq(char *url, int *reqType, uint16_t port_num);

// assumes the HTTP method is GET
// sets the URL requested in char *url
// char *tempBuffer is the string of complete request
void readUrlFromGETReq(char *url, char *tempBuffer);

// assumes the HTTP method is PUT
// sets the URL requested in char *url
// char *tempBuffer is the string of complete request
void readUrlFromPUTReq(char *url, char *tempBuffer);

// assumes the HTTP method is POST
// sets the URL requested in char *url
// char *tempBuffer is the string of complete request
void readUrlFromPOSTReq(char *url, char *tempBuffer);

// reads the url requested and sends appropriate
// response after checking internally
void sendResponse(uint16_t port_num);

// 200 OK response depends on whether the type of request was GET, PUT, POST
// constructs appropriate 200 OK response based on type of request and sends it
void sendAppropriateResponse_200OK(int reqType, uint16_t port_num, int sock, char urlString[]);

void sendAppropriateResponse_404NotFound(int reqType, uint16_t port_num, int sock, char urlString[]);

// HTTP response consists of several parts including METHOD, Content-Length, Content-Type, content
// this function creates a valid HTTP/1.1 200 OK response
// ARGUMENTS - PLAIN or HTML, and a *content which points to the actual message to be sent
// RETURN - pointer to a dynamically allocated string denoting a valid OK response
// free the memory from the caller side
// 200 OK response depends on whether the type of request was GET, PUT, POST
char* constructOKResponseToSend_GET_dyn(int conType, char *content);
char* constructOKResponseToSend_PUT_dyn(int conType, char *content);
char* constructOKResponseToSend_POST_dyn(int conType, char *content);

char* construct_404NotFound_ResponseToSend_GET_dyn(int conType, char *content);

#endif //DASHSERVER_COMMUNICATE_H

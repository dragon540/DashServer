//
// Created by shobhit on 19/2/24.
//

#ifndef DASHSERVER_CONNECT_H
#define DASHSERVER_CONNECT_H

#include <stdint.h>

// return communication socket_fd on success
// otherwise exits
int estTcpConnection(uint16_t port_num);

#endif //DASHSERVER_CONNECT_H

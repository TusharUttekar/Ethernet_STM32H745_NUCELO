/*
  ***************************************************************************************************************
  ***************************************************************************************************************
  ***************************************************************************************************************

  File:		  tcpClientRAW.h
  Author:     ControllersTech.com
  Updated:    29-Jul-2021

  ***************************************************************************************************************
  Copyright (C) 2017 ControllersTech.com

  This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
  of the GNU General Public License version 3 as published by the Free Software Foundation.
  This software library is shared with public for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
  or indirectly by this software, read more about this on the GNU General Public License.

  ***************************************************************************************************************
*/


#ifndef INC_TCPCLIENTRAW_H_
#define INC_TCPCLIENTRAW_H_

#include "lwip/tcp.h"

/*  protocol states */
enum tcp_client_states
{
  ES_NONE = 0,
  ES_CONNECTED,
  ES_RECEIVING,
  ES_CLOSING
};

/* structure for maintaining connection infos to be passed as argument
   to LwIP callbacks*/
struct tcp_client_struct
{
  u8_t state;             /* current connection state */
  u8_t retries;
  struct tcp_pcb *pcb;    /* pointer on the current tcp_pcb */
  struct pbuf *p;         /* pointer on the received/to be transmitted pbuf */
};

void tcp_client_init(void);

#endif /* INC_TCPCLIENTRAW_H_ */

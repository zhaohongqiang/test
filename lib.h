#ifndef _LIB_H_
#define _LIB_H_

#include "j1939_internal.h"

/*=================================    ���п�ӿ�   ===================================*/
extern void enqueue_can_to_tx_fifo(const CAN *ptr_can);
extern void dequeue_can_from_rx_fifo(CAN *ptr_can);

/* ���� */
extern void debug_init(void);

#endif /* _LIB_H_ */

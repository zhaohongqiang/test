#ifndef _TYPEDEF_H_
#define _TYPEDEF_H_

#include <pthread.h>

#include "config.h"

/*=================================  ���Ͷ��� ==========================================*/
typedef unsigned char                           BOOL;
typedef unsigned char                           UINT8;
typedef char                                    INT8;
typedef unsigned short                          UINT16;
typedef short                                   INT16;
typedef unsigned int                            UINT32;
typedef int                                     INT32;
typedef unsigned long                           UINT64;
typedef long                                    INT64;
typedef double                                  F64;
typedef float                                   F32;
typedef void *                                  VOID_PTR;
typedef void *                                  (*THREAD_FUNC)(void *arg);

#ifndef  NULL
#define  NULL                                   ((void*)0)
#endif

#ifndef false
#define false                                   (0)
#endif
#ifndef true
#define true                                    (!false)
#endif

/*==============================   j1939Э��Ӧ�ò���Ϣ����   ====================================*/

/* GUI��(QT)�ɷ��͵���Ϣ���� */
typedef enum _SENDDED_MSG_TYPE{
    tx_req_addr,
    tx_declare_addr,
    tx_unable_declare_addr,
    tx_req_engine_speed,
    tx_engine_speed
}SENDDED_MSG_TYPE;

/* J1939Ӧ�ò���Ϣ */
typedef struct _MSG{
    INT8  data_length;
    UINT8  dp;
    UINT8  pf;
    UINT8  ps;
    UINT8  p;
    UINT32 pgn;
    UINT8  data[MSG_MAX_LENGTH];
}MSG;

/* GUI��(QT)�������ʱ��ȡ����Ϣ�ṹ */
typedef struct _DTC{
    UINT32 spn;
    UINT8 fmi;
    UINT8 oc;
}DTC;

/* GUI��(QT)���յ���Ϣ�ṹ */
typedef struct _RECVED_MSG{
    F32 total_distance;             /* 1�����             62977        0-3        0.1(km)/bit */
    F32 speed;                      /* 2������             62980        1-2        1/256(km/h) / bit */
    F32 roate_speed;                /* 3��ת��             62980        5-6        0.125(rpm) / bit */
    INT32 water_temperature;        /* 4��ˮ��             62980        3-4        1(��) / bit */
    UINT8 oil_left;                 /* 5��ʣ������         62980        0          (�ٷ���) / bit */
    F32 oil_valid;                  /* 6����ʱȼ�;�����   62978        3-4        1/512 (km/kg) /bit */
    F32 oil_used;                   /* 7��ȼ�������ٶ�     62978        5-6        0.05(L/h) / bit */
    F32 total_oil_use;              /* 8���ۼ��ͺ�         62981        0-3        0.5(L) / bit */
    INT32 oil_press;                /* 9������ѹ��         62979        0-1        4(kpa) / bit */
}RECVED_MSG;

/* ��·��PDU */
typedef struct _PDU{
    UINT8                 p_r_dp;
    UINT8                 pf;
    UINT8                 ps;
    UINT8                 sa;
    UINT8                 data[8];
}PDU;

/* �����can�� */
typedef struct _CAN{
    UINT32        id;
    UINT8         dlc;
    UINT8         data[8];
}CAN;                             /* CAN�� */

#ifdef PP_DEBUG_QUEUE
typedef INT32   DATA_T;
#else
typedef CAN     DATA_T;
#endif

typedef struct _QUEUE{
    DATA_T buf[QUEUE_BUF_SIZE];
    INT32 size;
    INT32 head;
    INT32 tail;
    pthread_mutex_t mutex;
}QUEUE;

#endif /* _TYPEDEF_H_ */

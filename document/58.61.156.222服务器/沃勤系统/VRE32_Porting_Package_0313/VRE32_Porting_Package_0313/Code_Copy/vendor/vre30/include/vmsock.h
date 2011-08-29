/*
 *
 * TCP 的异步实现，对于TCP链路的事件会由异步方式
 * 通知客户端。需要通知客户端的事件如下:
 * 
 * VM_TCP_EVT_CONNECTED
 * 在TCP链路连接后把该事件通知客户端，该连接后对于TCP 的
 * 的读写通道都是可写，可读的。
 *
 * VM_TCP_EVT_CAN_READ
 * 在用户读阻塞后，当TCP链路中又有可读的数据，本实现会
 * 把该事件返回给客户端，通知客户端继续读取。在客户端
 * 调用vm_tcp_read函数的时候，返回0则表示当前读通道已经
 * 处于读阻塞状态，客户程序不应该再继续调用vm_tcp_read函数，
 * 而应该等待收到VM_TCP_EVT_CAN_READ事件后再继续读。
 *
 * VM_TCP_EVT_CAN_WRITE  
 * 在用户写阻塞后，当TCP链路中的buffer 又有空间可写时，
 * 本实现会把该事件返回给客户端，通知客户端继续写数据。
 * 在客户端调用vm_tcp_write函数的时候，返回0则表示当前写
 * 通道已经处于写阻塞状态，客户程序不应该再继续调用
 * vm_tcp_write函数，而应该等待收到VM_TCP_EVT_CAN_WRITE事件后再
 * 继续写。
 *
 * VM_TCP_EVT_PIPE_BROKEN
 * 该事件会在TCP通道连接失败的时候异步返回给客户端，
 * 客户端在收到该事件后，不应该再往通道里写数据或
 * 读数据，也不用继续调用vm_tcp_close函数。而应该重新建立
 * TCP连接。
 * 
 * VM_TCP_EVT_HOST_NOT_FOUND
 * 该事件只会在CMNET连接的时候才有可能返回该事件。在
 * CMNET连接时，通过主机名获取IP地址失败，该事件会被返回
 * 到客户端，客户程序在收到该事件后，不应该再往通道里
 * 写数据或读数据，也不应该调用vm_tcp_close函数，该TCP链路
 * 会被自动关闭。
 *
 * VM_TCP_EVT_PIPE_CLOSED
 * 该事件只在TCP链路已经建立后，也就是客户程序在收到
 * VM_TCP_EVT_CONNECTED事件后，如果这个时候通讯双方的任何
 * 一方关闭TCP连接，那么当TCP连接关闭后，客户端程序会
 * 收到该事件，就算是客户自己调用vm_tcp_close函数，也会
 * 收到该事件的通知。
 *
 */

#ifndef VM_SOCK_H
#define VM_SOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmglobalver.h"
/**
 * TCP链路已经建立，此时链路处在可读写状态。
 */
#define VM_TCP_EVT_CONNECTED	1

/**
 * TCP链路处在可写状态。
 */
#define VM_TCP_EVT_CAN_WRITE	2

/**
 * TCP链路处于可读状态。
 */
#define VM_TCP_EVT_CAN_READ		3

/**
 * TCP链路中断。
 */
#define VM_TCP_EVT_PIPE_BROKEN	4

/**
 * 主机未找到，这是在执行DNS解析失败后返回的状态。
 */
#define VM_TCP_EVT_HOST_NOT_FOUND	5

/*
 * TCP链路被关闭后的事件。
 */
#define VM_TCP_EVT_PIPE_CLOSED	6

/**
 * 没有足够资源来建立TCP链路。
 */
#define VM_TCP_ERR_NO_ENOUGH_RES	-1

/**
 * 创建套接字失败。
 */
#define VM_TCP_ERR_CREATE_FAILED	-2

/**
 * @name VRE支持的Access Point Name。
 * @{
 */
/**
 * 使用GPRS/CMNET帐号创建链接。
 */
#define VM_TCP_APN_CMNET		(1)

/**
 * 使用GPRS/CMWAP帐号创建链接。
 */
#define VM_TCP_APN_CMWAP		(2)

/**
 * 使用WLAN(802.11b/g)创建链接。
 */
#define VM_TCP_APN_WIFI		(3)
/** @} */

/**
 * 创建TCP连接，这是一个异步方法，连接状态通过回调函数回传给应用程序。
 * 如果系统返回大于等于0的TCP连接句柄，连接则处于可读写状态。在VRE中
 * 网络的读写都是异步模式，这是VRE的单任务特性决定的，应用程序必须以
 * 异步方式读写网络数据。
 *
 * @param host				远程主机名，可以为点分十进制格式的IP地址。
 * @param port				远程主机端口。
 * @param apn				连接所使用的GPRS帐号，必须为VM_TCP_APN_CMNET
 *							或VM_TCP_APN_CMWAP，以及VM_TCP_APN_WIFI。<br></br>
 *							CMNET是中国移动提供的手机直连互联网的APN，
 *							此时手机可以认为就是一个MODEM。<br></br>
 *							CMWAP是只用于承载WAP业务的APN，应用程序必须
 *							通过中国移动的WAP GATEWAY代理连接服务器，此时DNS
 *							默认不开，只能访问到10.0.0.172代理服务器。<br></br>
 *							VM_TCP_APN_WIFI使用Wi-Fi方式对已经连接上WLAN上的资源
 *							进行访问的APN。在使用本函数前可以调用vm_tcp_wifi_connected
 *							函数查询WIFI是否已经连接，如果在没有连接的情况下调用
 *							本函数，则可能得到VM_TCP_ERR_CREATE_FAILED。
 *
 * @param callback			事件回调函数，系统通过这个回调函数向应用
 *							程序传递TCP链路的状态。回调函数的第一个参
 *							数是vm_tcp_connect返回的句柄，event为TCP的链路的事件。
 *
 * @return					返回大于等于0的TCP连接句柄表示系统已经接收
 *							了连接请求，否则返回负数表示错误。
 */
VMINT vm_tcp_connect(const char* host, const VMINT port, const VMINT apn,
	void (*callback)(VMINT handle, VMINT event));

/**
 * 关闭TCP链路。
 *
 * @param handle			必须是由vm_tcp_connect()返回的句柄。
 */
void vm_tcp_close(VMINT handle);

/**
* TCP读链路读到了流的结束。
*/
#define VM_TCP_READ_EOF				(-1)

/**
 * 从TCP链路中读取若干字节。
 *
 * @param handle			TCP连接句柄。
 * @param buf				读缓冲区。
 * @param len				读缓冲区长度。
 *
 * @return					返回读取的字节数，返回0表示链路中没有数据可读，读链路
 *							阻塞。返回VM_TCP_READ_EOF表示读取到了流的结束，此时应用程序
 *							应该调用vm_tcp_close关闭连接。返回其它负数则表示链路发生异常，
 *							此时程序员应关闭链路。
 */
VMINT vm_tcp_read(VMINT handle, void* buf, VMINT len);

/**
 * 向TCP链路写入若干字节。
 *
 * @param handle			TCP连接句柄。
 * @param buf				存储写出数据的缓冲区地址指针。
 * @param len				要写出多少个字节。
 *
 * @return					返回实际写入TCP链路的字节数量。
 */
VMINT vm_tcp_write(VMINT handle, void* buf, VMINT len);


/**
 * 手机平台是否支持Wi-Fi。
 *
 * @return 		是否支持Wi-Fi。
 * @retval 		FALSE 表示不支持。
 * @retval 		TRUE 表示支持。
 */
VMINT vm_is_support_wifi(void);

/**
 * Wi-Fi是否已经连上。
 *
 * @return 		是否已经连上。
 * @retval 		FALSE 表示未连上。
 * @retval 		TRUE 表示已经连上。
 */
VMINT vm_wifi_is_connected(void);




typedef void (*vre_gprs_acct_set_done_callback)(void);


typedef void (*vm_tcp_check_ready_callback)(int);

#ifdef __cplusplus
}
#endif

#endif

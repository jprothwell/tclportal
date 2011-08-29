#ifndef HTTPUTIL_H
#define HTTPUTIL_H

#include "vmsys.h"
#include "vmhttp.h"
#include "vmstdlib.h"

#ifdef __cplusplus
extern "C" {
#endif

#define HTTP_HEAD_BUFFER_LEN		(1024 * 4)

/**
 * 读HTTP 头输入流的缓冲。
 */
struct http_head_buffer_t {
	int read_avail;									/* 在缓冲里总共可读的字节数 */
	int read_pos;									/* 在缓冲里当前正在读取的下标  */
	unsigned char buffer[HTTP_HEAD_BUFFER_LEN];		/* 缓冲 */
};

/**
 * HTTP会话队列。
 */
struct queue_item_t {	
	int active;					/* 激活状态。				*/
	http_session_t* session;		/* HTTP会话。				*/
	enum {CONNECTING, SENDING, RECV_STATUS_LINE, RECV_HEAD, RECV_BODY} state;	/* HTTP会话状态。*/
	enum {VM_SOC_CONNECTED, VM_SOC_CAN_READ, VM_SOC_CAN_WRITE, VM_SOC_ERROR} soc_state;	/* 套接字状态。	*/
	int dns_req_id;				/* DNS解析请求编号。	*/
	int sent;						/* 已发送字节数。		*/
	int read;						/* 已收到字节数。		*/
	vm_cache_t cache;			/* 缓存。*/
	enum {FIXED_LENGTH, CHUNKED} cnt_len_type;				/* HTTP响应长度类型。*/
	int chunk_len;				/* 块长度。					*/
	int body_buf_len;			/* 响应体缓冲区长度。	*/
	struct http_head_buffer_t http_head_buffer;						/* HTTP响应头和状态行的缓冲。*/
};
	
#define QUEUE_SIZE 3
	
#define SEND_NOTIFY(state, param) if (notify_callback != NULL) notify_callback(state, param)

/**
 * 分解URL的各个部分。
 */
int unpack_url(char* url, char* scheme, char* host, int* port, char* res, char* param);

/**
 * 分解URL主机名部分的主机名和端口。
 */
void unpack_host(char* url, char* host, int* port);

/**
 * 分解HTTP头。
 */
int unpack_head(char* s, char* name, char* value);

/**
 * 把HTTP会话加入处理队列。
 */
struct queue_item_t* enqueue(http_session_t* session);

/**
 * 处理HTTP会话。
 */
int proc_session(struct queue_item_t* item);

/**
 * 处理HTTP会话队列。
 */
void proc_queue(int tid);

/**
 * 处理HTTP会话队列的给定元素。
 */
void proc_queue_item(struct queue_item_t* item);

/**
 * 增加HTTP请求报头，如果HTTP的HEAD上已经有了同名的HEAD NAME，那么新的HEAD VALUE
 * 会替换掉老的HEAD VALUE。
 */
int add_http_request_head(http_session_t *session, char* name, char* value);

/**
 * 重设HTTP请求URL ，原有URL将被新的URL替换
 */
int reset_http_request_line(http_session_t *session, VMCHAR* url);

/**
 * 设置HTTP请求体。
 */
int set_http_request_body(http_session_t *session, int len, void* buf);

/**
 * 根据DNS解析请求编号找到相应的队列元素。
 */
struct queue_item_t* get_item_by_dns_req_id(int dns_req_id);

/**
 * 根据SOCKET编号获得相应的队列元素。
 */
struct queue_item_t* get_item_by_soc_id(SOCKET_T soc_id);

#ifdef __cplusplus
}
#endif

#endif

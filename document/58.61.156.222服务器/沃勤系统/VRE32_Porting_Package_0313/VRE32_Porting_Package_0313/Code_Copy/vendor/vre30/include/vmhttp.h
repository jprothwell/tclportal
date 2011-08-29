#ifndef VMHTTP_H_
#define VMHTTP_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 发送HTTP请求时默认的user-agent.
 */
#define USER_AGENT "HTTP4VRE/1.3.0(VRE)"

/**
 * HTTP请求的长度，包括HTTP请求的报头和报体的长度。
 */
#define HTTP_REQUEST_BUFSIZE 			(4096)

/**
 * HTTP响应报头的长度，不包括报体长度。
 */
#define HTTP_RESPONSE_HEADSIZE 		(8192)

/**
 * HTTP缓冲长度，用于提高网络读速度。
 */
#define HTTP_CACHE_SIZE 				(5 * 1024)

#ifdef WIN32
	typedef unsigned int SOCKET_T;
#else
	typedef int SOCKET_T;
#endif

/**
 * 解析远程主机名状态，param参数没有意义。
 */
#define HTTP_STATE_GET_HOSTNAME		(1)

/**
 * 连接远程主机状态，param参数没有意义。
 */
#define HTTP_STATE_CONNECTING			(2)

/**
 * 发送HTTP请求状态，param参数表示已发送字节的百分比。
 */
#define HTTP_STATE_SENDING			(3)

/**
 * 接收HTTP响应状态行状态，param参数没有意义。
 */
#define HTTP_STATE_RECV_STATUS		(4)

/**
 * 接收HTTP响应头状态，param参数没有意义。
 */
#define HTTP_STATE_RECV_HEADS			(5)

/**
 * 接收HTTP响应体状态，param参数表示接受到字节的百分比。
 */
#define HTTP_STATE_RECV_BODY			(6)

/**
 * HTTP会话。用于连接HTTP请求和响应关系，包括用户提供的回调函数。
 */
struct http_session_t {
	SOCKET_T s;								/* SOCKET句柄。								*/
	char url[255];							/* 请求地址。								*/
	char host[100];							/* 服务器主机名。							*/
	VMUINT8 ip_addr[4];						/* 主机名对应的IP地址。						*/
	VMUINT8 ip_addr_len;					/* IP地址长度。								*/
	int port;								/* 服务器端口，默认80。						*/
	int nreqbuf;							/* 请求缓冲区长度。							*/
	char reqbuf[HTTP_REQUEST_BUFSIZE];		/* 请求缓冲区。								*/
	int res_code;							/* HTTP响应码，返回负数表示TCP通信失败。	*/
	int nresbuf;							/* HTTP响应头缓冲区的长度。					*/
	VMUINT8 resbuf[HTTP_RESPONSE_HEADSIZE];	/* HTTP响应头缓冲区。						*/
	int nresbody;							/* HTTP响应体的长度。						*/
	VMUINT8* resbody;						/* HTTP响应体。								*/
	void (*hook)(int, void*);				/* 异步HTTP回调函数，由应用程序提供。		*/
	VMWCHAR lasterr[50];					/* 发生错误后最后错误的中文解释。			*/
};
typedef struct http_session_t http_session_t;

/**
 * HTTP头。
 */
struct http_head_t {
	char name[20];				/* 头部名称。		*/
	char value[100];			/* 头部值。			*/
};
typedef struct http_head_t http_head_t;

/**
 * HTTP请求。
 */
struct http_request_t {
	char url[255];					/* 地址。										*/
	int nhead;					/* 附加请求头的个数。					*/
	http_head_t *heads;			/* 附加请求头数组指针。				*/
	int nbody;					/* 附加请求体的长度，字节单位。	*/
	char* body;					/* 附加请求体指针。						*/
};
typedef struct http_request_t http_request_t;

/**
 * 发起HTTP请求，这是一个异步方法，调用后立即返回，HTTP响应报文通过回调函数返回。
 *
 * @param request			HTTP请求体。
 * @param session			HTTP会话。
 *
 * @return					返回0表示成功，否则为错误码。
 */
int vm_http_request(http_request_t *request, http_session_t *session);

/**
 * 获得HTTP响应报文中的头。
 *
 * @param session			HTTP会话。
 * @param name				HTTP头名称。
 * @param value				HTTP头对应的值。
 *
 * @return					返回0表示成功，否则为失败。
 */
int get_http_head(http_session_t* session, const char* name, char* value);

/**
 * 获得HTTP响应报头中的头数量。
 *
 * @param session			HTTP会话。
 *
 * @return					头数量。
 */
int get_http_head_number(http_session_t* session);

/**
 * 获得HTTP响应报文中的头。
 *
 * @param session			HTTP会话。
 * @param index				需要得到http head的索引值。
 * @param name				HTTP头名称。
 * @param value				HTTP头对应的值。
 *
 * @return					返回0表示成功，否则为失败。
 */
int get_http_head_by_index(http_session_t* session, int index, char* name, char* value);

/**
 * 取消所有活跃的HTTP会话，已经建立的TCP链路被立即中断。会话中断后系统不会向应用程序
 * 回调函数发送消息。
 */
void vm_cancel_all_http_sessions(void);

/**
 * 注册HTTP状态回调函数，HTTP协议栈通过回调方式把通信中各个状态回传给应用程序。
 *
 * @param f					状态回调函数，state参数表示当前所处的状态，param
 *							表示与当前在状态关联的值，详见HTTP_STATE_定义。
 */
void vm_reg_http_notification(void (*f)(VMINT state, VMINT param));

/**
 * 打开/关闭HTTP协议栈的代理功能，当代理功能打开时，系统通过CMWAP访问网络资源。
 * 当代理功能关闭时，系统通过CMNET访问网络资源。HTTP协议栈默认工作在代理模式下，
 * 代理模式的切换是全局性的，即程序员改变了代理模式后HTTP协议栈会一直工作在给定
 * 模式下，直到程序员改变了代理模式。
 *
 * @param use_proxy			TRUE代表使用代理模式，FALSE代表不使用代理模式。
 */
void vm_enable_proxy(VMINT use_proxy);


/**
  * HTTP request method的枚举类型的定义，但并不是这里的所有HTTP
  * request method 的类型都会被VRE的HTTP协议栈实现，需要查看相应
  * VRE的实现版本说明。
  */
typedef enum {
	GET = 1, 
	POST, 
	HEAD, 
	PUT, 
	DELETE, 
	TRACE, 
	CONNECT
}HTTP_METHOD;

/**
 * asyn_http_req_t.use_proxy的HTTP联网类型参数。
 */
typedef enum 
{
	HTTP_USE_CMNET = 0,				/**<用CMNET(移动cmnet或联通uninet) 进行联网,如果找不到对应的APN则可能联网失败。 											*/
	HTTP_USE_CMWAP, 					/**<用CMWAP(移动cmwap或联通uniwap)进行联网,如果找不到对应的APN则可能联网失败。											*/	
	HTTP_USE_CMNET_PRIORITY,			/**<如果找不到对应的CMNET(移动cmnet或联通uninet)联网的APN,则会去找对应CMWAP(移动cmwap或联通uniwap) APN进行联网。 	*/
	HTTP_USE_CMWAP_PRIORITY,			/**<如果找不到对应的CMWAP(移动cmwap或联通uniwap)联网的APN,则会去找对应CMNET(移动cmnet或联通uninet) APN进行联网。 	*/
	HTTP_USE_WIFI,						/**<用Wi-Fi方式进行连接。																														*/
	HTTP_USE_WIFI_CMNET,			/* wifi优连，wifi已经连上，用wifi连接，否则用HTTP_USE_CMNET方式 */
	HTTP_USE_WIFI_CMWAP,			/* wifi优连，wifi已经连上，用wifi连接，否则用HTTP_USE_CMWAP方式 */
	HTTP_USE_WIFI_CMNET_PRIORITY,	/* wifi优连，wifi已经连上，用wifi连接，否则用HTTP_USE_CMNET_PRIORITY方式 */
	HTTP_USE_WIFI_CMWAP_PRIORITY	/* wifi优连，wifi已经连上，用wifi连接，否则用HTTP_USE_CMWAP_PRIORITY方式 */
} VM_HTTP_PROXY_TYPE;

/**
  * 异步HTTP请求，在http_request_t扩充了VRE先前的HTTP请求缺失的
  * HTTP request method 和是否使用代理的字段。
  */
typedef struct asyn_http_req_t {
	HTTP_METHOD 	req_method;	/**<HTTP_METHOD类型。			*/
	VMUINT8 		use_proxy;		/**<VM_HTTP_PROXY_TYPE类型。	*/
	http_request_t* 	http_request;	/**<HTTP请求。					*/
}asyn_http_req_t;

/**
  * 调用vm_asyn_http_req函数返回值的定义。
  * 
  * ASYN_HTTP_REQ_ACCEPT_SUCCESS
  * 接受HTTP 请求成功，VRE将会 异步发送HTTP请求。
  *
  * ASYN_HTTP_REQ_NOT_SUPPORT_METHOD
  * 不支持当前的HTTP method。
  *
  * ASYN_HTTP_REQ_NOT_SUPPORT_HTTP_COMM
  * 不支持HTTP协议栈的通信。
  *
  * ASYN_HTTP_REQ_ONLY_SUPPORT_PROXY
  * 仅仅支持代理模式-即CMWAP。
  *
  * ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE
  * HTTP协议栈没有足够的资源，无法接受此次HTTP请求。
  * 如果HTTP只支持一个HTTP连接，在HTTP协议栈还没有
  * 把HTTP response通过客户程序注册到协议栈的回调函数
  * 之前又调用vm_asyn_http_req函数，那么该该结果将回被
  * 返回。
  *
  * ASYN_HTTP_REQ_URL_FORMAT_ERROR
  * HTTP格式错误。
  */
#define ASYN_HTTP_REQ_ACCEPT_SUCCESS								(0)
#define ASYN_HTTP_REQ_NOT_SUPPORT_METHOD						(1)
#define ASYN_HTTP_REQ_NOT_SUPPORT_HTTP_COMM					(2)
#define ASYN_HTTP_REQ_ONLY_SUPPORT_PROXY						(3)
#define ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE						(4)
#define ASYN_HTTP_REQ_URL_FORMAT_ERROR							(5)

/**
  * 发起一个HTTP请求，这是一个异步函数，调用后本函数将会立即返回。
  * 正确读取完HTTP响应后VRE HTTP协议栈将会通过用户注册上来的http_hook
  * 函数指针回调回客户程序。本函数参数表中http_state_notify是另外一个
  * 客户程序注册上来的函数指针，在HTTP通信过程中的各个时期
  * (HTTP_STATE_GET_HOSTNAME，HTTP_STATE_CONNECTINGHTTP_STATE_SENDING，
  * HTTP_STATE_RECV_STATUS，HTTP_STATE_RECV_HEADS，HTTP_STATE_RECV_BODY)，
  * 都会通过该个客户程序注册到HTTP协议栈中函数指针回调回去。http_hook和
  * http_state_notify这两个由客户程序注册到HTTP协议栈的函数指针,都是和
  * request参数对应起来。如果HTTP协议栈支持多于一个HTTP的并发请求，那么
  * 这样保证了各个HTTP请求的状态是相互独立的，并且是互不干扰的。
  *
  * @param 				request http 请求，如果该指针指向 null，那么本函数
  *						将会也将会返回ASYN_HTTP_REQ_ACCEPT_SUCCESS，但是
  *						HTTP协议栈将不会有任何的动作。
  *
  * @param 				http_hook 客户程序注册到HTTP协议栈上的函数指针，
  *						该函数将回被顺利读取HTTP response后调用或在
  *						HTTP通讯过程中发生错误后回调。客户程序注册到
  *						HTTP协议栈的函数必须有两个参数，第一个参数是
  *						VMINT类型表示是否接受http请求成功。为0表示成功，
  *						那么否者为失败。第二个参数是一个指向http_session_t
  *						的指针类型。只有在第一个参数为0的时候第二个参数
  *						才有意义，否者该指针指向null。
  *
  * @param				http_state_notify 客户注册到HTTP协议栈的函数指针。
  *						该函数将会在http的通讯的各个阶段回调。但
  *						在HTTP协议栈回调过http hook后，那么该函数将不
  *						会再被HTTP协议栈回调回来。
  *
  * @return 				返回码，如果成功的接受HTTP request 则返回
  *						ASYN_HTTP_REQ_ACCEPT_SUCCESS，否则返回相应的错误码。
  */
VMINT vm_asyn_http_req(asyn_http_req_t *request, void (*http_hook)(VMINT, void*), 
	void (*http_state_notify)(VMINT state, VMINT param, void* session));

/**
 * @name vm_get_asyn_http_req_handle函数的返回值
 * @{
 */
/**
 * 得到HTTP 句柄成功。
 */
#define VM_GET_AHH_SUCCESS					(0)
/**
 * 找不到指定REQUEST的HTTP句柄。
 */
#define VM_GET_AHH_NO_COMM				(-1)
/**
 * 错误的参数。
 */
#define VM_GET_AHH_ERROR_PARAM			(-2)
/** @} */

/**
 * 得到异步HTTP请求所关联的句柄。
 * @code
 * asyn_http_req_t req;
 * http_request_t internal_req;
 * 
 * req.http_request = &internal_req;
 * req.req_method = GET;
 * internal_req.nhead = internal_req.nbody = 0;
 * strcpy(internal_req.url, "http://www.google.cn");
 * 
 * if (vm_asyn_http_req(&req, http_hook_callback, http_state_callback) == ASYN_HTTP_REQ_ACCEPT_SUCCESS)
 * {
 *     VMINT handle = 0;
 *     vm_get_asyn_http_req_handle(&req, &handle); // 这里就得到了请求所关联的HTTP句柄。
 * }
 * @endcode
 * @param[in]			request http请求。
 * @param[out]			handle 把HTTP 句柄写入该指针指向地址中。
 * @return 				是否得到关联的句柄标志。
 * @retval				VM_GET_AHH_SUCCESS 得到句柄成功。
 * @retval				VM_GET_AHH_NO_COMM 找不到HTTP REQUEST对应的HTTP 句柄。
 * @retval				VM_GET_AHH_ERROR_PARAM 错误的参数。
 */
VMINT vm_get_asyn_http_req_handle(asyn_http_req_t* request, VMINT* handle);

/**
 * @name vm_cancel_asyn_http_req 的返回值。
 * @{
 */
/**
 * 取消成功。
 */
#define VM_CAH_REQ_SUCCESS			(0)
/**
 * 当前没有指定的句柄的HTTP连接。
 */
#define VM_CAH_REQ_NO_COMM		(-1)
/** @} */

/**
 * 取消一个指定句柄的HTTP请求。
 * 
 * @param[in]				handle HTTP句柄，该句柄通过vm_get_asyn_http_req_handle
 * 						函数得到。
 * @return				需要HTTP请求连接与否的标志。
 * @retval				VM_CAH_REQ_SUCCESS 取消HTTP请求成功。
 * @retval				VM_CAH_REQ_NO_COMM 没有指定句柄的HTTP 请求被发起。
 */
VMINT vm_cancel_asyn_http_req(VMINT handle);

/**
 * 把给定的GB2312编码的字符串进行URL编码。
 * 
 * @param[out] 			dst	存放编码好后的字符串的内存空间的首地址,URL编码后的内容将存放
 *						在该空间中.如果在写入全部编码的内容后还有剩余的空间将写入数值0
 *						来标志字符串的结束.
 * @param[in] 			size	存放编码好后的字符串的内存空间大小，单位为字节。
 * @param[in] 			src	需要被编码的字符串.
 *
 * @return				返回已经写入dst中的字节个数,不包含标志字符串结束的数值0.
 */
VMUINT vm_url_encode_gb2312(VMSTR dst, VMUINT size, const VMSTR src);

/**
 * 把给定的经过URL编码的GB2312格式的字符串进行URL解码。
 * 
 * @param[out] 			dst 存放解码好后的字符串的内存空间的首地址,URL解码后的内容将存放
 *						在该空间中.如果在写入全部编码的内容后还有剩余的空间, 那么将写入
 *						数值0来标志字符串的结束.
 * @param[in] 			size 存放解码好后的字符串的内存空间大小，单位为字节。
 * @param[in] 			src 需要解码的字符串。
 * 
 * @return				返回已经写入dst中的字节个数,不包含标志字符串结束的数值0.
 */
VMUINT vm_url_decode_gb2312(VMSTR dst, VMUINT size, VMSTR src);

/*********************************************************************
 * HTTP模块新增的接口定义 2009-11-18
 *********************************************************************/

/**
 * HTTP报文块接收回调函数。
 * 若回调函数被注册，HTTP模块会调用此函数接收HTTP报文体。
 * 调用vm_http_recv_data函数接收HTTP响应报文体块数据，并将返回值返回。
 *
 * @param[in] 			handle HTTP句柄
 * @param             		p 保留字段
 *
 * @return 				>0 时接收数据的总长度, ==0时表示阻塞, <0时表示出错
 */
typedef VMINT(*http_data_receiver)(VMINT handle, void* p);

/**
 * 注册HTTP报文块下载回调函数指针
 *
 * @param[in] 			reciever 由应用端提供的数据分块上传函数，
 *                 				在其中调用vm_http_post_data处理数据分块上传。
 *
 * @return 				是否成功
 */
VMINT vm_http_reg_receiver(VMINT handle, http_data_receiver reciever);

/**
 * 接收HTTP报文块。
 * 
 * VMCHAR data[128]
 * while(数据未完成接收)
 * {
 *     retlen = vm_http_recv_data(handle, data, len);
 *     //判断retlen的值：>0; ==0; <0
 *     //处理接收的数据
 * }
 *
 * @param[in] 			handle HTTP句柄
 * @param[out] 			data 用来接受HTTP响应报文块的字符缓冲区指针
 * @param[in] 			len 应用欲接收的HTTP响应报文块大小
 *
 * @return	 			真实接收到的报文块大小
 */
VMINT vm_http_recv_data(VMINT handle, VMUINT8* data, VMINT len);

/**
 * HTTP报文块发送回调函数。
 * 若回调函数被注册，HTTP模块会调用此函数发送HTTP报文体。
 * 调用vm_http_send_data 函数上传HTTP请求报文体块数据，并将返回值返回。
 *
 * @param[in] 			handle HTTP句柄
 * @param             		p 保留字段
 *
 * @return 				>0 时接收数据的总长度, ==0时表示阻塞, <0时表示出错
 */
typedef VMINT(*http_data_sender)(VMINT handle, void* p);
/**
 * 注册HTTP报文块上传回调函数。
 *
 * @param[in] 			sender 由应用端提供的数据分块上传函数，
 *               				在其中调用vm_http_send_data处理数据分块上传。
 *
 * @return 				是否成功
 */
VMINT vm_http_reg_sender(VMINT handle, http_data_sender sender);

/**
 * 发送HTTP报文块。
 * 在发起HTTP请求后调用此接口。
 *
 * VMCHAR data[128]
 * while((len=get_data(data)) > 0)
 * {
 *     vm_http_post_data(handle, data, len);
 * }
 *
 * @param[in] 			handle HTTP 句柄
 * @param[in] 			data HTTP 请求报文块
 * @param[in] 			len HTTP 请求报文块长度
 * @return 				是否成功
 */
VMINT vm_http_send_data(VMINT handle, VMUINT8* data, VMINT len); 

/**
 * 添加HTTP 请求报头字段，应用自行维护name, value 的内存空间。
 * 在发起HTTP请求前调用此接口。
 * 注意: name + value 长度不要超过400 字节，否则可能出错。
 *
 * @param[in] 			handle HTTP 句柄
 * @param[in] 			name HTTP 报头名称
 * @param[in] 			value HTTP 报头值
 *
 * @return 				是否成功
 */
VMINT vm_http_add_header(VMINT handle, VMCHAR* name, VMCHAR* value);

/**
 * 设置HTTP 请求URL ，应用自行维护url 的内存空间。
 * 在发起HTTP请求前调用此接口。
 * 注意:URL 长度不要超过400 字节，否则可能出错。
 *
 * @param[in] 			handle HTTP 句柄
 * @param[in] 			url HTTP 请求URL 。
 *						URL 解析后的数据在Request-Line 和Header 中的Host 中被使用。
 * @param[in] 			value HTTP 请求URL 长度。
 *
 * @return 				是否成功
 */
VMINT vm_http_set_url(VMINT handle, VMCHAR* url, VMINT len);

/**
 * 设置HTTP 请求报文体。
 * 在发起HTTP 请求前调用此接口。
 * 请求发出后用户自行释放报文数据内存。
 * 
 *
 * @param[in] 			handle HTTP句柄
 * @param[in] 			data HTTP请求报文体数据指针。
 *						可为NULL，此时报文体数据通过回调函数上传。
 * @param[in] 			len HTTP请求报文体长度。
 *						将被写入请求头中的Content-Length字段中。
 *
 * @return 				是否成功
 */
VMINT vm_http_set_body(VMINT handle, VMUINT8* data, VMINT len);

/**
  * 
  */
typedef enum {
	ASYN_HTTP_REQ = 0, 
	HTTP_REQUEST
} HTTP_HANDLE_TYPE;

/**
 * 取得一个可用的HTTP句柄。
 * 支持根据所创建的句柄，通过 vm_set_http_header(), vm_set_http_body()
 * 动态配置HTTP请求的内容。
 *
 * @param[in] 			type 获取HTTP句柄的请求类型
 * @param[in] 			p 获取HTTP句柄的请求类型结构体指针
 *
 * @return 				HTTP句柄
 */
VMINT vm_http_fetch_handle(VMINT type, void* p);

/**
 * 获取当前正被处理的HTTP句柄。
 * 可能需要在调用HTTP请求前判断当前句柄。
 *
 * @return 				HTTP句柄
 */
VMINT vm_http_get_current_handle(void);

/**
 * 设置当前正被处理的HTTP句柄。
 *
 * @param[in] 			handle 想要被处理的HTTP句柄
 *
 * @return 				HTTP 句柄
 */
VMINT vm_http_set_current_handle(VMINT handle);

/**
 * 释放HTTP句柄及相关所有资源。
 * 在完成HTTP操作后或在用户发出中断请求后调用。
 *
 * @param[in] 			handle HTTP句柄
 */
void vm_http_free_handle(VMINT handle);

/**
void vm_http_test_entrance(void);
 */

#ifdef __cplusplus
}
#endif

#endif /*HTTP_H_*/

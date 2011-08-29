#ifndef VMHTTP_H_
#define VMHTTP_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * ����HTTP����ʱĬ�ϵ�user-agent.
 */
#define USER_AGENT "HTTP4VRE/1.3.0(VRE)"

/**
 * HTTP����ĳ��ȣ�����HTTP����ı�ͷ�ͱ���ĳ��ȡ�
 */
#define HTTP_REQUEST_BUFSIZE 			(4096)

/**
 * HTTP��Ӧ��ͷ�ĳ��ȣ����������峤�ȡ�
 */
#define HTTP_RESPONSE_HEADSIZE 		(8192)

/**
 * HTTP���峤�ȣ��������������ٶȡ�
 */
#define HTTP_CACHE_SIZE 				(5 * 1024)

#ifdef WIN32
	typedef unsigned int SOCKET_T;
#else
	typedef int SOCKET_T;
#endif

/**
 * ����Զ��������״̬��param����û�����塣
 */
#define HTTP_STATE_GET_HOSTNAME		(1)

/**
 * ����Զ������״̬��param����û�����塣
 */
#define HTTP_STATE_CONNECTING			(2)

/**
 * ����HTTP����״̬��param������ʾ�ѷ����ֽڵİٷֱȡ�
 */
#define HTTP_STATE_SENDING			(3)

/**
 * ����HTTP��Ӧ״̬��״̬��param����û�����塣
 */
#define HTTP_STATE_RECV_STATUS		(4)

/**
 * ����HTTP��Ӧͷ״̬��param����û�����塣
 */
#define HTTP_STATE_RECV_HEADS			(5)

/**
 * ����HTTP��Ӧ��״̬��param������ʾ���ܵ��ֽڵİٷֱȡ�
 */
#define HTTP_STATE_RECV_BODY			(6)

/**
 * HTTP�Ự����������HTTP�������Ӧ��ϵ�������û��ṩ�Ļص�������
 */
struct http_session_t {
	SOCKET_T s;								/* SOCKET�����								*/
	char url[255];							/* �����ַ��								*/
	char host[100];							/* ��������������							*/
	VMUINT8 ip_addr[4];						/* ��������Ӧ��IP��ַ��						*/
	VMUINT8 ip_addr_len;					/* IP��ַ���ȡ�								*/
	int port;								/* �������˿ڣ�Ĭ��80��						*/
	int nreqbuf;							/* ���󻺳������ȡ�							*/
	char reqbuf[HTTP_REQUEST_BUFSIZE];		/* ���󻺳�����								*/
	int res_code;							/* HTTP��Ӧ�룬���ظ�����ʾTCPͨ��ʧ�ܡ�	*/
	int nresbuf;							/* HTTP��Ӧͷ�������ĳ��ȡ�					*/
	VMUINT8 resbuf[HTTP_RESPONSE_HEADSIZE];	/* HTTP��Ӧͷ��������						*/
	int nresbody;							/* HTTP��Ӧ��ĳ��ȡ�						*/
	VMUINT8* resbody;						/* HTTP��Ӧ�塣								*/
	void (*hook)(int, void*);				/* �첽HTTP�ص���������Ӧ�ó����ṩ��		*/
	VMWCHAR lasterr[50];					/* �������������������Ľ��͡�			*/
};
typedef struct http_session_t http_session_t;

/**
 * HTTPͷ��
 */
struct http_head_t {
	char name[20];				/* ͷ�����ơ�		*/
	char value[100];			/* ͷ��ֵ��			*/
};
typedef struct http_head_t http_head_t;

/**
 * HTTP����
 */
struct http_request_t {
	char url[255];					/* ��ַ��										*/
	int nhead;					/* ��������ͷ�ĸ�����					*/
	http_head_t *heads;			/* ��������ͷ����ָ�롣				*/
	int nbody;					/* ����������ĳ��ȣ��ֽڵ�λ��	*/
	char* body;					/* ����������ָ�롣						*/
};
typedef struct http_request_t http_request_t;

/**
 * ����HTTP��������һ���첽���������ú��������أ�HTTP��Ӧ����ͨ���ص��������ء�
 *
 * @param request			HTTP�����塣
 * @param session			HTTP�Ự��
 *
 * @return					����0��ʾ�ɹ�������Ϊ�����롣
 */
int vm_http_request(http_request_t *request, http_session_t *session);

/**
 * ���HTTP��Ӧ�����е�ͷ��
 *
 * @param session			HTTP�Ự��
 * @param name				HTTPͷ���ơ�
 * @param value				HTTPͷ��Ӧ��ֵ��
 *
 * @return					����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
int get_http_head(http_session_t* session, const char* name, char* value);

/**
 * ���HTTP��Ӧ��ͷ�е�ͷ������
 *
 * @param session			HTTP�Ự��
 *
 * @return					ͷ������
 */
int get_http_head_number(http_session_t* session);

/**
 * ���HTTP��Ӧ�����е�ͷ��
 *
 * @param session			HTTP�Ự��
 * @param index				��Ҫ�õ�http head������ֵ��
 * @param name				HTTPͷ���ơ�
 * @param value				HTTPͷ��Ӧ��ֵ��
 *
 * @return					����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
int get_http_head_by_index(http_session_t* session, int index, char* name, char* value);

/**
 * ȡ�����л�Ծ��HTTP�Ự���Ѿ�������TCP��·�������жϡ��Ự�жϺ�ϵͳ������Ӧ�ó���
 * �ص�����������Ϣ��
 */
void vm_cancel_all_http_sessions(void);

/**
 * ע��HTTP״̬�ص�������HTTPЭ��ջͨ���ص���ʽ��ͨ���и���״̬�ش���Ӧ�ó���
 *
 * @param f					״̬�ص�������state������ʾ��ǰ������״̬��param
 *							��ʾ�뵱ǰ��״̬������ֵ�����HTTP_STATE_���塣
 */
void vm_reg_http_notification(void (*f)(VMINT state, VMINT param));

/**
 * ��/�ر�HTTPЭ��ջ�Ĵ����ܣ��������ܴ�ʱ��ϵͳͨ��CMWAP����������Դ��
 * �������ܹر�ʱ��ϵͳͨ��CMNET����������Դ��HTTPЭ��ջĬ�Ϲ����ڴ���ģʽ�£�
 * ����ģʽ���л���ȫ���Եģ�������Ա�ı��˴���ģʽ��HTTPЭ��ջ��һֱ�����ڸ���
 * ģʽ�£�ֱ������Ա�ı��˴���ģʽ��
 *
 * @param use_proxy			TRUE����ʹ�ô���ģʽ��FALSE����ʹ�ô���ģʽ��
 */
void vm_enable_proxy(VMINT use_proxy);


/**
  * HTTP request method��ö�����͵Ķ��壬�����������������HTTP
  * request method �����Ͷ��ᱻVRE��HTTPЭ��ջʵ�֣���Ҫ�鿴��Ӧ
  * VRE��ʵ�ְ汾˵����
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
 * asyn_http_req_t.use_proxy��HTTP�������Ͳ�����
 */
typedef enum 
{
	HTTP_USE_CMNET = 0,				/**<��CMNET(�ƶ�cmnet����ͨuninet) ��������,����Ҳ�����Ӧ��APN���������ʧ�ܡ� 											*/
	HTTP_USE_CMWAP, 					/**<��CMWAP(�ƶ�cmwap����ͨuniwap)��������,����Ҳ�����Ӧ��APN���������ʧ�ܡ�											*/	
	HTTP_USE_CMNET_PRIORITY,			/**<����Ҳ�����Ӧ��CMNET(�ƶ�cmnet����ͨuninet)������APN,���ȥ�Ҷ�ӦCMWAP(�ƶ�cmwap����ͨuniwap) APN���������� 	*/
	HTTP_USE_CMWAP_PRIORITY,			/**<����Ҳ�����Ӧ��CMWAP(�ƶ�cmwap����ͨuniwap)������APN,���ȥ�Ҷ�ӦCMNET(�ƶ�cmnet����ͨuninet) APN���������� 	*/
	HTTP_USE_WIFI,						/**<��Wi-Fi��ʽ�������ӡ�																														*/
	HTTP_USE_WIFI_CMNET,			/* wifi������wifi�Ѿ����ϣ���wifi���ӣ�������HTTP_USE_CMNET��ʽ */
	HTTP_USE_WIFI_CMWAP,			/* wifi������wifi�Ѿ����ϣ���wifi���ӣ�������HTTP_USE_CMWAP��ʽ */
	HTTP_USE_WIFI_CMNET_PRIORITY,	/* wifi������wifi�Ѿ����ϣ���wifi���ӣ�������HTTP_USE_CMNET_PRIORITY��ʽ */
	HTTP_USE_WIFI_CMWAP_PRIORITY	/* wifi������wifi�Ѿ����ϣ���wifi���ӣ�������HTTP_USE_CMWAP_PRIORITY��ʽ */
} VM_HTTP_PROXY_TYPE;

/**
  * �첽HTTP������http_request_t������VRE��ǰ��HTTP����ȱʧ��
  * HTTP request method ���Ƿ�ʹ�ô�����ֶΡ�
  */
typedef struct asyn_http_req_t {
	HTTP_METHOD 	req_method;	/**<HTTP_METHOD���͡�			*/
	VMUINT8 		use_proxy;		/**<VM_HTTP_PROXY_TYPE���͡�	*/
	http_request_t* 	http_request;	/**<HTTP����					*/
}asyn_http_req_t;

/**
  * ����vm_asyn_http_req��������ֵ�Ķ��塣
  * 
  * ASYN_HTTP_REQ_ACCEPT_SUCCESS
  * ����HTTP ����ɹ���VRE���� �첽����HTTP����
  *
  * ASYN_HTTP_REQ_NOT_SUPPORT_METHOD
  * ��֧�ֵ�ǰ��HTTP method��
  *
  * ASYN_HTTP_REQ_NOT_SUPPORT_HTTP_COMM
  * ��֧��HTTPЭ��ջ��ͨ�š�
  *
  * ASYN_HTTP_REQ_ONLY_SUPPORT_PROXY
  * ����֧�ִ���ģʽ-��CMWAP��
  *
  * ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE
  * HTTPЭ��ջû���㹻����Դ���޷����ܴ˴�HTTP����
  * ���HTTPֻ֧��һ��HTTP���ӣ���HTTPЭ��ջ��û��
  * ��HTTP responseͨ���ͻ�����ע�ᵽЭ��ջ�Ļص�����
  * ֮ǰ�ֵ���vm_asyn_http_req��������ô�øý�����ر�
  * ���ء�
  *
  * ASYN_HTTP_REQ_URL_FORMAT_ERROR
  * HTTP��ʽ����
  */
#define ASYN_HTTP_REQ_ACCEPT_SUCCESS								(0)
#define ASYN_HTTP_REQ_NOT_SUPPORT_METHOD						(1)
#define ASYN_HTTP_REQ_NOT_SUPPORT_HTTP_COMM					(2)
#define ASYN_HTTP_REQ_ONLY_SUPPORT_PROXY						(3)
#define ASYN_HTTP_REQ_NOT_ENOUGH_RESOURCE						(4)
#define ASYN_HTTP_REQ_URL_FORMAT_ERROR							(5)

/**
  * ����һ��HTTP��������һ���첽���������ú󱾺��������������ء�
  * ��ȷ��ȡ��HTTP��Ӧ��VRE HTTPЭ��ջ����ͨ���û�ע��������http_hook
  * ����ָ��ص��ؿͻ����򡣱�������������http_state_notify������һ��
  * �ͻ�����ע�������ĺ���ָ�룬��HTTPͨ�Ź����еĸ���ʱ��
  * (HTTP_STATE_GET_HOSTNAME��HTTP_STATE_CONNECTINGHTTP_STATE_SENDING��
  * HTTP_STATE_RECV_STATUS��HTTP_STATE_RECV_HEADS��HTTP_STATE_RECV_BODY)��
  * ����ͨ���ø��ͻ�����ע�ᵽHTTPЭ��ջ�к���ָ��ص���ȥ��http_hook��
  * http_state_notify�������ɿͻ�����ע�ᵽHTTPЭ��ջ�ĺ���ָ��,���Ǻ�
  * request������Ӧ���������HTTPЭ��ջ֧�ֶ���һ��HTTP�Ĳ���������ô
  * ������֤�˸���HTTP�����״̬���໥�����ģ������ǻ������ŵġ�
  *
  * @param 				request http ���������ָ��ָ�� null����ô������
  *						����Ҳ���᷵��ASYN_HTTP_REQ_ACCEPT_SUCCESS������
  *						HTTPЭ��ջ���������κεĶ�����
  *
  * @param 				http_hook �ͻ�����ע�ᵽHTTPЭ��ջ�ϵĺ���ָ�룬
  *						�ú������ر�˳����ȡHTTP response����û���
  *						HTTPͨѶ�����з��������ص����ͻ�����ע�ᵽ
  *						HTTPЭ��ջ�ĺ���������������������һ��������
  *						VMINT���ͱ�ʾ�Ƿ����http����ɹ���Ϊ0��ʾ�ɹ���
  *						��ô����Ϊʧ�ܡ��ڶ���������һ��ָ��http_session_t
  *						��ָ�����͡�ֻ���ڵ�һ������Ϊ0��ʱ��ڶ�������
  *						�������壬���߸�ָ��ָ��null��
  *
  * @param				http_state_notify �ͻ�ע�ᵽHTTPЭ��ջ�ĺ���ָ�롣
  *						�ú���������http��ͨѶ�ĸ����׶λص�����
  *						��HTTPЭ��ջ�ص���http hook����ô�ú�������
  *						���ٱ�HTTPЭ��ջ�ص�������
  *
  * @return 				�����룬����ɹ��Ľ���HTTP request �򷵻�
  *						ASYN_HTTP_REQ_ACCEPT_SUCCESS�����򷵻���Ӧ�Ĵ����롣
  */
VMINT vm_asyn_http_req(asyn_http_req_t *request, void (*http_hook)(VMINT, void*), 
	void (*http_state_notify)(VMINT state, VMINT param, void* session));

/**
 * @name vm_get_asyn_http_req_handle�����ķ���ֵ
 * @{
 */
/**
 * �õ�HTTP ����ɹ���
 */
#define VM_GET_AHH_SUCCESS					(0)
/**
 * �Ҳ���ָ��REQUEST��HTTP�����
 */
#define VM_GET_AHH_NO_COMM				(-1)
/**
 * ����Ĳ�����
 */
#define VM_GET_AHH_ERROR_PARAM			(-2)
/** @} */

/**
 * �õ��첽HTTP�����������ľ����
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
 *     vm_get_asyn_http_req_handle(&req, &handle); // ����͵õ���������������HTTP�����
 * }
 * @endcode
 * @param[in]			request http����
 * @param[out]			handle ��HTTP ���д���ָ��ָ���ַ�С�
 * @return 				�Ƿ�õ������ľ����־��
 * @retval				VM_GET_AHH_SUCCESS �õ�����ɹ���
 * @retval				VM_GET_AHH_NO_COMM �Ҳ���HTTP REQUEST��Ӧ��HTTP �����
 * @retval				VM_GET_AHH_ERROR_PARAM ����Ĳ�����
 */
VMINT vm_get_asyn_http_req_handle(asyn_http_req_t* request, VMINT* handle);

/**
 * @name vm_cancel_asyn_http_req �ķ���ֵ��
 * @{
 */
/**
 * ȡ���ɹ���
 */
#define VM_CAH_REQ_SUCCESS			(0)
/**
 * ��ǰû��ָ���ľ����HTTP���ӡ�
 */
#define VM_CAH_REQ_NO_COMM		(-1)
/** @} */

/**
 * ȡ��һ��ָ�������HTTP����
 * 
 * @param[in]				handle HTTP������þ��ͨ��vm_get_asyn_http_req_handle
 * 						�����õ���
 * @return				��ҪHTTP�����������ı�־��
 * @retval				VM_CAH_REQ_SUCCESS ȡ��HTTP����ɹ���
 * @retval				VM_CAH_REQ_NO_COMM û��ָ�������HTTP ���󱻷���
 */
VMINT vm_cancel_asyn_http_req(VMINT handle);

/**
 * �Ѹ�����GB2312������ַ�������URL���롣
 * 
 * @param[out] 			dst	��ű���ú���ַ������ڴ�ռ���׵�ַ,URL���������ݽ����
 *						�ڸÿռ���.�����д��ȫ����������ݺ���ʣ��Ŀռ佫д����ֵ0
 *						����־�ַ����Ľ���.
 * @param[in] 			size	��ű���ú���ַ������ڴ�ռ��С����λΪ�ֽڡ�
 * @param[in] 			src	��Ҫ��������ַ���.
 *
 * @return				�����Ѿ�д��dst�е��ֽڸ���,��������־�ַ�����������ֵ0.
 */
VMUINT vm_url_encode_gb2312(VMSTR dst, VMUINT size, const VMSTR src);

/**
 * �Ѹ����ľ���URL�����GB2312��ʽ���ַ�������URL���롣
 * 
 * @param[out] 			dst ��Ž���ú���ַ������ڴ�ռ���׵�ַ,URL���������ݽ����
 *						�ڸÿռ���.�����д��ȫ����������ݺ���ʣ��Ŀռ�, ��ô��д��
 *						��ֵ0����־�ַ����Ľ���.
 * @param[in] 			size ��Ž���ú���ַ������ڴ�ռ��С����λΪ�ֽڡ�
 * @param[in] 			src ��Ҫ������ַ�����
 * 
 * @return				�����Ѿ�д��dst�е��ֽڸ���,��������־�ַ�����������ֵ0.
 */
VMUINT vm_url_decode_gb2312(VMSTR dst, VMUINT size, VMSTR src);

/*********************************************************************
 * HTTPģ�������Ľӿڶ��� 2009-11-18
 *********************************************************************/

/**
 * HTTP���Ŀ���ջص�������
 * ���ص�������ע�ᣬHTTPģ�����ô˺�������HTTP�����塣
 * ����vm_http_recv_data��������HTTP��Ӧ����������ݣ���������ֵ���ء�
 *
 * @param[in] 			handle HTTP���
 * @param             		p �����ֶ�
 *
 * @return 				>0 ʱ�������ݵ��ܳ���, ==0ʱ��ʾ����, <0ʱ��ʾ����
 */
typedef VMINT(*http_data_receiver)(VMINT handle, void* p);

/**
 * ע��HTTP���Ŀ����ػص�����ָ��
 *
 * @param[in] 			reciever ��Ӧ�ö��ṩ�����ݷֿ��ϴ�������
 *                 				�����е���vm_http_post_data�������ݷֿ��ϴ���
 *
 * @return 				�Ƿ�ɹ�
 */
VMINT vm_http_reg_receiver(VMINT handle, http_data_receiver reciever);

/**
 * ����HTTP���Ŀ顣
 * 
 * VMCHAR data[128]
 * while(����δ��ɽ���)
 * {
 *     retlen = vm_http_recv_data(handle, data, len);
 *     //�ж�retlen��ֵ��>0; ==0; <0
 *     //������յ�����
 * }
 *
 * @param[in] 			handle HTTP���
 * @param[out] 			data ��������HTTP��Ӧ���Ŀ���ַ�������ָ��
 * @param[in] 			len Ӧ�������յ�HTTP��Ӧ���Ŀ��С
 *
 * @return	 			��ʵ���յ��ı��Ŀ��С
 */
VMINT vm_http_recv_data(VMINT handle, VMUINT8* data, VMINT len);

/**
 * HTTP���Ŀ鷢�ͻص�������
 * ���ص�������ע�ᣬHTTPģ�����ô˺�������HTTP�����塣
 * ����vm_http_send_data �����ϴ�HTTP������������ݣ���������ֵ���ء�
 *
 * @param[in] 			handle HTTP���
 * @param             		p �����ֶ�
 *
 * @return 				>0 ʱ�������ݵ��ܳ���, ==0ʱ��ʾ����, <0ʱ��ʾ����
 */
typedef VMINT(*http_data_sender)(VMINT handle, void* p);
/**
 * ע��HTTP���Ŀ��ϴ��ص�������
 *
 * @param[in] 			sender ��Ӧ�ö��ṩ�����ݷֿ��ϴ�������
 *               				�����е���vm_http_send_data�������ݷֿ��ϴ���
 *
 * @return 				�Ƿ�ɹ�
 */
VMINT vm_http_reg_sender(VMINT handle, http_data_sender sender);

/**
 * ����HTTP���Ŀ顣
 * �ڷ���HTTP�������ô˽ӿڡ�
 *
 * VMCHAR data[128]
 * while((len=get_data(data)) > 0)
 * {
 *     vm_http_post_data(handle, data, len);
 * }
 *
 * @param[in] 			handle HTTP ���
 * @param[in] 			data HTTP �����Ŀ�
 * @param[in] 			len HTTP �����Ŀ鳤��
 * @return 				�Ƿ�ɹ�
 */
VMINT vm_http_send_data(VMINT handle, VMUINT8* data, VMINT len); 

/**
 * ���HTTP ����ͷ�ֶΣ�Ӧ������ά��name, value ���ڴ�ռ䡣
 * �ڷ���HTTP����ǰ���ô˽ӿڡ�
 * ע��: name + value ���Ȳ�Ҫ����400 �ֽڣ�������ܳ���
 *
 * @param[in] 			handle HTTP ���
 * @param[in] 			name HTTP ��ͷ����
 * @param[in] 			value HTTP ��ͷֵ
 *
 * @return 				�Ƿ�ɹ�
 */
VMINT vm_http_add_header(VMINT handle, VMCHAR* name, VMCHAR* value);

/**
 * ����HTTP ����URL ��Ӧ������ά��url ���ڴ�ռ䡣
 * �ڷ���HTTP����ǰ���ô˽ӿڡ�
 * ע��:URL ���Ȳ�Ҫ����400 �ֽڣ�������ܳ���
 *
 * @param[in] 			handle HTTP ���
 * @param[in] 			url HTTP ����URL ��
 *						URL �������������Request-Line ��Header �е�Host �б�ʹ�á�
 * @param[in] 			value HTTP ����URL ���ȡ�
 *
 * @return 				�Ƿ�ɹ�
 */
VMINT vm_http_set_url(VMINT handle, VMCHAR* url, VMINT len);

/**
 * ����HTTP �������塣
 * �ڷ���HTTP ����ǰ���ô˽ӿڡ�
 * ���󷢳����û������ͷű��������ڴ档
 * 
 *
 * @param[in] 			handle HTTP���
 * @param[in] 			data HTTP������������ָ�롣
 *						��ΪNULL����ʱ����������ͨ���ص������ϴ���
 * @param[in] 			len HTTP�������峤�ȡ�
 *						����д������ͷ�е�Content-Length�ֶ��С�
 *
 * @return 				�Ƿ�ɹ�
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
 * ȡ��һ�����õ�HTTP�����
 * ֧�ָ����������ľ����ͨ�� vm_set_http_header(), vm_set_http_body()
 * ��̬����HTTP��������ݡ�
 *
 * @param[in] 			type ��ȡHTTP�������������
 * @param[in] 			p ��ȡHTTP������������ͽṹ��ָ��
 *
 * @return 				HTTP���
 */
VMINT vm_http_fetch_handle(VMINT type, void* p);

/**
 * ��ȡ��ǰ���������HTTP�����
 * ������Ҫ�ڵ���HTTP����ǰ�жϵ�ǰ�����
 *
 * @return 				HTTP���
 */
VMINT vm_http_get_current_handle(void);

/**
 * ���õ�ǰ���������HTTP�����
 *
 * @param[in] 			handle ��Ҫ�������HTTP���
 *
 * @return 				HTTP ���
 */
VMINT vm_http_set_current_handle(VMINT handle);

/**
 * �ͷ�HTTP��������������Դ��
 * �����HTTP����������û������ж��������á�
 *
 * @param[in] 			handle HTTP���
 */
void vm_http_free_handle(VMINT handle);

/**
void vm_http_test_entrance(void);
 */

#ifdef __cplusplus
}
#endif

#endif /*HTTP_H_*/

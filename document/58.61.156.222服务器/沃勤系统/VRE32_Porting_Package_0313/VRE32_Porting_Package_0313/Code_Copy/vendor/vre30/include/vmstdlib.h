#ifndef VMSTDLIB_H_
#define VMSTDLIB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

#define VM_CACHE_SIZE 4096

/**
 * �ѿ��дģʽת��Ϊ����дģʽ�Ļ���ṹ��
 */
struct vm_cache_t {
	VMINT eof;					/* ��������־��					*/
	VMINT avail;				/* ���л������ݱ�־��			*/
	VMINT count;				/* ��ʣ���ֽڸ�����				*/
	VMUINT8 buf[VM_CACHE_SIZE];	/* ��������						*/
};
typedef struct vm_cache_t vm_cache_t;

/**
 * �����ָ�ʽ�ַ���ת��Ϊ������������ַ����г���a-f�ַ���
 * ִ��ʮ�����Ƹ�ʽ����ת��������ִ��ʮ���Ƹ�ʽ����ת����
 *
 * @param s			Ҫת�����ַ�����
 *
 * @return			����-1��ʾת��ʧ�ܣ����򷵻ؽ����
 */
int strtoi(char* s);

/**
 * �������ļ�·����ժȡ���ļ����ơ�
 *
 * @param path		����·������
 * @param filename	�ļ����ơ�
 */
void vm_get_filename(VMWSTR path, VMWSTR filename);

/**
 * ������·���н�ȡ·�����֣����ص�·��������β\�ַ���
 *
 * @param fullpath		�����ļ���������·����
 * @param path			���ص�·����
 * 
 * @return				����0��ʾ��ȡ·���ɹ���
 */
VMINT vm_get_path(VMWSTR fullpath, VMWSTR path);

/**
 * ��ô�2000��1��1�յ�����Ϊֹ��������
 *
 * @return			�ɹ����ش�2000��1��1�յ�����Ϊֹ�����������󷵻�-1��
 */
VMINT get_today_from_2000(void);

/**
 * ��Դ�ַ����е�Сд��ĸת��Ϊ��д��ĸ��
 *
 * @param dst			��Ž����Ŀ���ַ���������Ա���뱣֤Ŀ���ַ�������
 *						���ڵ���Դ�ַ������ȡ�
 * @param src			��ת����Դ�ַ�����
 */
void vm_upper_case(char* dst, char* src);

/**
 * ��Դ�ַ����Ĵ�д��ĸת��ΪСд��ĸ��
 *
 * @param dst			��Ž����Ŀ���ַ���������Ա���뱣֤Ŀ���ַ�������
 *						���ڵ���Դ�ַ������ȡ�
 * @param src			��ת����Դ�ַ�����
 */
void vm_lower_case(char* dst, char* src);

/**
 * �Ƚ������ַ��������Ƿ�һ�£��ַ����е���ĸ��Сд�����С�
 *
 * @param s1			�ַ���һ��
 * @param s2			�ַ�������
 *
 * @return				����0��ʾ�����ַ���������ͬ�����򷵻�-1��
 */
VMINT vm_string_equals_ignore_case(const char *s1, const char *s2);

/**
 * ����������д�����ݡ�vm_write_cache()��vm_read_cache()����ΪӦ�ó����ṩ��
 * ����дģʽ��SOCKET��C���ļ���д�������ṩ�˿��дģʽ��û���ṩ����дģʽ��
 * ϵͳͨ�������������д�������ڴ��ת��Ϊ����Ӧ�ó��������д�뻺���
 * vm_read_cache()�������������ķ�ʽ��Ӧ�ó����ṩ���ݡ�vm_write_cache()
 * �����򻺳�д�����ݣ����д������ݿ鳤�ȴ��ڻ�������ڴ泤�ȣ�ϵͳֻ��ȡ
 * �����ܹ����ɵ��ֽ��������ಿ�ֻ��Զ�����������ԱӦ��ʹ��
 * vm_get_cache_free_space()������ȡ������ÿռ䳤�ȡ�
 *
 * @param cache			������ָ�롣
 * @param buf			Ҫд������ݿ�ָ�롣
 * @param buf_len		Ҫд������ݿ��ֽڳ��ȣ�С��0���ʾû�и������ݿ���
 *						д�룬��ʱ�������EOF��־λ�ᱻ�Զ�����vm_read_cache()
 *						��һֱ����-1��ʾ���ܵ��Ѿ��رա�
 *
 * @return				ʵ��д����ֽ�����
 */
VMINT vm_write_cache(vm_cache_t *cache, void *buf, VMINT buf_len);

/**
 * ���������ж���һ���������ֽڡ�
 *
 * @param cache			������ָ�롣
 * @param buf			�������ݵ��ڴ��ָ�롣
 * @param buf_size		�������ݵ��ڴ��������
 * @param len			Ҫ��ȡ���ֽ�����
 * 
 * @return				ʵ�ʶ�����ֽ���������0��ʾ���ܵ��Ѿ��رգ�����֮��û��
 *						�������ݿɶ���
 */
VMINT vm_read_cache(vm_cache_t *cache, void *buf, VMINT buf_size, VMINT len);

/**
 * ���������ж���һ���ַ���
 *
 * @param cache			������ָ�롣
 * @param ch			Ҫ������ַ�ָ�롣
 *
 * @return				����0��ʾ���ɹ�������Ϊ�����롣
 */
VMINT vm_cache_read_char(vm_cache_t *cache, char *ch);

/**
 * �����������ÿռ䳤�ȡ�
 * 
 * @param cache			������ָ�롣
 *
 * @return				������������ÿռ���ֽ�����
 */
VMINT vm_get_cache_free_space(vm_cache_t *cache);

/**
 * ���������ж���һ���ַ������ַ�����\r\n��β��
 * 
 * @param line			Ҫ������ַ���ָ�롣
 * @param size			�ַ���������
 * @param cache			������ָ�롣
 *
 * @return				����0��ʾ���ַ����ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_read_line(char* line, VMINT size, vm_cache_t* cache);

/**
 * �ڴ濽����������C���memcpy������
 *
 * @param dst		Ŀ���ַ��
 * @param src		Դ��ַ��
 * @param count		Ҫ�������ֽ�����
 */
void vm_memcpy(void* dst, void* src, VMINT count);

/**
 * ��̬���顣
 */
typedef struct _vm_dyn_array_t {
	/**
	 * ������ÿ���ṹ��ĳ��ȡ�
	 */
	VMINT block_size;

	/**
	 * ��ʼ���鳤�ȡ�
	 */
	VMINT init_size;

	/**
	 * ÿ�����ӵļ�¼������
	 */
	VMINT inc_size;

	/**
	 * �������������ݵ��±������
	 */
	VMINT count;

	/**
	 * �����е��±������
	 */
	VMINT capacity;

	/**
	 * ��̬����Ŀ�ʼָ�롣
	 */
	void  *ptr;
} vm_dyn_array_t;

/**
 * ������̬���顣��̬������һ�������������飬������Ա��������µļ�¼ʱ�ܹ��Զ�������
 * ��̬�����ڴ���ʱ����һ����ʼ������������Ҫ�����ڴ��Դ���¼�¼ʱ����̬���ݻ��Զ�
 * ����һ���̶����������󡣶�̬������һ���ṹ���飬����Ա����ָ��������еĽṹ��ߴ硣
 *
 * @param init_size			��̬����ĳ�ʼ�����ȡ�
 * @param inc_size			��̬������Ҫ�����Դ���¼�¼ʱ�Ĺ̶���������
 * @param block_size		����ڶ�̬�����еĽṹ�峤�ȡ�
 *
 * @return			����NULL��ʾ��̬���鴴��ʧ�ܣ����򷵻ض�̬����ָ�롣
 */
vm_dyn_array_t* vm_create_dyn_array(VMINT init_size, VMINT inc_size, VMINT block_size);

/**
 * ��̬�������������ݣ��µ����ݱ�׷�ӵ������β����
 *
 * @param array				��̬����ָ�롣
 * @param data				Ҫ���ӵ�����ָ�롣
 *
 * @return			����0��ʾ���ӳɹ�������Ϊ�����롣
 */
VMINT vm_dyn_array_add(vm_dyn_array_t *array, void* data);

/**
 * �Ӷ�̬������ɾ�������±ꡣ
 *
 * @param array				��̬����ָ�롣
 * @param idx				�±ꡣ
 *
 * @return					����0��ʾ�ɹ���
 */
VMINT vm_dyn_array_del(vm_dyn_array_t *array, VMINT idx);

/**
 * ɾ����̬���������е��±ꡣ
 *
 * @param array				��̬����ָ�롣
 *
 * @return					����0��ʾ�ɹ���
 */
VMINT vm_dyn_array_del_all(vm_dyn_array_t *array);

/**
 * �ͷŶ�̬������ռ�õ��ڴ���Դ��
 *
 * @param array				��̬����ָ�롣
 */
void vm_free_dyn_array(vm_dyn_array_t *array);

/**
 * ����STACK�ɹ���        
 */
#define STACK_OPERATE_SUCCESS				(0)

/**
 * ����STACK��������
 */
#define STACK_PARAM_ERROR					(-1)

/**
 * ����STACKʱû���㹻����Դ����������ʧ�ܡ�
 */
#define STACK_LEAK_RESOUCE					(-2)

/**
 * STACK���޷�push������
 */
#define STACK_PUSH_OVERFLOW					(-3)

/**
 * �Կյ�STACK���г�ջ������
 */
#define STACK_OPERATE_EMPTY_STACK			(-4)

/**
 * ����STACK�Ǵ���STACK�������
 */
#define STACK_HANDLE_ERROR					(-5)

/**
 * �������������ջ�ṹ����ջ���������ܶ�̬�������ڲ�ʹ�ö�ջ��ʱ��Ӧ�õ���
 * vm_destory_stack���ٸö�ջ���ͷ���Դ��
 * 
 * @param capability		ջ�����������������stackʵ�ָ������ǲ��ᶯ̬���ӵġ�
 *							һ��������stack����ô�������ǲ��ɱ�ģ�����ջ��Ԫ��
 *							�Ѿ��ﵽ��capability��ֵ���ٵ���vm_push_stack������
 *							һ��ʧ�ܡ�
 * @param handle			ָ��ͻ������һ��VMINT�������������STACK_OPERATE_SUCCESS
 *							��ô�����ڻ�Ը�ָ��ָ��ı������и�ֵ��
 * @return					STACK_OPERATE_SUCCESS ����ջ�ɹ���
 *							STACK_PARAM_ERRORʵ��С�ڵ���0��
 *							STACK_LEAK_RESOUCE��ʾ��ȱ����Դ���´���stackʧ�ܡ�
 *							��ʱ��Ӧ�ó�������Ѿ��д�����������stack�������
 *							vm_destory_statck�������ٵ��ñ�������
 */
VMINT vm_create_array_stack(VMINT capability, VMINT* handle);

/**
 * ����һ�����������ջ�ṹ����ջ���������ܹ���̬���ӵġ��ڲ�ʹ�ö�ջ��ʱ��Ӧ�õ���
 * vm_destory_stack���ٸö�ջ���ͷ���Դ��
 * 
 * 
 * @param capability	����ջ��ʱ���ʼ������
 * @param handle			ָ��ͻ������һ��VMINT�������������STACK_OPERATE_SUCCESS
 *										��ô�����ڻ�Ը�ָ��ָ��ı������и�ֵ��
 * @return						STACK_OPERATE_SUCCESS����ջ�ɹ���
 *										STACK_PARAM_ERRORʵ��С�ڵ���0��
 *										STACK_LEAK_RESOUCE��ʾ��ȱ����Դ���´���stackʧ�ܡ�
 *										��ʱ��Ӧ�ó�������Ѿ��д�����������stack�������
 *										vm_destory_statck�������ٵ��ñ�������
 */
VMINT vm_create_linked_stack(VMINT capability, VMINT* handle);

/**
 * ����STACK�Ƿ�Ϊ�գ�ջ�Ƿ���Ԫ�ء�
 * 
 * @param					stackHandle	����ջ��ʱ��õ������			
 * @return					TRUE ��ʾ��ջ�ṹ�ǿա�
 *							FALSE ��ʾ��ջ�ṹΪ�ǿա�
 */
VMINT vm_is_empty_stack(VMINT stackHandle);

/**
 * Ԫ����ջ������
 * 
 * @return				STACK_OPERATE_SUCCESS��ʾ��ջ�ɹ���
 *						STACK_PUSH_OVERFLOW��ʾ��ջʧ�ܣ���ջ�����ˡ�
 *						���ڻ��ڵ������ջ��������ر�������
 *						��ʾϵͳ������ջ���ڴ�ռ��Ѿ��ľ���
 *						STACK_HANDLE_ERROR�����ջ�����			
 */
VMINT vm_push_stack(VMINT stackHandle, void* ptr);

/**
 * Ԫ�س�ջ������
 *
 * @return				STACK_OPERATE_SUCCESS ��ջ�����ɹ���
 *						STACK_HANDLE_ERROR �����ջ�����
 *						STACK_OPERATE_EMPTY_STACK �Կ�ջ�����˳�ջ������
 */
VMINT vm_popup_stack(VMINT stackHandle, void** ptr);

/**
 * �õ���ջ��һ����ջ��Ԫ�أ����Ǹ�Ԫ�ػ��ڶ�ջ�ڡ�
 *
 * @return				STACK_OPERATE_SUCCESS ��ջ�����ɹ���
 *						STACK_HANDLE_ERROR �����ջ�����
 *						STACK_OPERATE_EMPTY_STACK �Կ�ջ������peek������	
 */
VMINT vm_peek_stack(VMINT stackHandle, void** ptr);

/**
 * ������ж�ջ�ڵ��������ݣ����ǲ����ٸö�ջ���������
 * �����������ϵ���vm_peek_stack��vm_popup_stack����õ�
 * STACK_OPERATE_EMPTY_STACK�Ĵ����롣
 * 
 * @return				STACK_OPERATE_SUCCESS �����ɹ���
 *						STACK_HANDLE_ERROR ����Ķ�ջ�����
 */
VMINT vm_reset_stack(VMINT stackHandle);

/**
 * �ڶ�ջ���Ƿ����ָ����Ԫ�ء�
 * 
 * @return				TRUE ��ʾ���ڡ�
 *						FALSE ��ʾ�����ڡ�
 */
VMINT vm_is_exist_stack(VMINT stackHandle, void* ptr);

/**
 * ���ٶ�ջ���ͷŶ�ջռ�õ���Դ�������ջ����Ԫ�أ�����
 * �޸�Ԫ�����ݡ����ڲ�ʹ�õĶ�ջ��Ӧ�õ��ñ��������ͷ���Դ��
 * �����Ӧ���ﴴ���˶�ջ���ڵ���vm_exit_app�˳���Ӧ��ǰ��
 * Ӧ���ͷ���Ӧ�ó����ﴴ���Ķ�ջ���ͷ���Դ��
 *
 * @return				STACK_OPERATE_SUCCESS �����ɹ���
 *						STACK_HANDLE_ERROR ����Ķ�ջ�����
 */
VMINT vm_destroy_stack(VMINT stackHandle);

/**
 * �ж��ַ����Ƿ��Ը����ַ�����β��
 *
 * @param s1			�������ַ�����
 * @param s2			��β�ַ�����
 *
 * @return				���s1��s2��β�򷵻�0�����򷵻ط�0�����
 */
VMINT vm_ends_with(const char *s1, const char *s2);

/**
 * vm_ends_with()��UCS2ʵ�֣��ӿ�����һ����ֻ������ַ�����ΪUCS2��ʽ��
 */
VMINT vm_wends_with(const VMWSTR s1, const VMWSTR s2);

/**
 * ������ʱ�ļ����ƣ�ϵͳ�ᱣ֤��ʱ�ļ�����Ψһ�ԡ�
 *
 * @param prefix		��������ʱ�ļ���ǰ���ַ�����ͨ����·����
 * @param filename		��ʱ�ļ������Ϊ128���ַ���������β��\0��
 *						����Ա���뱣֤������ַ��������㹻�Ŀռ�
 *						��������ʱ�ļ�����
 */
void vm_tmp_filename(char* prefix, char* filename);

/**
 * ��ȫUCS2�ַ�������������wstrcpy�ı����汾����Ŀ�괮û���㹻�ռ���Դ��
 * ����ʱ���Զ��ü�������֡�
 *
 * @param dest			Ŀ���ַ���ָ�롣
 * @param size			Ŀ���ַ�������󳤶ȣ���UCS2�ַ�Ϊ��λ��
 * @param src			Դ�ַ���ָ�롣
 *
 * @return				ʵ�ʿ�����UCS2�ַ�������
 */
VMINT vm_safe_wstrcpy(VMWSTR dest, VMINT size, VMWSTR src);

#define wstrlen			vm_wstrlen
/**
 * ������\0��β��UCS2�ַ������ȡ�
 */
VMINT vm_wstrlen(VMWSTR s);

#define wstrcpy			vm_wstrcpy
/**
 * UCS2�����ַ���������
 */
VMINT vm_wstrcpy(VMWSTR dst, const VMWSTR src);

#define wstrcat			vm_wstrcat
/**
 * UCS2�����ַ���׷�ӡ�
 */
VMINT vm_wstrcat(VMWSTR dst, const VMWSTR src);

#define wstrncpy		vm_wstrncpy
/**
 * ��Դ������n���ַ���Ŀ�괮�������������Զ���Ŀ�괮β������'\x0'��Ӧ�ó���
 * ���뱣֤Ŀ�괮���㹻�ռ���n+1���ַ��ռ䣨����β����'\x0'����
 *
 * @param dst			Ŀ�괮ָ�롣
 * @param src			Դ��ָ�롣
 * @param length		�������ַ�������
 *
 * @return				�������ַ�������
 */
VMINT vm_wstrncpy(VMWSTR dst, const VMWSTR src, VMINT length);

#define wstrcmp			vm_wstrcmp

/**
 * UCS2�ַ����Ƚϡ�
 *
 * @param str_1			�ַ���1��
 * @param str_2			�ַ���2��
 *
 * @return				Դ�ַ�����Ŀ���ַ����Ƿ���ȣ����
 *						����0������ȷ��ط�0ֵ��
 */
VMINT vm_wstrcmp(VMWSTR str_1, VMWSTR str_2);

/**
 * UCS2�ַ����ıȽϣ����Ե���д��Сд������
 * 
 * @param[in]			str_1 �ַ���1��
 * @param[in]			str_2 �ַ���2��
 * 
 */
VMINT vm_wstrcmp_ignore_case(VMWSTR str_1, VMWSTR str_2);

/**
 * �ж�A���Ƿ���B����ͷ��
 *
 * @param a				������ַ���ָ�롣
 * @param b				��ʼ��ָ�롣
 *
 * @return				���A�ַ�����ʼ������B��һ���򷵻�0������"abcd"��
 *						��"ab"��ʼ�򷵻�0�����򷵻ط�0�����
 */
VMINT vm_wstarts_with(VMWSTR a, VMWSTR b);

#ifdef __cplusplus
}
#endif

#endif

#ifndef GNU_MALLOC_H
#define GUN_MALLOC_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "vmsys.h"

/**
 * ��ʼ���ڴ�أ���ӵ�д����ڴ��PC��ͬ��Ƕ��ϵͳͨ����ӵ�����޵��ڴ棬����
 * ���׼C���ܹ��Ӷ��з�����ڴ��СҲ�������ޣ����Ƕ��ϵͳͨ��������һ��
 * �̶���С���ڴ��Ӧ�ó�����Ӧ�ó������й�����ʼ������������ִ���κ���
 * �������ͷ�֮ǰ���á�
 *
 * @param pool_base		�ڴ�ص���ʼ��ַ��
 * @param pool_size		�ڴ�صĳ��ȣ����ֽ�Ϊ��λ��
 */
void gnu_malloc_init(VMUINT8* pool_base, int pool_size);

/**
 * ���ڴ���з��������С��һ���ڴ档
 *
 * @param n				�ڴ��С�����ֽ�Ϊ��λ��
 *
 * @return				���䵽���ڴ��ַ������NULL��ʾ����ʧ�ܡ�
 */
VMUINT8* gnu_malloc(VMUINT n);

/**
 * ��չ�ڴ浽ָ�����ȣ������������С�ڸ����ڴ��ĳ��������κ�
 * ������
 */
VMUINT8* gnu_realloc(VMUINT8* p, VMUINT n);

/**
 * �ͷ��ڴ棬ͨ��gnu_malloc������ڴ�ֻ�ܹ��ͷ�һ�Σ�����ͷŻᵼ���޷�Ԥ��
 * �ĺ����
 *
 * @param mem			Ҫ�ͷŵ��ڴ���ʼ��ַ��
 */
void gnu_free(VMUINT8* mem);

/**
 * ����Ѿ�ʹ�õ��ڴ����������ֽ�Ϊ��λ��
 */
VMINT gnu_malloc_mem_used(void);

/**
 * ��ÿ��е��ڴ����������ֽ�Ϊ��λ��
 */
VMINT gnu_malloc_mem_free(void);

#ifdef __cplusplus
}
#endif

#endif

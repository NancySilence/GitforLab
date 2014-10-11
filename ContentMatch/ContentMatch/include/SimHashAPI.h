#ifndef  __ICT_SIM_HASH_API_H__
#define  __ICT_SIM_HASH_API_H__

#if defined(_WINDOWS) || defined(WIN32)|| defined(_WIN32)
#	define WINDOWS_OS
#endif

#ifndef WINDOWS_OS
#include <inttypes.h>
#else//for Win
typedef unsigned __int64	uint64_t;
#endif

#ifdef WINDOWS_OS
#define ICT_SIM_HASH_API __declspec(dllexport)
#else
#define ICT_SIM_HASH_API
#endif

#include <string>

using namespace std;

	typedef void SH_H;



    /*!
    *	\fn	int SH_Init(const char *config_file,  SH_H **h);
    *	\brief SimHash��������ʼ��
    *   \param [in] config_file �����ļ�
    *   \param [out] h SimHash������
    *	\return	�ɹ����� 1�����򷵻� 0
    *	\author xxk
    */
   ICT_SIM_HASH_API int SH_Init(const char *config_file,  SH_H **h);



    /*!
    *	\fn	int SH_Exit( SH_H *h);
    *	\brief ����ͷ�
    *   \param [in] h ���
    *	\return	�ɹ����� 1�����򷵻� 0
    *	\author xxk
    */
ICT_SIM_HASH_API  int SH_Exit( SH_H *h);



    /*!
    * \fn int SH_Get(SH_H  *h, const string &text,  uint64_t &simhash);
    * \brief simhash����
    * \param [in] text �����ı�
    * \param [in] h ���
    * \param [out] simhash SimHashֵ��64λ��
    * \return	�ɹ����� 1�����򷵻� 0
    *  \author xxk
    */
ICT_SIM_HASH_API int SH_Get(SH_H  *h, const string &text, uint64_t &simhash);


#endif


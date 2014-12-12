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
    *	\brief SimHash计算句柄初始化
    *   \param [in] config_file 配置文件
    *   \param [out] h SimHash计算句柄
    *	\return	成功返回 1，否则返回 0
    *	\author xxk
    */
   ICT_SIM_HASH_API int SH_Init(const char *config_file,  SH_H **h);



    /*!
    *	\fn	int SH_Exit( SH_H *h);
    *	\brief 句柄释放
    *   \param [in] h 句柄
    *	\return	成功返回 1，否则返回 0
    *	\author xxk
    */
ICT_SIM_HASH_API  int SH_Exit( SH_H *h);



    /*!
    * \fn int SH_Get(SH_H  *h, const string &text,  uint64_t &simhash);
    * \brief simhash计算
    * \param [in] text 输入文本
    * \param [in] h 句柄
    * \param [out] simhash SimHash值（64位）
    * \return	成功返回 1，否则返回 0
    *  \author xxk
    */
ICT_SIM_HASH_API int SH_Get(SH_H  *h, const string &text, uint64_t &simhash);


#endif


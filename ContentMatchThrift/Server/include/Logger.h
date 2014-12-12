/*!
 *	\class	CLogger
 *	\brief	记录日志类
 *	\n		输出日志，可以输出到文件（分天）或标准输出
 *  \n		使用时需先调用Init()函数指定当前程序名，日志模式，日志文件路径，时间戳标识
 *  \n		日志分为Debug, Info, Warn, Error四类，优先级递增，由LOG_LEVEL控制
 *	\n		定义LOG_LEVEL后，大于等于该等级的日志可以输出，例如默认LOG_LEVEL为LOG_INFOTYPE，则输出Info, Warn, Error三类日志
 *	\n		可使用预处理器定义LOG_ALL, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_NONE覆盖LOG_LEVEL的定义，优先级类似
 *	\n		预处理器定义(LOG_ALL等)定义后，LOG_LEVEL宏不再生效
 *	\n		程序名，日志模式，文件路径，时间戳标识，输出流可使用set方法修改
 *	\date	2012-2-23 
 *	\author zhujunjie(zhujunjie@software.ict.ac.cn)	
*/

#ifndef CLOGGER_H
#define CLOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

#define LOG_TOCONSOLE	0		//日志输出到标准输出，默认
#define LOG_TOFILE		1		//日志输出到文件（分天）

#define LOG_WITHTIME	0		//日志带有时间戳（默认）
#define LOG_WITHOUTTIME	1		//日志不使用时间戳

#define LOG_INFOTYPE	0		//Info日志类型
#define LOG_STATTYPE	1		//统计日志类型
#define LOG_WARNTYPE	2		//Warn日志类型
#define LOG_ERRORTYPE	3		//Error日志类型
#define LOG_DEBUGTYPE	-1		//Debug日志类型
#define LOG_ALLTYPE		-5		//所有日志类型
#define LOG_NONETYPE	5		//屏蔽所有日志类型

#define LOG_LEVEL		LOG_INFOTYPE	//日志等级，默认为Info等级

class CLogger
{
public:
	//------------------构造函数与析构函数-------------------
	/*! 
	* \fn CLogger()
	* \brief 记录日志类构造函数，初始化所有成员变量，其中输出流初始化为cout
	* \return 无
	* \author zhujunjie
	* \date 2012-2-23
	*/
	CLogger();

	/*! 
	* \fn ~CLogger()
	* \brief 记录日志类析构函数，若日志文件打开，则关闭
	* \return 无
	* \author zhujunjie
	* \date 2012-2-23
	*/
	~CLogger();
public:

	/*! 
	* \fn int Init(string appname, int logmode = LOG_TOCONSOLE, string logpath = "", int timeflag = LOG_WITHTIME)
	* \brief 初始化函数，指定程序名，日志模式，日志文件路径，时间戳标识
	* \param[in] appname	当前程序名
	* \param[in] logmode	日志模式，默认输出到标准输出
	* \param[in] logpath	日志文件路径，默认为当前目录
	* \param[in] timeflag	时间戳标识，默认为使用时间戳
	* \return 成功则返回0
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int Init(string appname, int logmode = LOG_TOCONSOLE, string logpath = "", int timeflag = LOG_WITHTIME);
	
	/*! 
	* \fn int LogDebug(string logcode, string &msg)
	* \brief 记录Debug类型日志
	* \param[in] logcode	日志代码
	* \param[in] msg		日志信息
	* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogDebug(string logcode, string &msg);

	/*! 
	* \fn int LogInfo(string logcode, string &msg)
	* \brief 记录Info类型日志
	* \param[in] logcode	日志代码
	* \param[in] msg		日志信息
	* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogInfo(string logcode, string &msg);

	/*! 
	* \fn int LogStat(string logcode, string &msg)
	* \brief 记录统计类型日志
	* \param[in] logcode	日志代码
	* \param[in] msg		日志信息
	* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogStat(string logcode, string &msg);

	/*! 
	* \fn intLogWarn(string logcode, string &msg)
	* \brief 记录Warn类型日志
	* \param[in] logcode	日志代码
	* \param[in] msg		日志信息
	* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogWarn(string logcode, string &msg);

	/*! 
	* \fn int LogError(string logcode, string &msg)
	* \brief 记录Error类型日志
	* \param[in] logcode	日志代码
	* \param[in] msg		日志信息
	* \return 成功则返回0，-1为记录错误，-2为根据当前日志等级，该日志未被记录
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int LogError(string logcode, string &msg);
	
	/*! 
	* \fn void setAppName(string appname)
	* \brief 程序名set方法，指定程序名
	* \param[in] appname	程序名
	* \return 无
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setAppName(string appname);

	/*! 
	* \fn void setLogMode(int logmode)
	* \brief 日志模式set方法，指定日志模式
	* \param[in] logmode	日志模式
	* \return 无
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setLogMode(int logmode);

	/*! 
	* \fn void setLogPath(string logpath)
	* \brief 日志文件路径set方法，指定日志文件路径
	* \param[in] logpath	日志文件路径
	* \return 无
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setLogPath(string logpath);

	/*! 
	* \fn void setTimeFlag(int timeflag)
	* \brief 时间戳标识set方法，指定时间戳标识
	* \param[in] timeflag	时间戳标识
	* \return 无
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setTimeFlag(int timeflag);

	/*! 
	* \fn void setOutputStream(streambuf *buf)
	* \brief 日志输出流set方法，指定日志输出流缓存
	* \param[in] buf	IO流缓存
	* \return 无
	* \author zhujunjie
	* \date 2012-2-23
	*/
	void setOutputStream(streambuf *buf);

private:
	
	/*! 
	* \fn //WriteLog(int logtype, string logcode, string &msg)
	* \brief 写日志函数，将日志输出到标准输出或文件
	* \param[in] logtype	日志类型（Debug, Info, Warn, Error等）
	* \param[in] logcode	日志代码
	* \param[in] msg		日志信息
	* \return 成功则返回0，负数为错误
	* \author zhujunjie
	* \date 2012-2-23
	*/
	int WriteLog(int logtype, string logcode, string &msg);

	/*! 
	* \fn string formatPath(string path)
	* \brief 格式化路径，确保路径以"/"或"\"结尾
	* \param[in] path	未格式化的路径
	* \return 格式化后的路径
	* \author zhujunjie
	* \date 2012-2-23
	*/
	string formatPath(string path);

	/*! 
	* \fn inline int getCurDay()
	* \brief 返回 yyyymmdd 格式的当前日期
	* \return yyyymmdd 格式的当前日期
	* \author zhujunjie
	* \date 2012-2-23
	*/
	inline int getCurDay();

public:

private:
	string strAppName;		/**< 当前程序名 */
	int iLogMode;			/**< 日志模式 */
	string strLogPath;		/**< 日志文件路径 */
	int iTimeFlag;			/**< 时间戳标识 */
	string strLogFileName;	/**< 日志文件名 */
	ofstream sLogFile;		/**< 日志文件输出流 */
	iostream sOutputStream;	/**< 日志输出流，可以为标准输出或文件 */
	int iCurDay;			/**< 当前日期 */
};
#endif

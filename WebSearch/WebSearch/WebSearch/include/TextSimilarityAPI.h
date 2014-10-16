#ifndef  __ICT_TEXT_SIMILARITY_API_H__
#define  __ICT_TEXT_SIMILARITY_API_H__

#ifdef _WIN32
#define ICT_TEXT_SIM_API __declspec(dllexport)
#else
#define ICT_TEXT_SIM_API
#endif

using namespace std;

	typedef void SIM_H;



    /*!
    *	\fn	int Sim_Init(const char *config_file,  SIM_H **h);
    *	\brief 相似度计算句柄初始化
    *   \param [in] config_file 配置文件
    *   \param [out] h 相似度计算句柄
    *	\return	成功返回 1，否则返回 0
    *	\author xxk
    */
   ICT_TEXT_SIM_API int Sim_Init(const char *config_file,  SIM_H **h);



    /*!
    *	\fn	int Sim_Exit(SIM_H *h_clf);
    *	\brief 句柄释放
    *   \param [in] h 句柄
    *	\return	成功返回 1，否则返回 0
    *	\author xxk
    */
ICT_TEXT_SIM_API int Sim_Exit( SIM_H *h);



    /*!
    * \fn int Sim_Get(SIM_H *h, const string &source_text,  const vector<string> &target_texts, vector<double> &sim_scores);
    * \brief 计算相似度
    * \param [in] text 输入源文本
    * \param [in] target_texts 输入目标文本列表
    * \param [in] h 句柄
    * \param [out] sim_scores 相似度得分列表，与 target_texts一一对应
    * \return	成功返回 1，否则返回 0
    *  \author xxk
    */
ICT_TEXT_SIM_API int Sim_Get(SIM_H *h, const string &source_text,  const vector<string> &target_texts, vector<double> &sim_scores);


#endif


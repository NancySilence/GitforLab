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
    *	\brief ���ƶȼ�������ʼ��
    *   \param [in] config_file �����ļ�
    *   \param [out] h ���ƶȼ�����
    *	\return	�ɹ����� 1�����򷵻� 0
    *	\author xxk
    */
   ICT_TEXT_SIM_API int Sim_Init(const char *config_file,  SIM_H **h);



    /*!
    *	\fn	int Sim_Exit(SIM_H *h_clf);
    *	\brief ����ͷ�
    *   \param [in] h ���
    *	\return	�ɹ����� 1�����򷵻� 0
    *	\author xxk
    */
ICT_TEXT_SIM_API int Sim_Exit( SIM_H *h);



    /*!
    * \fn int Sim_Get(SIM_H *h, const string &source_text,  const vector<string> &target_texts, vector<double> &sim_scores);
    * \brief �������ƶ�
    * \param [in] text ����Դ�ı�
    * \param [in] target_texts ����Ŀ���ı��б�
    * \param [in] h ���
    * \param [out] sim_scores ���ƶȵ÷��б��� target_textsһһ��Ӧ
    * \return	�ɹ����� 1�����򷵻� 0
    *  \author xxk
    */
ICT_TEXT_SIM_API int Sim_Get(SIM_H *h, const string &source_text,  const vector<string> &target_texts, vector<double> &sim_scores);


#endif


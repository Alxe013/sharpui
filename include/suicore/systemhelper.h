// ���ڿƼ���Ȩ���� 2010-2011
// 
// �ļ�����systemhelper.h
// ��  �ܣ�ϵͳ�����ࡣ
// 
// ��  �ߣ�����
// ʱ  �䣺2010-07-02
// 
// ============================================================================

# ifndef _UISYSTEMHELPER_H_
# define _UISYSTEMHELPER_H_

#include <suicore/uiobject.h>
#include <suicore/uiinterface.h>
#include <suicore/uiwindow.h>
#include <suicore/uibuilder.h>

namespace suic
{

class SUICORE_API SystemHelper : public Object
{
public:

    SystemHelper();

    static void* Malloc(int);
    static void Free(void*);

    static void Trace(suic::Char * format, ...);

    static String CalculatePath(const String& path);
    static bool ReadResource(const String& path);

    static DrawingContextPtr GetRenderContext(Element* pElem);

    static Uint32 SetTimer(suic::ElementPtr, suic::Uint32, int iPriority=-10);
    static void KillTimer(suic::ElementPtr, suic::Uint32);

    static suic::ImagePtr GetImage();

    /// <summary>
    ///     ������ʽ�����ļ������ظ�Ԫ��
    /// </summary>
    /// <remarks>
    ///     �˺���������Դ�ļ����ɽ���Ԫ�أ��ⲿ���Դ���
    ///     ��Ԫ�ص�ʵ���࣬ϵͳ��ʹ�ô��������Ԫ�أ�Ҳ��
    ///     �Դ���һ����������Դ����������ϵͳ��ʹ�ô����
    ///     ��Դ�����ʼ��Ԫ����ʽ������ʹ��ϵͳĬ�ϣ����鴫�룩
    /// </remarks>
    /// <param name="resid">
    ///     ��Դ�����ʶ
    /// </param>
    /// <param name="main">
    ///     ��Ԫ��ʵ����
    /// </param>
    /// <param name="xml">
    ///     ��Դ�����ļ�
    /// </param>
    /// <returns>��Ԫ�ض������main��Ϊ�գ���Ϊmain</returns>

    static suic::ImagePtr RenderToImage(suic::FrameworkElementPtr root);

    static void RegisterInitializeHook(suic::InitializeHookPtr);

    static void RegisterHwndMessageSystemHook(suic::HwndAdapterHookPtr hook);
    static void RemoveHwndMessageSystemHook(suic::HwndAdapterHookPtr hook);
    static void RegisterHwndMessageHook(suic::ElementPtr, suic::HwndAdapterHookPtr);
    static void RemoveHwndMessageHook(suic::ElementPtr, suic::HwndAdapterHookPtr);

    static void SetElementTopMost(suic::ElementPtr, bool);

    static void AddSystemMessageListener(MessageListener ml);
    static void RemoveSystemMessageListener(MessageListener ml);
    static void AddMessageListener(suic::Element*, MessageListener ml);
    static void RemoveMessageListener(suic::Element*, MessageListener ml);

    static void RegisterContent(ContentBuilder val);
};

};

#define UISys suic::SystemHelper
#define UIBuildApp(xml,m,res) suic::SystemHelper::BuildApp(xml,m,res)
#define UIBuildElem(xml,m,res) suic::SystemHelper::BuildElement(xml,m,res)

# endif
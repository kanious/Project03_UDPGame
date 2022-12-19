#ifndef _UIMANAGER_H_
#define _UIMANAGER_H_

#include "Base.h"

class Scene3D;
class UIManager : public Engine::CBase
{
	SINGLETON(UIManager)
private:
	Scene3D* m_pScene;

private:
	explicit UIManager();
	~UIManager();
public:
	void Destroy();
	void RenderUI();
	RESULT Ready(Scene3D* pScene);
};

#endif //_UIMANAGER_H_
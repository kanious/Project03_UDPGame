#include "UIManager.h"
#include "..\imgui\imgui_impl_glfw.h"
#include "..\imgui\imgui_impl_opengl3.h"
#include "OpenGLDevice.h"
#include "Define.h"
#include "Scene3D.h"

#include <sstream>
#include <iomanip>

SINGLETON_FUNCTION(UIManager)
USING(Engine)
USING(ImGui)
USING(std)

UIManager::UIManager()
	: m_pScene(nullptr)
{
}

UIManager::~UIManager()
{
}

void UIManager::Destroy()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	DestroyContext();
}

void UIManager::RenderUI()
{
	if (nullptr == m_pScene)
		return;

	if (!m_pScene->IsPlayerDead())
		return;
	
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	NewFrame();

	ImVec2 screen = ImVec2((_float)COpenGLDevice::GetInstance()->GetWidthSize(), (_float)COpenGLDevice::GetInstance()->GetHeightSize());
	SetNextWindowPos(ImVec2(0.f, 0.f));
	SetNextWindowSize(screen);
	if (Begin("Game Info", (bool*)0,
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoCollapse |
		ImGuiWindowFlags_NoTitleBar))
	{
		PushStyleColor(ImGuiCol_Text, IM_COL32(255, 0, 0, 255));
		Text("You are Dead!");
		PopStyleColor();
	}
	End();

	Render();
	ImGui_ImplOpenGL3_RenderDrawData(GetDrawData());
}

RESULT UIManager::Ready(Scene3D* pScene)
{
	m_pScene = pScene;

	IMGUI_CHECKVERSION();
	CreateContext();
	ImGuiIO& io = GetIO();

	if (!ImGui_ImplGlfw_InitForOpenGL(COpenGLDevice::GetInstance()->GetWindow(), true) ||
		!ImGui_ImplOpenGL3_Init("#version 460"))
		return PK_ERROR_IMGUI;
	StyleColorsDark();

	return PK_NOERROR;
}
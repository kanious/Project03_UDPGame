#include <sstream>

#include "Client.h"
#include "Define.h"
#include "GameMaster.h"
#include "Timer.h"
#include "OpenGLDevice.h"
#include "InputDevice.h"
#include "ComponentMaster.h"
#include "Camera.h"
#include "Transform.h"
#include "XMLParser.h"
#include <sstream>
#include <atlconv.h>

#include "Scene.h"
#include "Scene3D.h"
#include "UIManager.h"
#include "NetworkManager.h"

USING(Engine)
USING(std)

Client::Client()
{
	m_pGameMaster = CGameMaster::GetInstance();
	m_pTimer = CTimer::GetInstance(); m_pTimer->AddRefCnt();
	m_pGraphicDevice = COpenGLDevice::GetInstance(); m_pGraphicDevice->AddRefCnt();
	m_pInputDevice = CInputDevice::GetInstance(); m_pInputDevice->AddRefCnt();
	m_pNetworkManager = NetworkManager::GetInstance();

	m_iFPS = FPS;

	wchar_t path[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, path, MAX_PATH);
	USES_CONVERSION;
	std::string str = W2A(path);
	str = str.substr(0, str.find_last_of("\\/"));
	stringstream ss;
	ss << str << "\\..\\";
	m_DataPath = ss.str();
	m_SoundDataFileName = "UDPGame_sound.xml";
	m_ShaderDataFileName = "UDPGame_shader.xml";
	m_TextureDataFileName = "UDPGame_texture.xml";
	m_MeshDataFileName = "UDPGame_mesh.xml";
}

Client::~Client()
{
}

void Client::Destroy()
{
	SafeDestroy(m_pTimer);
	SafeDestroy(m_pInputDevice);
	SafeDestroy(m_pGraphicDevice);
	SafeDestroy(m_pGameMaster);

	SafeDestroy(UIManager::GetInstance());
	SafeDestroy(m_pNetworkManager);

	delete this;
}

void Client::Loop()
{
	_uint iFPS = 0;
	_float fCheckTime = 0.f;

	while (true)
	{
		if (nullptr == m_pGameMaster || nullptr == m_pTimer)
			break;

		if (glfwWindowShouldClose(COpenGLDevice::GetInstance()->GetWindow()) ||
			m_pInputDevice->IsKeyDown(GLFW_KEY_ESCAPE))
			break;

		if (m_pGameMaster->GetGameClose())
			break;

		m_pTimer->Update();
		if (m_pTimer->IsUpdateAvailable())
		{
			m_pGraphicDevice->GetWindowSize();
			glViewport(0, 0, m_pGraphicDevice->GetWidthSize(), m_pGraphicDevice->GetHeightSize());
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			_float dt = m_pTimer->GetTimeDelta();

			m_pGameMaster->Update(dt);

			m_pNetworkManager->Update(dt);
			m_pNetworkManager->SendTo(dt);
			m_pNetworkManager->RecvFrom(dt);

			m_pGameMaster->Render();

			glfwSwapBuffers(m_pGraphicDevice->GetWindow());
			glfwPollEvents();

			iFPS++;
		}

		fCheckTime += m_pTimer->GetTimeDefault();
		if (fCheckTime >= 1.f)
		{
			stringstream ssTitle;
			ssTitle << "FPS: " << iFPS;
			glfwSetWindowTitle(m_pGraphicDevice->GetWindow(), ssTitle.str().c_str());

			iFPS = 0;
			fCheckTime = 0.f;
		}
	}
}

RESULT Client::Ready()
{
	RESULT result = PK_NOERROR;

	srand((unsigned int)time(NULL));

	if (nullptr != m_pGraphicDevice)
	{
		result = m_pGraphicDevice->CreateOpenGLWindow(1920, 1080, "OpenGL Window", false, false);
		if (PK_NOERROR != result)
			return result;
	}

	if (nullptr != m_pTimer)
	{
		m_pTimer->SetFrameRate(m_iFPS);
	}

	if (nullptr != m_pInputDevice)
	{
		result = m_pInputDevice->SetupInputSystem(m_pGraphicDevice->GetWindow(), GLFW_CURSOR_NORMAL);
		if (PK_NOERROR != result)
			return result;
	}

	result = Ready_Basic_Component();
	if (PK_NOERROR != result)
		return result;

	m_pNetworkManager->Ready("127.0.0.1", DEFAULT_PORT);

	if (nullptr != m_pGameMaster)
	{
		CScene* pScene = Scene3D::Create();
		pScene->SetDataPath(m_DataPath);
		m_pGameMaster->SetCurrentScene(pScene);
		m_pNetworkManager->SetScene(dynamic_cast<Scene3D*>(pScene));
	}

	return PK_NOERROR;
}

RESULT Client::Ready_Basic_Component()
{
	CComponentMaster* pMaster = CComponentMaster::GetInstance();
	CComponent* pComponent = nullptr;

	//Create.Camera
	pComponent = CCamera::Create();
	if (nullptr != pComponent)
		pMaster->AddNewComponent("Camera", pComponent);
	else
		return PK_CAMERA_CREATE_FAILED;

	//Create.Transform
	pComponent = CTransform::Create();
	if (nullptr != pComponent)
		pMaster->AddNewComponent("Transform", pComponent);
	else
		return PK_TRANSFORM_CREATE_FAILED;

	//CXMLParser::GetInstance()->LoadSoundData(m_DataPath, m_SoundDataFileName);
	CXMLParser::GetInstance()->LoadShaderData(m_DataPath, m_ShaderDataFileName);
	CXMLParser::GetInstance()->LoadTextureData(m_DataPath, m_TextureDataFileName);
	CXMLParser::GetInstance()->LoadMeshData(m_DataPath, m_MeshDataFileName);

	return PK_NOERROR;
}

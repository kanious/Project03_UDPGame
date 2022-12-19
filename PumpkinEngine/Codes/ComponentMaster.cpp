#include "pch.h"
#include "..\Headers\ComponentMaster.h"
#include "..\Headers\Component.h"


USING(Engine)
USING(std)
SINGLETON_FUNCTION(CComponentMaster)

CComponentMaster::CComponentMaster()
{
	m_mapComponent.clear();
	m_mapMesh.clear();
}

CComponentMaster::~CComponentMaster()
{
}

void CComponentMaster::Destroy()
{
	COMPONENT_MAP::iterator iter;
	for (iter = m_mapComponent.begin(); iter != m_mapComponent.end(); ++iter)
		SafeDestroy(iter->second);

	m_mapComponent.clear();
	m_mapMesh.clear();
}

RESULT CComponentMaster::AddNewComponent(string tag, CComponent* pComponent)
{
	COMPONENT_MAP::iterator iter = m_mapComponent.find(tag);
	if (iter == m_mapComponent.end())
		m_mapComponent.insert(COMPONENT_MAP::value_type(tag, pComponent));
	else
		return PK_COMPONENT_EXIST;

	return PK_NOERROR;
}

RESULT CComponentMaster::AddNewMeshInfo(string tag, string initSize)
{
	MESH_MAP::iterator iter = m_mapMesh.find(tag);
	if (iter == m_mapMesh.end())
		m_mapMesh.insert(MESH_MAP::value_type(tag, initSize));
	else
		return PK_COMPONENT_EXIST;

	return PK_NOERROR;
}

CComponent* CComponentMaster::FindComponent(std::string tag)
{
	CComponent* pComponent = nullptr;

	COMPONENT_MAP::iterator iter = m_mapComponent.find(tag);
	if (iter != m_mapComponent.end())
		pComponent = iter->second;

	return pComponent;
}

#pragma once
#include "Include.h"

class CObj
{
protected:
	CObj*	m_pFront;
	INFO	m_tInfo;
	CObj*	m_pBack;

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	CObj* GetBack() { return  m_pBack; }
	CObj* GetFront() { return  m_pFront; }
	INFO GetInfo() { return m_tInfo; }
	void SetFront(CObj* _pnode) { m_pFront = _pnode; }
	void SetBack(CObj* _pnode) { m_pBack = _pnode; }
	char* SetName(); 

public:
	CObj(void);
	virtual ~CObj(void);
};

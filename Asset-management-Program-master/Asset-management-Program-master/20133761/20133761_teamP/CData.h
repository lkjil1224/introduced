#include "CObj.h"

class CData : public CObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	void CreateInfo();
public:
	CData(void);
	virtual ~CData(void);
};


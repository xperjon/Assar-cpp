#ifndef _OutlineFont_h_
#define _OutlineFont_h_

#include <GL/gl.h>
#include <string.h>





class COutlineFont
{
public:
	COutlineFont(
		CDC* dc,
		char* fontname);
	virtual ~COutlineFont();

	void 
	DrawString(char* s);

private:
	GLuint m_listbase;
	CDC* m_pDC;


private:
	COutlineFonr(){ }
	COutlineFont(const COutlineFont& obj) { }
	COutlineFont& operator=(const COutlineFont& obj) {return *this; }
};

#endif
# Microsoft Developer Studio Generated NMAKE File, Based on ASSAR.dsp
!IF "$(CFG)" == ""
CFG=radarplot - Win32 Debug
!MESSAGE No configuration specified. Defaulting to radarplot - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "radarplot - Win32 Release" && "$(CFG)" != "radarplot - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ASSAR.mak" CFG="radarplot - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "radarplot - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "radarplot - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "radarplot - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\ASSAR.exe"


CLEAN :
	-@erase "$(INTDIR)\ASSAR.obj"
	-@erase "$(INTDIR)\ASSAR.pch"
	-@erase "$(INTDIR)\ASSAR.res"
	-@erase "$(INTDIR)\AVIGenerator.obj"
	-@erase "$(INTDIR)\Cell.obj"
	-@erase "$(INTDIR)\CellLista.obj"
	-@erase "$(INTDIR)\ColorSlider.obj"
	-@erase "$(INTDIR)\DialogChoise.obj"
	-@erase "$(INTDIR)\DialogDiagram.obj"
	-@erase "$(INTDIR)\DialogKalibreraRadar.obj"
	-@erase "$(INTDIR)\DlgOverView.obj"
	-@erase "$(INTDIR)\DlgOverViewOpenGL.obj"
	-@erase "$(INTDIR)\dlgradarppi.obj"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\OpenGL.obj"
	-@erase "$(INTDIR)\ProgressBar.obj"
	-@erase "$(INTDIR)\PropPageJammer.obj"
	-@erase "$(INTDIR)\PropPageRadar.obj"
	-@erase "$(INTDIR)\PropPageTarget.obj"
	-@erase "$(INTDIR)\PropSheetUtrustning.obj"
	-@erase "$(INTDIR)\PropSheetUtrustning1.obj"
	-@erase "$(INTDIR)\PropSheetUtrustning2.obj"
	-@erase "$(INTDIR)\RadarCalculate.obj"
	-@erase "$(INTDIR)\radarplotDoc.obj"
	-@erase "$(INTDIR)\radarplotView.obj"
	-@erase "$(INTDIR)\RadarPPI.obj"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\Utrustning.obj"
	-@erase "$(INTDIR)\UtrustningLista.obj"
	-@erase "$(INTDIR)\UtrustningsKlasser.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\YellowEdit.obj"
	-@erase "$(OUTDIR)\ASSAR.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=df.exe
CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ASSAR.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x41d /fo"$(INTDIR)\ASSAR.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ASSAR.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glaux.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\ASSAR.pdb" /machine:I386 /out:"$(OUTDIR)\ASSAR.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ASSAR.obj" \
	"$(INTDIR)\AVIGenerator.obj" \
	"$(INTDIR)\Cell.obj" \
	"$(INTDIR)\CellLista.obj" \
	"$(INTDIR)\ColorSlider.obj" \
	"$(INTDIR)\DialogChoise.obj" \
	"$(INTDIR)\DialogDiagram.obj" \
	"$(INTDIR)\DialogKalibreraRadar.obj" \
	"$(INTDIR)\DlgOverView.obj" \
	"$(INTDIR)\DlgOverViewOpenGL.obj" \
	"$(INTDIR)\dlgradarppi.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OpenGL.obj" \
	"$(INTDIR)\ProgressBar.obj" \
	"$(INTDIR)\PropPageJammer.obj" \
	"$(INTDIR)\PropPageRadar.obj" \
	"$(INTDIR)\PropPageTarget.obj" \
	"$(INTDIR)\PropSheetUtrustning.obj" \
	"$(INTDIR)\PropSheetUtrustning1.obj" \
	"$(INTDIR)\PropSheetUtrustning2.obj" \
	"$(INTDIR)\RadarCalculate.obj" \
	"$(INTDIR)\radarplotDoc.obj" \
	"$(INTDIR)\radarplotView.obj" \
	"$(INTDIR)\RadarPPI.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Utrustning.obj" \
	"$(INTDIR)\UtrustningLista.obj" \
	"$(INTDIR)\UtrustningsKlasser.obj" \
	"$(INTDIR)\YellowEdit.obj" \
	"$(INTDIR)\ASSAR.res"

"$(OUTDIR)\ASSAR.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\ASSAR.exe" "$(OUTDIR)\ASSAR.bsc"


CLEAN :
	-@erase "$(INTDIR)\ASSAR.obj"
	-@erase "$(INTDIR)\ASSAR.pch"
	-@erase "$(INTDIR)\ASSAR.res"
	-@erase "$(INTDIR)\ASSAR.sbr"
	-@erase "$(INTDIR)\AVIGenerator.obj"
	-@erase "$(INTDIR)\AVIGenerator.sbr"
	-@erase "$(INTDIR)\Cell.obj"
	-@erase "$(INTDIR)\Cell.sbr"
	-@erase "$(INTDIR)\CellLista.obj"
	-@erase "$(INTDIR)\CellLista.sbr"
	-@erase "$(INTDIR)\ColorSlider.obj"
	-@erase "$(INTDIR)\ColorSlider.sbr"
	-@erase "$(INTDIR)\DialogChoise.obj"
	-@erase "$(INTDIR)\DialogChoise.sbr"
	-@erase "$(INTDIR)\DialogDiagram.obj"
	-@erase "$(INTDIR)\DialogDiagram.sbr"
	-@erase "$(INTDIR)\DialogKalibreraRadar.obj"
	-@erase "$(INTDIR)\DialogKalibreraRadar.sbr"
	-@erase "$(INTDIR)\DlgOverView.obj"
	-@erase "$(INTDIR)\DlgOverView.sbr"
	-@erase "$(INTDIR)\DlgOverViewOpenGL.obj"
	-@erase "$(INTDIR)\DlgOverViewOpenGL.sbr"
	-@erase "$(INTDIR)\dlgradarppi.obj"
	-@erase "$(INTDIR)\dlgradarppi.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\OpenGL.obj"
	-@erase "$(INTDIR)\OpenGL.sbr"
	-@erase "$(INTDIR)\ProgressBar.obj"
	-@erase "$(INTDIR)\ProgressBar.sbr"
	-@erase "$(INTDIR)\PropPageJammer.obj"
	-@erase "$(INTDIR)\PropPageJammer.sbr"
	-@erase "$(INTDIR)\PropPageRadar.obj"
	-@erase "$(INTDIR)\PropPageRadar.sbr"
	-@erase "$(INTDIR)\PropPageTarget.obj"
	-@erase "$(INTDIR)\PropPageTarget.sbr"
	-@erase "$(INTDIR)\PropSheetUtrustning.obj"
	-@erase "$(INTDIR)\PropSheetUtrustning.sbr"
	-@erase "$(INTDIR)\PropSheetUtrustning1.obj"
	-@erase "$(INTDIR)\PropSheetUtrustning1.sbr"
	-@erase "$(INTDIR)\PropSheetUtrustning2.obj"
	-@erase "$(INTDIR)\PropSheetUtrustning2.sbr"
	-@erase "$(INTDIR)\RadarCalculate.obj"
	-@erase "$(INTDIR)\RadarCalculate.sbr"
	-@erase "$(INTDIR)\radarplotDoc.obj"
	-@erase "$(INTDIR)\radarplotDoc.sbr"
	-@erase "$(INTDIR)\radarplotView.obj"
	-@erase "$(INTDIR)\radarplotView.sbr"
	-@erase "$(INTDIR)\RadarPPI.obj"
	-@erase "$(INTDIR)\RadarPPI.sbr"
	-@erase "$(INTDIR)\Splash.obj"
	-@erase "$(INTDIR)\Splash.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\Utrustning.obj"
	-@erase "$(INTDIR)\Utrustning.sbr"
	-@erase "$(INTDIR)\UtrustningLista.obj"
	-@erase "$(INTDIR)\UtrustningLista.sbr"
	-@erase "$(INTDIR)\UtrustningsKlasser.obj"
	-@erase "$(INTDIR)\UtrustningsKlasser.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(INTDIR)\YellowEdit.obj"
	-@erase "$(INTDIR)\YellowEdit.sbr"
	-@erase "$(OUTDIR)\ASSAR.bsc"
	-@erase "$(OUTDIR)\ASSAR.exe"
	-@erase "$(OUTDIR)\ASSAR.ilk"
	-@erase "$(OUTDIR)\ASSAR.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

F90=df.exe
CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ASSAR.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x41d /fo"$(INTDIR)\ASSAR.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ASSAR.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ASSAR.sbr" \
	"$(INTDIR)\AVIGenerator.sbr" \
	"$(INTDIR)\Cell.sbr" \
	"$(INTDIR)\CellLista.sbr" \
	"$(INTDIR)\ColorSlider.sbr" \
	"$(INTDIR)\DialogChoise.sbr" \
	"$(INTDIR)\DialogDiagram.sbr" \
	"$(INTDIR)\DialogKalibreraRadar.sbr" \
	"$(INTDIR)\DlgOverView.sbr" \
	"$(INTDIR)\DlgOverViewOpenGL.sbr" \
	"$(INTDIR)\dlgradarppi.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\OpenGL.sbr" \
	"$(INTDIR)\ProgressBar.sbr" \
	"$(INTDIR)\PropPageJammer.sbr" \
	"$(INTDIR)\PropPageRadar.sbr" \
	"$(INTDIR)\PropPageTarget.sbr" \
	"$(INTDIR)\PropSheetUtrustning.sbr" \
	"$(INTDIR)\PropSheetUtrustning1.sbr" \
	"$(INTDIR)\PropSheetUtrustning2.sbr" \
	"$(INTDIR)\RadarCalculate.sbr" \
	"$(INTDIR)\radarplotDoc.sbr" \
	"$(INTDIR)\radarplotView.sbr" \
	"$(INTDIR)\RadarPPI.sbr" \
	"$(INTDIR)\Splash.sbr" \
	"$(INTDIR)\StdAfx.sbr" \
	"$(INTDIR)\Utrustning.sbr" \
	"$(INTDIR)\UtrustningLista.sbr" \
	"$(INTDIR)\UtrustningsKlasser.sbr" \
	"$(INTDIR)\YellowEdit.sbr"

"$(OUTDIR)\ASSAR.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=opengl32.lib glu32.lib glaux.lib vfw32.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\ASSAR.pdb" /debug /machine:I386 /out:"$(OUTDIR)\ASSAR.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ASSAR.obj" \
	"$(INTDIR)\AVIGenerator.obj" \
	"$(INTDIR)\Cell.obj" \
	"$(INTDIR)\CellLista.obj" \
	"$(INTDIR)\ColorSlider.obj" \
	"$(INTDIR)\DialogChoise.obj" \
	"$(INTDIR)\DialogDiagram.obj" \
	"$(INTDIR)\DialogKalibreraRadar.obj" \
	"$(INTDIR)\DlgOverView.obj" \
	"$(INTDIR)\DlgOverViewOpenGL.obj" \
	"$(INTDIR)\dlgradarppi.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\OpenGL.obj" \
	"$(INTDIR)\ProgressBar.obj" \
	"$(INTDIR)\PropPageJammer.obj" \
	"$(INTDIR)\PropPageRadar.obj" \
	"$(INTDIR)\PropPageTarget.obj" \
	"$(INTDIR)\PropSheetUtrustning.obj" \
	"$(INTDIR)\PropSheetUtrustning1.obj" \
	"$(INTDIR)\PropSheetUtrustning2.obj" \
	"$(INTDIR)\RadarCalculate.obj" \
	"$(INTDIR)\radarplotDoc.obj" \
	"$(INTDIR)\radarplotView.obj" \
	"$(INTDIR)\RadarPPI.obj" \
	"$(INTDIR)\Splash.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Utrustning.obj" \
	"$(INTDIR)\UtrustningLista.obj" \
	"$(INTDIR)\UtrustningsKlasser.obj" \
	"$(INTDIR)\YellowEdit.obj" \
	"$(INTDIR)\ASSAR.res"

"$(OUTDIR)\ASSAR.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ASSAR.dep")
!INCLUDE "ASSAR.dep"
!ELSE 
!MESSAGE Warning: cannot find "ASSAR.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "radarplot - Win32 Release" || "$(CFG)" == "radarplot - Win32 Debug"
SOURCE=.\ASSAR.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\ASSAR.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\ASSAR.obj"	"$(INTDIR)\ASSAR.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\ASSAR.rc

"$(INTDIR)\ASSAR.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\AVIGenerator.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\AVIGenerator.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\AVIGenerator.obj"	"$(INTDIR)\AVIGenerator.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\Cell.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\Cell.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\Cell.obj"	"$(INTDIR)\Cell.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\CellLista.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\CellLista.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\CellLista.obj"	"$(INTDIR)\CellLista.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\ColorSlider.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\ColorSlider.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\ColorSlider.obj"	"$(INTDIR)\ColorSlider.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\DialogChoise.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\DialogChoise.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\DialogChoise.obj"	"$(INTDIR)\DialogChoise.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\DialogDiagram.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\DialogDiagram.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\DialogDiagram.obj"	"$(INTDIR)\DialogDiagram.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\DialogKalibreraRadar.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\DialogKalibreraRadar.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\DialogKalibreraRadar.obj"	"$(INTDIR)\DialogKalibreraRadar.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\DlgOverView.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\DlgOverView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\DlgOverView.obj"	"$(INTDIR)\DlgOverView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\DlgOverViewOpenGL.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\DlgOverViewOpenGL.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\DlgOverViewOpenGL.obj"	"$(INTDIR)\DlgOverViewOpenGL.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\dlgradarppi.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\dlgradarppi.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\dlgradarppi.obj"	"$(INTDIR)\dlgradarppi.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\MainFrm.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\OpenGL.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\OpenGL.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\OpenGL.obj"	"$(INTDIR)\OpenGL.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\ProgressBar.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\ProgressBar.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\ProgressBar.obj"	"$(INTDIR)\ProgressBar.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\PropPageJammer.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\PropPageJammer.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\PropPageJammer.obj"	"$(INTDIR)\PropPageJammer.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\PropPageRadar.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\PropPageRadar.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\PropPageRadar.obj"	"$(INTDIR)\PropPageRadar.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\PropPageTarget.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\PropPageTarget.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\PropPageTarget.obj"	"$(INTDIR)\PropPageTarget.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\PropSheetUtrustning.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\PropSheetUtrustning.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\PropSheetUtrustning.obj"	"$(INTDIR)\PropSheetUtrustning.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\PropSheetUtrustning1.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\PropSheetUtrustning1.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\PropSheetUtrustning1.obj"	"$(INTDIR)\PropSheetUtrustning1.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\PropSheetUtrustning2.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\PropSheetUtrustning2.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\PropSheetUtrustning2.obj"	"$(INTDIR)\PropSheetUtrustning2.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\RadarCalculate.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\RadarCalculate.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\RadarCalculate.obj"	"$(INTDIR)\RadarCalculate.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\radarplotDoc.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\radarplotDoc.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\radarplotDoc.obj"	"$(INTDIR)\radarplotDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\radarplotView.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\radarplotView.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\radarplotView.obj"	"$(INTDIR)\radarplotView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\RadarPPI.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\RadarPPI.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\RadarPPI.obj"	"$(INTDIR)\RadarPPI.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\Splash.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\Splash.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\Splash.obj"	"$(INTDIR)\Splash.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Fp"$(INTDIR)\ASSAR.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\ASSAR.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ASSAR.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\ASSAR.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 

SOURCE=.\Utrustning.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\Utrustning.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\Utrustning.obj"	"$(INTDIR)\Utrustning.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\UtrustningLista.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\UtrustningLista.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\UtrustningLista.obj"	"$(INTDIR)\UtrustningLista.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\UtrustningsKlasser.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\UtrustningsKlasser.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\UtrustningsKlasser.obj"	"$(INTDIR)\UtrustningsKlasser.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 

SOURCE=.\YellowEdit.cpp

!IF  "$(CFG)" == "radarplot - Win32 Release"


"$(INTDIR)\YellowEdit.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"


"$(INTDIR)\YellowEdit.obj"	"$(INTDIR)\YellowEdit.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\ASSAR.pch"


!ENDIF 


!ENDIF 


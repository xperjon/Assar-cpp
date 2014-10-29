# Microsoft Developer Studio Project File - Name="radarplot" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=radarplot - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ASSAR.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "radarplot - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE F90 /compile_only /nologo /warn:nofileopt /winapp
# ADD F90 /compile_only /nologo /warn:nofileopt /winapp
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x41d /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 opengl32.lib glu32.lib glaux.lib vfw32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "radarplot - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
F90=df.exe
# ADD BASE F90 /check:bounds /compile_only /debug:full /nologo /traceback /warn:argument_checking /warn:nofileopt /winapp
# ADD F90 /browser /check:bounds /compile_only /debug:full /nologo /traceback /warn:argument_checking /warn:nofileopt /winapp
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x41d /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 opengl32.lib glu32.lib glaux.lib vfw32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "radarplot - Win32 Release"
# Name "radarplot - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;f90;for;f;fpp"
# Begin Source File

SOURCE=.\ASSAR.cpp
# End Source File
# Begin Source File

SOURCE=.\ASSAR.rc
# End Source File
# Begin Source File

SOURCE=.\Cell.cpp
# End Source File
# Begin Source File

SOURCE=.\CellLista.cpp
# End Source File
# Begin Source File

SOURCE=.\ColorSlider.cpp
# End Source File
# Begin Source File

SOURCE=.\DataFile.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogChoise.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogKalibreraRadar.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgOverViewOpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\dlgradarppi.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRandomFalseTargets.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\OpenGL.cpp
# End Source File
# Begin Source File

SOURCE=.\PropPageJammer.cpp
# End Source File
# Begin Source File

SOURCE=.\PropPageRadar.cpp
# End Source File
# Begin Source File

SOURCE=.\PropPageTarget.cpp
# End Source File
# Begin Source File

SOURCE=.\PropSheetUtrustning.cpp
# End Source File
# Begin Source File

SOURCE=.\PropSheetUtrustning1.cpp
# End Source File
# Begin Source File

SOURCE=.\PropSheetUtrustning2.cpp
# End Source File
# Begin Source File

SOURCE=.\RadarCalculate.cpp
# End Source File
# Begin Source File

SOURCE=.\radarplotDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\radarplotView.cpp
# End Source File
# Begin Source File

SOURCE=.\RadarPPI.cpp
# End Source File
# Begin Source File

SOURCE=.\Splash.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\Utrustning.cpp
# End Source File
# Begin Source File

SOURCE=.\UtrustningLista.cpp
# End Source File
# Begin Source File

SOURCE=.\UtrustningsKlasser.cpp
# End Source File
# Begin Source File

SOURCE=.\YellowEdit.cpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ASSAR.ico
# End Source File
# Begin Source File

SOURCE=.\res\ASSARDOC.ico
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Exempel.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fmvlogga.bmp
# End Source File
# Begin Source File

SOURCE=.\res\fmvloggaliten.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\res\ico00002.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon1_j.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon3_j.ico
# End Source File
# Begin Source File

SOURCE=..\..\iconer\icon3_j.ico
# End Source File
# Begin Source File

SOURCE=.\iconstop.ico
# End Source File
# Begin Source File

SOURCE=.\res\iconstop.ico
# End Source File
# Begin Source File

SOURCE=.\res\iconwarn.ico
# End Source File
# Begin Source File

SOURCE=.\res\JAS39.bmp
# End Source File
# Begin Source File

SOURCE=.\res\JAS392.bmp
# End Source File
# Begin Source File

SOURCE=.\res\JAS39_4.bmp
# End Source File
# Begin Source File

SOURCE=".\res\jonne&emma(liten).bmp"
# End Source File
# Begin Source File

SOURCE=".\res\L-39.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\L-39200x160.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\l39.bmp
# End Source File
# Begin Source File

SOURCE=.\res\MONA.BMP
# End Source File
# Begin Source File

SOURCE=.\res\radarplot.ico
# End Source File
# Begin Source File

SOURCE=.\res\radarplot.rc2
# End Source File
# Begin Source File

SOURCE=.\res\radarplotDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\RadarPPI.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Splash.bmp
# End Source File
# Begin Source File

SOURCE=.\Splsh16.bmp
# End Source File
# Begin Source File

SOURCE=.\res\test.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\res\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\visby2profil.bmp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=.\ASSAR.h
# End Source File
# Begin Source File

SOURCE=.\Cell.h
# End Source File
# Begin Source File

SOURCE=.\CellLista.h
# End Source File
# Begin Source File

SOURCE=.\ColorSlider.h
# End Source File
# Begin Source File

SOURCE=.\DataFile.h
# End Source File
# Begin Source File

SOURCE=.\DialogChoise.h
# End Source File
# Begin Source File

SOURCE=.\DialogKalibreraRadar.h
# End Source File
# Begin Source File

SOURCE=.\DlgOverViewOpenGL.h
# End Source File
# Begin Source File

SOURCE=.\dlgradarppi.h
# End Source File
# Begin Source File

SOURCE=.\DlgRandomFalseTargets.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\OpenGL.h
# End Source File
# Begin Source File

SOURCE=.\PropPageJammer.h
# End Source File
# Begin Source File

SOURCE=.\PropPageRadar.h
# End Source File
# Begin Source File

SOURCE=.\PropPageTarget.h
# End Source File
# Begin Source File

SOURCE=.\PropSheetUtrustning.h
# End Source File
# Begin Source File

SOURCE=.\PropSheetUtrustning1.h
# End Source File
# Begin Source File

SOURCE=.\PropSheetUtrustning2.h
# End Source File
# Begin Source File

SOURCE=.\RadarCalculate.h
# End Source File
# Begin Source File

SOURCE=.\radarplotDoc.h
# End Source File
# Begin Source File

SOURCE=.\radarplotView.h
# End Source File
# Begin Source File

SOURCE=.\RadarPPI.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Splash.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Utrustning.h
# End Source File
# Begin Source File

SOURCE=.\UtrustningLista.h
# End Source File
# Begin Source File

SOURCE=.\UtrustningsKlasser.h
# End Source File
# Begin Source File

SOURCE=.\YellowEdit.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section radarplot : {0BBDD0B9-A5DB-4B72-B18C-63EB0880B938}
# 	1:19:IDD_DIALOG_PPI_PLOT:103
# 	2:16:Resource Include:resource.h
# 	2:19:IDD_DIALOG_PPI_PLOT:IDD_DIALOG_PPI_PLOT
# 	2:22:CLASS: DIALOG_PPI_PLOT:DIALOG_PPI_PLOT
# 	2:17:DIALOG_PPI_PLOT.h:DIALOG_PPI_PLOT2.h
# 	2:10:ENUM: enum:enum
# 	2:19:DIALOG_PPI_PLOT.cpp:DIALOG_PPI_PLOT2.cpp
# 	2:19:Application Include:radarplot.h
# End Section
# Section radarplot : {72ADFD78-2C39-11D0-9903-00A0C91BC942}
# 	1:10:IDB_SPLASH:119
# 	2:21:SplashScreenInsertKey:4.0
# End Section

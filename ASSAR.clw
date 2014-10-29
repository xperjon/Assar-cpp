; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRadarplotView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "radarplot.h"
LastPage=0

ClassCount=34
Class1=CASSARApp
Class2=CRadarplotDoc
Class3=CRadarplotView
Class4=CMainFrame

ResourceCount=60
Resource1=IDD_DIALOG_RANDOM (Swedish)
Resource2=IDD_PROP_JAMMER_JAMODE1 (Swedish)
Class5=CAboutDlg
Resource3=IDD_PROP_RADAR_INDICATOR
Resource4=IDD_RADARPROP_SIGNALPROCESSING (English (U.S.))
Class6=CDlgOverViewOpenGL
Resource5=IDD_PROP_JAMMER_JAMODE1
Resource6=IDR_MENU_RADAR
Class7=COpenGL
Class8=CDlgRadarPPI
Resource7=IDD_DIALOG_PPI_PLOT1 (English (U.S.))
Class9=CRadarPPI
Resource8=IDD_PROP_RADAR_TX
Resource9=IDD_PROP_JAMMER_JAMODE2 (Swedish)
Resource10=IDR_MENU_JAMMER
Resource11=IDD_DIALOG_DIAGRAM
Resource12=IDR_MENU_VIEW_RUN (English (U.S.))
Resource13=IDD_PROPPAGE_MEDIUM (English (U.S.))
Resource14=IDD_PROP_JAMMER_RXTX
Resource15=IDD_ABOUTBOX
Class10=CPropSheetRadar
Class11=CPropPage1Radar
Class12=CPropPage2Radar
Class13=CPropPage3Radar
Class14=CPropPage4Radar
Class15=CPropPage5Radar
Resource16=IDD_PROP_TARGET_IDENTITY
Resource17=IDD_FORMVIEW (English (U.S.))
Resource18=IDD_DIALOG1 (Swedish)
Resource19=IDD_PROP_RADAR_IDENTITY
Resource20=IDD_DIALOG_RADARPPI
Class16=CPropSheetJammer
Class17=CPropPage1Jammer
Class18=CPropPage2Jammer
Class19=CPropPage3Jammer
Class20=CPropPage4Jammer
Class21=CPropPage5Jammer
Resource21=IDD_ABOUTBOX (English (U.S.))
Class22=CPropSheetTarget
Class23=CPropPage1Target
Class24=CPropPage2Target
Resource22=IDD_DLG_KALIBRERA
Resource23=IDD_PROP_RADAR_ECCM (English (U.S.))
Class25=CDlgRandomFalseTargets
Resource24=IDR_MENU_RUN
Resource25=IDD_PROP_RADAR_RXSIGNALPROCESSING
Class26=CPropPage6Radar
Resource26=IDD_DIALOG_PPI_PLOT (English (U.S.))
Class27=CPropPage7Radar
Resource27=IDD_DIALOGOVERVIEW
Class28=CDialogKalibreraRadar
Class29=CSplashWnd
Class30=CYellowEdit
Class31=CColorSlider
Resource28=IDD_PROP_SYMBOL
Class32=CDialogChoise
Class33=CDialogDiagram
Resource29=IDD_PROP_RADAR_RXSIGNALPROCESSING2 (English (U.S.))
Resource30=IDR_MAINFRAME (English (U.S.))
Resource31=IDD_PROP_RADAR_ANTENNA
Class34=CAntennaDiagramForm
Resource32=IDD_PROP_JAMMER_JAMODE2
Resource33=IDD_PROP_JAMMER_RXTX (Swedish)
Resource34=IDD_PROP_TARGET_IDENTITY (Swedish)
Resource35=IDD_DIALOGOVERVIEW (Swedish)
Resource36=IDR_MENU_RUN (Swedish)
Resource37=IDR_MENU_RADAR (Swedish)
Resource38=IDR_MENU_JAMMER (Swedish)
Resource39=IDR_MENU_TARGET (Swedish)
Resource40=IDD_DIALOG_CHOISE (Swedish)
Resource41=IDD_DLG_KALIBRERA (Swedish)
Resource42=IDD_DIALOG_DIAGRAM (Swedish)
Resource43=IDR_MAINFRAME
Resource44=IDD_DIALOG_RADARPPI (Swedish)
Resource45=IDD_PROP_RADAR_INDICATOR (Swedish)
Resource46=IDD_PROP_RADAR_ECCM
Resource47=IDD_PROP_RADAR_RXSIGNALPROCESSING2
Resource48=IDD_PROP_RADAR_IDENTITY (Swedish)
Resource49=IDD_DIALOG_PPI_PLOT
Resource50=IDD_PROP_RADAR_TX (Swedish)
Resource51=IDD_PROP_RADAR_ANTENNA (Swedish)
Resource52=IDD_PROP_RADAR_RXSIGNALPROCESSING (Swedish)
Resource53=IDD_PROP_JAMMER_IDENTITY (Swedish)
Resource54=IDD_PROP_JAMMER_ANTENNA (Swedish)
Resource55=IDD_PROP_SYMBOL (Swedish)
Resource56=IDD_PROP_JAMMER_ANTENNA
Resource57=IDR_MENU_TARGET
Resource58=IDD_DIALOG_CHOISE
Resource59=IDD_PROP_JAMMER_IDENTITY
Resource60=IDD_DIALOG_RANDOM

[CLS:CRadarplotDoc]
Type=0
HeaderFile=radarplotDoc.h
ImplementationFile=radarplotDoc.cpp
Filter=N
LastObject=CRadarplotDoc

[CLS:CRadarplotView]
Type=0
HeaderFile=radarplotView.h
ImplementationFile=radarplotView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CRadarplotView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=assar.h
ImplementationFile=assar.cpp
BaseClass=CDialog
LastObject=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_DIAGRAMS_EFFECT
Command3=ID_ANALASYS_FILMCLIP
Command4=ID_VIEW_TOOLBAR
Command5=ID_VIEW_STATUS_BAR
Command6=ID_VIEW_SENARIO
Command7=ID_VIEW_OVERVIEW
Command8=ID_VIEW_EXTRA
Command9=ID_APP_ABOUT
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_CUT
Command14=ID_EDIT_UNDO
CommandCount=14

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVEAS
Command6=ID_FILE_SAVEALL
Command7=ID_FILE_IMPORT
Command8=ID_FILE_EXPORT
Command9=ID_APP_EXIT
Command10=ID_SCENARIO_ADDRADAR
Command11=ID_SCENARIO_ADDJAMMER
Command12=ID_SCENARIO_ADDTARGET
Command13=ID_SCENARIO_CLEAR
Command14=ID_SIMULATION_START
Command15=ID_SIMULATION_STOP
Command16=ID_SIMULATION_PAUSE
Command17=ID_SIMULATION_RESUME
Command18=ID_SIMULATION_FULLSCREEN
Command19=ID_SIMULATION_PREFERENCES
Command20=ID_VIEW_TOOLBAR
Command21=ID_VIEW_STATUS_BAR
Command22=ID_VIEW_SENARIO
Command23=ID_VIEW_OVERVIEW
Command24=ID_APP_ABOUT
CommandCount=24

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_FILE_SAVE
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_CUT
Command14=ID_EDIT_UNDO
CommandCount=14

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342177294
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_FORMVIEW (English (U.S.))]
Type=1
Class=CAntennaDiagramForm
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_PROPPAGE_MEDIUM (English (U.S.))]
Type=1
Class=?
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_PPI_PLOT1 (English (U.S.))]
Type=1
Class=CDialogDiagram
ControlCount=1
Control1=IDC_PPIPLOT_STATIC,static,1342308352

[DLG:IDD_DIALOG_PPI_PLOT (English (U.S.))]
Type=1
Class=CDlgRadarPPI
ControlCount=30
Control1=IDC_BUTTON1,button,1342242880
Control2=IDC_BUTTON_JAMMODE1,button,1342242816
Control3=IDC_BUTTON_JAMMODE2,button,1342242816
Control4=IDC_BUTTON_JAMMODE3,button,1476460544
Control5=IDC_TIMELINE,msctls_trackbar32,1342242836
Control6=IDC_BUTTON_JAMMODE4,button,1476460544
Control7=IDC_BUTTON_PAUS,button,1342242880
Control8=IDC_EDIT_JAM1,edit,1342244997
Control9=IDC_EDIT_JAM2,edit,1342244997
Control10=IDC_EDIT_JAM5,edit,1342244997
Control11=IDC_EDIT_JAM6,edit,1342244997
Control12=IDC_EDIT_JAM4,edit,1342244997
Control13=IDC_EDIT_TIMELINE,edit,1342244993
Control14=IDC_BUTTON_OFF,button,1342242816
Control15=IDC_EDIT_JAM3,edit,1342244997
Control16=IDC_BUTTON_RESTORE,button,1342275584
Control17=IDC_EDIT_RAD1,edit,1342244997
Control18=IDC_EDIT_RAD2,edit,1342244997
Control19=IDC_EDIT_RAD5,edit,1342244997
Control20=IDC_EDIT_RAD6,edit,1342244997
Control21=IDC_EDIT_RAD4,edit,1342244997
Control22=IDC_EDIT_RAD3,edit,1342244997
Control23=IDC_EDIT_RAD7,edit,1342244997
Control24=IDC_EDIT_RAD8,edit,1342244997
Control25=IDC_BUTTON_RADSYNTETIC,button,1476460544
Control26=IDC_BUTTON_RADRAWVIDEO,button,1476460544
Control27=IDC_BUT_SHOWDISK,button,1342245888
Control28=IDC_BUT_DEGREES,button,1342242816
Control29=IDC_BUT_FFW,button,1342242816
Control30=IDC_BUT_REW,button,1342242816

[MNU:IDR_MENU_RADAR]
Type=1
Class=CRadarplotView
Command1=ID_OPENRADAR
Command2=ID_SAVERADAR
Command3=ID_PROPERTIES_RADAR
Command4=ID_KALIBRERA_RADAR
Command5=ID_DELETE_RADAR
CommandCount=5

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_BUTTON_CREATE_RADAR
Command2=ID_BUTTON_CREATE_JAMMER
Command3=ID_BUTTON_CREATE_TARGET
Command4=ID_BUTTON_CLEARALL
Command5=ID_BUTTON_PPI
Command6=ID_BUTTON_STOP
Command7=ID_BUTTON32816
Command8=ID_BUTTON32817
Command9=ID_BUTTON32818
CommandCount=9

[MNU:IDR_MENU_JAMMER]
Type=1
Class=CRadarplotView
Command1=ID_OPENJAMMER
Command2=ID_SAVEJAMMER
Command3=ID_PROPERTIES_JAMMER
Command4=ID_DELETE_JAMMER
CommandCount=4

[MNU:IDR_MENU_TARGET]
Type=1
Class=CRadarplotView
Command1=ID_PROPERTIES_TARGET
Command2=ID_DELETE_TARGET
CommandCount=2

[CLS:CPropSheetRadar]
Type=0
HeaderFile=PropSheetUtrustning.h
ImplementationFile=PropSheetUtrustning.cpp
BaseClass=CPropertySheet
LastObject=CPropSheetRadar
Filter=W
VirtualFilter=hWC

[CLS:CPropPage1Radar]
Type=0
HeaderFile=PropPageRadar.h
ImplementationFile=PropPageRadar.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_EDIT_NAME

[CLS:CPropPage2Radar]
Type=0
HeaderFile=PropPageRadar.h
ImplementationFile=PropPageRadar.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPropPage2Radar

[CLS:CPropPage3Radar]
Type=0
HeaderFile=PropPageRadar.h
ImplementationFile=PropPageRadar.cpp
BaseClass=CPropertyPage
LastObject=IDC_EDIT_JSRATIO
Filter=D
VirtualFilter=idWC

[CLS:CPropPage4Radar]
Type=0
HeaderFile=PropPageRadar.h
ImplementationFile=PropPageRadar.cpp
BaseClass=CPropertyPage
LastObject=IDC_EDIT_WIDTHMAINLOBE
Filter=D
VirtualFilter=idWC

[CLS:CPropPage5Radar]
Type=0
HeaderFile=PropPageRadar.h
ImplementationFile=PropPageRadar.cpp
BaseClass=CPropertyPage
LastObject=IDC_COMBO_INDICATORTYPE
Filter=D
VirtualFilter=idWC

[CLS:CPropSheetJammer]
Type=0
HeaderFile=PropSheetUtrustning1.h
ImplementationFile=PropSheetUtrustning1.cpp
BaseClass=CPropertySheet
LastObject=CPropSheetJammer

[CLS:CPropPage1Jammer]
Type=0
HeaderFile=PropPageJammer.h
ImplementationFile=PropPageJammer.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_EDIT_VELOCITY

[CLS:CPropPage2Jammer]
Type=0
HeaderFile=PropPageJammer.h
ImplementationFile=PropPageJammer.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPropPage2Jammer

[CLS:CPropPage3Jammer]
Type=0
HeaderFile=PropPageJammer.h
ImplementationFile=PropPageJammer.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=IDC_EDIT_BEAMWIDTHRX

[CLS:CPropPage4Jammer]
Type=0
HeaderFile=PropPageJammer.h
ImplementationFile=PropPageJammer.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPropPage4Jammer

[CLS:CPropPage5Jammer]
Type=0
HeaderFile=PropPageJammer.h
ImplementationFile=PropPageJammer.cpp
BaseClass=CPropertyPage
LastObject=CPropPage5Jammer
Filter=D
VirtualFilter=idWC

[CLS:CPropSheetTarget]
Type=0
HeaderFile=PropSheetUtrustning2.h
ImplementationFile=PropSheetUtrustning2.cpp
BaseClass=CPropertySheet
LastObject=CPropSheetTarget

[CLS:CPropPage1Target]
Type=0
HeaderFile=PropPageTarget.h
ImplementationFile=PropPageTarget.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPropPage1Target

[CLS:CPropPage2Target]
Type=0
HeaderFile=PropPageTarget.h
ImplementationFile=PropPageTarget.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CPropPage2Target

[MNU:IDR_MENU_RUN]
Type=1
Class=CDlgRadarPPI
Command1=ID_MENU_STOP
Command2=ID_MENU_RUN
Command3=ID_MENU_PAUSE
Command4=ID_MENU_FASTER
Command5=ID_MENU_SLOWER
Command6=ID_MENUD_ZOOMIN
Command7=ID_MENUD_ZOOMOUT
Command8=ID_MENUD_FITTOSCREEN
Command9=ID_MENUD_RAWVIDEOMODE
Command10=ID_MENUD_SYNTETICMODE
Command11=ID_MENUD_RAWVIDEOSYNTETIC
CommandCount=11

[DLG:IDD_DIALOGOVERVIEW]
Type=1
Class=CDlgOverViewOpenGL
ControlCount=7
Control1=IDC_BUT_MOVE,button,1342242816
Control2=IDC_BUT_WAYPOINT,button,1342242816
Control3=IDC_BUT_DELETEWAYPOINT,button,1342242816
Control4=IDC_STATIC_TIME,static,1342308352
Control5=IDC_STATIC_COOR,static,1342308352
Control6=IDC_STATIC_DISTTORADAR,static,1342308352
Control7=IDC_CHECK_ALLWAYPOINTS,button,1342242819

[DLG:IDD_RADARPROP_SIGNALPROCESSING (English (U.S.))]
Type=1
Class=CPropSheetRadar
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_IDENTITY]
Type=1
Class=CPropPage1Radar
ControlCount=5
Control1=IDC_EDIT_NAME,edit,1350631552
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_JAMMER_IDENTITY]
Type=1
Class=CPropPage1Jammer
ControlCount=23
Control1=IDC_EDIT_JAMMERNAME,edit,1350631552
Control2=IDC_COMBO_COLOR,combobox,1344340226
Control3=IDC_EDIT_DISTANCETORADAR,edit,1350631552
Control4=IDC_EDIT_BEARING,edit,1350631552
Control5=IDC_EDIT_VELOCITY,edit,1350631552
Control6=IDC_EDIT_VELOCITY_KMH,edit,1350631552
Control7=IDC_EDIT_VELOCITY_KNOP,edit,1350631552
Control8=IDC_EDIT_SIGMA,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_TARGET_IDENTITY]
Type=1
Class=CPropPage1Target
ControlCount=22
Control1=IDC_EDIT_TARGETNAME,edit,1350631552
Control2=IDC_COMBO_COLOR,combobox,1344340226
Control3=IDC_EDIT_DISTANCETORADAR,edit,1350631552
Control4=IDC_EDIT_BEARING,edit,1350631552
Control5=IDC_EDIT_COURSE,edit,1350631552
Control6=IDC_EDIT_VELOCITY,edit,1350631552
Control7=IDC_EDIT_SIGMA,edit,1350631552
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_TX]
Type=1
Class=CPropPage2Radar
ControlCount=35
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_EDIT_PULSEWIDTH,edit,1350631552
Control3=IDC_CHECK_PULSEGROUP,button,1342242819
Control4=IDC_CHECK_FIXFREQ,button,1342242819
Control5=IDC_EDIT_NBROFPULSES,edit,1350631552
Control6=IDC_EDIT_CHANNELSEPARATION,edit,1350631552
Control7=IDC_EDIT_MINFREQ,edit,1350631552
Control8=IDC_EDIT_MAXFREQ,edit,1350631552
Control9=IDC_COMBO_PRITYPE,combobox,1344340226
Control10=IDC_EDIT_PRI,edit,1350631552
Control11=IDC_EDIT_PRF,edit,1350631552
Control12=IDC_EDIT_PRIDEVIATION,edit,1484783744
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,button,1342177287
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,button,1342177287
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_BUTTON1,button,1476460544

[DLG:IDD_PROP_JAMMER_RXTX]
Type=1
Class=CPropPage2Jammer
ControlCount=17
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EDIT_FREQMIN,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_FREQMAX,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_EDIT_SENSITIVITY,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_FREQMIN2,edit,1484849280
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_FREQMAX2,edit,1484849280
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_ANTENNA]
Type=1
Class=CPropPage4Radar
ControlCount=43
Control1=IDC_EDIT_SCANPERIOD,edit,1350631552
Control2=IDC_EDIT_SIDELOBESUPRESSION,edit,1350631552
Control3=IDC_EDIT_WIDTHMAINLOBE,edit,1350631552
Control4=IDC_EDIT_GAINMAINLOBE,edit,1350631552
Control5=IDC_EDIT_SPILLOVERLOBESUPRESSION,edit,1350631552
Control6=IDC_EDIT_WIDTHSPILLOVERLOBE,edit,1350631552
Control7=IDC_EDIT_OFFSETSPILLOVERLOBE,edit,1350631552
Control8=IDC_EDIT_BACKLOBESUPRESSION,edit,1350631552
Control9=IDC_EDIT_WIDTHBACKLOBE,edit,1350631552
Control10=IDC_COMBO_POLARIZATION,combobox,1344340226
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_EDIT_SIDELOBESUPRESSION3,edit,1350631552
Control23=IDC_EDIT_WIDTHMAINLOBE2,edit,1350631552
Control24=IDC_EDIT_GAINMAINLOBE2,edit,1350631552
Control25=IDC_EDIT_SPILLOVERLOBESUPRESSION2,edit,1350631552
Control26=IDC_EDIT_WIDTHSPILLOVERLOBE2,edit,1350631552
Control27=IDC_EDIT_OFFSETSPILLOVERLOBE2,edit,1350631552
Control28=IDC_EDIT_BACKLOBESUPRESSION2,edit,1350631552
Control29=IDC_EDIT_WIDTHBACKLOBE2,edit,1350631552
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_STATIC,static,1342308352
Control38=IDC_STATIC,static,1342308352
Control39=IDC_STATIC,static,1342308352
Control40=IDC_STATIC,static,1342308352
Control41=IDC_LOOKUP_BUTTON,button,1342242816
Control42=IDC_CHECK_FROMFILE,button,1342242819
Control43=IDC_STATIC_FILENAME,static,1342312448

[DLG:IDD_PROP_JAMMER_ANTENNA]
Type=1
Class=CPropPage3Jammer
ControlCount=23
Control1=IDC_COMBO_ANTENNATYPE,combobox,1344340226
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_COMBO_POLARIZATION,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_SIDELOBESUPRESSION,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_ANTENNAGAINTX,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_BEAMWIDTHTX,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_ANTENNAGAINRX,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_BEAMWIDTHRX,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_RADAR_INDICATOR]
Type=1
Class=CPropPage5Radar
ControlCount=9
Control1=IDC_COMBO_INDICATORTYPE,combobox,1344340226
Control2=IDC_EDIT_SIGMAREF,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_SIGMAREF2,edit,1350631552

[CLS:CPropPage6Radar]
Type=0
HeaderFile=proppageradar.h
ImplementationFile=proppageradar.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPropPage6Radar
VirtualFilter=idWC

[DLG:IDD_PROP_RADAR_ECCM (English (U.S.))]
Type=1
Class=CPropPage6Radar
ControlCount=23
Control1=IDC_EDIT1,edit,1484849280
Control2=IDC_STATIC,static,1476526080
Control3=IDC_STATIC,static,1476526080
Control4=IDC_EDIT2,edit,1484849280
Control5=IDC_STATIC,static,1476526080
Control6=IDC_STATIC,static,1476526080
Control7=IDC_CHECK1,button,1476460547
Control8=IDC_STATIC,static,1476526080
Control9=IDC_STATIC,static,1476526080
Control10=IDC_CHECK3,button,1476460547
Control11=IDC_STATIC,static,1476526080
Control12=IDC_CHECK4,button,1476460547
Control13=IDC_STATIC,static,1476526080
Control14=IDC_CHECK5,button,1476460547
Control15=IDC_STATIC,static,1476526080
Control16=IDC_CHECK6,button,1476460547
Control17=IDC_STATIC,static,1476526080
Control18=IDC_CHECK7,button,1476460547
Control19=IDC_EDIT3,edit,1484849280
Control20=IDC_STATIC,static,1476526080
Control21=IDC_STATIC,static,1476526080
Control22=IDC_CHECK8,button,1476460547
Control23=IDC_STATIC,button,1476395015

[DLG:IDD_PROP_RADAR_RXSIGNALPROCESSING]
Type=1
Class=CPropPage3Radar
ControlCount=38
Control1=IDC_EDIT_IFBANDWIDTH,edit,1350568064
Control2=IDC_EDIT_NOISEFIGURE,edit,1350631552
Control3=IDC_EDIT_LOSSES,edit,1350631552
Control4=IDC_EDIT_JSRATIO,edit,1350631552
Control5=IDC_CHECK_COHERENTINTEGRATION,button,1476460547
Control6=IDC_EDIT_PULSECOMPRATIO,edit,1484849280
Control7=IDC_EDIT_SNRMIN,edit,1350631552
Control8=IDC_EDIT_PROCESSINGGAIN,edit,1350568064
Control9=IDC_CHECK2,button,1476395011
Control10=IDC_EDIT12,edit,1484783744
Control11=IDC_EDIT13,edit,1484783744
Control12=IDC_EDIT14,edit,1484783744
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,button,1476395015
Control25=IDC_STATIC,static,1476526080
Control26=IDC_STATIC,static,1476526080
Control27=IDC_STATIC,static,1476526080
Control28=IDC_STATIC,static,1476526080
Control29=IDC_STATIC,button,1342177287
Control30=IDC_STATIC,button,1342177287
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_EDIT1,edit,1484849280
Control38=IDC_EDIT2,edit,1484849280

[DLG:IDD_PROP_RADAR_RXSIGNALPROCESSING2 (English (U.S.))]
Type=1
Class=CPropPage7Radar
ControlCount=22
Control1=IDC_CHECK_MTI,button,1476460547
Control2=IDC_EDIT_LOWERVELOCITYLIMIT,edit,1350631552
Control3=IDC_EDIT_ATTENUATION,edit,1350631552
Control4=IDC_STATIC,button,1476395015
Control5=IDC_EDIT1,edit,1484849280
Control6=IDC_STATIC,static,1476526080
Control7=IDC_EDIT2,edit,1484849280
Control8=IDC_STATIC,static,1476526080
Control9=IDC_EDIT3,edit,1484849280
Control10=IDC_STATIC,static,1476526080
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1476526080
Control18=IDC_STATIC,static,1476526080
Control19=IDC_STATIC,static,1476526080
Control20=IDC_STATIC,static,1342308352
Control21=IDC_SPIN1,msctls_updown32,1342177312
Control22=IDC_EDIT5,edit,1484849280

[CLS:CPropPage7Radar]
Type=0
HeaderFile=proppageradar.h
ImplementationFile=proppageradar.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=IDC_CHECK_MTI
VirtualFilter=idWC

[DLG:IDD_DLG_KALIBRERA]
Type=1
Class=CDialogKalibreraRadar
ControlCount=29
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_EDIT_ANTENNAGAIN,edit,1350631552
Control3=IDC_EDIT_LOSSES,edit,1350631552
Control4=IDC_EDIT_PROCESSINGGAIN,edit,1350631552
Control5=IDC_BUTTON_CALCMAXRANGE,button,1342242816
Control6=IDC_EDIT_MAXRANGE,edit,1350568064
Control7=IDC_EDIT_SENSITIVITY,edit,1350568064
Control8=IDOK,button,1342242817
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_SPIN_LOSSES,msctls_updown32,1342177312
Control16=IDC_SPIN_PROCESSINGGAIN,msctls_updown32,1342177312
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_SPIN_ANTENNAGAIN,msctls_updown32,1342177312
Control21=IDC_SPIN_PEAKPOWER,msctls_updown32,1342177330
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_EDIT_ANTENNAGAIN2,edit,1350631552
Control28=IDC_SPIN_ANTENNAGAIN2,msctls_updown32,1342177312
Control29=IDC_STATIC,static,1342308352

[CLS:CDialogKalibreraRadar]
Type=0
HeaderFile=DialogKalibreraRadar.h
ImplementationFile=DialogKalibreraRadar.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogKalibreraRadar
VirtualFilter=dWC

[DLG:IDD_PROP_JAMMER_JAMODE1]
Type=1
Class=CPropPage4Jammer
ControlCount=31
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_COMBO_JAMMODE,combobox,1344340226
Control3=IDC_COMBO_MODE,combobox,1344340226
Control4=IDC_EDIT_CENTERFREQ,edit,1350631552
Control5=IDC_EDIT_BANDWIDTH_BARRAGE,edit,1350631552
Control6=IDC_EDIT_SETONDELAY,edit,1350762624
Control7=IDC_EDIT_BANDWIDTH_TRACKING,edit,1350631552
Control8=IDC_COMBO_TYPE,combobox,1344340226
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_CHECK_INVERSEGAIN,button,1342242819
Control23=IDC_CHECK_CONSTANTPOWER,button,1342242819
Control24=IDC_CHECK_CONSTANTGAIN,button,1342242819
Control25=IDC_EDIT_LOOPGAIN,edit,1350631552
Control26=IDC_EDIT_DYNAMICRANGE,edit,1350631552
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,button,1342177287

[CLS:CSplashWnd]
Type=0
HeaderFile=Splash.h
ImplementationFile=Splash.cpp
BaseClass=CWnd
LastObject=CSplashWnd

[CLS:CYellowEdit]
Type=0
HeaderFile=YellowEdit.h
ImplementationFile=YellowEdit.cpp
BaseClass=CEdit
Filter=W
LastObject=CYellowEdit
VirtualFilter=WC

[CLS:CColorSlider]
Type=0
HeaderFile=ColorSlider.h
ImplementationFile=ColorSlider.cpp
BaseClass=CSliderCtrl
Filter=W
VirtualFilter=KWC
LastObject=CColorSlider

[DLG:IDD_DIALOG_CHOISE]
Type=1
Class=CDialogChoise
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_CHOISE,static,1342308353
Control4=IDC_STATIC,static,1342177283

[CLS:CDialogChoise]
Type=0
HeaderFile=DialogChoise.h
ImplementationFile=DialogChoise.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogChoise
VirtualFilter=dWC

[DLG:IDD_PROP_JAMMER_JAMODE2]
Type=1
Class=CPropPage5Jammer
ControlCount=23
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_COMBO_JAMMODE,combobox,1344340226
Control3=IDC_COMBO_PATTERN,combobox,1344340226
Control4=IDC_EDIT_REPEATED_PULSEWIDTH,edit,1484849280
Control5=IDC_EDIT_REPEATERDELAY,edit,1350566016
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CHECK_INVERSEGAIN,button,1342242819
Control15=IDC_CHECK_CONSTANTPOWER2,button,1342242819
Control16=IDC_CHECK_CONSTANTGAIN2,button,1342242819
Control17=IDC_EDIT_LOOPGAIN,edit,1350631552
Control18=IDC_EDIT_DYNAMICRANGE2,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,button,1342177287

[CLS:CDialogDiagram]
Type=0
HeaderFile=DialogDiagram.h
ImplementationFile=DialogDiagram.cpp
BaseClass=CDialog
Filter=D
LastObject=CDialogDiagram
VirtualFilter=dWC

[DLG:IDD_DIALOG_DIAGRAM]
Type=1
Class=CDlgOverViewOpenGL
ControlCount=0

[DLG:IDD_PROP_SYMBOL]
Type=1
Class=CPropPage2Target
ControlCount=1
Control1=IDC_STATIC_PREVIEW,button,1342178055

[DLG:IDD_DIALOG_RADARPPI]
Type=1
Class=CRadarPPI
ControlCount=0

[CLS:CRadarPPI]
Type=0
HeaderFile=RadarPPI.h
ImplementationFile=RadarPPI.cpp
BaseClass=CDialog
Filter=D
LastObject=CRadarPPI
VirtualFilter=dWC

[CLS:COpenGL]
Type=0
HeaderFile=OpenGL.h
ImplementationFile=OpenGL.cpp
BaseClass=CWnd
Filter=W
LastObject=COpenGL
VirtualFilter=WC

[CLS:CDlgOverViewOpenGL]
Type=0
HeaderFile=DlgOverViewOpenGL.h
ImplementationFile=DlgOverViewOpenGL.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgOverViewOpenGL

[CLS:CDlgRadarPPI]
Type=0
HeaderFile=dlgradarppi.h
ImplementationFile=dlgradarppi.cpp
BaseClass=CDialog
LastObject=CDlgRadarPPI
Filter=D
VirtualFilter=dWC

[CLS:CASSARApp]
Type=0
HeaderFile=assar.h
ImplementationFile=assar.cpp
BaseClass=CWinApp
LastObject=CASSARApp
Filter=N

[CLS:CAntennaDiagramForm]
Type=0
HeaderFile=AntennaDiagramForm.h
ImplementationFile=AntennaDiagramForm.cpp
BaseClass=CDialog
Filter=D
LastObject=CAntennaDiagramForm

[DLG:IDD_DIALOGOVERVIEW (Swedish)]
Type=1
Class=CDlgOverViewOpenGL
ControlCount=7
Control1=IDC_BUT_MOVE,button,1342242816
Control2=IDC_BUT_WAYPOINT,button,1342242816
Control3=IDC_BUT_DELETEWAYPOINT,button,1342242816
Control4=IDC_STATIC_TIME,static,1342308352
Control5=IDC_STATIC_COOR,static,1342308352
Control6=IDC_STATIC_DISTTORADAR,static,1342308352
Control7=IDC_CHECK_ALLWAYPOINTS,button,1342242819

[DLG:IDD_DIALOG_RADARPPI (Swedish)]
Type=1
Class=CRadarPPI
ControlCount=0

[DLG:IDD_DIALOG_PPI_PLOT]
Type=1
Class=CDlgRadarPPI
ControlCount=31
Control1=IDC_BUTTON1,button,1342242880
Control2=IDC_BUTTON_JAMMODE1,button,1342242816
Control3=IDC_BUTTON_JAMMODE2,button,1342242816
Control4=IDC_BUTTON_JAMMODE3,button,1476460544
Control5=IDC_BUT_FFW,button,1342242816
Control6=IDC_TIMELINE,msctls_trackbar32,1342242836
Control7=IDC_BUTTON_JAMMODE4,button,1476460544
Control8=IDC_BUT_REW,button,1342242816
Control9=IDC_BUTTON_PAUS,button,1342242880
Control10=IDC_EDIT_JAM1,edit,1342244997
Control11=IDC_EDIT_JAM2,edit,1342244997
Control12=IDC_EDIT_JAM5,edit,1342244997
Control13=IDC_EDIT_JAM6,edit,1342244997
Control14=IDC_EDIT_JAM4,edit,1342244997
Control15=IDC_EDIT_TIMELINE,edit,1342244993
Control16=IDC_BUTTON_OFF,button,1342242816
Control17=IDC_EDIT_JAM3,edit,1342244997
Control18=IDC_BUTTON_RESTORE,button,1342242816
Control19=IDC_STATIC_FRAME,static,1342181383
Control20=IDC_EDIT_RAD1,edit,1342244997
Control21=IDC_EDIT_RAD2,edit,1342244997
Control22=IDC_EDIT_RAD5,edit,1342244997
Control23=IDC_EDIT_RAD6,edit,1342244997
Control24=IDC_EDIT_RAD4,edit,1342244997
Control25=IDC_EDIT_RAD3,edit,1342244997
Control26=IDC_EDIT_RAD7,edit,1342244997
Control27=IDC_EDIT_RAD8,edit,1342244997
Control28=IDC_BUTTON_RADSYNTETIC,button,1342242816
Control29=IDC_BUTTON_RADRAWVIDEO,button,1342242816
Control30=IDC_BUT_SHOWDISK,button,1342245888
Control31=IDC_BUT_DEGREES,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_BUTTON_CREATE_RADAR
Command2=ID_BUTTON_CREATE_JAMMER
Command3=ID_BUTTON_CREATE_TARGET
Command4=ID_BUTTON_CLEARALL
Command5=ID_BUTTON_PPI
Command6=ID_BUTTON_STOP
Command7=ID_BUTTON32816
Command8=ID_BUTTON32817
Command9=ID_BUTTON32818
CommandCount=9

[MNU:IDR_MENU_RADAR (Swedish)]
Type=1
Class=?
Command1=ID_OPENRADAR
Command2=ID_SAVERADAR
Command3=ID_PROPERTIES_RADAR
Command4=ID_SHOW_PPI
Command5=ID_KALIBRERA_RADAR
Command6=ID_DELETE_RADAR
CommandCount=6

[MNU:IDR_MENU_JAMMER (Swedish)]
Type=1
Class=?
Command1=ID_OPENJAMMER
Command2=ID_SAVEJAMMER
Command3=ID_PROPERTIES_JAMMER
Command4=ID_DELETE_JAMMER
CommandCount=4

[MNU:IDR_MENU_TARGET (Swedish)]
Type=1
Class=?
Command1=ID_PROPERTIES_TARGET
Command2=ID_DELETE_TARGET
CommandCount=2

[MNU:IDR_MENU_RUN (Swedish)]
Type=1
Class=?
Command1=ID_MENU_STOP
Command2=ID_MENU_RUN
Command3=ID_MENU_PAUSE
Command4=ID_MENU_FASTER
Command5=ID_MENU_SLOWER
Command6=ID_MENUD_ZOOMIN
Command7=ID_MENUD_ZOOMOUT
Command8=ID_MENUD_FITTOSCREEN
Command9=ID_MENUD_RAWVIDEOMODE
Command10=ID_MENUD_SYNTETICMODE
Command11=ID_MENUD_RAWVIDEOSYNTETIC
CommandCount=11

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=6
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_STATIC,static,1342177294
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_ECCM]
Type=1
Class=CPropPage6Radar
ControlCount=23
Control1=IDC_EDIT1,edit,1484849280
Control2=IDC_STATIC,static,1476526080
Control3=IDC_STATIC,static,1476526080
Control4=IDC_EDIT2,edit,1484849280
Control5=IDC_STATIC,static,1476526080
Control6=IDC_STATIC,static,1476526080
Control7=IDC_CHECK1,button,1476460547
Control8=IDC_STATIC,static,1476526080
Control9=IDC_STATIC,static,1476526080
Control10=IDC_CHECK3,button,1476460547
Control11=IDC_STATIC,static,1476526080
Control12=IDC_CHECK4,button,1476460547
Control13=IDC_STATIC,static,1476526080
Control14=IDC_CHECK5,button,1476460547
Control15=IDC_STATIC,static,1476526080
Control16=IDC_CHECK6,button,1476460547
Control17=IDC_STATIC,static,1476526080
Control18=IDC_CHECK7,button,1476460547
Control19=IDC_EDIT3,edit,1484849280
Control20=IDC_STATIC,static,1476526080
Control21=IDC_STATIC,static,1476526080
Control22=IDC_CHECK8,button,1476460547
Control23=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_RADAR_RXSIGNALPROCESSING2]
Type=1
Class=CPropPage7Radar
ControlCount=16
Control1=IDC_CHECK_MTI,button,1342242819
Control2=IDC_EDIT_LOWERVELOCITYLIMIT,edit,1350631552
Control3=IDC_EDIT_ATTENUATION,edit,1350631552
Control4=IDC_STATIC,button,1476395015
Control5=IDC_EDIT1,edit,1484849280
Control6=IDC_STATIC,static,1476526080
Control7=IDC_EDIT2,edit,1484849280
Control8=IDC_STATIC,static,1476526080
Control9=IDC_EDIT3,edit,1484849280
Control10=IDC_STATIC,static,1476526080
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_IDENTITY (Swedish)]
Type=1
Class=CPropPage1Radar
ControlCount=5
Control1=IDC_EDIT_NAME,edit,1350631552
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_TX (Swedish)]
Type=1
Class=CPropPage2Radar
ControlCount=36
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_EDIT_PULSEWIDTH,edit,1350631552
Control3=IDC_CHECK_PULSEGROUP,button,1342242819
Control4=IDC_CHECK_FIXFREQ,button,1342242819
Control5=IDC_EDIT_NBROFPULSES,edit,1350631552
Control6=IDC_EDIT_CHANNELSEPARATION,edit,1350631552
Control7=IDC_EDIT_MINFREQ,edit,1350631552
Control8=IDC_EDIT_MAXFREQ,edit,1350631552
Control9=IDC_COMBO_PRITYPE,combobox,1344340226
Control10=IDC_EDIT_PRI,edit,1350631552
Control11=IDC_EDIT_PRF,edit,1350631552
Control12=IDC_EDIT_PULSEGROUPNBROFPULSES,edit,1484783744
Control13=IDC_EDIT_PRIDEVIATION,edit,1484783744
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,button,1342177287
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,button,1342177287
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_RXSIGNALPROCESSING (Swedish)]
Type=1
Class=CPropPage3Radar
ControlCount=34
Control1=IDC_EDIT_IFBANDWIDTH,edit,1350568064
Control2=IDC_EDIT_NOISEFIGURE,edit,1350631552
Control3=IDC_EDIT_LOSSES,edit,1350631552
Control4=IDC_EDIT_JSRATIO,edit,1350631552
Control5=IDC_CHECK_COHERENTINTEGRATION,button,1342242819
Control6=IDC_EDIT_PULSECOMPRATIO,edit,1350631552
Control7=IDC_EDIT_SNRMIN,edit,1350631552
Control8=IDC_EDIT_PROCESSINGGAIN,edit,1350568064
Control9=IDC_CHECK2,button,1476395011
Control10=IDC_EDIT12,edit,1484783744
Control11=IDC_EDIT13,edit,1484783744
Control12=IDC_EDIT14,edit,1484783744
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,button,1476395015
Control25=IDC_STATIC,static,1476526080
Control26=IDC_STATIC,static,1476526080
Control27=IDC_STATIC,static,1476526080
Control28=IDC_STATIC,static,1476526080
Control29=IDC_STATIC,button,1342177287
Control30=IDC_STATIC,button,1342177287
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_RADAR_ANTENNA (Swedish)]
Type=1
Class=CPropPage4Radar
ControlCount=41
Control1=IDC_EDIT_SCANPERIOD,edit,1350631552
Control2=IDC_EDIT_SIDELOBESUPRESSION,edit,1350631552
Control3=IDC_EDIT_WIDTHMAINLOBE,edit,1350631552
Control4=IDC_EDIT_GAINMAINLOBE,edit,1350631552
Control5=IDC_EDIT_SPILLOVERLOBESUPRESSION,edit,1350631552
Control6=IDC_EDIT_WIDTHSPILLOVERLOBE,edit,1350631552
Control7=IDC_EDIT_OFFSETSPILLOVERLOBE,edit,1350631552
Control8=IDC_EDIT_BACKLOBESUPRESSION,edit,1350631552
Control9=IDC_EDIT_WIDTHBACKLOBE,edit,1350631552
Control10=IDC_COMBO_POLARIZATION,combobox,1344340226
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_EDIT_SIDELOBESUPRESSION3,edit,1350631552
Control23=IDC_EDIT_WIDTHMAINLOBE2,edit,1350631552
Control24=IDC_EDIT_GAINMAINLOBE2,edit,1350631552
Control25=IDC_EDIT_SPILLOVERLOBESUPRESSION2,edit,1350631552
Control26=IDC_EDIT_WIDTHSPILLOVERLOBE2,edit,1350631552
Control27=IDC_EDIT_OFFSETSPILLOVERLOBE2,edit,1350631552
Control28=IDC_EDIT_BACKLOBESUPRESSION2,edit,1350631552
Control29=IDC_EDIT_WIDTHBACKLOBE2,edit,1350631552
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC,static,1342308352
Control37=IDC_STATIC,static,1342308352
Control38=IDC_STATIC,static,1342308352
Control39=IDC_STATIC,static,1342308352
Control40=IDC_STATIC,static,1342308352
Control41=IDC_LOOKUP_BUTTON,button,1342242816

[DLG:IDD_PROP_RADAR_INDICATOR (Swedish)]
Type=1
Class=CPropPage5Radar
ControlCount=10
Control1=IDC_COMBO_INDICATORTYPE,combobox,1344340226
Control2=IDC_CHECK_DEFLECTION,button,1342242819
Control3=IDC_EDIT_SIGMAREF,edit,1350631552
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_SIGMAREF2,edit,1350631552

[DLG:IDD_PROP_JAMMER_IDENTITY (Swedish)]
Type=1
Class=CPropPage1Jammer
ControlCount=23
Control1=IDC_EDIT_JAMMERNAME,edit,1350631552
Control2=IDC_COMBO_COLOR,combobox,1344340226
Control3=IDC_EDIT_DISTANCETORADAR,edit,1350631552
Control4=IDC_EDIT_BEARING,edit,1350631552
Control5=IDC_EDIT_VELOCITY,edit,1350631552
Control6=IDC_EDIT_VELOCITY_KMH,edit,1350631552
Control7=IDC_EDIT_VELOCITY_KNOP,edit,1350631552
Control8=IDC_EDIT_SIGMA,edit,1350631552
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,button,1342177287
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_JAMMER_RXTX (Swedish)]
Type=1
Class=CPropPage2Jammer
ControlCount=17
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EDIT_FREQMIN,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_FREQMAX,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,button,1342177287
Control9=IDC_EDIT_SENSITIVITY,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT_FREQMIN2,edit,1484849280
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_FREQMAX2,edit,1484849280
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_JAMMER_ANTENNA (Swedish)]
Type=1
Class=CPropPage3Jammer
ControlCount=23
Control1=IDC_COMBO_ANTENNATYPE,combobox,1344340226
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,button,1342177287
Control5=IDC_COMBO_POLARIZATION,combobox,1344340226
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_SIDELOBESUPRESSION,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT_ANTENNAGAINTX,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_BEAMWIDTHTX,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_ANTENNAGAINRX,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_BEAMWIDTHRX,edit,1350631552
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,button,1342177287
Control23=IDC_STATIC,button,1342177287

[DLG:IDD_PROP_JAMMER_JAMODE1 (Swedish)]
Type=1
Class=CPropPage4Jammer
ControlCount=31
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_COMBO_JAMMODE,combobox,1344340226
Control3=IDC_COMBO_MODE,combobox,1344340226
Control4=IDC_EDIT_CENTERFREQ,edit,1350631552
Control5=IDC_EDIT_BANDWIDTH_BARRAGE,edit,1350631552
Control6=IDC_EDIT_SETONDELAY,edit,1484980352
Control7=IDC_EDIT_BANDWIDTH_TRACKING,edit,1350631552
Control8=IDC_COMBO_TYPE,combobox,1344340226
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC_NOISE,button,1342308359
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_CHECK_INVERSEGAIN,button,1342242819
Control24=IDC_CHECK_CONSTANTPOWER,button,1342242819
Control25=IDC_CHECK_CONSTANTGAIN,button,1342242819
Control26=IDC_EDIT_LOOPGAIN,edit,1350631552
Control27=IDC_EDIT_DYNAMICRANGE,edit,1350631552
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_JAMMER_JAMODE2 (Swedish)]
Type=1
Class=CPropPage5Jammer
ControlCount=22
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_COMBO_JAMMODE,combobox,1344340226
Control3=IDC_COMBO_PATTERN,combobox,1344340226
Control4=IDC_EDIT_REPEATED_PULSEWIDTH,edit,1350631552
Control5=IDC_EDIT_REPEATERDELAY,edit,1484783744
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_CHECK_INVERSEGAIN,button,1342242819
Control15=IDC_CHECK_CONSTANTPOWER2,button,1342242819
Control16=IDC_CHECK_CONSTANTGAIN2,button,1342242819
Control17=IDC_EDIT_LOOPGAIN,edit,1350631552
Control18=IDC_EDIT_DYNAMICRANGE2,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_TARGET_IDENTITY (Swedish)]
Type=1
Class=CPropPage1Target
ControlCount=22
Control1=IDC_EDIT_TARGETNAME,edit,1350631552
Control2=IDC_COMBO_COLOR,combobox,1344340226
Control3=IDC_EDIT_DISTANCETORADAR,edit,1350631552
Control4=IDC_EDIT_BEARING,edit,1350631552
Control5=IDC_EDIT_COURSE,edit,1350631552
Control6=IDC_EDIT_VELOCITY,edit,1350631552
Control7=IDC_EDIT_SIGMA,edit,1350631552
Control8=IDC_STATIC,button,1342177287
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352

[DLG:IDD_PROP_SYMBOL (Swedish)]
Type=1
Class=CPropPage2Target
ControlCount=1
Control1=IDC_STATIC_PREVIEW,button,1342178055

[DLG:IDD_DLG_KALIBRERA (Swedish)]
Type=1
Class=CDialogKalibreraRadar
ControlCount=29
Control1=IDC_EDIT_PEAKPOWER,edit,1350631552
Control2=IDC_EDIT_ANTENNAGAIN,edit,1350631552
Control3=IDC_EDIT_LOSSES,edit,1350631552
Control4=IDC_EDIT_PROCESSINGGAIN,edit,1350631552
Control5=IDC_BUTTON_CALCMAXRANGE,button,1342242816
Control6=IDC_EDIT_MAXRANGE,edit,1350568064
Control7=IDC_EDIT_SENSITIVITY,edit,1350568064
Control8=IDOK,button,1342242817
Control9=IDC_STATIC,button,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_SPIN_LOSSES,msctls_updown32,1342177312
Control16=IDC_SPIN_PROCESSINGGAIN,msctls_updown32,1342177312
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_SPIN_ANTENNAGAIN,msctls_updown32,1342177312
Control21=IDC_SPIN_PEAKPOWER,msctls_updown32,1342177330
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_EDIT_ANTENNAGAIN2,edit,1350631552
Control28=IDC_SPIN_ANTENNAGAIN2,msctls_updown32,1342177312
Control29=IDC_STATIC,static,1342308352

[DLG:IDD_DIALOG_CHOISE (Swedish)]
Type=1
Class=CDialogChoise
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_CHOISE,static,1342308353
Control4=IDC_STATIC,static,1342177283

[DLG:IDD_DIALOG_DIAGRAM (Swedish)]
Type=1
Class=CDlgOverViewOpenGL
ControlCount=0

[DLG:IDD_DIALOG1 (Swedish)]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_DIALOG_RANDOM]
Type=1
Class=CDlgRandomFalseTargets
ControlCount=31
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_PROPABILITY,edit,1484849280
Control4=IDC_EDIT_VELOCITY,edit,1484849280
Control5=IDC_EDIT_RADARFREQFORDOPPLER,edit,1484849280
Control6=IDC_EDIT_APPLIEDDOPPLER,edit,1484849280
Control7=IDC_EDIT_TIMEBETWEEN,edit,1484849280
Control8=IDC_EDIT_DISTANCEBETWEEN,edit,1484849280
Control9=IDC_EDIT_DUTYCYCLE,edit,1484849280
Control10=IDC_EDIT_CLOCKRATE,edit,1484849280
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_EDIT_PROPABILITY2,edit,1484849280
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352

[CLS:CDlgRandomFalseTargets]
Type=0
HeaderFile=DlgRandomFalseTargets.h
ImplementationFile=DlgRandomFalseTargets.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgRandomFalseTargets
VirtualFilter=dWC

[DLG:IDD_DIALOG_RANDOM (Swedish)]
Type=1
Class=?
ControlCount=31
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_PROPABILITY,edit,1350631552
Control4=IDC_EDIT_VELOCITY,edit,1350631552
Control5=IDC_EDIT_RADARFREQFORDOPPLER,edit,1350631552
Control6=IDC_EDIT_APPLIEDDOPPLER,edit,1350631552
Control7=IDC_EDIT_TIMEBETWEEN,edit,1350631552
Control8=IDC_EDIT_DISTANCEBETWEEN,edit,1350631552
Control9=IDC_EDIT_DUTYCYCLE,edit,1350631552
Control10=IDC_EDIT_CLOCKRATE,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=IDC_STATIC,static,1342308352
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_STATIC,static,1342308352
Control24=IDC_STATIC,static,1342308352
Control25=IDC_STATIC,static,1342308352
Control26=IDC_STATIC,static,1342308352
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_EDIT_PROPABILITY2,edit,1484849280
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352

[MNU:IDR_MENU_VIEW_RUN (English (U.S.))]
Type=1
Class=CDlgRadarPPI
Command1=ID_R_STOP
Command2=ID_R_PAUSE
Command3=ID_R_RESUME
Command4=ID_R_JAMMODE1
Command5=ID_R_JAMMODE2
Command6=ID_R_JAMMEROFF
Command7=ID_R_FULLSCEEN
CommandCount=7


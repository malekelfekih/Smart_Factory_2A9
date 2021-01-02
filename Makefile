#############################################################################
# Makefile for building: Atelier_Connexion
# Generated by qmake (3.1) (Qt 5.9.9)
# Project:  Atelier_Connexion.pro
# Template: app
# Command: C:\Qt\5.9.9\5.9.9\mingw53_32\bin\qmake.exe -o Makefile Atelier_Connexion.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = C:\Qt\5.9.9\5.9.9\mingw53_32\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = C:\Qt\5.9.9\5.9.9\mingw53_32\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = C:\Qt\5.9.9\5.9.9\mingw53_32\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: Atelier_Connexion.pro C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/win32-g++/qmake.conf C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_pre.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/qdevice.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/device_config.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/sanitize.conf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/gcc-base.conf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/g++-base.conf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/angle.conf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/qconfig.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_charts.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_charts_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_datavisualization.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_datavisualization_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_networkauth.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_networkauth_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_remoteobjects.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_repparser.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_repparser_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_script.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_script_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_texttospeech.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_texttospeech_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_functions.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_config.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/win32-g++/qmake.conf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_post.prf \
		.qmake.stash \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/toolchain.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/default_pre.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/default_pre.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/resolve_config.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds_post.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/default_post.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qml_debug.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/precompile_header.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/warn_on.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qt.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/resources.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/moc.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/opengl.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/uic.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qmake_use.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/file_copies.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/windows.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/testcase_targets.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/exceptions.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/yacc.prf \
		C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/lex.prf \
		Atelier_Connexion.pro \
		C:/Qt/5.9.9/5.9.9/mingw53_32/lib/qtmaind.prl \
		C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Charts.prl \
		C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Widgets.prl \
		C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Gui.prl \
		C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Sql.prl \
		C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5SerialPort.prl \
		C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Core.prl
	$(QMAKE) -o Makefile Atelier_Connexion.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_pre.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/qdevice.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/device_config.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/sanitize.conf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/gcc-base.conf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/g++-base.conf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/common/angle.conf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/qconfig.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_charts.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_charts_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_datavisualization.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_datavisualization_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_networkauth.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_networkauth_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_purchasing.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_purchasing_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_remoteobjects.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_remoteobjects_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_repparser.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_repparser_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_script.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_script_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scripttools.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scripttools_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_texttospeech.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_texttospeech_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_functions.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_config.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/win32-g++/qmake.conf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_post.prf:
.qmake.stash:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/toolchain.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/default_pre.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/default_pre.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/resolve_config.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds_post.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/default_post.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qml_debug.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/precompile_header.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/warn_on.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qt.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/resources.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/moc.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/opengl.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/uic.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/qmake_use.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/file_copies.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/windows.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/testcase_targets.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/exceptions.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/yacc.prf:
C:/Qt/5.9.9/5.9.9/mingw53_32/mkspecs/features/lex.prf:
Atelier_Connexion.pro:
C:/Qt/5.9.9/5.9.9/mingw53_32/lib/qtmaind.prl:
C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Charts.prl:
C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Widgets.prl:
C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Gui.prl:
C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Sql.prl:
C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5SerialPort.prl:
C:/Qt/5.9.9/5.9.9/mingw53_32/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile Atelier_Connexion.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile

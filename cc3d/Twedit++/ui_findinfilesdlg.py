# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'findinfiles.ui'
#
# Created: Thu Jan 20 13:28:38 2011
#      by: PyQt4 UI code generator 4.7.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

class Ui_FindInFiles(object):
    def setupUi(self, FindInFiles):
        FindInFiles.setObjectName("FindInFiles")
        FindInFiles.resize(452, 331)
        FindInFiles.setContextMenuPolicy(QtCore.Qt.DefaultContextMenu)
        FindInFiles.setToolTip("")
        FindInFiles.setWhatsThis("")
        self.horizontalLayout_7 = QtGui.QHBoxLayout(FindInFiles)
        self.horizontalLayout_7.setObjectName("horizontalLayout_7")
        self.tabWidget = QtGui.QTabWidget(FindInFiles)
        self.tabWidget.setObjectName("tabWidget")
        self.tab = QtGui.QWidget()
        self.tab.setObjectName("tab")
        self.horizontalLayout_12 = QtGui.QHBoxLayout(self.tab)
        self.horizontalLayout_12.setObjectName("horizontalLayout_12")
        self.verticalLayout_8 = QtGui.QVBoxLayout()
        self.verticalLayout_8.setObjectName("verticalLayout_8")
        self._2 = QtGui.QGridLayout()
        self._2.setMargin(0)
        self._2.setSpacing(6)
        self._2.setObjectName("_2")
        self.label_2 = QtGui.QLabel(self.tab)
        self.label_2.setObjectName("label_2")
        self._2.addWidget(self.label_2, 1, 0, 1, 1)
        self.label = QtGui.QLabel(self.tab)
        self.label.setObjectName("label")
        self._2.addWidget(self.label, 0, 0, 1, 1)
        self.replaceComboBox = QtGui.QComboBox(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.replaceComboBox.sizePolicy().hasHeightForWidth())
        self.replaceComboBox.setSizePolicy(sizePolicy)
        self.replaceComboBox.setMaximumSize(QtCore.QSize(200, 16777215))
        self.replaceComboBox.setSizeAdjustPolicy(QtGui.QComboBox.AdjustToContentsOnFirstShow)
        self.replaceComboBox.setObjectName("replaceComboBox")
        self._2.addWidget(self.replaceComboBox, 1, 1, 1, 1)
        self.findComboBox = QtGui.QComboBox(self.tab)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.findComboBox.sizePolicy().hasHeightForWidth())
        self.findComboBox.setSizePolicy(sizePolicy)
        self.findComboBox.setMaximumSize(QtCore.QSize(200, 16777215))
        self.findComboBox.setSizeAdjustPolicy(QtGui.QComboBox.AdjustToContentsOnFirstShow)
        self.findComboBox.setObjectName("findComboBox")
        self._2.addWidget(self.findComboBox, 0, 1, 1, 1)
        self.verticalLayout_8.addLayout(self._2)
        self._3 = QtGui.QHBoxLayout()
        self._3.setSpacing(6)
        self._3.setMargin(0)
        self._3.setObjectName("_3")
        self.wholeCheckBox = QtGui.QCheckBox(self.tab)
        self.wholeCheckBox.setChecked(False)
        self.wholeCheckBox.setObjectName("wholeCheckBox")
        self._3.addWidget(self.wholeCheckBox)
        self.caseCheckBox = QtGui.QCheckBox(self.tab)
        self.caseCheckBox.setObjectName("caseCheckBox")
        self._3.addWidget(self.caseCheckBox)
        self.verticalLayout_8.addLayout(self._3)
        self._4 = QtGui.QHBoxLayout()
        self._4.setSpacing(6)
        self._4.setMargin(0)
        self._4.setObjectName("_4")
        self.label_3 = QtGui.QLabel(self.tab)
        self.label_3.setObjectName("label_3")
        self._4.addWidget(self.label_3)
        self.syntaxComboBox = QtGui.QComboBox(self.tab)
        self.syntaxComboBox.setObjectName("syntaxComboBox")
        self.syntaxComboBox.addItem("")
        self.syntaxComboBox.addItem("")
        self._4.addWidget(self.syntaxComboBox)
        self.verticalLayout_8.addLayout(self._4)
        self.line = QtGui.QFrame(self.tab)
        self.line.setFrameShape(QtGui.QFrame.HLine)
        self.line.setFrameShadow(QtGui.QFrame.Sunken)
        self.line.setObjectName("line")
        self.verticalLayout_8.addWidget(self.line)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.transparencyGroupBox = QtGui.QGroupBox(self.tab)
        self.transparencyGroupBox.setCheckable(True)
        self.transparencyGroupBox.setObjectName("transparencyGroupBox")
        self.horizontalLayout_11 = QtGui.QHBoxLayout(self.transparencyGroupBox)
        self.horizontalLayout_11.setObjectName("horizontalLayout_11")
        self.verticalLayout_7 = QtGui.QVBoxLayout()
        self.verticalLayout_7.setObjectName("verticalLayout_7")
        self.transparencySlider = QtGui.QSlider(self.transparencyGroupBox)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.transparencySlider.sizePolicy().hasHeightForWidth())
        self.transparencySlider.setSizePolicy(sizePolicy)
        self.transparencySlider.setMaximum(100)
        self.transparencySlider.setSingleStep(1)
        self.transparencySlider.setProperty("value", 75)
        self.transparencySlider.setOrientation(QtCore.Qt.Horizontal)
        self.transparencySlider.setObjectName("transparencySlider")
        self.verticalLayout_7.addWidget(self.transparencySlider)
        self.onLosingFocusRButton = QtGui.QRadioButton(self.transparencyGroupBox)
        self.onLosingFocusRButton.setChecked(True)
        self.onLosingFocusRButton.setObjectName("onLosingFocusRButton")
        self.verticalLayout_7.addWidget(self.onLosingFocusRButton)
        self.alwaysRButton = QtGui.QRadioButton(self.transparencyGroupBox)
        self.alwaysRButton.setObjectName("alwaysRButton")
        self.verticalLayout_7.addWidget(self.alwaysRButton)
        self.horizontalLayout_11.addLayout(self.verticalLayout_7)
        self.horizontalLayout.addWidget(self.transparencyGroupBox)
        spacerItem = QtGui.QSpacerItem(40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem)
        self.verticalLayout_8.addLayout(self.horizontalLayout)
        spacerItem1 = QtGui.QSpacerItem(20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_8.addItem(spacerItem1)
        self.horizontalLayout_12.addLayout(self.verticalLayout_8)
        self.line_2 = QtGui.QFrame(self.tab)
        self.line_2.setFrameShape(QtGui.QFrame.VLine)
        self.line_2.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_2.setObjectName("line_2")
        self.horizontalLayout_12.addWidget(self.line_2)
        self._5 = QtGui.QVBoxLayout()
        self._5.setSpacing(6)
        self._5.setMargin(0)
        self._5.setObjectName("_5")
        self.findNextButton = QtGui.QPushButton(self.tab)
        self.findNextButton.setObjectName("findNextButton")
        self._5.addWidget(self.findNextButton)
        self.line_5 = QtGui.QFrame(self.tab)
        self.line_5.setFrameShape(QtGui.QFrame.HLine)
        self.line_5.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_5.setObjectName("line_5")
        self._5.addWidget(self.line_5)
        self.findAllInCurrentDocButton = QtGui.QPushButton(self.tab)
        self.findAllInCurrentDocButton.setObjectName("findAllInCurrentDocButton")
        self._5.addWidget(self.findAllInCurrentDocButton)
        self.findAllInOpenDocsButton = QtGui.QPushButton(self.tab)
        self.findAllInOpenDocsButton.setObjectName("findAllInOpenDocsButton")
        self._5.addWidget(self.findAllInOpenDocsButton)
        self.line_4 = QtGui.QFrame(self.tab)
        self.line_4.setFrameShape(QtGui.QFrame.HLine)
        self.line_4.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_4.setObjectName("line_4")
        self._5.addWidget(self.line_4)
        self.replaceButton = QtGui.QPushButton(self.tab)
        self.replaceButton.setObjectName("replaceButton")
        self._5.addWidget(self.replaceButton)
        self.replaceAllButton = QtGui.QPushButton(self.tab)
        self.replaceAllButton.setObjectName("replaceAllButton")
        self._5.addWidget(self.replaceAllButton)
        self.inSelectionBox = QtGui.QCheckBox(self.tab)
        self.inSelectionBox.setObjectName("inSelectionBox")
        self._5.addWidget(self.inSelectionBox)
        self.replaceAllInOpenDocsButton = QtGui.QPushButton(self.tab)
        self.replaceAllInOpenDocsButton.setObjectName("replaceAllInOpenDocsButton")
        self._5.addWidget(self.replaceAllInOpenDocsButton)
        self.line_6 = QtGui.QFrame(self.tab)
        self.line_6.setFrameShape(QtGui.QFrame.HLine)
        self.line_6.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_6.setObjectName("line_6")
        self._5.addWidget(self.line_6)
        spacerItem2 = QtGui.QSpacerItem(20, 16, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self._5.addItem(spacerItem2)
        self.closeButton = QtGui.QPushButton(self.tab)
        self.closeButton.setObjectName("closeButton")
        self._5.addWidget(self.closeButton)
        self.horizontalLayout_12.addLayout(self._5)
        self.tabWidget.addTab(self.tab, "")
        self.tab_2 = QtGui.QWidget()
        self.tab_2.setObjectName("tab_2")
        self.horizontalLayout_4 = QtGui.QHBoxLayout(self.tab_2)
        self.horizontalLayout_4.setObjectName("horizontalLayout_4")
        self.verticalLayout = QtGui.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        self.gridLayout = QtGui.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.label_4 = QtGui.QLabel(self.tab_2)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 0, 0, 1, 1)
        self.findComboBoxIF = QtGui.QComboBox(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.findComboBoxIF.sizePolicy().hasHeightForWidth())
        self.findComboBoxIF.setSizePolicy(sizePolicy)
        self.findComboBoxIF.setMaximumSize(QtCore.QSize(200, 16777215))
        self.findComboBoxIF.setObjectName("findComboBoxIF")
        self.gridLayout.addWidget(self.findComboBoxIF, 0, 1, 1, 1)
        self.label_5 = QtGui.QLabel(self.tab_2)
        self.label_5.setObjectName("label_5")
        self.gridLayout.addWidget(self.label_5, 1, 0, 1, 1)
        self.replaceComboBoxIF = QtGui.QComboBox(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.replaceComboBoxIF.sizePolicy().hasHeightForWidth())
        self.replaceComboBoxIF.setSizePolicy(sizePolicy)
        self.replaceComboBoxIF.setMaximumSize(QtCore.QSize(200, 16777215))
        self.replaceComboBoxIF.setObjectName("replaceComboBoxIF")
        self.gridLayout.addWidget(self.replaceComboBoxIF, 1, 1, 1, 1)
        self.label_6 = QtGui.QLabel(self.tab_2)
        self.label_6.setObjectName("label_6")
        self.gridLayout.addWidget(self.label_6, 2, 0, 1, 1)
        self.filtersComboBoxIF = QtGui.QComboBox(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.filtersComboBoxIF.sizePolicy().hasHeightForWidth())
        self.filtersComboBoxIF.setSizePolicy(sizePolicy)
        self.filtersComboBoxIF.setMaximumSize(QtCore.QSize(200, 16777215))
        self.filtersComboBoxIF.setObjectName("filtersComboBoxIF")
        self.gridLayout.addWidget(self.filtersComboBoxIF, 2, 1, 1, 1)
        self.label_7 = QtGui.QLabel(self.tab_2)
        self.label_7.setObjectName("label_7")
        self.gridLayout.addWidget(self.label_7, 3, 0, 1, 1)
        self.directoryComboBoxIF = QtGui.QComboBox(self.tab_2)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.directoryComboBoxIF.sizePolicy().hasHeightForWidth())
        self.directoryComboBoxIF.setSizePolicy(sizePolicy)
        self.directoryComboBoxIF.setMaximumSize(QtCore.QSize(200, 16777215))
        self.directoryComboBoxIF.setObjectName("directoryComboBoxIF")
        self.gridLayout.addWidget(self.directoryComboBoxIF, 3, 1, 1, 1)
        self.pickDirectoryButtonIF = QtGui.QPushButton(self.tab_2)
        self.pickDirectoryButtonIF.setObjectName("pickDirectoryButtonIF")
        self.gridLayout.addWidget(self.pickDirectoryButtonIF, 3, 2, 1, 1)
        self.verticalLayout.addLayout(self.gridLayout)
        self.gridLayout_2 = QtGui.QGridLayout()
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.wholeCheckBoxIF = QtGui.QCheckBox(self.tab_2)
        self.wholeCheckBoxIF.setEnabled(True)
        self.wholeCheckBoxIF.setChecked(False)
        self.wholeCheckBoxIF.setObjectName("wholeCheckBoxIF")
        self.gridLayout_2.addWidget(self.wholeCheckBoxIF, 0, 0, 1, 1)
        self.caseCheckBoxIF = QtGui.QCheckBox(self.tab_2)
        self.caseCheckBoxIF.setObjectName("caseCheckBoxIF")
        self.gridLayout_2.addWidget(self.caseCheckBoxIF, 0, 1, 1, 1)
        self.verticalLayout.addLayout(self.gridLayout_2)
        self.horizontalLayout_3 = QtGui.QHBoxLayout()
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.label_8 = QtGui.QLabel(self.tab_2)
        self.label_8.setObjectName("label_8")
        self.horizontalLayout_3.addWidget(self.label_8)
        self.syntaxComboBoxIF = QtGui.QComboBox(self.tab_2)
        self.syntaxComboBoxIF.setObjectName("syntaxComboBoxIF")
        self.syntaxComboBoxIF.addItem("")
        self.syntaxComboBoxIF.addItem("")
        self.horizontalLayout_3.addWidget(self.syntaxComboBoxIF)
        self.verticalLayout.addLayout(self.horizontalLayout_3)
        spacerItem3 = QtGui.QSpacerItem(20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout.addItem(spacerItem3)
        self.horizontalLayout_4.addLayout(self.verticalLayout)
        self.line_3 = QtGui.QFrame(self.tab_2)
        self.line_3.setFrameShape(QtGui.QFrame.VLine)
        self.line_3.setFrameShadow(QtGui.QFrame.Sunken)
        self.line_3.setObjectName("line_3")
        self.horizontalLayout_4.addWidget(self.line_3)
        self.verticalLayout_2 = QtGui.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.findAllButtonIF = QtGui.QPushButton(self.tab_2)
        self.findAllButtonIF.setObjectName("findAllButtonIF")
        self.verticalLayout_2.addWidget(self.findAllButtonIF)
        self.replaceButtonIF = QtGui.QPushButton(self.tab_2)
        self.replaceButtonIF.setObjectName("replaceButtonIF")
        self.verticalLayout_2.addWidget(self.replaceButtonIF)
        self.inAllSubFoldersCheckBoxIF = QtGui.QCheckBox(self.tab_2)
        self.inAllSubFoldersCheckBoxIF.setEnabled(True)
        self.inAllSubFoldersCheckBoxIF.setChecked(False)
        self.inAllSubFoldersCheckBoxIF.setObjectName("inAllSubFoldersCheckBoxIF")
        self.verticalLayout_2.addWidget(self.inAllSubFoldersCheckBoxIF)
        spacerItem4 = QtGui.QSpacerItem(20, 18, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_2.addItem(spacerItem4)
        self.closeButtonIF = QtGui.QPushButton(self.tab_2)
        self.closeButtonIF.setObjectName("closeButtonIF")
        self.verticalLayout_2.addWidget(self.closeButtonIF)
        self.horizontalLayout_4.addLayout(self.verticalLayout_2)
        self.tabWidget.addTab(self.tab_2, "")
        self.tab_3 = QtGui.QWidget()
        self.tab_3.setObjectName("tab_3")
        self.gridLayout_3 = QtGui.QGridLayout(self.tab_3)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.groupBox = QtGui.QGroupBox(self.tab_3)
        self.groupBox.setObjectName("groupBox")
        self.verticalLayout_4 = QtGui.QVBoxLayout(self.groupBox)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.verticalLayout_3 = QtGui.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.findCPB = QtGui.QPushButton(self.groupBox)
        self.findCPB.setObjectName("findCPB")
        self.verticalLayout_3.addWidget(self.findCPB)
        self.replaceCPB = QtGui.QPushButton(self.groupBox)
        self.replaceCPB.setObjectName("replaceCPB")
        self.verticalLayout_3.addWidget(self.replaceCPB)
        self.filtersCPB = QtGui.QPushButton(self.groupBox)
        self.filtersCPB.setObjectName("filtersCPB")
        self.verticalLayout_3.addWidget(self.filtersCPB)
        self.directoryCPB = QtGui.QPushButton(self.groupBox)
        self.directoryCPB.setObjectName("directoryCPB")
        self.verticalLayout_3.addWidget(self.directoryCPB)
        self.verticalLayout_4.addLayout(self.verticalLayout_3)
        self.gridLayout_3.addWidget(self.groupBox, 0, 0, 1, 1)
        spacerItem5 = QtGui.QSpacerItem(199, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.gridLayout_3.addItem(spacerItem5, 0, 1, 1, 1)
        spacerItem6 = QtGui.QSpacerItem(20, 90, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.gridLayout_3.addItem(spacerItem6, 1, 0, 1, 1)
        self.tabWidget.addTab(self.tab_3, "")
        self.horizontalLayout_7.addWidget(self.tabWidget)
        self.label_2.setBuddy(self.replaceComboBox)
        self.label.setBuddy(self.findComboBox)
        self.label_3.setBuddy(self.syntaxComboBox)
        self.label_4.setBuddy(self.findComboBox)
        self.label_5.setBuddy(self.replaceComboBox)
        self.label_8.setBuddy(self.syntaxComboBox)

        self.retranslateUi(FindInFiles)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QObject.connect(self.closeButton, QtCore.SIGNAL("clicked()"), FindInFiles.close)
        QtCore.QObject.connect(self.closeButtonIF, QtCore.SIGNAL("clicked()"), FindInFiles.reject)
        QtCore.QMetaObject.connectSlotsByName(FindInFiles)
        FindInFiles.setTabOrder(self.findComboBox, self.replaceComboBox)
        FindInFiles.setTabOrder(self.replaceComboBox, self.wholeCheckBox)
        FindInFiles.setTabOrder(self.wholeCheckBox, self.syntaxComboBox)
        FindInFiles.setTabOrder(self.syntaxComboBox, self.findNextButton)
        FindInFiles.setTabOrder(self.findNextButton, self.replaceButton)
        FindInFiles.setTabOrder(self.replaceButton, self.replaceAllButton)
        FindInFiles.setTabOrder(self.replaceAllButton, self.closeButton)
        FindInFiles.setTabOrder(self.closeButton, self.findComboBoxIF)
        FindInFiles.setTabOrder(self.findComboBoxIF, self.replaceComboBoxIF)
        FindInFiles.setTabOrder(self.replaceComboBoxIF, self.filtersComboBoxIF)
        FindInFiles.setTabOrder(self.filtersComboBoxIF, self.caseCheckBox)
        FindInFiles.setTabOrder(self.caseCheckBox, self.directoryComboBoxIF)
        FindInFiles.setTabOrder(self.directoryComboBoxIF, self.pickDirectoryButtonIF)
        FindInFiles.setTabOrder(self.pickDirectoryButtonIF, self.wholeCheckBoxIF)
        FindInFiles.setTabOrder(self.wholeCheckBoxIF, self.caseCheckBoxIF)
        FindInFiles.setTabOrder(self.caseCheckBoxIF, self.syntaxComboBoxIF)
        FindInFiles.setTabOrder(self.syntaxComboBoxIF, self.findAllButtonIF)
        FindInFiles.setTabOrder(self.findAllButtonIF, self.replaceButtonIF)
        FindInFiles.setTabOrder(self.replaceButtonIF, self.inAllSubFoldersCheckBoxIF)
        FindInFiles.setTabOrder(self.inAllSubFoldersCheckBoxIF, self.closeButtonIF)

    def retranslateUi(self, FindInFiles):
        FindInFiles.setWindowTitle(QtGui.QApplication.translate("FindInFiles", "Find and Replace", None, QtGui.QApplication.UnicodeUTF8))
        self.label_2.setText(QtGui.QApplication.translate("FindInFiles", "Replace w&ith:", None, QtGui.QApplication.UnicodeUTF8))
        self.label.setText(QtGui.QApplication.translate("FindInFiles", "Find &what:", None, QtGui.QApplication.UnicodeUTF8))
        self.wholeCheckBox.setText(QtGui.QApplication.translate("FindInFiles", "Wh&ole words", None, QtGui.QApplication.UnicodeUTF8))
        self.caseCheckBox.setText(QtGui.QApplication.translate("FindInFiles", "&Case sensitive", None, QtGui.QApplication.UnicodeUTF8))
        self.label_3.setText(QtGui.QApplication.translate("FindInFiles", "&Syntax:", None, QtGui.QApplication.UnicodeUTF8))
        self.syntaxComboBox.setItemText(0, QtGui.QApplication.translate("FindInFiles", "Literal text", None, QtGui.QApplication.UnicodeUTF8))
        self.syntaxComboBox.setItemText(1, QtGui.QApplication.translate("FindInFiles", "Regular expression", None, QtGui.QApplication.UnicodeUTF8))
        self.transparencyGroupBox.setTitle(QtGui.QApplication.translate("FindInFiles", "Transparency", None, QtGui.QApplication.UnicodeUTF8))
        self.onLosingFocusRButton.setText(QtGui.QApplication.translate("FindInFiles", "On Losing Focus", None, QtGui.QApplication.UnicodeUTF8))
        self.alwaysRButton.setText(QtGui.QApplication.translate("FindInFiles", "Always", None, QtGui.QApplication.UnicodeUTF8))
        self.findNextButton.setText(QtGui.QApplication.translate("FindInFiles", "Find Next", None, QtGui.QApplication.UnicodeUTF8))
        self.findAllInCurrentDocButton.setText(QtGui.QApplication.translate("FindInFiles", "Find All in Current Doc", None, QtGui.QApplication.UnicodeUTF8))
        self.findAllInOpenDocsButton.setText(QtGui.QApplication.translate("FindInFiles", "Find All in Open Docs", None, QtGui.QApplication.UnicodeUTF8))
        self.replaceButton.setText(QtGui.QApplication.translate("FindInFiles", "&Replace", None, QtGui.QApplication.UnicodeUTF8))
        self.replaceAllButton.setText(QtGui.QApplication.translate("FindInFiles", "Replace &All", None, QtGui.QApplication.UnicodeUTF8))
        self.inSelectionBox.setText(QtGui.QApplication.translate("FindInFiles", "In Selection", None, QtGui.QApplication.UnicodeUTF8))
        self.replaceAllInOpenDocsButton.setText(QtGui.QApplication.translate("FindInFiles", "Replace All in Open Docs", None, QtGui.QApplication.UnicodeUTF8))
        self.closeButton.setText(QtGui.QApplication.translate("FindInFiles", "Close", None, QtGui.QApplication.UnicodeUTF8))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), QtGui.QApplication.translate("FindInFiles", "Find and Replace", None, QtGui.QApplication.UnicodeUTF8))
        self.label_4.setText(QtGui.QApplication.translate("FindInFiles", "Find &what:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_5.setText(QtGui.QApplication.translate("FindInFiles", "Replace w&ith:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_6.setText(QtGui.QApplication.translate("FindInFiles", "Filters:", None, QtGui.QApplication.UnicodeUTF8))
        self.label_7.setText(QtGui.QApplication.translate("FindInFiles", "Directory:", None, QtGui.QApplication.UnicodeUTF8))
        self.pickDirectoryButtonIF.setText(QtGui.QApplication.translate("FindInFiles", "...", None, QtGui.QApplication.UnicodeUTF8))
        self.wholeCheckBoxIF.setText(QtGui.QApplication.translate("FindInFiles", "Wh&ole words", None, QtGui.QApplication.UnicodeUTF8))
        self.caseCheckBoxIF.setText(QtGui.QApplication.translate("FindInFiles", "&Case sensitive", None, QtGui.QApplication.UnicodeUTF8))
        self.label_8.setText(QtGui.QApplication.translate("FindInFiles", "&Syntax:", None, QtGui.QApplication.UnicodeUTF8))
        self.syntaxComboBoxIF.setItemText(0, QtGui.QApplication.translate("FindInFiles", "Literal text", None, QtGui.QApplication.UnicodeUTF8))
        self.syntaxComboBoxIF.setItemText(1, QtGui.QApplication.translate("FindInFiles", "Regular expression", None, QtGui.QApplication.UnicodeUTF8))
        self.findAllButtonIF.setText(QtGui.QApplication.translate("FindInFiles", "Find All", None, QtGui.QApplication.UnicodeUTF8))
        self.replaceButtonIF.setText(QtGui.QApplication.translate("FindInFiles", "&Replace in Files", None, QtGui.QApplication.UnicodeUTF8))
        self.inAllSubFoldersCheckBoxIF.setText(QtGui.QApplication.translate("FindInFiles", "In all sub-folders", None, QtGui.QApplication.UnicodeUTF8))
        self.closeButtonIF.setText(QtGui.QApplication.translate("FindInFiles", "Close", None, QtGui.QApplication.UnicodeUTF8))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), QtGui.QApplication.translate("FindInFiles", "Find and Replace in Files", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate("FindInFiles", "Options", None, QtGui.QApplication.UnicodeUTF8))
        self.findCPB.setText(QtGui.QApplication.translate("FindInFiles", "Clear Find History", None, QtGui.QApplication.UnicodeUTF8))
        self.replaceCPB.setText(QtGui.QApplication.translate("FindInFiles", "Clear Replace History", None, QtGui.QApplication.UnicodeUTF8))
        self.filtersCPB.setText(QtGui.QApplication.translate("FindInFiles", "Clear Filters History", None, QtGui.QApplication.UnicodeUTF8))
        self.directoryCPB.setText(QtGui.QApplication.translate("FindInFiles", "Clear Directory History", None, QtGui.QApplication.UnicodeUTF8))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), QtGui.QApplication.translate("FindInFiles", "Clear Data", None, QtGui.QApplication.UnicodeUTF8))


# import sys
# from PyQt5.QtWidgets import QApplication, QDesktopWidget, QMainWindow, QTextEdit, QPushButton,qApp, QMessageBox, QAction, QMenu,QToolTip
# from PyQt5.QtGui import QIcon, QFont
# from PyQt5.QtCore import QCoreApplication
#
# class Example(QMainWindow):
#     def __init__(self):
#         super().__init__()
#         self.initUI()
#
#     def initUI(self):
#         self.setGeometry(300, 300, 300, 220)  # 设置窗口的位置和大小
#         self.setWindowTitle('杂种')
#         self.statusBar().showMessage('Ready')  # 状态栏
#         self.setWindowIcon(QIcon('web.png'))
#
#         QToolTip.setFont(QFont('SansSerif', 10))  # 10px的SansSerif字体。
#         self.setToolTip('This is a <b>QWidget</b> widget')
#
#         # textEdit = QTextEdit()
#         # self.setCentralWidget(textEdit)
#
#         btn = QPushButton('Button', self)
#         btn.setToolTip('This is a <b>QPushButton</b> widget')  # 设置提示框
#         btn.resize(btn.sizeHint())  # sizeHint()方法提供了一个默认的按钮大小
#         btn.move(50, 50)  # 移动到x=50,y=50的位置
#
#         qbtn = QPushButton('Quit', self)
#         qbtn.clicked.connect(QCoreApplication.instance().quit)  # 点击按钮，调用QCoreApplication的quit()方法结束应用
#         qbtn.resize(qbtn.sizeHint())
#         qbtn.move(50, 70)
#
#         cbtn = QPushButton('closeevent', self)
#         cbtn.clicked.connect(self.closeEvent)  # 需要传递一个可调用对象
#         cbtn.resize(qbtn.sizeHint())
#         cbtn.move(50, 100)
#
#         exitAct = QAction(QIcon('exit.png'), '&Exit', self)
#         exitAct.setShortcut('Ctrl+Q')
#         exitAct.setStatusTip('Exit application')  # 鼠标悬停状态栏提示
#         exitAct.triggered.connect(QCoreApplication.instance().quit)
#
#         impMenu = QMenu('Import', self)  # 创建一个子菜单
#         impAct = QAction('Import mail', self)  # 创建一个动作
#         impMenu.addAction(impAct)  # 将动作添加到子菜单中
#
#         viewStatAct = QAction('View statusbar', self, checkable=True)
#         viewStatAct.setStatusTip('View statusbar')
#         viewStatAct.setChecked(True)
#         viewStatAct.triggered.connect(self.toggleMenu)
#
#         self.statusBar()
#         self.toolbar=self.addToolBar('Exit')
#         self.toolbar.addAction(exitAct)
#
#         menubar = self.menuBar()  # 创建菜单栏
#
#
#         fileMenu = menubar.addMenu('&File')  # 字幕快捷键？
#         viewMenu = menubar.addMenu('View')
#         viewMenu.addAction(viewStatAct)
#
#         fileMenu.addAction(exitAct)
#         fileMenu.addMenu(impMenu)  # 将子菜单添加到菜单栏中
#
#         self.resize(250, 150)
#
#         self.center()
#         self.show()
#
#     def toggleMenu(self, state):
#         if state:
#             self.statusBar().hide()
#         else:
#             self.statusBar().show()
#
#     def center(self):
#         qr = self.frameGeometry()
#         cp = QDesktopWidget().availableGeometry().center()
#         qr.moveCenter(cp)
#         self.move(qr.topLeft())
#
#     def closeEvent(self, event):
#         reply = QMessageBox.question(self, 'Message', "Are you sure to quit?", QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
#
#         if reply == QMessageBox.Yes:
#             event.accept()
#         else:
#             event.ignore()
#
#     def contextMenuEvent(self, event):
#         cmenu = QMenu(self)
#
#         newAct = cmenu.addAction("New")
#         opnAct = cmenu.addAction("Open")
#         quitAct = cmenu.addAction("Quit")
#         action = cmenu.exec_(self.mapToGlobal(event.pos()))
#
#         if action == quitAct:
#             qApp.quit()
#
# if __name__ == '__main__':
#     app = QApplication(sys.argv)
#     ex = Example()
#     sys.exit(app.exec_())

import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QLineEdit, \
    QPushButton, QSlider, QCheckBox
from PyQt5.QtGui import QPainter, QPen, QPixmap, QImage, QColor
from PyQt5.QtCore import Qt


class CustomWidget(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.initUI()

    def initUI(self):
        self.data = {}
        self.data['history'] = []

        self.input_top_label = QLabel("输入模块 - 号码和金额：", self)
        self.number_input = QLineEdit(self)
        self.number_input.setPlaceholderText("请输入号码（1-49）")
        self.amount_input = QLineEdit(self)
        self.amount_input.setPlaceholderText("请输入金额")
        self.add_button = QPushButton("添加", self)
        self.add_button.clicked.connect(self.on_add_button_clicked)

        self.input_bottom_label = QLabel("输入模块 - 自选金额斩杀线和推荐金额斩杀线：", self)
        self.k_input = QLineEdit(self)
        self.k_input.setPlaceholderText("请输入自选金额斩杀线（k）")
        self.recommended_k_label = QLabel("推荐金额斩杀线：", self)
        self.recommended_k_amount = QLabel("", self)

        self.history_label = QLabel("历史模块 - 操作历史：", self)
        self.history_display = QLabel("", self)

        self.display_label = QLabel("展示模块 - 柱状图：", self)
        self.slider_label = QLabel("显示超过自选金额的柱状图：", self)
        self.slider = QSlider(Qt.Horizontal, self)
        self.slider.setMaximum(100)
        self.slider.setValue(0)
        self.slider.valueChanged.connect(self.on_slider_value_changed)
        self.show_above_k_checkbox = QCheckBox("只显示金额超过自选金额的号码", self)
        self.show_above_k_checkbox.stateChanged.connect(self.on_checkbox_state_changed)

        layout = QVBoxLayout()
        layout.addWidget(self.input_top_label)
        layout.addWidget(self.number_input)
        layout.addWidget(self.amount_input)
        layout.addWidget(self.add_button)
        layout.addWidget(self.input_bottom_label)
        layout.addWidget(self.k_input)
        layout.addWidget(self.recommended_k_label)
        layout.addWidget(self.recommended_k_amount)
        layout.addWidget(self.history_label)
        layout.addWidget(self.history_display)
        layout.addWidget(self.display_label)
        layout.addWidget(self.slider_label)
        layout.addWidget(self.slider)
        layout.addWidget(self.show_above_k_checkbox)
        self.setLayout(layout)

        self.setGeometry(100, 100, 800, 600)
        self.setWindowTitle('金额统计应用程序')
        self.show()

    def on_add_button_clicked(self):
        number = self.number_input.text()
        amount = self.amount_input.text()
        try:
            number = int(number)
            amount = float(amount)
            if 1 <= number <= 49 and amount >= 0:
                if number not in self.data:
                    self.data[number] = 0
                self.data[number] += amount
                self.update_history_display()
                self.update_display()
        except ValueError:
            pass

    def on_slider_value_changed(self):
        self.update_display()

    def on_checkbox_state_changed(self):
        self.update_display()

    def update_history_display(self):
        history_text = ""
        for number, amount in self.data.items():
            if isinstance(number, int):
                history_text += f"号码{number}，金额：{amount}\n"
        self.history_display.setText(history_text)

    def update_display(self):
        self.recommended_k_amount.setText("")
        slider_value = self.slider.value() / 100
        show_above_k = self.show_above_k_checkbox.isChecked()
        self.update()

    def paintEvent(self, event):
        pixmap = QPixmap(self.size())
        pixmap.fill(QColor("white"))
        painter = QPainter(pixmap)
        painter.setPen(QPen(Qt.black, 2))

        max_amount = max(self.data.values()) if self.data else 1
        max_display = max_amount * 1.2

        bar_width = self.width() / 49
        bar_height_unit = self.height() / max_display

        for number, amount in self.data.items():
            if isinstance(number, int):
                x = (number - 1) * bar_width
                y = self.height() - (amount * bar_height_unit)
                # if show_above_k and amount < k:
                #     painter.setBrush(Qt.lightGray)
                # else:
                #     painter.setBrush(Qt.blue)
                painter.drawRect(x, y, bar_width, amount * bar_height_unit)

        # if show_above_k:
        #     k = float(self.k_input.text())
        #     self.recommended_k_amount.setText(str(self.get_recommended_k(k)))

        painter.end()
        painter = QPainter(self)
        painter.drawPixmap(0, 0, pixmap)

    def get_recommended_k(self, k):
        max_profit = 0
        recommended_k = 0
        for amount in self.data.values():
            profit = sum([max(0, amount - value) for value in self.data.values()]) - (47 * amount)
            if profit > max_profit:
                max_profit = profit
                recommended_k = amount
        return recommended_k


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        central_widget = CustomWidget(self)
        self.setCentralWidget(central_widget)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    mainWindow = MainWindow()
    sys.exit(app.exec_())

import QtQuick 2.9
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Window 2.2

import "./"

ApplicationWindow {
    id: root
    objectName: "roott"
    width: 500
    height: 370
    visible: true

    flags: Qt.Window | Qt.FramelessWindowHint



    Image {
        id: backgrand
        x: 0
        y: 0
        width: parent.width
        height: parent.height
        source: "qrc:/qmlforms/image 2.1.png"
    }
    Image {
        id: close
        x: parent.width - 25
        y: 11
        width: 13
        height: 13
        source: "qrc:/qmlforms/close.png"
    }
    Image {
        id: minmax
        x: parent.width - 45
        y: 21
        width: 13
        height: 2
        source: "qrc:/qmlforms/minmax.png"
    }


    Text {
        id: tittle
        x: 12
        y: 21
        width: 185
        height: 50
        color: "#ffffff"

        text: "NDR 东软校园网络认证 ver0.76"
        font.bold: true
    }

    MouseArea{
        id: rootMouseArea
        anchors.fill: parent
        property int rootx
        property int rooty
        property int mousex
        property int mousey
        property bool flag: false
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        hoverEnabled: true
        onPressed: {

            rootx = root.x
            rooty = root.y
            mousex = mouseX
            mousey = mouseY
            if(mouseY <= 50){
                flag = true
            }
            else{
                flag = false
            }
        }

        onPositionChanged: {
            var x = mouseX
            var y = mouseY
            if (x >= (parent.width - 25) && x <= (parent.width - 12) && y >= 11 && y <= 24)
                console.log ("reset close image")
            else if (x >= (parent.width - 45) && x <= (parent.width - 32) && y >= 11 && y <= 24)
                // reset minmax image
                console.log ("reset minmax image")
            if (mouse.buttons === 1) {
                if(mouseY <= 50 && flag){
                    root.x = root.x + (mouseX - mousex)
                    root.y = root.y + (mouseY - mousey)
                    rootx = root.x
                    rooty = root.y
                }
            }


        }

        onClicked: {
            var x = mouseX
            var y = mouseY
            if (x >= (parent.width - 25) && x <= (parent.width - 12) && y >= 11 && y <= 24)
                Qt.quit()
            else if (x >= (parent.width - 45) && x <= (parent.width - 32) && y >= 11 && y <= 24)
                root.visibility = Window.Minimized
        }





    }

    Rectangle {
        id: rectangle
        x: 0
        y: 150
        width: parent.width
        height: parent.height - 150
        color: "#ffffff"
        border.color: "#000000"
        ComboBox {
            id: combMod
            x: 80
            y: 30
            width: 150
            height: 30
            textRole: text
            editable: false

            model: ListModel{
                id: mod1
                ListElement{text: "aaa"; data: "bbb"}
                ListElement{text: "aaaa"; data: "bbbb"}
            }

            style: ComboBoxStyle {
                background: {
                    raise()
                }
            }

        }
        ComboBox {
            id: account
            x: 80
            y: 80
            height: 30
            textRole: "history"
            editable: true
            width: 150

        }

        TextField {
            id: password
            x: 80
            y: 130
            width: 150
            height: 30
            echoMode: TextInput.Password


        }

        CheckBox {
            id: remPassword
            x: 299
            y: 83
            width: 107
            height: 27
            text: qsTr("记住密码")

            style: CheckBoxStyle{
                indicator: Rectangle {
                                implicitWidth: 16
                                implicitHeight: 16
                                radius: 3
                                border.color: control.activeFocus ? "darkblue" : "gray"
                                border.width: 1
                                Rectangle {
                                    visible: control.checked
                                    color: "#555"
                                    border.color: "#333"
                                    radius: 1
                                    anchors.margins: 4
                                    anchors.fill: parent
                                }
                        }
            }
        }

        CheckBox {
            id: autoLogin
            x: 299
            y: 121
            width: 102
            height: 26
            text: qsTr("自动登录")

            style: CheckBoxStyle{
                indicator: Rectangle {
                                implicitWidth: 16
                                implicitHeight: 16
                                radius: 3
                                border.color: control.activeFocus ? "darkblue" : "gray"
                                border.width: 1
                                Rectangle {
                                    visible: control.checked
                                    color: "#555"
                                    border.color: "#333"
                                    radius: 1
                                    anchors.margins: 4
                                    anchors.fill: parent
                                }
                }
            }
        }

        MouseArea{
            onClicked: {}

            onReleased: {}

            onPressed: {}
        }

                Text {
                    id: text1
                    x: 16
                    y: 196
                    width: 66
                    height: 19
                    color: "#7c6e6e"
                    text: qsTr("修复网络")
                    font.pixelSize: 14
                }

                Text {
                    id: text2
                    x: 299
                    y: 46
                    color: "#0b82f9"
                    text: qsTr("选择网卡")
                    font.pixelSize: 16
                }
                Text {
                    id: tittle1
                    x: 299
                    y: 196
                    width: 185
                    height: 50
                    color: "#7c6e6e"
                    text: "NDR 东软校园网络认证 ver0.76"
                }
    }

    Rectangle {
        id: login_button
        x: 351
        y: 129
        height: 55
        color: "#448AFF"
        width: 55
        radius: 100
        border.color: "#448AFF"

        Image {
            x: 16
            y: 14
            width: 29
            height: 26
            source: "qrc:/qmlforms/login_logo.png"
        }

        MouseArea{
            id: login_button_mouse
            anchors.fill: parent
            onClicked: {

                login_button.color = "#448AFF"
            }
            onPressed: {
                login_button.color = "#5c7ffe"
                // transmit login signal
            }
        }
    }





}
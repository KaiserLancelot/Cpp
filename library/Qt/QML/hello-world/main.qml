import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    id: root
    visible: true
    width: 1000
    height: 618
    title: qsTr("Hello World")

    Image {
        id: background
        anchors.top: parent.top
        source: "qrc:/images/background.png"

        Image {
            id: pole
            source: "qrc:/images/pole.png"
            // 锚点可以指定对象与父对象和同级对象的相对几何位置
            // 水平居中(相对与元素的左右两边居中)
            anchors.horizontalCenter: parent.horizontalCenter
            // 底部位置
            anchors.bottom: parent.bottom
        }

        Image {
            id: wheel
            source: "qrc:/images/pinwheel.png"
            // 放在中央
            anchors.centerIn: parent
            Behavior on rotation {
                // 动画
                NumberAnimation {
                    duration: 250
                }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: wheel.rotation += 90
        }
    }

    Text {
        id: msg
        text: qsTr("Hello World!")
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }
}

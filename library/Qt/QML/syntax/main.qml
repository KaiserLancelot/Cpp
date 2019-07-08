import QtQuick 2.13
import QtQuick.Window 2.13

// 子元素从父元素上继承了坐标系统,它的x,y坐标总是相对应于它的父元素坐标系统
Window {
    id: root
    visible: true
    width: 1000
    height: 618
    title: qsTr("syntax")

    // 颜色属性
    color: "green"

    // 声明一个嵌套元素
    Image {
        id: rocket

        x: (parent.width - width) / 2
        y: 40

        source: "qrc:/images/background.png"
    }

    Text {
        y: rocket.y + rocket.height + 20

        // 设置文本项目宽度和高度内文本的水平和垂直对齐方式
        // 默认情况下,文本与顶部垂直对齐.水平对齐遵循文本的自然对齐
        // 例如从左到右读取的文本将与左对齐
        // 如果想让文本在其父对象中居中,那么你需要
        // 将horizontalAlignment设置为Text.AlignHCenter
        // 并将宽度绑定到父对象的宽度
        horizontalAlignment: Text.AlignHCenter
        width: root.width
        text: "Rocket"
    }

    Text {
        id: thisLabel

        // (2) set x- and y-position
        x: 24
        y: 16

        // (3) bind height to 2 * width
        height: 2 * width

        // (4) custom property
        property int times: 24

        // (5) property alias
        property alias anotherTimes: thisLabel.times

        // (6) set text appended by value
        text: "Greetings " + times

        // (7) font is a grouped property
        font.family: "Ubuntu"
        font.pixelSize: 24

        // (8) KeyNavigation is an attached property
        KeyNavigation.tab: otherLabel

        // (9) signal handler for property changes
        onHeightChanged: console.log('height:', height)

        // focus is neeed to receive key events
        focus: true

        // change color based on focus value
        color: focus ? "red" : "black"
    }
}

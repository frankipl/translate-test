import Felgo 3.0
import QtQuick 2.9

Rectangle {
    id:root
    property string lang_name
    property string lang_code
    property string lang_image
    property bool bottom_line:false
    property bool selected: (AppData.curr_lang_code===lang_code ? true : false)
    signal clicked()
    width:parent.width
    color: "transparent"
    anchors.leftMargin: dp(5)
    anchors.rightMargin: dp(5)

    Rectangle {
        id:delegateMainRect
        anchors.fill: parent
        color:"white"

        Text {
            id:nameText
            anchors.left: parent.left
            anchors.right: rightIcon.left
            anchors.top:parent.top
            anchors.leftMargin: dp(10)
            height: parent.height
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            text: lang_name
            font.pixelSize: height*0.3
            // MarkRect {}
        }
        Icon {
            id:rightIcon
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
            height:parent.height*0.5
            width:height
            scale:  1
            color: Theme.disclosureColor
            icon:  IconType.circle
            visible: selected
        }
        Rectangle {
            id:bottomLine
            anchors.bottom: parent.bottom
            anchors.left: nameText.left
            anchors.right: parent.right
            height:1
            color:Theme.dividerColor
            visible: bottom_line
        }
        MouseArea {
            id:insideMouse
            anchors.top:parent.top
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            onClicked: {
                AppData.selectLang(lang_code)
                root.clicked()
            }
        }
    }
}

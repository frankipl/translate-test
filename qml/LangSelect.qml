import Felgo 3.0
import QtQuick 2.9
//import QtGraphicalEffects 1.0

Page {
    id:page
    title: qsTr("languaqge select")
    backgroundColor: "lightgray"

//    RectangularGlow {
//        id: effect
//        anchors.fill: mainRect
//        glowRadius: 10
//        spread: 0.2
//        color: "black"
//        cornerRadius: mainRect.radius + glowRadius
//    }

    Rectangle {
        id:mainRect
        anchors.top:parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: dp(20)
        anchors.leftMargin: dp(10)
        anchors.rightMargin: dp(10)
        height:page.height-dp(40)-dp(Theme.navigationBar.height)-Theme.statusBarHeight
        radius:dp(10)
        border.width: 2
        border.color: "gray"
        LanguageRow {
            id:plLang
            anchors.top:parent.top
            anchors.topMargin: dp(10)
            anchors.left: parent.left
            anchors.right: parent.right
            height:dp(48)
            bottom_line: true
            lang_code: "pl"
            lang_name: qsTr("Polish lang")
            lang_image: "pl-flag-icon.png"
            onClicked: {
              //  langSelected()
            }
        }
        LanguageRow {
            id:enLang
            anchors.top:plLang.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height:dp(48)
            bottom_line: true
            lang_code: "en"
            lang_name: qsTr("English lang")
            lang_image: "en-flag-icon.png"
            onClicked: {
               // langSelected()
            }
        }
        LanguageRow {
            id:deLang
            anchors.top:enLang.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height:dp(48)
            bottom_line: true
            lang_code: "de"
            lang_name: qsTr("Deutsch lang")
            lang_image: "de-flag-icon.png"
            onClicked: {
               // langSelected()
            }
        }
    }
}

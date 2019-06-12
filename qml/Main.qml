import Felgo 3.0
import QtQuick 2.0

App {
    // You get free licenseKeys from https://felgo.com/licenseKey
    // With a licenseKey you can:
    //  * Publish your games & apps for the app stores
    //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
    //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
    //licenseKey: "<generate one from https://felgo.com/licenseKey>"

    Navigation {
        id: nav
        // Comment to use a navigation drawer instead of tabs on Android
        navigationMode: navigationModeTabs

        NavigationItem {
            id:greetItem
            title: qsTr("greetings")
            icon: IconType.checksquareo

            NavigationStack {
                id:greetItemNavStack
                splitView: tablet

            }
        }

        NavigationItem {
            id:readItem
            title: qsTr("read")
            icon: IconType.leanpub

            NavigationStack {
                id:readItemStack
                splitView: tablet

            }
        }
        NavigationItem {
            id:writeItem
            title: qsTr("write")
            icon: IconType.pencilsquareo

            NavigationStack {
                id:writeItemStack
                splitView: tablet

            }
        }
        NavigationItem {
            id:settingsItem
            title: qsTr("settings")
            icon: IconType.cog

            NavigationStack {
                id:settingsItemStack
                splitView: tablet

                LangSelect {
                    id:langSelect
                    visible: false
                }
            }
        }
    }
}

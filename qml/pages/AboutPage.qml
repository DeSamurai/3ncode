import QtQuick 2.0
import Sailfish.Silica 1.0
import Opal.About 1.0 as About

About.AboutPageBase {
    id: root

    appName: mainWindow.appname
    appIcon: Qt.resolvedUrl(mainWindow.appicon)
    appVersion: mainWindow.version
    description: qsTr("An easy to use audio & video encoder based on ffmpeg.")
    authors: ["DeSamurai (" + qsTr("fork maintainer") + ")",
        "llelectronics (" + qsTr("original app creator") + ")"]
    homepageUrl: "https://openrepos.net/"
    extraSections: [
        About.InfoSection {
            title: qsTr("Fork source code")
            buttons: [
                About.InfoButton {
                    text: qsTr("Link")
                    onClicked: root.openOrCopyUrl("https://github.com/DeSamurai/3ncode")
                }
            ]
        },
        About.InfoSection {
            title: qsTr("Original source code")
            buttons: [
                About.InfoButton {
                    text: qsTr("Link")
                    onClicked: root.openOrCopyUrl("https://github.com/llelectronics/3ncode")
                }
            ]
        }
    ]
    licenses: About.License {
        spdxId: "BSD-3-Clause"
        customShortText: "This is free software: you are welcome to redistribute it under certain conditions. " +
                         "There is NO WARRANTY, to the extent permitted by law."
    }
    contributionSections: [
        About.ContributionSection {
            title: qsTr("Development")
            groups: [
                About.ContributionGroup {
                    title: qsTr("Icon Design")
                    entries: ["llelectronics"]
                }
            ]
        },
        About.ContributionSection {
            title: qsTr("Translations")
            groups: [
                About.ContributionGroup {
                    title: qsTr("English")
                    entries: ["llelectronics"]
                },
                About.ContributionGroup {
                    title: qsTr("Deutsch")
                    entries: ["llelectronics"]
                },
                About.ContributionGroup {
                    title: qsTr("Swedish")
                    entries: ["Åke Engelbrektson"]
                }
            ]
        }
    ]
}

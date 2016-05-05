import QtQuick 2.0
import com.syberos.basewidgets 2.0
import base 1.0

CPageStackWindow {
    initialPage:CPage{
        id: root
        width:parent.width
        height:parent.height
        TextEdit {
            id: edit
            width: flick.width
            height: flick.height
            focus: true
            wrapMode: TextEdit.Wrap
            visible: false

            onFocusChanged: {
                edit.visible = focus;
            }
        }
        SyberImage{
            id: contentImage
            anchors.fill: parent
            onNewText:{
                edit.x = 0;
                edit.y = 0;
                edit.width = 100;
                edit.height = 100;
                edit.visible = true;
            }

            MouseArea{
                anchors.fill: parent

                onPressed: {
                    contentImage.mousePress(Qt.point(mouse.x, mouse.y));
                }
                onPositionChanged: {
                    contentImage.mouseMouse(Qt.point(mouse.x, mouse.y));
                }
                onDoubleClicked: {
                    contentImage.mouseDoubleClick(Qt.point(mouse.x, mouse.y));
                }

                onReleased: {
                    contentImage.mouseRelease(Qt.point(mouse.x, mouse.y));
                }
            }
        }
        Rectangle{
            width: parent.width
            height: 100
            anchors.bottom: parent.bottom
            color: "gray"
        }

        Row{
            width: parent.width
            height: 100
            anchors.bottom: parent.bottom

            Image{
                height: 100
                width: parent.width/7
                source: "./img/EditMove.png";

                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(0);
                    }
                }
            }
            Image{
                height: 100
                width: parent.width/7
                source: "./img/DrawLine.png";
                sourceSize: Qt.size(parent.width-5, parent.height-5);
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(1);
                    }
                }
            }
            Image{
                height: 100
                width: parent.width/7
                source: "./img/DrawRectangle.png";
                sourceSize: Qt.size(parent.width-5, parent.height-5);
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(2);
                    }
                }
            }
            Image{
                height: 100
                width: parent.width/7
                source: "./img/DrawRoundRect.png";
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(3);
                    }
                }
            }
            Image{
                height: 100
                width: parent.width/7
                source: "./img/DrawString.png";
                sourceSize: Qt.size(parent.width-5, parent.height-5);

                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(4);
                    }
                }
            }
            Image{
                height: 100
                width: parent.width/7
                source: "./img/DrawImage.png";
                sourceSize: Qt.size(parent.width-5, parent.height-5);
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        var imgPage = pageStack.push(Qt.resolvedUrl("ChoseImage.qml"));
                        imgPage.pathRetrived.connect(function(path, is_original) {
                            console.log("path = ", path);
                            contentImage.setImagePath(path);
                            pageStack.pop(root);
                        })
                        contentImage.setOperatorTool(0);
                    }
                }
            }
            Image{
                height: 100
                width: parent.width/7
                source: "./img/delete.png";
                sourceSize: Qt.size(parent.width-5, parent.height-5);

                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.deleteItem();
                    }
                }
            }
        }
        Component.onCompleted: {
            gScreenInfo.setStatusBar(true)
            gScreenInfo.setStatusBarStyle("black")
        }
    }
}

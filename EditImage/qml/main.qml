import QtQuick 2.0
import com.syberos.basewidgets 2.0
import base 1.0

CPageStackWindow {
    initialPage:CPage{
        id: root
        width:parent.width
        height:parent.height
        property variant items:[move, line, rect, roundRect, dstring, img, del];
        SyberImage{
            id: contentImage
            anchors.fill: parent
            onNewText:{
                console.log("xingkongdao=====================", rect);
                edit.text="";
                edit.x = rect.x;
                edit.y = rect.y;
                edit.width = rect.width;
                edit.height = rect.height;
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
            visible: false
        }

        Rectangle{
            id: frame
            x: edit.x -5
            y: edit.y -5
            width: edit.width+5
            height: edit.height+5

            border.width: 3
            visible: edit.visible;
        }
        TextEdit {
            id: edit
            width: 100
            height: 100
            wrapMode: TextEdit.Wrap
            visible: false
            focus: visible
            onFocusChanged: {
                if(!focus){
                    edit.visible = focus;
                    contentImage.setCurText(edit.text);
                }
            }
        }

        Row{
            width: parent.width
            height: 100
            anchors.bottom: parent.bottom
            Item{
                id: move
                height: 100
                width: parent.width/7

                Image{
                    scale: 2
                    anchors.centerIn: parent
//                    height: width
//                    width: parent.width/7 - 40
                    source: "./img/EditMove.png";
                }
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(0);
                        root.setStatus(parent);
                    }
                }
            }
            Item{
                id: line
                height: 100
                width: parent.width/7
                Image{
                    scale: 2
                    anchors.centerIn: parent
                    source: "./img/DrawLine.png";
                }
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(1);
                        root.setStatus(parent);
                    }
                }
            }
            Item{
                id: rect
                height: 100
                width: parent.width/7
                Image{
                    scale: 2
                    anchors.centerIn: parent
                    source: "./img/DrawRectangle.png";
                }
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(2);
                        root.setStatus(parent);
                    }
                }
            }
            Item{
                id:roundRect
                height: 100
                width: parent.width/7
                Image{
                    scale: 2
                    anchors.centerIn: parent
                    source: "./img/DrawRoundRect.png";
                }
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(3);
                        root.setStatus(parent);
                    }
                }
            }
            Item{
                id: dstring
                height: 100
                width: parent.width/7
                Image{
                    scale: 2
                    anchors.centerIn: parent
                    source: "./img/DrawString.png";
                }
                MouseArea{
                    anchors.fill: parent

                    onClicked: {
                        contentImage.setOperatorTool(5);
                        root.setStatus(parent);
                    }
                }
            }
            Item{
                id: img
                height: 100
                width: parent.width/7
                Image{
                    scale: 2
                    anchors.centerIn: parent
                    source: "./img/DrawImage.png";
                }
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
            Item{
                id: del
                height: 100
                width: parent.width/7
                Image{
                    scale: 2
                    anchors.centerIn: parent
                    source: "./img/delete.png";
                    sourceSize: Qt.size(20, 20);
                }
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
        function setStatus(id)
        {
            for(var i = 0; i<items.length; i++)
            {
                if(items[i] == id)
                {
                    items[i].opacity = 0.2
                }
                else
                {
                    items[i].opacity = 1.0
                }
            }
        }
    }
}
